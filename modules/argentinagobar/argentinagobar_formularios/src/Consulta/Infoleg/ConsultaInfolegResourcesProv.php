<?php

class ConsultaInfolegResourcesProv extends Consulta
{
  function get_endpoint()
  {
    return variable_get('consulta_infoleg_recursos_provinciales_endpoint', NULL);
  }

  function get_params()
  {
    return str_replace(' ', '%20', $this->values);
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();

    if(is_null($endpoint)) {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    return $endpoint . '/' . $this->get_params();
  }

  function get_response($request)
  {
    $data = null;

    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 200) {

      $data = $request->headers['content-type'];
      $contentHTM = $request->data;

      if ($data == 'application/json; charset=utf-8') {
        $data = $contentHTM;
      }else {
        $data = 'data:' . $request->headers['content-type'] . ';base64,' . base64_encode($request->data);
      }
    }
    
    return $data;

  }

}
