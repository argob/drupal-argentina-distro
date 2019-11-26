<?php
class ConsultaRadicacionPorDomicilioDepartamentos extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_departamentos_endpoint;
  public $departamentos = array();
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_departamentos_endpoint =  variable_get('consulta_radicacion_departamentos_client_endpoint', NULL);
  }

  function consultar() {

    $params = array(
      'tipoVehiculo' => $this->values['tipoVehiculo'],
      'idProvincia' => $this->values['idProvincia'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consultar_radicacion_por_departamentos_endpoint . '?' . $data;

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
        if ($this->isCapitalFederal($this->results)) {
          $this->departamentos[$this->results['idDepartamento']] = $this->results['denominacion'];
        } else {
          foreach ($data as $departamento) {
            $this->departamentos[$departamento['idDepartamento']] = $departamento['denominacion'];
          }
        }
      }
    }

    return $this->results;
  }

  function isCapitalFederal($results) {
    return $this->results['denominacion'] == "CAPITAL FEDERAL";
  }

  function definirSiguienteAccion($values){
    if ($this->isCapitalFederal($this->results)) {
      $siguienteAccion = "consultarLocalidades";
    }
    else{
      foreach ($this->results as $key => $result) {
        if($result['idDepartamento'] == $values['idDepartamento']) {
          $siguienteAccion = $result['metodoSiguiente'];
          if($siguienteAccion == 'consultarRegistroSeccional'){
            $this->setCodigoRegistroSeccional($result['codigoRegistroSeccional']);
          }
        }
      }
    }
    return $siguienteAccion;
  }

  function getDepartamentos(){
    return $this->departamentos;
  }

  function traducirValue($value){
    if ($this->isCapitalFederal($this->results)){
      $opcionBuscada['denominacion'] = $this->results['denominacion'];
    }
    else{
      foreach ($this->results as $key => $result) {
        if($result['idDepartamento'] == $value) {
          $opcionBuscada = $result;
        }
      }

    }
    return $opcionBuscada['denominacion'];
  }

}
