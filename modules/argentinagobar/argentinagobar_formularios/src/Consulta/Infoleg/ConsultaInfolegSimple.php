<?php

class ConsultaInfolegSimple extends ConsultaInfoleg
{
    public $items;

  function get_form($form, &$form_state, $consulta) {

    $form = parent::get_form($form, $form_state, $consulta);

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
      $form['contenedor']['tipo_norma']['#prefix'] = '<div class="col-md-3">';
      $form['contenedor']['tipo_norma']['#suffix'] = '</div>';

    }

    $numero = new FieldNumeric('Número (sin puntos)');
    $form['contenedor']['numero'] = $numero->render();
    $form['contenedor']['numero']['#rules'] =
      array(
        array('rule' => 'numeric', 'error' => 'El campo %field solo admite números'),
        array('rule' => 'length[1, 10]', 'error' => 'La longitud ingresada en el campo %field es incorrecta.'),
      );
    $form['contenedor']['numero']['#prefix'] = '<div class="col-md-2">';
    $form['contenedor']['numero']['#suffix'] = '</div>';

    $anio = new FieldSelect('Año', $this->getYears());
    $form['contenedor']['sancion'] = $anio->render();
    $form['contenedor']['sancion']['#empty_value'] = '';
    $form['contenedor']['sancion']['#prefix'] = '<div class="col-md-2">';
    $form['contenedor']['sancion']['#suffix'] = '</div>';

    $form['contenedor']['submit-wrapper'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'submit-wrapper',
        'class' => array(
          'col-md-2'
        ),
      ),
    );

    $submitButton = $this->getFieldSubmit();
    $submitButton->addClass('m-t-2');
    $form['contenedor']['submit-wrapper']['submit'] = $submitButton->render();

    # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
    $form_state['handler']['class'] = serialize($this);

    return $form;
  }

  function validParams() {

    return [
      'sancion',
      'tipo_norma',
      'numero',
      'limit',
      'offset',
      'jurisdiccion',
      'provincia'
    ];

  }

  function validar_busqueda($form, &$form_state)
  {

    if (sizeof($this->filtrarParametros($form_state['values'])) < 3 ) {
      form_set_error('', t('Debes ingresar por lo menos dos parametros validos.'));
    }

  }

  function hayParametros()
  {
    return sizeof($this->filtrarParametros($this->getParametros())) >= 3;
  }

}
