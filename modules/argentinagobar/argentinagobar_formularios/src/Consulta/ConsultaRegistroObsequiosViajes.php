<?php

class ConsultaRegistroObsequiosViajes extends Consulta{

  private $consulta_registro_viajes;
  private $consulta_registro_obsequios;
  public $items;

  function __construct($api_gateway_auth, $values = array()){
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consulta_registro_viajes = new ConsultaRegistroViajes();
    $this->consulta_registro_obsequios = new ConsultaRegistroObsequios();
  }

  function consultar(){

    $params = array(
      'value' => '""',
    );

    $params = http_build_query($params);

    $access_token = $this->api_gateway_auth->getAccessToken();

    $options = array(
      'headers' => array('Authorization' => 'Bearer ' . $access_token),
    );

    try {

      $this->consulta_registro_obsequios->consultarRegistro($params, $options);
      $this->consulta_registro_viajes->consultarRegistro($params, $options);

      cache_set('obsequios', $this->consulta_registro_obsequios->obtenerItems());

      cache_set('viajes', $this->consulta_registro_viajes->obtenerItems());

    } catch (ConsultaException $e) {
      watchdog('Registro de Obsequios y Viajes', $e->getMessage(), $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);
    }
  }

  function obtenerItems(){
    return $this->items;
  }

  function consultarRegistro($params, $options){

    $itemsFormateados = [];

    $url = $this->client_endpoint . '?' . $params;
    $request = drupal_http_request($url, $options);

    if(isset($request->error)){
      watchdog('Registro de Obsequios y Viajes', 'Request Error: ' . $request->code, $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);
      throw new ConsultaSinServicioException("Sin servicio", 1);

    }

    if($request->code == "200"){

      $data = drupal_json_decode($request->data);

      if(isset($data['results']) && !empty($data['results'])){

        $this->items = $data['results'];

        foreach ($this->items as $key => $item) {
          if($this->esEstructuraDatosValida($item)){

            $numero = $item['numero'];

            $itemFormateado = $this->formatear($item);

            cache_set('obsequio_' . $numero, $itemFormateado);

            $itemsFormateados[$numero] = $itemFormateado;
          } else {
            throw new EstructuraDeDatosNoValidaException("Estructura de datos no válida", 1);
          }
        }

        $this->setItems($itemsFormateados);

      } else {
        throw new ConsultaSinDatosException("Consulta sin resultados", 1);
      }
    }
  }
}
