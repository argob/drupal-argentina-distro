<?php
function argentinagobar_formularios_configuracionDC($form, &$form_state) {
  
	$opciones = variable_get('DC_opciones');
	$queue = variable_get('update_redmine_tickets');

	$query = db_select('file_managed', 'fm');
	$query->fields('fm', array('filename', 'fid'));
	$query->condition('status',1,'=');
	$query->condition('uri',db_like('public://temp_consumidor').'%','LIKE');
	$result = $query->execute();
	$records = $result->fetchAll();

	$queue_print = '';
	if (!empty($records)){
		//$queue = array_reverse($records);
		foreach ($records as $key => $value) {
			$tries = isset($queue[$value->fid]) ? $queue[$value->fid] : $opciones['try'];
			$queue_print .= sprintf("%02d", $tries) . ' intentos restantes ' . $value->filename . "\n";
		}
	}

	$form['issue_manager'] = array(
		'#type' => 'radios',
		'#title' => 'Indicar el tipo de gestor de issues',
		'#options' => array(
			'rdm' => 'Redmine',
			'crm' => 'CRM a traves de API GATEWAY'
		),
		'#required' => TRUE,
		'#default_value' => isset($opciones['issue_manager']) ? $opciones['issue_manager'] : 'rdm',
	);

	$form['destination'] = array(
		'#type' => 'textfield',
		'#title' => 'URL donde apunta defensa del consumidor no terminar con / final',
		'#size' => 500,
		'#maxlength' => 500,
		'#required' => TRUE,
		'#default_value' => isset($opciones['destination']) ? $opciones['destination'] : 'https://consumidor.argentina.gob.ar',
	);

	$form['localidades'] = array(
		'#type' => 'fieldset',
		'#title' => 'Localidades',
		'#description' => 'Configuración para los templates que permiten cargar los selects de localidades muy rápido',
	);

	$form['desc'] = array(
		'#title' => 'Reporte',
		'#markup' => '<a href="../../../admin/reports/DefensaDelConsumidor">Ver reportes de Cron</a>'
	);

	$form['localidades']['hora_carga_localidades'] = array(
		'#type' => 'textfield',
		'#title' => 'Rango horario',
		'#description' => 'Rango horario en que se crearan los templates que es un proceso bastante largo ej 10-12 o 00-06 en horario de Buenos Aires',
		'#size' => 5,
		'#maxlength' => 5,
		'#required' => TRUE,
		'#default_value' => isset($opciones['hora_carga_localidades']) ? $opciones['hora_carga_localidades'] : '05-12',
		'#rules' => array(
			array(
				'rule' => 'regexp[/[0-2][0-9]\-[0-2][0-9]/]',
				'error' => 'El rango horario debe contener 2 horas en formato decimal (#00) separadas por un guión ejemplo 10-18 en horario de Buenos Aires'
			),
		  ),
	);

	$form['archivos'] = array(
		'#type' => 'fieldset',
		'#title' => 'Archivos',
		'#description' => 'Configuración para archivos adjuntos en los tickets de defensa del consumidor',
	);

	$form['archivos']['hora_carga_archivos'] = array(
		'#type' => 'textfield',
		'#title' => 'Rango horario',
		'#description' => 'Rango horario en que se cargaran los archivos adjuntos por cron ej 10-12 o  00-06 en horario de Buenos Aires',
		'#size' => 5,
		'#maxlength' => 5,
		'#required' => TRUE,
		'#default_value' => isset($opciones['hora_carga_archivos']) ? $opciones['hora_carga_archivos'] : '05-12',
		'#rules' => array(
			array(
				'rule' => 'regexp[/[0-2][0-9]\-[0-2][0-9]/]',
				'error' => 'El rango horario debe contener 2 horas en formato decimal (#00) separadas por un guión ejemplo 10-18 en horario de Buenos Aires'
			),
		  ),
	);

	for($i=1; $i<=30; $i++){
		$numeros[$i] = $i;
	}

	$form['archivos']['try'] = array(
		'#type' => 'select',
		'#title' => 'Intentos',
		'#description' => 'Cuántas veces se intentará cargar los archivos en caso de fallar',
		'#options' => $numeros,
		'#required' => TRUE,
		'#default_value' => isset($opciones['try']) ? $opciones['try'] : 5,
	);

	for($i=1; $i<=3; $i++){
		$numeros[$i] = $i;
	}

	$form['archivos']['cant_cron'] = array(
		'#type' => 'select',
		'#title' => 'Intentos consecutivos',
		'#description' => 'Cuántas veces se hará el intento en el cron',
		'#options' => $numeros,
		'#required' => TRUE,
		'#default_value' => isset($opciones['cant_cron']) ? $opciones['cant_cron'] : 5,
	);

	//timeout
	for($i=1; $i<=60; $i++){
		$numeros[$i] = $i;
	}

	$form['archivos']['timeout'] = array(
		'#type' => 'select',
		'#title' => 'Timeout',
		'#description' => 'Timeout en las 2 request',
		'#options' => $numeros,
		'#required' => TRUE,
		'#default_value' => isset($opciones['timeout']) ? $opciones['timeout'] : 5,
	);

	//cantidad de registros
	for($i=1; $i<=50; $i++){
		$numeros[$i] = $i;
	}

	$form['archivos']['registros'] = array(
		'#type' => 'select',
		'#title' => 'Registros',
		'#description' => 'Cantidad de registros que procesará',
		'#options' => $numeros,
		'#required' => TRUE,
		'#default_value' => isset($opciones['registros']) ? $opciones['registros'] : 5,
	);


	$form['queue'] = array(
		'#title' => 'Cola de archivos para cargar',
		'#type' => 'textarea',
		'#default_value' => (!empty($queue_print)) ? $queue_print : '',
		'#cols' => 1,
		'#rows' => 15,
	);

	$form['cacheGeoRef'] = array(
		'#title' => 'Limpiar cache Georef',
		'#options' => array(0 => 0, 1 => 1),
		'#description' => 'Elimina las localidades en Variables',
		'#type' => 'checkbox',
		'#default_value' => null,
	);

	/*$form['rebuild_template'] = array(
		'#title' => 'Correr el cron de localidades',
		'#options' => array(0 => 0, 1 => 1),
		'#description' => 'Marcando esta opción se recrea el template de localidades',
		'#type' => 'checkbox',
		'#default_value' => null,
	);

	$form['clean_variable'] = array(
		'#title' => 'Limpiar la variable update redmine tickets',
		'#options' => array(0 => 0, 1 => 1),
		'#description' => 'Marcando esta opción se borra la variable lo que elimina los tries',
		'#type' => 'checkbox',
		'#default_value' => null,
	);

	$form['eliminar_back'] = array(
		'#title' => 'Reemplazar back',
		'#options' => array(0 => 0, 1 => 1),
		'#description' => 'Reemplaza back en las url porque los archivos no pueden ser encontrados',
		'#type' => 'checkbox',
		'#default_value' => isset($opciones['eliminar_back']) ? $opciones['eliminar_back'] : 1,
	);*/

	$form['submit_button'] = array(
		'#type' => 'submit',
		'#value' => t('Setear'),
	);

	return $form;
}

function argentinagobar_formularios_configuracionDC_submit($form, &$form_state) {

	variable_set('DC_opciones', $form_state['values']);

	/*if($form_state['values']['clean_variable'] == 1) {
		variable_del('update_redmine_tickets');
	}*/

	if($form_state['values']['cacheGeoRef'] == 1){
		$borrar = variable_get('georef_provincias');
		if(!empty($borrar)){
			foreach($borrar as $key => $value){
				variable_del('georef'.$key);
			}
		}
	}
	variable_del('georef_provincias');

	/*if($form_state['values']['rebuild_template'] == 1 && function_exists('argentinagobar_formstyler_cron')){
		argentinagobar_formstyler_cron();
	}*/

}
?>