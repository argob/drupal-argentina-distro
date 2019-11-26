<?php

abstract class ConsultaPOST extends Consulta{
  
  function get_request_method()
  {
  	return 'POST';
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
  
  function get_headers()
  {
    return array(
      'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
      'Content-Type' => 'application/json',
      'Accept' => 'application/json',
    );
  }
  
  function get_request_headers()
  {
    return array(
      'data' => $this->get_params(),
      'method' => $this->get_request_method(),
      'headers' => $this->get_headers(),
    );
  }
  
}
