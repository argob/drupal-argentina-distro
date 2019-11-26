<?php

define("USERNAME", variable_get('consulta_cortes_programados_username', NULL));
define("PASSWORD", variable_get('consulta_cortes_programados_password', NULL));
define("CLIENT_ID", variable_get('consulta_cortes_programados_client_id', NULL));
define("CLIENT_SECRET", variable_get('consulta_cortes_programados_client_secret', NULL));
define("TOKEN_ENDPOINT", variable_get('consulta_cortes_programados_token_endpoint', NULL));
define("CLIENT_ENDPOINT", variable_get('consulta_cortes_programados_client_endpoint', NULL));

function argentinagobar_formularios_consulta_cortes_programados($form, &$form_state) {

  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor',
    ),
  );

  $form['contenedor']['empresa'] = array(
    '#type' => 'select',
    '#title' => t('Empresa'),
    '#required' => TRUE,
    '#empty_option' => t('Seleccioná una empresa'),
    '#options' => array(
      'edenor' => t('Edenor'),
      'edesur' => t('Edesur'),
    ),
    '#description' => t('Seleccione aqui una opción'),
  );

  $form['contenedor']['factura_edesur'] = array(
    '#title' => t('Estos son los datos que tenés que buscar en tu factura.'),
    '#type' => 'item',
    '#states' => array(
      'visible' => array(
        ':input[name="empresa"]' => array(
            'value' => 'edesur',
        )
      )
    ),
    '#markup' =>'<img src="https://www.argentina.gob.ar/sites/default/files/edesur_0.jpg">'
  );

  $form['contenedor']['factura_edenor'] = array(
    '#title' => t('Estos son los datos que tenés que buscar en tu factura.'),
    '#type' => 'item',
    '#states' => array(
      'visible' => array(
        ':input[name="empresa"]' => array(
            'value' => 'edenor',
        )
      )
    ),
    '#markup' => '<img src="https://www.argentina.gob.ar/sites/default/files/edenor.jpg">'
  );

  $form['contenedor']['n_cliente'] = array(
    '#type' => 'textfield',
    '#title' => t('Número de cliente o cuenta'),
    '#description' => t('<small class="text-muted">Este dato figura en tu factura en el lugar indicado en la imagen</small>'),
    '#size' => 60,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#rules' => array(
      array('rule' => 'numeric', 'error' => 'El campo Número de cliente o cuenta debe tener solamente números.'),
    ),
  );

  $form['contenedor']['n_medidor'] = array(
    '#type' => 'textfield',
    '#title' => t('Últimos tres números de tu medidor'),
    '#description' => t('<small class="text-muted">Este dato figura en tu factura en el lugar indicado en la imagen</small>'),
    '#size' => 60,
    '#maxlength' => 3,
    '#required' => TRUE,
    '#rules' => array(
      array('rule' => 'length[3]', 'error' => 'El campo Últimos tres números de tu medidor debe ser un número de tres dígitos.'),
      array('rule' => 'numeric', 'error' => 'El campo Últimos tres números de tu medidor debe tener solamente números.'),
    ),
  );

  $form['contenedor']['boton_consulta_cortes_programados'] = array(
    '#prefix' => '<div class="text-center">',
    '#suffix' => '</div>',
    '#type' => 'submit',
    '#value' => t('Ver si hay cortes programados'),
    '#attributes' => array(
      'class' => array(
        'btn',
        'btn-success',
        'btn-lg',
        'text-center'
      ),
    ),
    '#ajax' => array(
      'callback' => 'argentinagobar_formularios_consulta_cortes_programados_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['contenedor']['info'] = array(
    '#type' => 'markup',
    '#markup' => '<hr><div class=""><h4>Para más información</h4>
                <p><strong>EDESUR: 0800-333-3787 - EDENOR: 0800-666-4001</strong></p>
                <p>' . l('Volver a inicio', 'node/7053') . '</p>
                </div>'
  );


  return $form;
}

function argentinagobar_formularios_consulta_cortes_programados_submit_ajax($form, &$form_state) {

  drupal_validate_form('argentinagobar_formularios_consulta_cortes_programados', $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }

  return consultar_cortes_programados(obtener_token(), $form_state);

}

function consultar_cortes_programados($access_token, $form_state){

  $params = array(
    'company' => $form_state['values']['empresa'],
    'meter' => $form_state['values']['n_medidor'],
    'client' => $form_state['values']['n_cliente'],
  );

  $hash = base64_encode(drupal_json_encode($params));

  $mi_argentina_link = variable_get('argentinagobar_ciudadano_digital_profile_link', '') . '?api=cortes#' . $hash;

  $data = http_build_query($params);

  $url = CLIENT_ENDPOINT . '?' . $data;

  $options = array(
    'headers' => array('Authorization' => 'Bearer ' . $access_token),
  );

  $request = drupal_http_request($url, $options);

  if($request->code == 401){
    consultar_cortes_programados(refresh_token(), $form_state);
  }

  $company = $form_state['values']['empresa'] == 'edenor' ? 'EDENOR:  0800-666-4001' : 'EDESUR: 0800-333-3787';

  if($request->code == 404){

    $feedback_data = array(
      'titulo' => t('No están previstos cortes programados en tu zona'),
      'mensaje' => NULL,
      'icono' => 'fa-check-circle text-success',
      'empresa' => $company,
      'mi_argentina_link' => $mi_argentina_link,
    );

    $response = theme('argentinagobar_formularios_consulta_cortes_programados_feedback', array('data' => $feedback_data));
  }

  if($request->code == 200){

    $data = drupal_json_decode($request->data);

    $feedback_data = array(
      'titulo' => t('Están previstos cortes programados en tu zona'),
      'mensaje' => t(
        'El !start_date a !end_date aproximadamente se efectuará un corte de suministro en la zona de tu domicilio.',
        array(
          '!start_date' => '<strong>' . format_date(strtotime($data['start_date']), 'custom', 'd/m/Y \d\e H:i') . '</strong>',
          '!end_date' => '<strong>' . format_date(strtotime($data['end_date']), 'custom', 'H:i') . 'hs.</strong>',
        )
      ),
      'icono' => 'fa-exclamation-triangle text-warning',
      'empresa' => $company,
      'mi_argentina_link' => $mi_argentina_link,
    );

    $response = theme('argentinagobar_formularios_consulta_cortes_programados_feedback', array('data' => $feedback_data));
  }

  return '<div id="contenedor">' . $response . '</div>';
}

function refresh_token(){

  variable_del('access_token');

  return obtener_token();
}

function obtener_token(){

  $access_token = variable_get('access_token', $default = NULL);

  if(!is_null($access_token)) {
    return $access_token;
  }

  $params = array(
    'username' => USERNAME,
    'password' => PASSWORD,
  );

  $data = http_build_query($params);

  $options = array(
    'method' => 'POST',
    'data' => $data,
    'timeout' => 15,
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
  );

  $url = TOKEN_ENDPOINT;

  $request = drupal_http_request($url, $options);

  if($request->code == 200){

    $data = drupal_json_decode($request->data);

    variable_set('access_token', $data['token']);
    variable_set('expires_in', $data['expires_in']);

    return $data['token'];

  } else {

    drupal_set_message("No pudimos procesar tu consulta. Por favor intentalo nuevamente", 'error', $repeat = FALSE);
    $form_state['rebuild'] = TRUE;

    return $form;
  }
}
