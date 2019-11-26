<?php

// ESTA CLASE ESTA DEPRECADA SE BORRARÁ

class ConsultaDefensaDelConsumidorUploadFile extends ConsultaPOST{
	
	function get_form($form, &$form_state, $consulta){

	}

	function get_params() {
		$this->values['tk'] = 'Bearer ' . $this->api_gateway_auth->getAccessToken();
		return $this->values;
  	}
	
	function get_endpoint(){
		
		$opciones = variable_get('DC_opciones');
		global $base_url;
    	$helperURL = $base_url;

    	if ($opciones['eliminar_back'] && strpos($helperURL, 'back') !== false ) {
	      $helperURL = str_replace('back', 'www', $helperURL);
	    }

	    return $helperURL . '/drup4lh3lper/help/drupal/drupalHelper.php';
		
	}

	function get_response($request){
		if($request->code == 401){
			$this->api_gateway_auth->refresh_token();
			$this->consultar();
		}
		if($request->code == 200){
			$data = drupal_json_decode($request->data);
		}
		return $request;
	}

	function get_request_headers() {
		$opciones = variable_get('DC_opciones');
		return array(
		  'headers' => array(
			'Content-Type' => 'application/x-www-form-urlencoded',
			'Authorization' => 'Basic cG9zdHVsYW50ZTpNNGMwZDNtMTAh'
		  ),
		  'timeout' => $opciones['timeout'],
		  'method' => $this->get_request_method(),
		  'data' => http_build_query($this->get_params()),
		);
	}
}