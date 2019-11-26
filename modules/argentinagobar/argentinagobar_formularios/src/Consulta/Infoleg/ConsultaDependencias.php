<?php

class ConsultaDependencias extends Consulta
  {

  function get_form($form, &$form_state, $consulta) {

    $form = array();

    return $form;
  }

  function get_endpoint() {
    $endpoint = variable_get('consulta_infoleg_dependencias_endpoint', NULL);

    if(is_null($endpoint) || $enpoint = ''){
      throw new EndpointNuloException("Falta endpoint para Consulta Infoleg", 1);
    }
    return $endpoint;
  }

  function get_response($request) {
    $response = NULL;

    if($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200) {
      $response = drupal_json_decode($request->data);

      return $response;
    }
  }
}
