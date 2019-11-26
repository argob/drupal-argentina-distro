<?php

class ConsultaInfolegBoletin extends ConsultaInfoleg
{

  public function __construct(
    ConsultaInfolegProvincias $consultaProvincias,
    IConsultaInfolegTipoNorma $consultaTipoNorma,
    ApiGatewayAuth $api_gateway_auth,
    array $values = array()
  ) {

    parent::__construct($consultaProvincias, $consultaTipoNorma, $api_gateway_auth, $values);

    $this->modosBusqueda = array('fecha', 'numero');

  }

  function get_form($form, &$form_state, $consulta)
  {
    $form = parent::get_form($form, $form_state, $consulta);

    $form['#attached']['css'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/Infoleg/estilosInfoleg.css',
    );

    if($this::getJurisdiccion() == 'provincial') {

      $form['contenedor']['provincia'] = $this->getFieldProvincias();
      $form['contenedor']['provincia']['#prefix'] = '<div class="col-md-3">';
      $form['contenedor']['provincia']['#suffix'] = '</div>';

    }

    $form['contenedor']['buscar'] = array(
      '#type' => 'date_popup',
      '#title' => 'Fecha de Publicación',
      '#attributes' => array(
        'placeholder' => 'Seleccioná la fecha de publicación'
      ),
      '#date_format' => 'd-m-Y',
      '#date_year_range' => '-200:+0',
      '#theme' => array('form_element_date'),
      '#prefix' => '<div class="col-md-4">',
      '#suffix' => '</div>',
      '#default_value' => isset($_GET['buscar']) ? check_plain($_GET['buscar']) : '',
      '#element_validate' => [[$this, 'validar_fecha']]
    );

    $form['contenedor']['submit-wrapper'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'submit-wrapper',
        'class' => array(
          'col-md-2'
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

  function validateParams()
  {
    if (!isset($this->values['buscar'])) {
      throw new ParametroRequeridoException('Falta uno o más parámetros requeridos', 'Falta uno o más parámetros requeridos', 7);
    }
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();

    if (is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    $params = $this->get_params();

    return $endpoint. "/publicaciones/" . $params['buscar'] . '?'. http_build_query($params);
  }

  function renderResponse($form, &$form_state, $data)
  {

    if (isset($data['results']) && count($data['results']) > 0) {

      $numero = $data['results'][0]['numeroBoletin'];
      $cantidad = $data['metadata']['resultset']['count'];
      $fechaPublicacion = $data['results'][0]['publicacion'];
      $hoy = date('Y-m-d', time());

      if($fechaPublicacion == $hoy){
        $siguiente = "";
      }else{
        $siguiente = base_path() . drupal_get_path_alias() . '?modo_busqueda=numero&buscar=' . ($numero + 1);
      }

      $response = theme('listado_infoleg_boletin', array(
          'items'=> $data['results'],
          'numero' => $numero,
          'fechaPublicacion' => $data['results'][0]['publicacion'],
          'siguiente' => $siguiente,
          'anterior' => base_path() . drupal_get_path_alias() . '?modo_busqueda=numero&buscar=' . ($numero - 1),
          'paginas' => ceil($cantidad / $this->getItemsPerPage()),
          'offset' => $data['metadata']['resultset']['offset'],
        )
      );

    } else {
      $response = theme('infoleg_no_se_encontro_norma');
    }

    return $response;
  }

  function addModoBusqueda($modoBusqueda)
  {
    $this->modosBusqueda[] = $modoBusqueda;
  }

  function getModosBusqueda()
  {
    return $this->modosBusqueda;
  }

  function modoDeBusquedaValido($modoBusqueda)
  {
    return in_array($modoBusqueda, $this->getModosBusqueda());
  }

  function validParams()
  {
    return array(
      'modo_busqueda',
      'numero',
      'limit',
      'offset',
      'buscar',
      'provincia',
      'jurisdiccion',
    );
  }


  function validar_busqueda($form, &$form_state)
  {
    if($form_state['values']['tabs']['tabs__active_tab'] == 'modo-busqueda-fecha' && !$form_state['values']['fecha_publicacion']){
      form_set_error('argobar-consulta-infoleg-buscar-boletin', t('Debes ingresar una fecha válida'));
    }
    if($form_state['values']['tabs']['tabs__active_tab'] == 'modo-busqueda-numero' && !$form_state['values']['numero']){
      form_set_error('argobar-consulta-infoleg-buscar-boletin', t('Debes ingresar un número válido'));
    }
  }

  function validar_fecha($element, $form, &$form_state)
  {
    if(empty($element['#value']['date'])) {
      form_set_error($element, t('Debes ingresar una fecha válida'));
    }
  }

  function hayParametros()
  {
    return isset($this->getParametros()['buscar']) && $this->getParametros()['buscar'] != null;
  }
}
