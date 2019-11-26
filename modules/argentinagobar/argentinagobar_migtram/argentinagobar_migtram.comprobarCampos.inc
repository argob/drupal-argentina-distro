<?php
function _comprobarEstructuraContenido(){

	// Agregar los fields que requeris de CSV

	$campos_requeridos = array(
		'body',
		'og_group_ref',
		'field_download',
		'field_servicio_categoria',
		'field_acciones',
		'field_costo',
		'field_dirigido',
		'field_modalidad_digital',
		'field_modalidad_otro',
		'field_modalidad_otro_especificar',
		'field_modalidad_presencial',
		'field_modalidad_telefonico',
		'field_pasos',
		'field_requisitos_collection',
		'field_vigencia',
		'field_id_migracion',
		'field_es_migrado',
		//Relevamiento
		'field_transaccion_tipo',
		'field_digitalizacion_medir',
		'field_digitalizacion_observacion',
		'field_descargas_obligatorias',
		'field_formulario_digital',
		'field_turno_requerido',
		'field_turno_digital',
		'field_identificacion_digital',
		'field_posee_notificaciones',
		'field_notificaciones',
		'field_pago_requerido_list',
		'field_pago_electronico_list',
		'field_resumen_nivel',
		'field_relevamiento_observaciones'
	);

	$fields = field_info_instances('node', 'tramite');

	foreach($fields as $key => $value){
		$campos_servicio[] = $key;
	}
	
	foreach ($campos_requeridos as $key => $value) {
		if(!in_array($value, $campos_servicio)){
			die('El campo '.$value.' no esta presente verificar la feature de servicios');
		}
	}

}

function _comprobarListas(){

	$listas = array(
		'field_accion' => array(
			'pedir_turno',
			'consultar_en_linea',
			'descargar_documento',
			'web_del_tramite',
		),
		'field_oficina' => array(
			'todas',
			'correspondiente',
			'otra'
		),
		'field_transaccion_tipo' => array(
			'actividad',
			'asesoramiento',
			'consulta',
			'denuncia',
			'documentacion',
			'inscripcion',
			'legalizacion',
			'solicitud',
			'turno',
			'otro',
			'sin_informacion'
		),
		'field_resumen_nivel' => array(
			1,
			2,
			3,
			4
		),
		'field_pago_requerido_list' => array(
			0,
			'si_obligatorio',
			'si_segun_opcion'
		),
		'field_pago_electronico_list' => array(
			0,
			1,
			'si_segun_dependencia'
		),
	);

	foreach ($listas as $field => $lista) {
		$my_field = field_info_field($field);
		$allowed_values = list_allowed_values($my_field);

		// Extraigo las opciones posibles de los campos
		$arrayAllowed = array();
		foreach($allowed_values as $opcion => $texto){
			$arrayAllowed[] = $opcion;
		}

		foreach ($lista as $opcion) {
			
			if(!in_array($opcion, $arrayAllowed, true)){
				die('La opción '.$opcion.' no esta presente en el campo '. $field . ' verificar la feature de servicios');
			}
		}
	}

}