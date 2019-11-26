<?php

class ConsultaInfolegAvanzada extends ConsultaInfoleg
{
  function get_form($form, &$form_state, $consulta)
  {
    $form = parent::get_form($form, $form_state, $consulta);

    $form['#attached']['css'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/Infoleg/estilosInfoleg.css',
    );

    $form['contenedor']['texto'] = array(
      '#type' => 'textfield',
      '#title' => t('Texto'),
      '#attributes' => array(
        'placeholder' => t('norma, número y/o dependencia'),
      ),
      '#prefix' => '<div class="col-md-3">',
      '#suffix' => '</div>',
      '#default_value' => isset($_GET['texto']) ? htmlspecialchars_decode($_GET['texto']): '',
    );

    if($this::getJurisdiccion() == 'provincial') {

      $form['contenedor']['provincia'] = $this->getFieldProvincias();
      $form['contenedor']['provincia']['#prefix'] = '<div class="col-md-3">';
      $form['contenedor']['provincia']['#suffix'] = '</div>';

      $form['contenedor']['tipo_norma'] = array(
        '#type' => 'textfield',
        '#title' => t('Tipo de norma'),
        '#prefix' => '<div class="col-md-3">',
        '#suffix' => '</div>',
        '#value' => t('Ley'),
        '#attributes' => array('disabled' => TRUE,
      ),
    );

    }

    if($this::getJurisdiccion() == 'nacional') {

      $form['contenedor']['tipo_norma'] = $this->getFieldTiposNormas();
      $form['contenedor']['tipo_norma']['#prefix'] = '<div class="col-md-2">';
      $form['contenedor']['tipo_norma']['#suffix'] = '</div>';

    }

    $numero = new FieldNumeric('Número (sin puntos)');
    $form['contenedor']['numero'] = $numero->render();
    $form['contenedor']['numero']['#rules'] =
      array(
        array('rule' => 'numeric', 'error' => 'El campo %field solo admite números'),
        array('rule' => 'textNumberSpaces', 'error' => 'El campo %field solo admite números'),
      );
    $form['contenedor']['numero']['#prefix'] = '<div class="col-md-2">';
    $form['contenedor']['numero']['#suffix'] = '</div>';

    $anio = new FieldSelect('Año', $this->getYears());
    $form['contenedor']['sancion'] = $anio->render();
    $form['contenedor']['sancion']['#empty_value'] = '';
    $form['contenedor']['sancion']['#prefix'] = '<div class="col-md-2">';
    $form['contenedor']['sancion']['#suffix'] = '</div>';

    if($this::getJurisdiccion() == 'nacional') {

      $form['contenedor']['dependencia'] = array(
        '#type' => 'select',
        '#title' => t('Dependencia'),
        '#options' => $this->getDependencias(),
        '#empty_option' => t(''),
        '#prefix' => '<div class="col-md-3">',
        '#suffix' => '</div>',
        '#attributes' => array(
          'name' => 'dependencia'
        ),
        '#default_value' => isset($_GET['dependencia']) ? check_plain($_GET['dependencia']) : '',
      );

    }

    $form['contenedor']['publicacion_desde'] = array(
      '#type' => 'date_popup',
      '#title' => t('Publicación desde'),
      '#date_format' => 'd-m-Y',
      '#date_year_range' => '-200:+0',
      '#element_validate' => [
        [$this, 'menos_de_cuatro_años'],
        [$this, 'desdeMayorHasta']
      ],
      '#prefix' => '<div class="col-md-3">',
      '#suffix' => '</div>',
      '#theme' => array('form_element_date'),
      '#attributes' => array(
        'name' => 'publicacion_desde'
      ),
      '#default_value' => isset($_GET['publicacion_desde']) ? check_plain($_GET['publicacion_desde']) : '',
    );

    $form['contenedor']['publicacion_hasta'] = array(
      '#type' => 'date_popup',
      '#title' => t('Publicación hasta'),
      '#date_format' => 'd-m-Y',
      '#date_year_range' => '-200:+0',
      '#prefix' => '<div class="col-md-3">',
      '#suffix' => '</div>',
      '#theme' => array('form_element_date'),
      '#attributes' => array(
        'name' => 'publicacion_hasta'
      ),
      '#default_value' => isset($_GET['publicacion_hasta']) ? check_plain($_GET['publicacion_hasta']) : '',
    );

    $form['contenedor']['submit-wrapper'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'submit-wrapper',
        'class' => array(
          'col-md-3'
        ),
      ),
    );

    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn-primary');
    $submitButton->addClass('btn-block');
    $submitButton->setValue("Buscar");

    $form['contenedor']['submit-wrapper']['submit'] = $submitButton->render();
    $form['contenedor']['submit-wrapper']['submit']['#attributes']['class'][] = 'm-t-2';

    # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
    $form_state['handler']['class'] = serialize($this);

    return $form;
  }

  function validParams()
  {
    return array(
      'sancion',
      'tipo_norma',
      'numero',
      'dependencia',
      'publicacion_desde',
      'publicacion_hasta',
      'texto',
      'jurisdiccion',
      'provincia',
      'limit',
      'offset',
    );
  }

  function menos_de_cuatro_años($element, &$form_state, $form)
  {
    // if(validarFecha($form_state['values']['publicacion_desde']['date']) || validarFecha($form_state['values']['publicacion_desde']['hasta'])){
    $desde = new DateTime($form_state['values']['publicacion_desde']['date']);
    $hasta = new DateTime($form_state['values']['publicacion_hasta']['date']);
    $diff = $desde->diff($hasta);
// }

    if (isset($diff) && $diff->days > 1461  ){
      form_error($element, t('El rango de fechas debe ser Menor o Igual a 4 años.'));
    }
  }

  function desdeMayorHasta($element, &$form_state, $form)
  {
    $fechaDesde = strtotime($form_state['values']['publicacion_desde']['date']);
    $fechaHasta = strtotime($form_state['values']['publicacion_hasta']['date']);

    if (!empty($fechaHasta) && $fechaDesde > $fechaHasta ){
      form_error($element, t('La Fecha Desde no puede ser mayor que la Fecha Hasta.'));
    }
  }

  function validar_busqueda($form, &$form_state)
  {

    if (is_null($form_state['values']['texto']) && sizeof($this->filtrarParametros($form_state['values'])) < 3 ) {

      form_set_error('', t('Debes ingresar por lo menos dos parametros validos.'));

    }

  }

  function hayParametros()
  {
    return isset($this->getParametros()['texto']) || sizeof($this->filtrarParametros($this->getParametros())) >= 3;
  }

}

function validarFecha($fecha)
{
  return (bool) preg_match('/^\d{4}-\d{4}$/',$fecha);
}
