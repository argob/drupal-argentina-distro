<?php
  class ConsultaListadoFronteras extends Consulta {

      private $consultar_listado_fronteras_endpoint;
      public $pasos;
      function __construct($api_gateway_auth, $values) {
        $this->api_gateway_auth = $api_gateway_auth;
        $this->consulta_listado_fronteras_endpoint = variable_get('consulta_listado_fronteras_endpoint', NULL);
        $this->pasos = $this->consultar();
      }

      function consultar(){
        $access_token = $this->api_gateway_auth->getAccessToken();
        $options = array(
          'headers' => array('Authorization' => 'Bearer ' . $access_token),
        );

        $url = $this->consulta_listado_fronteras_endpoint;
        $request = drupal_http_request($url, $options);
        dsm($this->pasos);
        if($request->code == 404 || $request->code == 500){
          watchdog('Consulta Listado Pasos Fronterisos', 'Request Error: ' . $request->code, $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);
        }

        $itemsFormateados = array();
        if($request->code == "200"){
          $data = drupal_json_decode($request->data);
          if(isset($data['results']) && !empty($data['results'])){
            $this->items = $data['results'];
            foreach ($this->items as $key => $item) {
                $itemsFormateados[$item['id']] = $this->formatear($item);
            }

            $this->items = $itemsFormateados;
            variable_set('pasos_fronterizos',$itemsFormateados );
          }
      }
    }

    function formatear($item) {
      return array(
        'class' => array('clickable-item'),
        'elemento' => $item,
        'onclick' => 'window.location="/pasosinternacionales/' . $item['id'] . '"',
        'data' => array(
          array('data' => $item['estado'], 'class' => array('estado')),
          array('data' => $item['nombre'], 'class' => array('nombre')),
          array('data' => $item['pais_limitrofe'], 'class' => array('pais_limitrofe')),
          array('data' => $item['provincia'], 'class' => array('provincia')),
          array('data' => $item['tipo'], 'class' => array('tipo')),
        ),
      );
    }
}
