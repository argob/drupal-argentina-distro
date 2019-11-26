<?php

class ConsultaVUFDCStatus extends Consulta
{

  function get_params()
  {
    return http_build_query(['issues' => 'comprueboServicio'.rand(10,999)]);
  }

  function get_endpoint(){
    $opciones = variable_get('DC_opciones');
    return $opciones['destination'] . '/api/v1.0/defensa-consumidor/search';
  }

  function get_response($request)
  {

    $response = NULL;

    if($request->code == 401){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200)
    {
      $response = 'verdadero';
    }
    else
    {
      $response = 'false';
      drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
      watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);

    }

    return $response;
  }

  function get_request_headers()
  {
    return array(
      'headers' => $this->get_headers(),
      'method' => $this->get_request_method(),
      'timeout' => 1,
    );
  }

  function get_request()
  {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

    if(isset($request->error))
    {
      throw new ConsultaErrorException($request->error);
    }

    return $request;
  }

}
