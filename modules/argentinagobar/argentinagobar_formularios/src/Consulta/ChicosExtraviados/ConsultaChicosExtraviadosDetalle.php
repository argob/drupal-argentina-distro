<?php

  class ConsultaChicosExtraviadosDetalle extends Consulta
  {
    function get_params()
    {
      $params = array();
      $params['filtro'] = explode('--', $this->values['filter'])[0];

      return $params;
    }

    function get_endpoint()
    {
      return variable_get('consulta_chicos_extraviados_endpoint');
    }

    function get_request_id($id){
      return drupal_http_request($this->get_endpoint().$id, $this->get_request_headers());
    }

    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      if(is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }
      $params = $this->get_params();

      return $endpoint . '?' . http_build_query($params);
    }
    function get_response($request)
    {

      $items = array();

      switch ($request->code) {
        case 401:
          $this->api_gateway_auth->refresh_token();
          $this->consultar();
          break;
        case 500:
          throw new ConsultaSinServicioException('El servicio de RLM No esta respondiendo', 4);
          break;
        case 503:
          throw new ConsultaSinServicioException('El servicio de RLM No esta respondiendo', 4);
          break;
        case 404:
          // nada
          break;
        case 200:
          $items = drupal_json_decode($request->data);
          break;

        default:
          break;
      }

      return $items;
    }

  }
