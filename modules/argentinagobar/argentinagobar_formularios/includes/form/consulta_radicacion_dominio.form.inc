<?php

function consulta_radicacion_dominio($form, &$form_state) {

  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor',
    ),
  );

  $form['#attached']['js'][] = array(
    'type' => 'file',
    'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/onKeyPressEnterSubmitForm.js',
  );

  $form['contenedor']['item_titulo'] = array(
    '#type' => 'markup',
    '#markup' => '<p>Si estás por comprar un automóvil u otro vehículo automotor, necesitás saber cuál es el Registro Automotor en el que está radicado.</p>',
  );

  $form['contenedor']['patente'] = array(
    '#type' => 'textfield',
    '#title' => 'Patente del vehículo',
    '#maxlength' => 8,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('submit-with-enter'),
    ),
    '#rules' => array('length[0, 8]', 'alpha_numeric'),
  );


  $form['contenedor']['envio_formulario'] = array(
    '#type' => 'submit',
    '#value' => t('Consultar'),
    '#attributes' => array(
      'class' => array(
        'btn-success',
        'btn',
        'btn-block',
        'btn-lg',
      ),
    ),
    '#ajax' => array(
      'callback' => 'consulta_radicacion_dominio_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}



function consulta_radicacion_dominio_submit_ajax($form, &$form_state){

  $form_id = $form_state['build_info']['form_id'];
  drupal_validate_form($form_id, $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }

  $consulta = new ConsultaRadicacionPorDominio(ApiGatewayAuth::getInstance(), $form_state['values']);

  return $consulta->consultar();

}
