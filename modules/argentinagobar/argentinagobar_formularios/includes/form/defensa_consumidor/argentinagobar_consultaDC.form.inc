<?php

include_once 'defensaconsumidor.helpers.inc';

function argentinagobar_consultadc_form($form, &$form_state, $no_js_use = FALSE) {

	$form['#name']='argentinagobar_consultadc';

	$active = array('DNI' => t('DNI'), 'LC' => t('LC'), 'LE' => t('LE'), 'CI' => t('CI'), 'Pasaporte' => t('Pasaporte'));
	$form['tipo_doc'] = array(
		'#prefix' => '<div class="col-md-4" style="padding-left:0;">',
		'#suffix' => '</div>',
		'#type' => 'select',
		'#title' => t('Tipo de documento'),
		'#options' => $active,
		'#group' => 'consulta',
		'#required' => TRUE,
		'#default_value' => 'DNI',
	);

	$form['doc'] = array(
		'#prefix' => '<div class="col-md-8" style="padding-right:0;">',
		'#suffix' => '</div>',
		'#type' => 'textfield',
		'#title' => t('Número de documento'),
		'#size' => 30,
		'#maxlength' => 9,
		'#required' => TRUE,
	);

	$form['numero'] = array(
		'#type' => 'textfield',
		'#title' => t('Número de consulta'),
		'#size' => 30,
		'#maxlength' => 20,
		'#required' => TRUE,
		'#rules' => array(
			array('rule' => 'numeric', 'error' => 'El campo debe contener un número'),
			array('rule' => 'length[3, 8]', 'error' => 'El número de reclamo debe contener entre 3 y 8 caracteres'),
		  ),
		);

	$form['submit']['#type'] = 'submit';
	$form['submit']['#value'] = t('Consultar');

	$options = array (
		'title' => 'Seguí tu reclamo a Defensa del Consumidor',
		'subtitle' => '(Los campos marcados con * son obligatorios)',
		'response' => TRUE,
		'progress' => TRUE,
	);

	argentinagobar_formstyler($form, $options);

	return $form;
}


function argentinagobar_consultadc_validar($form, $form_state){

}

function argentinagobar_consultadc_consultar($form, $form_state) {

	$opciones = variable_get('DC_opciones');

	$form_state['rebuild'] = TRUE;

	$form_id = str_replace('_','-',$form_state['values']['form_id']);
	$selector = "#".$form_id." #response";

	if(empty(form_get_errors())){

		$api_gateway = new ConsultaDefensaDelConsumidorTicket(ApiGatewayAuth::getInstance());
		$api_gateway->setValues(
			array(
				'dni' => $form_state['values']['doc'],
				'tipoDNI' => 'dni',
				'issues' => $form_state['values']['numero']
			)
		);
		$response['respuesta'] = $api_gateway->consultar();

	}

	$response['form_id'] = $form_id;
	$response['multiple'] = false;

	return array(
		'#type' => 'ajax',
		'#commands' => array(
			array(
				'command' => 'consultaAfter',
				'data' => $response,
				'messages' => form_get_errors(),
				'template' => $response['respuesta']
				)
			)
	);

}
