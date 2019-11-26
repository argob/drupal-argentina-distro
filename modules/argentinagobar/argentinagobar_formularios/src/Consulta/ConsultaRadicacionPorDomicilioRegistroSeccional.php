<?php
class ConsultaRadicacionPorDomicilioRegistroSeccional extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_registro_seccional_endpoint;
  public $dataRegistroSeccional;
  public $results;

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_registro_seccional_endpoint = variable_get('consulta_radicacion_registro_seccional_client_endpoint', NULL);
  }


  function consultar() {

    $params = array(
      'codigoRegistroSeccional' => $this->values['codigoRegistroSeccional'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consultar_radicacion_por_registro_seccional_endpoint . '?' . $data;
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
        $this->dataRegistroSeccional = $data;
      }
    }

    return $this->results;
  }

  function definirSiguienteAccion($values){
    return 'consultarRegistroSeccional';
  }

  function traducirValue($value){
    return $value;
  }
}
