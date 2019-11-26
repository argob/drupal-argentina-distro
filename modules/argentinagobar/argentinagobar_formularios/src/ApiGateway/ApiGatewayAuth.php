<?php

class ApiGatewayAuth{

  // Contenedor Instancia de la clase
  private static $instance = NULL;

  public $username;
  public $password;
  public $token_endpoint;
  public $access_token = array();

  // Constructor privado, previene la creación de objetos vía new
  private function __construct() {
    $this->username = variable_get('apigateway_username', NULL);
    $this->password = variable_get('apigateway_password', NULL);
    $this->token_endpoint = variable_get('apigateway_token_endpoint', NULL);
  }

  // Clone no permitido
  private function __clone(){}

  public function __wakeup(){}

  // Método singleton
  public static function getInstance(){
    if (is_null(self::$instance)) {
        self::$instance = new ApiGatewayAuth();
    }
    return self::$instance;
  }

  private function getUsername(){
    return $this->username;
  }

  private function getPassword(){
    return $this->password;
  }

  private function isAuthorized(){
    return !empty($this->access_token);
  }

  function getAccessToken(){

    if(!$this->isAuthorized()) {
      $this->authorize();
    }

    if(isset($this->access_token['token'])){
      return $this->access_token['token'];
    }
  }

  function getTokenType(){
    return $this->access_token['token_type'];
  }

  private function authorize(){

    $params = array(
      'username' => $this->getUsername(),
      'password' => $this->getPassword(),
    );

    $data = http_build_query($params);

    $options = array(
      'method' => 'POST',
      'data' => $data,
      'timeout' => 60, //1 minuto
      'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
    );

    $url = $this->token_endpoint;

    if(empty($params['username']) || empty($params['password']) || empty($url)){

    	throw new CredencialesInvalidasException('Falta username, password o endpoint', 1);

    } else {

    	$request = drupal_http_request($url, $options);

    	if($request->code == 200){

    		$data = drupal_json_decode($request->data);

    		$this->access_token = array(
    				'token' => $data['token'],
    				'token_type' => $data['token_type'],
    				'expires_in' => $data['expires_in'],
    		);

    	} else {

    		watchdog('Formularios', 'Error en la autenticación API', $variables = array(), WATCHDOG_ERROR, $link = NULL);
    		drupal_set_message("No pudimos procesar tu consulta. Por favor intentalo nuevamente", 'error', $repeat = FALSE);

    		$form_state['rebuild'] = TRUE;

    	}
    }
  }

  function refresh_token(){
    // TODO: usar parámetro @expires_in para calcular cuando pedir otro token y no esperar un 401
    $this->access_token = array();
    $this->authorize();
  }
}
