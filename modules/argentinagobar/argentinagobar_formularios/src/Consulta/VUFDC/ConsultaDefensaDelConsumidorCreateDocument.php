<?php

class ConsultaDefensaDelConsumidorCreateDocument extends ConsultaPOST{
  
  function get_request_method()
  {
  	return 'POST';
  }

  function set_name($name){
    $this->name = $name;
  }

  function get_endpoint(){
    $opciones = variable_get('DC_opciones');
    return $opciones['destination'] . '/api/v1.0/defensa-consumidor/create-document/' . $this->name;
  }
  
  function get_request_url()
  {
    
    $endpoint = $this->get_endpoint();
    
    if(is_null($endpoint) || $enpoint = '')
    {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }
    
    return $endpoint;
  }
  
  function get_request_headers()
  {
    return array(
      'headers' => array(
        'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
        'Content-Type' => 'application/json',
        'Accept' => 'application/json'
      ),
      'method' => $this->get_request_method(),
      'data' => $this->get_params(),
    );
  }

  function get_response($request)
  {
    
    $response = array();

    if($request->code == 401){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200)
    {
      
      $response = $request->data;
      
    }
    else
    {
      throw new ConsultaExceptionDC('Code different than 200', 1);
    }

    return $response;
  }
  
}