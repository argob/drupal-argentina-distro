<?php

class ConsultaRegistroRenabapResponse3{
	
	function render(){
		return theme('response_success', array(
			'title' => t('No fuiste encuestado.'),
			'message' => t('Si tu hogar pertenece a un Barrio Popular y no tenés el Certificado de Vivienda Familiar, podés solicitar el relevamiento de tu barrio indicando el nombre o la localidad.'),
			'icon' => 'text-warning fa-warning hide',
			'response_id' => 3,
		));
	}
}