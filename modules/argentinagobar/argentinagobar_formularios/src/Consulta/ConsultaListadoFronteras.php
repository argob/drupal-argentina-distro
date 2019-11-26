<?php
  class ConsultaListadoFronteras extends Consulta {
    public $items;
    function get_form($form, &$form_state, $consulta)
    {
      $form = array();

      return $form;
    }

    function get_params()
    {
      return http_build_query(
        array(
          // 'orden' => 'nombre',
        )
      );
    }

    function get_endpoint()
    {

      $endpoint = variable_get('consulta_listado_fronteras_endpoint', NULL);

      if(is_null($endpoint) || $enpoint = ''){
        throw new EndpointNuloException("Falta endpoint para Consulta GeoRef", 1);
      }

      return $endpoint;
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

        // $data = drupal_json_decode($request->data);
        //
        // $response = $data['results'];
        $itemsFormateados = array();
        //     if($request->code == "200"){
              $data = drupal_json_decode($request->data);
              if(isset($data['results']) && !empty($data['results'])){
                $this->items = $data['results'];


                variable_set('pasos_fronterizos',$this->items );
              }


      }

      else
      {
        drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
        watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
      }

      return $response;
    }


    //     $itemsFormateados = array();
    //     if($request->code == "200"){
    //       $data = drupal_json_decode($request->data);
    //       if(isset($data['results']) && !empty($data['results'])){
    //         $this->items = $data['results'];
    //         foreach ($this->items as $key => $item) {
    //             $itemsFormateados[$item['id']] = $this->formatear($item);
    //         }
    //
    //         $this->items = $itemsFormateados;
    //         variable_set('pasos_fronterizos',$itemsFormateados );
    //       }
    //   }
    // }

    function formatear($item) {
      return array(
        'class' => array('clickable-item'),
        'elemento' => $item,
        'onclick' => 'window.location="/pasos-fronterizos/' . $item['id'] . '"',
        'data' => array(
          array('data' => $item['estado']['estado'], 'class' => array('estado label label-success')),
          array('data' => $item['nombre'], 'class' => array('nombre')),
          array('data' => $item['pais']['nombre'], 'class' => array('pais_limitrofe')),
          array('data' => $item['provincia']['nombre'], 'class' => array('provincia')),
          array('data' => 'Rio', 'class' => array('tipo')),
        ),
      );
    }
}
