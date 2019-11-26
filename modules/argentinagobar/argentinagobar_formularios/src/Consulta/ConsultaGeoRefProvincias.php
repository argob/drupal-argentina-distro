<?php

class ConsultaGeoRefProvincias extends Consulta{

  function get_form($form, &$form_state, $consulta)
  {
    $form = array();

    return $form;
  }

  // function get_params()
  // {
  //   return http_build_query(
  //     array(
  //       'orden' => 'nombre',
  //     )
  //   );
  // }

  // function get_endpoint()
  // {
  //
  //   // $endpoint = variable_get('consulta_georef_provincias_endpoint', NULL);
  //   //
  //   // if(is_null($endpoint) || $enpoint = ''){
  //   //   throw new EndpointNuloException("Falta endpoint para Consulta GeoRef", 1);
  //   // }
  //   //
  //   // return $endpoint;
  //   return file_get_contents(dirname(__FILE__, 3).'/json/georef_provincias.json');
  // }


  // function get_request()
  // {
  //   $request = file_get_contents(dirname(__FILE__, 3).'/json/georef_provincias.json');
  //   return $request;
  // }

  function get_select_options()
  {

    $cache = '';

    if (empty($cache)) {

      try
      {

        $request = file_get_contents(dirname(dirname(dirname(__FILE__))).'/json/georef_provincias.json');
        $options = array();
        $results = drupal_json_decode($request);

      if(!empty($results)){
        foreach($results as $value){

          for ($i=0; $i<count($value); $i++){
            $options[$value[$i]['id']] = mb_strtoupper($value[$i]['nombre']);
          }

        }
      }
        return $options;

      }

      catch (ConsultaException $e)
      {
        // Muestra mensaje genérico al usuario
        drupal_set_message('Servicio momentáneamente no disponible', 'error', FALSE);

        // Loguea el mensaje de la excepción en los registros
        watchdog('AR Formularios', $e->getMessage(), $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);

      }

    }

    return '';

  }

  // function get_response($request)
  // {
  //
  //   $response = NULL;
  //
  //   if($request->code == 401)
  //   {
  //     $this->api_gateway_auth->refresh_token();
  //     $this->consultar();
  //   }
  //
  //   if($request->code == 200)
  //   {
  //
  //     $data = drupal_json_decode($request->data);
  //
  //     $response = $data['results'];
  //
  //   }
  //
  //   else
  //   {
  //     drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
  //     watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
  //   }
  //
  //   return $response;
  // }
}
