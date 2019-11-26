<?php
class ConsultaRegistroRenabap extends Consulta{
	
	function get_form($form, &$form_state, $consulta){
						
		$form = array();
		
		$wrapper = new FieldContainer('wrapper');
		$form['wrapper'] = $wrapper->render();
		
		$dni = new FieldDNI();
		$dni->set_required(TRUE);
		$form['wrapper']['dni'] = $dni->render();
			
		$birthdate = new FieldBirthdate();
		$birthdate->set_required(TRUE);
		$form['wrapper']['fecha_nacimiento'] = $birthdate->render();
		
		$submit = new FieldSubmitAJAX();
		$form['wrapper']['submit'] = $submit->render();
		
		# serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
		$form_state['handler']['class'] = serialize($this);
		
		return $form;
	}
		
	function get_params(){
		return http_build_query(
			array(
				'dni' => $this->values['dni'],
				'fecha_nacimiento' => $this->values['fecha_nacimiento']
			)
		);
	}
	
	function get_endpoint(){
		return variable_get('consulta_registro_renabap_endpoint', NULL);
	}
	
	function get_response($request){
		
		$response = NULL;
						
		if($request->code == 401){
			$this->api_gateway_auth->refresh_token();
			$this->consultar();
		}
				
		if($request->code == 200){
			
			$data = drupal_json_decode($request->data);
			
			$response_id = $data['situacion'];
						
			$response = $this->responses[$response_id]->render();
			
		} else {
			
			drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
			watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
		}
		
		return $response;
		
	}
}