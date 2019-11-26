<?php

class ConsultaDefensaDelConsumidorTicket extends Consulta{
	
	function get_form($form, &$form_state, $consulta){

	}

	function get_params(){
		$parametros = http_build_query($this->values);
		return $parametros;
	}
	
	function get_endpoint(){
		$opciones = variable_get('DC_opciones');
		return $opciones['destination'] . '/api/v1.0/defensa-consumidor/search';
	}
	
	function get_response($request){
		if($request->code == 401){
			$this->api_gateway_auth->refresh_token();
			$this->consultar();
		}
		if($request->code == 200){
			$data = drupal_json_decode($request->data);
			$response = $data['results'][0];
			if (!empty($response)){

				$issue = $response['issue']['custom_fields'];

				$proveedores = '';

				for ($c=0; $c<6; $c++) {
					$proveedores .= ( isset($issue['prov_' . $c . '_nombre']) && $issue['prov_' . $c . '_nombre'] != null ) ? $issue['prov_' . $c . '_nombre'].'<br>' : '';
				}

				$ticket = array(
	        		'proveedores' => $proveedores,
	        		'finicio' => date("d/m/Y", strtotime($issue['date_entered'])),
	        		'id' => $response['issue']['id'],
	        		'name' => $issue['status'],
	        	);

	        	if (isset($response['issue']['proyect'])) {

	        		$proj = $response['issue']['proyect'];
					$datos = array(
		        		'direccion' => isset($proj['adress']) ? $proj['adress'] : null,
		        		'mails' => isset($proj['email']) ? $proj['email'] : null,
		        		'telefono' => isset($proj['phone']) ? $proj['phone'] : null,
		        		'horario' => isset($proj['opening_hours']) ? $proj['opening_hours'] : null,
	        		);
	        	}

				return theme('defensa_consumidor_estado', array('datos' => $datos, 'ticket' => $ticket));
			} else {
				return theme('defensa_consumidor_error', array('error' => 'No existen datos registrados del reclamo ingresado'));
			}
			
		}
		return $response;
	}

}