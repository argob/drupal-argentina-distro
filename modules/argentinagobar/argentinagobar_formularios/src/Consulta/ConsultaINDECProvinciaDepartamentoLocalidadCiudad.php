<?php

class ConsultaINDECProvinciaDepartamentoLocalidadCiudad extends Consulta{

	function get_form($form, &$form_state, $consulta){

	}

	function get_params(){
    $parametros = http_build_query(array('limit'=>'17000'));
   return $parametros;
	}

	function get_endpoint(){
		return variable_get('ConsultaINDECProvinciaDepartamentoLocalidadCiudad_endpoint', NULL);
	}

	function get_response($request){
		if($request->code == 401){
			$this->api_gateway_auth->refresh_token();
			$this->consultar();
		}
		if($request->code == 200){
			$data = drupal_json_decode($request->data);
			$response = $data;
		}
		return $response;
	}
}
