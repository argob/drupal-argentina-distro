<?php

class ConsultaInfolegProvincias extends Consulta
{

  function get_endpoint()
  {
    return variable_get('consulta_infoleg_provincias_endpoint', NULL);
  }

  function get_response($request)
  {
    $response = NULL;

    if($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200) {
      $response = drupal_json_decode($request->data);
    }

    return $response;
  }

}