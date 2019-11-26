<?php
class ConsultaRadicacionPorDomicilioLocalidades extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_localidades_endpoint;
  public $localidades = array();
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_localidades_endpoint = variable_get('consulta_radicacion_localidades_client_endpoint', NULL);

  }

  function consultar() {
    $params = array(
      'tipoVehiculo' => $this->values['tipoVehiculo'],
      'idProvincia' => $this->values['idProvincia'],
      'idDepartamento' => $this->values['idDepartamento'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consultar_radicacion_por_localidades_endpoint . '?' . $data;

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

      } elseif (is_array($this->results[0])) {
        foreach ($this->results as $localidad) {
          $this->localidades[$localidad['idLocalidad']] = $localidad['denominacion'];
        }
      } else {

        $this->localidades[$this->results['idLocalidad']] = $this->results['denominacion'];
      }
    }

    return $this->results;
  }

  function definirSiguienteAccion($values){
    if(!is_array($this->results[0])){
      $siguienteAccion = 'consultarCallesBarrios';
    }
    else {
      foreach ($this->results as $key => $result) {
        if($result['idLocalidad'] == $values['idLocalidad']) {
          $siguienteAccion = $result['metodoSiguiente'];
          if($siguienteAccion == 'consultarRegistroSeccional'){
            $this->setCodigoRegistroSeccional($result['codigoRegistroSeccional']);
          }
        }
      }
    }
    return $siguienteAccion;
  }

  function getLocalidades(){
    return $this->localidades;
  }

  function traducirValue($value){
    if (!is_array($this->results[0])){
      $opcionBuscada['denominacion'] = $this->results['denominacion'];
    }
    else{

    foreach ($this->results as $key => $result) {
      if($result['idLocalidad'] == $value) {
        $opcionBuscada = $result;
      }
    }
  }

    return $opcionBuscada['denominacion'];
  }
}
