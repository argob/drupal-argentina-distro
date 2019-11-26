<?php

  class ConsultaRLMDetalle extends Consulta
  {
    function get_params()
    {
      $params = array();
      $params['filtro'] = explode('--', $this->values['filter'])[0];

      return $params;
    }

    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

      return $request;
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
      global $base_url;
      $response = array();
      $bases = array();
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
          $data = drupal_json_decode($request->data);

          $id = drupal_get_path_alias();
          $id = explode('--', $id);
          $id = $id[0];
          $id = explode('/', $id);

          foreach ($data['results'] as $result){

            $domicilio = $result['valoresFC']['txt_calle'];
            $domicilio .= ' - ' . $result['valoresFC']['lng_altura'];
            $domicilio .= ' - ' . $result['valoresFC']['txt_piso'];
            $domicilio .= ' - ' . $result['valoresFC']['txt_oficina'];
            $domicilio .= ' - ' . $result['valoresFC']['bahra_ubicacion'];
            $domicilio .= '  ' . $result['valoresFC']['bahra_ubicacion_dpto'];
            $domicilio .= ' - ' . $result['valoresFC']['bahra_ubicacion_localidad'];

            $result['valoresFC']['finalidades'] = $this->formatFinalidad($result['valoresFC']);
            $requisitos =  $result['valoresFC']['txt_requisitos'] . ' </br>' . $result['valoresFC']['txt_procedimientos'];

            $result['valoresFC']['requisitos'] = $requisitos;
            $result['valoresFC']['nombre_base_datos'] = $result['valoresFC']['txt_nombre_base_datos'];
            $result['valoresFC']['domicilio'] = $domicilio;
            $result['valoresFC']['id'] = $result['id'];

            $bases[] = $result;
          }

          $response['bases'] = $bases;



          $rlmListado = new ConsultaRLMListado(ApiGatewayAuth::getInstance());
          $requestListado = $rlmListado->get_request_id($id[3]);
          $rlmListadoData = $rlmListado->get_response($requestListado, true);

          if($rlmListadoData != array()){

            $itemm = $rlmListadoData['results'][0];
            $alias = variable_get('rlm_alias');

            $items['cuit'] = $itemm['cuit'];
            $items['name'] = isset($itemm['razonsocial']) ? $itemm['razonsocial'] : $itemm['nombre'] .' '. $itemm['apellido'];
            $items['ref_number'] =  $itemm['letra'];;
            $items['ref_number'] .= '-' . $itemm['anio'];
            $items['ref_number'] .= '-' . $itemm['numero'];
            $items['ref_number'] .= '-' . $itemm['reparticionActuacion'];
            $items['ref_number'] .= '-' . $itemm['reparticionUsuario'];
            $items['link'] = $base_url . '/' . $alias . '/'  . $itemm['cuit'] . '--' . $items['ref_number']  ;
            $items['tipoPersona'] = isset($itemm['razonsocial']) ? 'Juridica' : 'Fisica';
          }

          break;

        default:
          break;
      }

      return theme('detalle_rlm',array(
         'bases'=> $bases,
         'items'=> $items,
         'base_url' => $base_url,
         'breadcrumb' => getBreadcrumbRLM(),
       )
      );
    }

    function formatFinalidad($results)
    {
      $finalidades =  array();
      foreach ($results as $result => $value) {
       if (strstr($result, 'cmb_finalidad_base_datos')) {
        $finalidades[$result] = $value;
        }
      }
      return $finalidades;
    }
  }
