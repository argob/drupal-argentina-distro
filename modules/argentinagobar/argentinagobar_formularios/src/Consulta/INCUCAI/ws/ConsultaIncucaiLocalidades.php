<?php

class ConsultaIncucaiLocalidades extends Consulta
{

    const ENDPOINT = 'incucai_localidades';


    static function static_get_endpoint()
    {
        $endpoint = variable_get(static::ENDPOINT, null);

        return $endpoint . '/0';
    }

    function get_endpoint()
    {
      return variable_get('incucai_localidades', NULL);
    }

    function get_params(){
        return $this->values['partido'];
    }

    function get_response($request)
    {
      $data = null;
      if ($request->code == 401) {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if ($request->code == 200) {
        $data = drupal_json_decode($request->data);
      }

      return $data;
    }

    function get_request_url()
    {
      $endpoint = $this->get_endpoint();


      if(is_null($endpoint) || $enpoint = '')
      {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }

      return $endpoint . '/' . $this->get_params();
    }

}
