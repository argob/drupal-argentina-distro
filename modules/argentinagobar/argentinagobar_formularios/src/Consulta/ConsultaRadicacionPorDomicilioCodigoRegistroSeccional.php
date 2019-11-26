<?php
class ConsultaRadicacionPorDomicilioCodigoRegistroSeccional extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_altura_exacta_endpoint;
  public $codigoRegistroSeccional;
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_altura_exacta_endpoint = variable_get('consulta_radicacion_altura_exacta_client_endpoint', NULL);
    $this->observers = array();

  }

  function consultar() {

    $params = array(
      'tipoVehiculo' => $this->values['tipoVehiculo'],
      'idProvincia' => $this->values['idProvincia'],
      'idDepartamento' => $this->values['idDepartamento'],
      'idLocalidad' => $this->values['idLocalidad'],
      'idCalle' => $this->values['idCalle'],
      'alturaExacta' => $this->values['alturaExacta'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consultar_radicacion_por_altura_exacta_endpoint . '?' . $data;

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
      $this->notificar();
      drupal_set_message('Ha ocurrido un error, intenta de nuevo con otra altura', $type = 'error', $repeat = FALSE);
      watchdog('Formularios: Consulta Radicación por Domicilio', 'Request code 500 en: ' . $url, $variables = array(), WATCHDOG_ERROR, $link = NULL);
    }

    if($request->code == 200){

      $this->results = $data;
      if(empty($this->results)){
        $this->notificar();

        drupal_set_message('Ha ocurrido un error, intenta de nuevo con otra altura', $type = 'error', $repeat = FALSE);

        watchdog('Formularios: Consulta Radicación por Domicilio', 'No devolvió resultados en ' . $url, $variables = array(), WATCHDOG_ERROR, $link = NULL);

      } else {
        $this->codigoRegistroSeccional = $this->results['codigoRegistroSeccional'];
      }
    }

    return $this->results;
  }

  function traducirValue($value){
    return $value;
  }

  function add_observer($consulta){
    array_push($this->observers, $consulta);
  }

  function notificar(){
    foreach ($this->observers as $observer) {
      $observer->setError();
    }
  }

  function definirSiguienteAccion($values){
    return 'consultarRegistroSeccional';
  }
}
