<?php

class ConsultaRadicacionPorDomicilio extends Consulta {
  public $storage = array();
  private $consultar_departamentos;
  private $provincias = array();
  private $tipoVehiculos = array();
  private $localidades = array();
  private $calles_barrios = array();
  private $registro_seccional = array();
  public $consultaActual;
  public $codigoRegistroSeccional;

  function __construct($api_gateway_auth, $values) {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $consultaRegistro = new ConsultaRadicacionPorDomicilioCodigoRegistroSeccional($this->api_gateway_auth, $this->values);
    $consultaRegistro->add_observer($this);
    $this->error = FALSE;
    $this->consultas = array(
      1 => new ConsultaRadicacionPorDomicilioTipoVehiculo($this->api_gateway_auth, $this->values),
      2 => new ConsultaRadicacionPorDomicilioProvincias($this->api_gateway_auth, $this->values),
      3 => new ConsultaRadicacionPorDomicilioDepartamentos($this->api_gateway_auth, $this->values),
      4 => new ConsultaRadicacionPorDomicilioLocalidades($this->api_gateway_auth, $this->values),
      5 => new ConsultaRadicacionPorDomicilioCallesBarrios($this->api_gateway_auth, $this->values),
      6 => new ConsultaRadicacionPorDomicilioAlturaExacta($this->api_gateway_auth, $this->values),
      7 => $consultaRegistro,
      8 => new ConsultaRadicacionPorDomicilioRegistroSeccional($this->api_gateway_auth, $this->values),
    );
    $this->consultaActual = $this->getConsulta(1);
    $this->siguienteAccion = $this->consultaActual->definirSiguienteAccion($values);
    $this->tipoVehiculos = array(
      'A' => t('Automotor'),
      'M' => t('Motovehículo'),
    );
    $this->storage = array(
      'step' => '1',
      'step_information' => $this->consulta_radicacion_domicilio_pasos(),

    );
  }

  function cantidadPasos(){
    return count($this->consultas);
  }

  function getStepInformation($step){
    return $this->storage['step_information'][$step]['form'];
  }

  function getStepForm(){
    $step_information = $this->getStepInformation($this->getStep());
    return $this->$step_information();
  }

  function setCodigoRegistroSeccional($codigoRegistroSeccional){
    $this->codigoRegistroSeccional = $codigoRegistroSeccional;
  }

  function getCodigoRegistroSeccional($codigoRegistroSeccional){
    return $this->codigoRegistroSeccional;
  }

  public function getStep(){
    return $this->storage['step'];
  }

  function setStep($step){
    return $this->storage['step'] = $step;
  }

  function setProvincias($provincias){
    $this->provincias = $provincias;
  }

  function getProvincias(){
    return $this->provincias;
  }

  function setTipoVehiculos($tipoVehiculos){
    $this->$tipoVehiculos = $tipoVehiculos;
  }

  function setError(){
    $this->error = TRUE;
  }

  function getError(){
    return $this->error;
  }

  function getTipoVehiculos(){
    return $this->tipoVehiculos;
  }

  function consulta_radicacion_domicilio_pasos() {
    return array(
      1 => array(
        'form' => 'consulta_radicacion_domicilio_tipo_vehiculo',
        'action' => 'consultar_radicacion_domicilio_tipo_vehiculo',
        'storable_values' => array(
          'tipoVehiculo' => t('Tipo de vehículo'),
        ),
      ),
      2 => array(
        'form' => 'consulta_radicacion_domicilio_provincia',
        'action' => 'consultar_radicacion_domicilio_provincia',
        'storable_values' => array(
          'idProvincia' => t('Provincia'),
        ),
      ),
      3 => array(
        'form' => 'consulta_radicacion_domicilio_departamento',
        'action' => 'consultar_radicacion_domicilio_departamento',
        'storable_values' => array(
          'idDepartamento' => t('Departamento'),
        ),
      ),
      4 => array(
        'form' => 'consulta_radicacion_domicilio_localidad',
        'action' => 'consultar_radicacion_domicilio_localidad',
        'storable_values' => array(
          'idLocalidad' => t('Localidad'),
        ),
      ),
      5 => array(
        'form' => 'consulta_radicacion_domicilio_calle',
        'action' => 'consultar_radicacion_domicilio_calle',
        'storable_values' => array(
          'idCalle' => t('Calle'),
        ),
      ),
      6 => array(
        'form' => 'consulta_radicacion_domicilio_altura',
        'action' => 'consultar_radicacion_domicilio_altura',
        'storable_values' => array(
          'alturaExacta' => t('Altura exacta'),
        ),
      ),
      7 => array(
        'form' => 'consultar_radicacion_domicilio_codigo_registro',
        'action' => 'consultar_radicacion_domicilio_codigo_registro',
        'storable_values' => array(),
      ),
      8 => array(
        'form' => 'consultar_radicacion_domicilio_registro',
        'action' => 'consultar_radicacion_domicilio_registro',
        'storable_values' => array(),
      ),
    );
  }

  function consulta_radicacion_domicilio_tipo_vehiculo(){

    $form['tipoVehiculo'] = array(
      '#type' => 'radios',
      '#title' => t('Tipo de vehículo'),
      '#theme' => array('form_element_radios_inline'),
      '#options' => $this->getTipoVehiculos(),
      '#required' => TRUE,
    );

    return $form;
  }

  function saveValues($values){
    $this->siguienteAccion = $this->consultaActual->definirSiguienteAccion($values);
    foreach ($values as $key => $value) {
      $this->storage['step_information'][$this->getStep()]['values'][$key] = $value;
    }
  }


  function consulta_radicacion_domicilio_provincia(){

    $form['idProvincia'] = array(
      '#type' => 'select',
      '#title' => t('Provincia'),
      '#options' =>  $this->getConsulta(2)->getProvincias(),
      '#required' => TRUE,
    );

    return $form;
  }

  function consulta_radicacion_domicilio_departamento($form, &$form_state){

    $form['idDepartamento'] = array(
      '#type' => 'select',
      '#title' => t('Departamento (partido)'),
      '#options' => $this->getConsulta(3)->getDepartamentos(),
      '#required' => TRUE,
    );

    return $form;
  }

  function consulta_radicacion_domicilio_localidad($form, &$form_state){

    $form['idLocalidad'] = array(
      '#type' => 'select',
      '#title' => t('Localidad'),
      '#options' => $this->getConsulta(4)->getLocalidades(),
      '#required' => TRUE,
    );

    return $form;
  }

  function consulta_radicacion_domicilio_calle($form, &$form_state){

    $form['idCalle'] = array(
      '#type' => 'select',
      '#title' => t('Calle'),
      '#options' => $this->getConsulta(5)->getCallesBarrios(),
      '#required' => TRUE,
    );

    return $form;
  }

  function consulta_radicacion_domicilio_altura($form, &$form_state){

    $form['alturaExacta'] = array(
      '#type' => 'textfield',
      '#title' => t('Altura exacta'),
      '#required' => TRUE,
      '#rules' => array(
  			'length[1, 5]',
      )
    );

    return $form;
  }

  function consultar_radicacion_domicilio_codigo_registro($form_,&$form_state){
    return $form;
  }

  function consultar_radicacion_domicilio_registro($form_,&$form_state){
    return $form;
  }

  function consultar() {
    $action = $this->siguienteAccion;
    $this->$action();
  }

  function getConsulta($step) {
    return $this->consultas[$step];
  }


  function consultarProvincias(){
    $this->storage['step'] = 2;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarDepartamentos(){
    $this->storage['step'] = 3;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarLocalidades(){
    $this->storage['step'] = 4;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarCallesBarrios(){
    $this->storage['step'] = 5;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarAlturaExacta(){
    $this->storage['step'] = 6;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarCodigoRegistroSeccional(){
    $this->storage['step'] = 7;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $values = $this->obtenerStepValues();
    $this->consultaActual->set_values($values);
    $this->consultaActual->consultar();
  }

  function consultarRegistroSeccional(){
    $this->storage['step'] = 8;
    $this->consultaAnterior = $this->consultaActual;
    $this->consultaActual = $this->getConsulta($this->getStep());
    $this->consultaActual->set_values(array('codigoRegistroSeccional' => $this->consultaAnterior->getCodigoRegistroSeccional()));
    $this->consultaActual->consultar();
  }

  function obtenerStepValues(){
    $values = array();
    for ($i=1; $i < $this->getStep(); $i++) {
      $stepValues = $this->getValues($i);
      $values = !empty($stepValues) ? array_merge($values, $stepValues) : $values;
    }
    return $values;
  }

  function stepTieneValues($step){
    return isset($this->storage['step_information'][$step]['values']);
  }

  function getValues($step){

    return $this->storage['step_information'][$step]['values'];
  }

}
