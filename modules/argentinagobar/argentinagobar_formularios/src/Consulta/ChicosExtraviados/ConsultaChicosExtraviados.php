<?php

class ConsultaChicosExtraviados extends Consulta {

      #Funcion que construye la URL de consulta a la API
      function get_request_url() {
        $endpoint = $this->get_endpoint();
          if (is_null($endpoint) || empty($endpoint)) {
            throw new EndpointNuloException("Falta endpoint para Consulta", 1);
          }
        $urlconsulta = $endpoint;

        return $urlconsulta;
      }


      #Funcion que trae el endpoint de conexion a la API
      function get_endpoint() {
        return variable_get('consulta_chicos_extraviados_endpoint');
      }

      #Funcion que hace el request a la api
      function get_request() {
        $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
        return $request;
      }

      #Funcion que formatea la respuesta de acuerdo al codigo del request
      function get_response($request){
        $items = array();
        $response = NULL;
        $data = NULL;

        if($request->code == 401) {
          $this->api_gateway_auth->refresh_token();
          $this->consultar();
        }

        if ($request->code == 500 || $request->code == 503) {
          throw new ConsultaException('Convocatorias Chicos Extraviados no esta funcionando', 1);
        }

        if ($request->code == 400 || $request->code == 404) {
          $theme = 'chicos_extraviados_error';
        }

        if ($request->code == 200) {
          $data = drupal_json_decode($request->data);
          $items = $this->formatItems($data['results']);

        $response = $items;
        return $this->renderResponseSinForm($response);
        }
      }

      function formatItems($data)
      {
        $alias = variable_get('chicos_extraviados_alias');
        global $base_url;
        $items = array();
        foreach ($data as $data2) {
          $item = array();
          $item['ImagenNormal'] = $data2['ImagenNormal'];
          $item['ProvinciaHecho'] = $data2['ProvinciaHecho'];
          $item['nombreCompleto'] = $data2['Nombre'] .' '. $data2['Apellido'];
          $item['link'] = $base_url . '/' . $alias . '/' . $data2['ExpedienteId'];
          // $item['ExpedienteId'] = $data2['ExpedienteId'];
          // $item['nombreCompleto'] = $data2['Nombre'] .' '. $data2['Apellido'];
          // $item['Sexo'] = $data2['Sexo'];
          // $item['Contextura'] = $data2['Contextura'];
          // $item['ColorPiel'] = $data2['ColorPiel'];
          // $item['ColorOjos'] = $data2['ColorOjos'];
          // $item['Altura'] = $data2['Altura'];
          // $item['Peso'] = $data2['Peso'];
          // $item['ColorCabello'] = $data2['ColorCabello'];
          // $item['TipoCabello'] = $data2['TipoCabello'];
          // $item['Indumentaria'] = $data2['Indumentaria'];
          // $item['Sobrenombre'] = $data2['Sobrenombre'];
          // $item['SeniaParticular'] = $data2['SeniaParticular'];
          // $item['TipoCasoId'] = $data2['TipoCasoId'];
          // $item['TipoCaso'] = $data2['TipoCaso'];
          // $item['CasoId'] = $data2['CasoId'];
          // $item['DocumentoId'] = $data2['DocumentoId'];
          // $item['PersonaId'] = $data2['PersonaId'];
          // $item['AutoridadInterviniente'] = $data2['AutoridadInterviniente'];
          // $item['AutoridadTelefono'] = $data2['AutoridadTelefono'];
          // $item['AutoridadFax'] = $data2['AutoridadFax'];
          // $item['AutoridadCodigoPostal'] = $data2['AutoridadCodigoPostal'];
          // $item['AutoridadNumeroTribunal'] = $data2['AutoridadNumeroTribunal'];
          // $item['AutoridadEmail'] = $data2['AutoridadEmail'];
          // $item['AutoridadResponsable'] = $data2['AutoridadResponsable'];
          // $item['AutoridadPais'] = $data2['AutoridadPais'];
          // $item['AutoridadProvincia'] = $data2['AutoridadProvincia'];
          // $item['AutoridadDomicilio'] = $data2['AutoridadDomicilio'];
          // $item['CircunstanciaHecho'] = $data2['CircunstanciaHecho'];
          // $item['FechaHecho'] = $data2['FechaHecho'];
          // $item['PresicionFechaHecho'] = $data2['PresicionFechaHecho'];
          // $item['DomicilioHecho'] = $data2['DomicilioHecho'];
          // $item['ProvinciaHecho'] = $data2['ProvinciaHecho'];
          // $item['PaisHecho'] = $data2['PaisHecho'];
          // $item['LocalidadHecho'] = $data2['LocalidadHecho'];
          // $item['PaisNacimiento'] = $data2['PaisNacimiento'];
          // $item['FechaNacimiento'] = $data2['FechaNacimiento'];
          // $item['ProvinciaNacimiento'] = $data2['ProvinciaNacimiento'];
          // $item['LocalidadNacimiento'] = $data2['LocalidadNacimiento'];
          // $item['EstiloCabello'] = $data2['EstiloCabello'];
          // $item['Edad'] = $data2['Edad'];
          // $item['ImagenMiniatura'] = $data2['ImagenMiniatura'];
          // $item['ImagenNormal'] = $data2['ImagenNormal'];
          // $item['ProvinciaHecho'] = $data2['ProvinciaHecho'];
          // $item['link'] = $base_url . '/' . $alias . '/' . $item['ExpedienteId']  ;
          $items[] = $item;
        }
        return $items;
      }


      function renderResponseSinForm($response)
      {
        $theme = count($response) >= 1  ? 'chicos_extraviados_ok' : 'chicos_extraviados_error' ;
        return theme($theme, array(
            'items' => $response,
          )
        );
      }

}
