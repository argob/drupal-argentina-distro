<?php

abstract class Consulta
{

  protected $api_gateway_auth;
  const ENDPOINT = null;
  public $values;
  public $contador;

   static function verificacion($token)
  {
      $verificacion = drupal_http_request(static::static_get_endpoint(),array(
          'headers' => array('Authorization' => 'Bearer ' . $token),
          'method' => 'HEAD'));

     return $verificacion->code == 200;
  }

  function salud_general($consultas,$apiAuth)
  {
      $token = $apiAuth->getAccessToken();
      $verif = true;

      foreach ($consultas as $consulta) {

        $verif = $verif && $consulta::verificacion($token);

        if (!$verif) {

            watchdog('AR Formularios','<p>Error en: ' . $consulta . '<br> Mensaje: ' . 'No esta respondiendo el servicio'  . '</p>');
        }

      }

      return $verif;
  }

  static function static_get_endpoint()
  {
      return variable_get(static::ENDPOINT, null);
  }

  function __construct($api_gateway_auth, $values = array())
  {
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->contador = 0;
  }

  public function setContador($valor)
  {
    $this->contador = $valor;
  }

  public function getContador(){
    return $this->contador;
  }

  function get_form($form, &$form_state, $consulta){
    $form = array();
    return $form;
  }

  function isValidParam($param) {
    return true;
  }

  function setValues($values)
  {
    foreach ($values as $key => $value) {
      if ($this->isValidParam($key) && $value != '') {
        $this->values[$key] = check_plain($value);
      }
    }
  }

  function add_response_theme($response_id, $response)
  {
    $this->responses[$response_id] = $response;
  }

  function get_response_theme($response_id)
  {
    return $this->responses[$response_id];
  }

  function set_values($values)
  {
    $this->values = $values;
  }

  function get_values()
  {
      return $this->values;
  }

  function get_endpoint()
  {
      return '';
  }

  function hayParametros()
  {
    return count($this->getParametros()) > 0;
  }

  function getParametros()
  {
    return drupal_get_query_parameters($query = NULL, $exclude = array('q'), $parent = '');
  }


  function get_request_method(){
    return 'GET';
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();


    if(is_null($endpoint) || $enpoint = '')
    {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    return $endpoint . '?' . $this->get_params();
  }

  function get_params()
  {
    return http_build_query(array());
  }

  function get_headers()
  {
    return array('Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken());
  }

  function get_request_headers()
  {
    return array(
      'headers' => $this->get_headers(),
      'method' => $this->get_request_method(),
    );
  }

  function get_request()
  {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

    if (isset($request->error)) {
      $this->handleError($request);
    }

    return $request;
  }

  function handleError($request)
  {
    throw new ConsultaErrorException($request->error);
  }

  function get_response($request)
  {
    $data = null;

    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 200) {
      $data = drupal_json_decode($request->data);
    }

    return $data;
  }

  function renderResponse($form, &$form_state, $response)
  {
    return $response;
  }

  function renderResponseSinForm($response)
  {
    return $response;
  }


  function consultar()
  {
    try {

      $request = $this->get_request();
      return $this->get_response($request);

    }

    catch (ConsultaException $e)
    {

      // Muestra mensaje genérico al usuario
      drupal_set_message('Servicio momentáneamente no disponible', 'error', FALSE);

      // Loguea el mensaje de la excepción en los registros
      watchdog('AR Formularios', '<p>Error code: ' . $e->getCode() . '<br> Mensaje: ' . $e->getMessage()  . '</p>' . '<pre>' . $e->getTraceAsString() . '</pre>', $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);

    }
  }

}
