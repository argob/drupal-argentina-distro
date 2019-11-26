<?php
class ConsultaRadicacionPorDomicilioTipoVehiculo extends ConsultaRadicacionPorDomicilio {
  private $consultar_radicacion_por_provincia_endpoint;
  public $tipos = array();
  public $results = array();

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consultar_radicacion_por_provincia_endpoint = variable_get('consulta_radicacion_provincias_client_endpoint', NULL);
    $this->results = array(
      'A' => t('Automotor'),
      'M' => t('Motovehículo'),
    );
  }

  function consultar() {}

  function definirSiguienteAccion($values){
    return 'consultarProvincias';
  }

  function traducirValue($value){
    return $this->results[$value];
  }

}
