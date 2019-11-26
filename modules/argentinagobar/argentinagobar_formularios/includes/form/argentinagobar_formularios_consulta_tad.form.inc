<?php

function argentinagobar_formularios_consulta_tad($form, &$form_state) {

  $form = array(
    '#attributes' => array(
      'class' => 'm-t-2',
    ),
  );

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor',
    ),
  );

  $form['contenedor']['row-1'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'row-1',
      'class' => array('row'),
    ),
  );

  $form['contenedor']['row-2'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'row-2',
      'class' => array('row'),
    ),
  );

  $form['contenedor']['row-1']['anioExpediente'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Año de Expediente'),
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div>',
    '#rules' => array('numeric', 'length[4]'),
    '#theme' => array('form_element_addon'),
    '#attributes' => array(
      'data-input-group-addon-left-text' => 'EXP-',
      'aria-describedby' => "addon-" . $form['#id'],
    ),
  );

  $form['contenedor']['row-1']['numeroExpediente'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title'    => t('Número de Expediente'),
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div>',
    '#theme' => array('form_element_addon'),
    '#attributes' => array(
      'data-input-group-addon-left-text' => '-',
      'aria-describedby' => "addon-" . $form['#id'],
    ),
  );

  $form['contenedor']['row-1']['codigoReparticion'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title'    => t('Código de Repartición'),
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div>',
    '#theme' => array('form_element_addon'),
    '#attributes' => array(
      'data-input-group-addon-left-text' => '-APN-',
      'aria-describedby' => "addon-" . $form['#id'],
    ),
  );

  $form['contenedor']['row-2']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Enviar'),
    '#attributes' => array(
      'class' => array('btn', 'btn-success', 'btn-block', 'form-submit'),
    ),
    '#prefix' => '<div class="col-md-8 col-md-offset-2">',
    '#suffix' => '</div>',
    '#ajax' => array(
      'callback' => 'argentinagobar_formularios_consulta_tad_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}

function argentinagobar_formularios_consulta_tad_submit_ajax($form, $form_state) {

  $form_id = $form_state['build_info']['form_id'];

  drupal_validate_form($form_id, $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }

  $request = drupal_http_request("https://tramitesadistancia.gob.ar/tramitesadistancia/rest/consultaExpedienteTAD/anio/" . drupal_encode_path($form_state['values']['anioExpediente']) . "/numero/" . drupal_encode_path($form_state['values']['numeroExpediente']) . "/repUsuario/" . drupal_encode_path($form_state['values']['codigoReparticion']) . "/data.json");

  if(empty($request)  || !isset($request)) {
    drupal_set_message("No pudimos procesar tu consulta. Por favor intentalo nuevamente", 'error', $repeat = FALSE);
    $form_state['rebuild'] = TRUE;

    return $form;
  }

  if($request->code == 400) {
    drupal_set_message("Por favor verificá que los datos ingresados sean correctos e intentalo nuevamente", 'error', $repeat = FALSE);
    $form_state['rebuild'] = TRUE;

    return $form;
  }

  if($request->code == 200) {
    $data = drupal_json_decode($request->data);
    $response = theme('argentinagobar_formularios_consulta_tad_respuesta', array('data' => $data));

  } else {
    drupal_set_message("No pudimos procesar tu consulta. Por favor intentalo nuevamente", 'error', $repeat = FALSE);
    $form_state['rebuild'] = TRUE;

    return $form;
  }

  return '<div id="contenedor">' . $response . '</div>';
}
