<?php
class ConsultaRadicacionPorDomicilioCallesBarrios extends Consulta {
  private $consulta_radicacion_calles_barrios_client_endpoint;
  public $calles_barrios = array();
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consulta_radicacion_calles_barrios_client_endpoint =  variable_get('consulta_radicacion_calles_barrios_client_endpoint', NULL);

  }

  function consultar() {
    $params = array(
      'tipoVehiculo' => $this->values['tipoVehiculo'],
      'idProvincia' => $this->values['idProvincia'],
      'idDepartamento' => $this->values['idDepartamento'],
      'idLocalidad' => $this->values['idLocalidad'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consulta_radicacion_calles_barrios_client_endpoint . '?' . $data ;
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

        foreach ($data as $calle_barrio) {
          $this->calles_barrios[$calle_barrio['idCalle']] = $calle_barrio['denominacion'];
        }
      }
    }

    return $this->results;
  }

  function definirSiguienteAccion($values){
    foreach ($this->results as $key => $result) {
      if($result['idCalle'] == $values['idCalle']) {
        $siguienteAccion = $result['metodoSiguiente'];
      }
    }

    return $siguienteAccion;
  }

  function traducirValue($value) {
      foreach ($this->results as $key => $result) {
        if($result['idCalle'] == $value) {
          $opcionBuscada = $result;
          }
        }

      return $opcionBuscada['denominacion'];
    }


  function getCallesBarrios(){
    return $this->calles_barrios;
  }
}
