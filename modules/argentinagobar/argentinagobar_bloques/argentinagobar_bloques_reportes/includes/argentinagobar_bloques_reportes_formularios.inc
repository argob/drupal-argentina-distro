<?php


function argentinagobar_bloques_reportes_formularios_reportes($form, &$form_state){


	$form['contenedor'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'contenedor',
			)
	);

	$form['contenedor']['link'] = array(
		'#type' => 'markup',
		'#markup' => "<p><button class='btn btn-link' type='button' data-toggle='collapse' data-target='#contenedor-colapsible'>" . t("¿Hay algún error en esta página?") . "</button></p>",
	);

	$form['contenedor']['contenedor-colapsible'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => array('contenedor-colapsible'),
			'class' => array(
				'collapse',
				'well',
			),
		)
	);

	$form['contenedor']['contenedor-colapsible']['titulo'] = array(
		'#type' => 'item',
		'#markup' => "<p>Si encontraste información errónea o algún problema con esta página, envianos tus comentarios para poder mejorarlo. <strong>No incluyas información personal</strong>.</p>",
  );

	$form['contenedor']['contenedor-colapsible']['haciendo'] = array(
		'#type' => 'textfield',
    	'#title' => t('¿Qué estabas haciendo?'),
    	'#description' => t('Escribí la acción que estabas realizando.'),
			'#required' => TRUE,
	);

	$form['contenedor']['contenedor-colapsible']['problema'] = array(
		'#type' => 'textfield',
    	'#title' => t('¿Qué salió mal?'),
    	'#description' => t('Contanos el problema que tuviste navegando.'),
			'#required' => TRUE,
	);

	$form['contenedor']['contenedor-colapsible']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Enviar'),
 		'#ajax' => array(
			'callback' => 'argentinagobar_bloques_reportes_formularios_reportes_ajax',
			'wrapper' => 'contenedor',
			'method' => 'replace',
			'effect' => 'fade',
		)
	);

	$form['nodo'] = array(
		'#type' => 'hidden',
		'#value' => arg(1),
	);
	return $form;
}

function argentinagobar_bloques_reportes_formularios_reportes_ajax($form, &$form_state) {
	$form_id = $form_state['build_info']['form_id'];

  drupal_validate_form($form_id, $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
		return $form;
  }
	
	return theme('argentinagobar_bloques_reportes_formularios_mensaje');
}

function argentinagobar_bloques_reportes_formularios_reportes_submit($form, &$form_state) {


	db_insert('argentinagobar_reportes')
	->fields(
		array(
			'nid' => $form_state['values']['nodo'],
			'haciendo' => $form_state['values']['haciendo'],
			'problema' => $form_state['values']['problema'],
		)
	)
	->execute();
}
