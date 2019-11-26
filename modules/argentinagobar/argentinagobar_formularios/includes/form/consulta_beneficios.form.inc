<?php
function consulta_beneficios($form, &$form_state){
  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor'
    ),
  );

  $form['contenedor']['cuil'] = array(
    '#type' => 'textfield',
    '#title' => t('CUIL'),
    '#required' => TRUE,
    '#rules' => array('numeric', 'length[11, 14]'),

  );

  $form['contenedor']['submit'] = array(
    '#prefix' => '<div class="text-center">',
    '#suffix' => '</div>',
    '#type' => 'submit',
    '#ajax' => array(
      'callback' => 'consulta_beneficios_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#value' => t('Consultar Beneficios'),
      '#attributes' => array(
        'class' => array(
        'btn',
        'btn-success',
        'btn-block',
        'btn-lg',
        ),
      ),
  );
  return $form;
}

function consulta_beneficios_ajax($form, $form_state){
  $form_id = $form_state['build_info']['form_id'];

  drupal_validate_form($form_id, $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }


  $consulta = new ConsultaBeneficios(ApiGatewayAuth::getInstance(), $form_state['values']);

  return $consulta->consultar();
  }
