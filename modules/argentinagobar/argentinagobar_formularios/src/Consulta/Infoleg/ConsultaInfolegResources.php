<?php

class ConsultaInfolegResources extends Consulta
{
  function get_endpoint()
  {
    return variable_get('consulta_infoleg_recursos_endpoint', NULL);
  }

  function get_params()
  {
    return $this->values['id'] . '/' . $this->values['filename'] . '.' . $this->values['extension'];
  }

  function get_request_url()
  {

    $endpoint = $this->get_endpoint();

    if(is_null($endpoint) || $enpoint = '') {
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
      $html = drupal_json_decode($request->data);

      if ($html['content-type'] == 'text/html') {
        $data = $html['data'];
      }else {
        $data = 'data:' . $request->headers['content-type'] . ';base64,' . base64_encode($request->data);
      }
    }
    return $data;
  }
}
