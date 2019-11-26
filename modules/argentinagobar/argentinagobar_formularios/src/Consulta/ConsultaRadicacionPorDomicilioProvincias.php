<?php
class ConsultaRadicacionPorDomicilioProvincias extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_provincia_endpoint;
  public $provincias = array();
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_provincia_endpoint = variable_get('consulta_radicacion_provincias_client_endpoint', NULL);
  }


  function consultar() {
    $params = array(
      'tipoVehiculo' => $this->values['tipoVehiculo'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consultar_radicacion_por_provincia_endpoint . '?' . $data;

    $options = array(
      'headers' => array('Authorization' => 'Bearer ' . $access_token),
    );

    $request = drupal_http_request($url, $options);
    $data = drupal_json_decode($request->data);

    if($request->code == 401){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 500){
      drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
      watchdog('Formularios: Consulta Radicación por Domicilio', 'Request code 500 en: ' . $url, $variables = array(), WATCHDOG_ERROR, $link = NULL);
    }

    if($request->code == 200){
      $this->results = $data;
      if(empty($this->results)){

        drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);

        watchdog('Formularios: Consulta Radicación por Domicilio', 'No devolvió resultados en ' . $url, $variables = array(), WATCHDOG_ERROR, $link = NULL);

      } else {
        foreach ($this->results as $provincia) {
          $this->provincias[$provincia['idProvincia']] = $provincia['denominacion'];
        }
      }
    }

    return $this->results;
  }

  function definirSiguienteAccion($values){
    foreach ($this->results as $key => $result) {
      if($result['idProvincia'] == $values['idProvincia']) {
        $siguienteAccion = $result['metodoSiguiente'];
      }
    }
    return $siguienteAccion;
  }

  function getProvincias(){
    return $this->provincias;
  }

  function traducirValue($value){
    foreach ($this->results as $key => $result) {
      if($result['idProvincia'] == $value) {
        $opcionBuscada = $result;
      }
    }
    return $opcionBuscada['denominacion'];
  }

}
