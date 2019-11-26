<?php

class ConsultaInfolegNorma extends ConsultaInfoleg
{

  function __construct($api_gateway_auth, $values = array())
  {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
  }

  function get_endpoint()
  {
    return variable_get('consulta_infoleg_endpoint', NULL);
  }

  function get_params()
  {
    return http_build_query(
      array(
        'id' => $this->values['id']
      )
    );
  }

  function get_request_url()
  {

    $endpoint = $this->get_endpoint();

    if (is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    return $endpoint . '?' . $this->get_params();
  }

  function get_request_id($id, $tipoNorma){
    return drupal_http_request($this->get_endpoint().'/'.$tipoNorma.'?numero='.$id, $this->get_request_headers());
  }

  function validParams()
  {
    return array('id');
  }

  function handleError($request)
  {

    if ($request->code = 404) {
    }
    elseif ($request->code = 500) {
      throw new ConsultaSinDatosException($request->error, $request->userMessage);
    } else {
      parent::handleError($request);
    }

  }

  function get_response($request)
  {
    $norma = null;

    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 200) {
      $norma = drupal_json_decode($request->data);
      $this->setNormaURL($norma);
      $this->setNormaTitulo($norma);
    }

    return $norma;
  }
}
