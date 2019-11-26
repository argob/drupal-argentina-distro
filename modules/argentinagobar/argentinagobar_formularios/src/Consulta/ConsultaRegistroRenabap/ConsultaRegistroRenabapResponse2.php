<?php

class ConsultaRegistroRenabapResponse2{
	
	function render(){
		return theme('response_success', array(
			'title' => t('Fuiste encuestado y no sos responsable de la vivienda.'),
			'message' => t('Acercate a cualquier oficina de ANSES con tu DNI y el DNI (o fotocopia) del Responsable de Vivienda para obtener el Certificado de Vivienda Familiar.'),
			'icon' => 'text-success fa-check-circle',
			'response_id' => 2,
		));
	}
}