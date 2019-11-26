<?php
class ConsultaRadicacionPorDomicilioAlturaExacta extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_altura_exacta_endpoint;
  public $codigoRegistroSeccional;
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_altura_exacta_endpoint = variable_get('consulta_radicacion_altura_exacta_client_endpoint', NULL);
  }

  function consultar() {}

  function traducirValue($value){
    return $value;
  }

  function definirSiguienteAccion($values){
    return 'consultarCodigoRegistroSeccional';
  }
}
