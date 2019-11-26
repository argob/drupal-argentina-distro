<?php

  class ConsultaPasosDetalle extends ConsultaListadoFronteras {

    public $items;
    public $response;

    function get_form($form, &$form_state, $consulta){
      $form = array();

      return $form;
    }

    function get_params() {
      return "/" . $this->values['origen'] . "/" . $this->values['id'];
    }

    function get_endpoint()
    {

      $endpoint = variable_get('consulta_listado_fronteras_endpoint', NULL);

      if(is_null($endpoint) || $enpoint = ''){
        throw new EndpointNuloException("Falta endpoint para Consulta GeoRef", 1);
      }

      return $endpoint;
    }

    function get_request_url()
    {

      $endpoint = $this->get_endpoint();

      if(is_null($endpoint) || $enpoint = '')
      {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }

      return $endpoint . $this->get_params();
    }


    function get_response($request)
    {

      $response = NULL;

      if($request->code == 401)
      {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if($request->code == 200)
      {

        $data = drupal_json_decode($request->data);

        $response = $data;

      }

      else
      {
        drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
        watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
      }

      return $response;
    }
}
