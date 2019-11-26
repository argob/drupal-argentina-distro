<?php

class ConsultaInfolegNormaProvincial extends ConsultaInfolegNorma
{

  function __construct($api_gateway_auth, $values = array())
  {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
  }

  function get_endpoint()
  {
    return variable_get('consulta_infoleg_provinciales_endpoint', NULL);
  }

}