<?php

class ConsultaRegistroRenabapResponse1{
		
	function render(){
		return theme('response_success', array(
			'title' => t('Fuiste encuestado y sos responsable de la vivienda.'),
			'message' => t('Acercate a cualquier oficina de ANSES con tu DNI para obtener el Certificado de Vivienda Familiar.'),
			'icon' => 'text-success fa-check-circle',
			'response_id' => 1,
		));
	}
}