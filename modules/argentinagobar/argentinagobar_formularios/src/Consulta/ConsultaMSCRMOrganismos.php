<?php

class ConsultaMSCRMOrganismos extends Consulta
{
    
  function get_endpoint()
  {
    return variable_get('consulta_mscrm_tramites_organismos_endpoint', NULL);
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
      
      $data = drupal_json_decode($request->data);
      $response = $data['results'];
      
    }
    else
    {
      
      drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
      watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
      
    }

    return $response;
  }
  
}