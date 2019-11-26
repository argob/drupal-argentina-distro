<?php
function argentinagobar_formularios_casadelfuturo($form, &$form_state) {

	//botón de descarga
	global $base_root;
	//$url_archivo = variable_get('file_public_path', conf_path() . '/files');
	$url_archivo .= "/casas_del_futuro/casas_del_futuro.csv";

	$form['columna_izquierda0'] = array(
		'#type' => 'markup',
		'#markup' => "<div class='col-xs-12 col-sm-12'> <a class='fa fa-download btn btn-primary btn-sm m-b-2' href='$url_archivo'>  Descargar la base de datos</a> </div>",
	);

	//estilos
	$form['columna_izquierda'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
	);

	$form['columna_derecha'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
	);

	$form['columna_centro']['datos_personales'] = array(
		'#type' => 'container',
		'#attributes' => array(
			)
	);

	$form['columna_centro'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro2'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_centro4'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_centro5'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda2'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
	);

	$form['columna_centro6'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

	$form['columna_centro7'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_centro8'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_derecha_chica'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_centro'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_derecha'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_centro8_1'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

	$form['columna_izquierda_chica'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_izquierda_chica_centro'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_izquierda_chica_derecha'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	 	$form['columna_derecha_chica2'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_centro2'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_derecha2'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_centro9'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda_chica3'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_izquierda_chica_centro3'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_izquierda_chica_derecha3'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_centro3'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_derecha3'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_derecha_chica_derecha3_vacio'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
	);

	$form['columna_centro10'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda10'] = array(
    '#type' => 'container',
        '#attributes' => array(
            'class' => array(
                'col-xs-12', 'col-sm-6'
            )
        )
    );

 	$form['columna_izquierda_chica4'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-3'
			)
		)
	);

	$form['columna_centro11'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda4_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha2_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha2_2'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_derecha2_2_d'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_centro12'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda5'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_derecha3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_izquierda6'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro13'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	//primer conviviente

 	$form['columna_centro14'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda5_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha3_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha3_2'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_derecha3_2_d'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_centro15'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda7'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_derecha4'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_izquierda7'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro16'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	//segundo conviviente

 	$form['columna_centro17'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda6_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha4_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha4_2'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_derecha4_2_d'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_centro19'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda8'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_derecha5'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_izquierda8'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro20'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	//tercer conviviente

 	$form['columna_centro21'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda7_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha5_3'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-4'
			)
		)
 	);

 	$form['columna_derecha5_2'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_derecha5_2_d'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-2'
			)
		)
 	);

 	$form['columna_centro22'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	$form['columna_izquierda9'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_derecha6'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_izquierda9'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
 	);

 	$form['columna_centro23'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

 	//campos

	//datos personales

	$form['columna_izquierda']['datos_personales']['nombre_apellido'] = array(
		'#type' => 'textfield',
		'#title' => 'Nombre y apellido',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[6, 100]'
			)
	);



	$form['columna_derecha']['datos_personales']['identidad_de_genero'] = array(
		'#type' => 'select',
		'#title' => 'Sexo',
    '#empty_option' => t('Seleccioná una opción'),
    '#options' => array(
      'masculino' => t('Masculino'),
      'femenino' => t('Femenino'),
    ),
	);


	$form['columna_izquierda']['datos_personales']['nacionalidad'] = array(
		'#type' => 'textfield',
		'#title' => 'Nacionalidad',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'alpha',
			'length[3, 30]'
			)
		);

	$form['columna_derecha']['datos_personales']['numero_cuil'] = array(
		'#type' => 'textfield',
		'#title' => 'Número de CUIL',
		'#size' => 30,
		'#maxlength' => 11,
		'#rules' => array(
			'numeric',
			'length[9, 11]'
			)
		);

	$form['columna_izquierda']['datos_personales']['edad_solicitante'] = array(
		'#type' => 'textfield',
		'#title' => 'Edad',
		'#size' => 30,
		'#maxlength' => 100,
		'#default_value' => '0',
		'#rules' => array(
			'numeric',
			'length[1, 3]'
			)
		);

	$form['columna_derecha']['datos_personales']['estado_civil'] = array(
		'#type' => 'select',
		'#title' => 'Estado civil',
    '#empty_option' => t('Seleccioná una opción'),
    '#options' => array(
      'soltero' => t('Soltero'),
      'casado' => t('Casado'),
      'viudo' => t('Viudo'),
      'divorciado' => t('Divorciado'),
      'separado' => t('Separado'),
    ),
		'#rules' => array(
			'alpha',
			'length[3, 20]'
			)
		);

	$form['columna_izquierda']['datos_personales']['telefono_fijo'] = array(
		'#type' => 'textfield',
		'#title' => 'Teléfono familiar',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'numeric',
			'length[6, 15]'
			)
		);

	$form['columna_derecha']['datos_personales']['telefono_celular'] = array(
		'#type' => 'textfield',
		'#title' => 'Teléfono celular',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'numeric',
			'length[7, 15]'
			)
		);

	$form['columna_izquierda']['datos_personales']['mail'] = array(
		'#type' => 'textfield',
		'#title' => 'Correo electrónico',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'email'
			)
		);

	$form['columna_derecha']['datos_personales']['fecha_nacimiento'] = array(
		'#type' => 'date',
		'#title' => ' Fecha de Nacimiento'

	);

	$form['columna_centro']['datos_personales']['tipo_documento'] = array(
		'#type' => 'radios',
		'#title' => 'Tipo de documento',
		'#attributes' => array(),
		'#default_value' => isset($node->active) ? $node->active : 'dni',
		'#options' => array(
			'dni' => t("DNI"),
			'lc' => t("Libreta cívica"),
			'le' => t("Libreta de enrolamiento")
			),
		);

	$form['columna_centro2']['datos_personales']['numero_documento'] = array(
		'#type' => 'textfield',
		'#title' => 'Número de documento',
		'#size' => 30,
		'#maxlength' => 9,
		'#rules' => array(
			'numeric',
			'length[7, 9]'
			)
		);

	//información de Educación

	$form['columna_centro3']['info_educacion']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Información de Educación')."</h2>",
	);

	$form['columna_centro4']['escolaridad_']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h3>".t('Escolaridad:')."</h3>",
	);

	$form['columna_centro4']['escolaridad'] = array(
		'#type' => 'radios',
		'#title' => '¿Asistís a un establecimiento educativo (escuela, terciario, universidad, etc.?)',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo'] = array(
	'#type' =>'container',
	'#states' => array(
	'visible' => array(
		':input[name="escolaridad"]' => array('value' => 'si')
		),
	),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo']['modalidad'] = array(
		'#type' => 'radios',
		'#title' => 'Modalidad',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'publica' => t("Pública"),
			'privada' => t("Privada"),
			'privada_con_beca' => t("Privada con beca"),
			'privada_sin_beca' => t("Privada sin beca")
			),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo']['turno'] = array(
		'#type' => 'radios',
		'#title' => 'Turno al que concurrís',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'mañana' => t("Mañana"),
			'tarde' => t("Tarde"),
			'mañana_tarde' => t("Mañana y tarde"),
			'vespertino' => t("Vespertino")
			),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo']['nivel'] = array(
		'#type' => 'radios',
		'#title' => 'En qué nivel estás estudiando:',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'primario' => t("Primario"),
			'media_secundario' => t("Media/Secundario"),
			'terciario' => t("Terciario"),
			'universitario' => t("Universitario")
			),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo']['max_nivel'] = array(
		'#type' => 'radios',
		'#title' => 'Máximo grado o año que llegaste a cursar en el 2016:',
		'#attributes' => array(),
		'#options' => array(
			'primario' => t("Primario"),
			'primero_secundario' => t("1° Media/Secundario"),
			'segundo_secundario' => t("2° Media/Secundario"),
			'tercero_secundario' => t("3° Media/Secundario"),
			'cuarto_secundario' => t("4° Media/Secundario"),
			'quinto_secundario' => t("5° Media/Secundario"),
			'sexto_secundario' => t("6° Media/Secundario"),
			'terciario_universitario' => t("Terciario o universitario")
			),
		);

	$form['columna_centro4']['asistencia_establecimiento_educativo_no']['no_max_nivel'] = array(
		'#type' => 'radios',
		'#title' => 'Máximo nivel de estudio alcanzado:',
		'#attributes' => array(),
		'#states' => array(
		'visible' => array(
		':input[name="escolaridad"]' => array('value' => 'no')
		),
	),
		'#options' => array(
			'sin_estudios' => t("Sin estudios"),
			'primaria_abandonada' => t("Comenzaste Primario pero abandonaste"),
			'primaria' => t("Completaste primario pero nunca comenzaste secundario"),
			'secundaria_abandonada' => t("Comenzaste secundario pero abandonaste"
			),
			'secundaria' => t("Completaste secundario"),
			'secundaria_materias_pendientes' => t("Completaste secundario pero adeudás materias"),
			'terciaria_incompleto' => t("Terciario/universitario incompleto"
			),
			'terciaria_completo' => t("Terciario/universitario completo"
			),
			),
		);

	$form['columna_centro4']['cursos_realizados'] = array(
		'#type' => 'textarea',
		'#title' => 'Cursos realizados:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_centro4']['max_nivel_alcanzado_2016'] = array(
		'#type' => 'textfield',
		'#title' => 'En caso que asistas, indica máximo grado o año que llegaste a cursar (en el 2016):',
		'#size' => 30,
		'#maxlength' => 100,
		);

	//información de Salud

	$form['columna_centro5']['info_salud']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Información de Salud')."</h2>",
	);

	$form['columna_centro5']['salud'] = array(
		'#type' => 'radios',
		'#title' => '¿Tenés cobertura de salud?',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	$form['columna_centro5']['tipo_cobertura'] = array(
		'#type' => 'radios',
		'#title' => '¿Qué tipo?',
		'#attributes' => array(),
		'#states' => array(
		'visible' => array(
		':input[name="salud"]' => array('value' => 'si')
		),
	),
		'#options' => array(
			'obra_social_mutual' => t("Obra social, mutual"),
			'prepaga' => t("Prepaga"),
			'salud_publica' => t("Cobertura de salud pública (Programas, planes estatales)"),
			),
		);

	$form['columna_izquierda2']['salud_publica']['cual'] = array(
		'#type' => 'textfield',
		'#title' => 'En caso de haber elegido cobertura de salud pública, indiciar cuál:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_centro6']['info_salud_enfermedades']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Enfermedades')."</h2>",
	);

	$form['columna_centro6']['enfermedades'] = array(
		'#type' => 'radios',
		'#title' => 'Poseés alguna discapacidad permanente o enfermedad grave/crónica:',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	$form['columna_centro6']['enfer_cual'] = array(
		'#type' => 'textfield',
		'#title' => '¿Cuál?',
		'#size' => 30,
		'#maxlength' => 100,
		'#attributes' => array(),
		'#states' => array(
		'visible' => array(
		':input[name="enfermedades"]' => array('value' => 'si')
		),
	),
		);

	$form['columna_centro6']['enfermedades_hogar'] = array(
		'#type' => 'radios',
		'#title' => 'Alguien de tu hogar posee alguna discapacidad permanente o enfermedad grave/crónica:',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No"),
			'ns_nr' => t("No sabe/No responde")
			),
		);

	$form['columna_centro6']['enfer_hogar_cual'] = array(
		'#type' => 'textfield',
		'#title' => 'Indique cuál',
		'#size' => 30,
		'#maxlength' => 100,
		'#attributes' => array(),
		'#states' => array(
		'visible' => array(
		':input[name="enfermedades_hogar"]' => array('value' => 'si')
		),
	),
		);

	$form['columna_centro6']['info_salud_adjuntos']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<p class ='fa fa-info-circle'>".t(' Documentación adjuntada: Por cada discapacidad o enfermedad aquí reportada, del adolescente y/o algún inconveniente, deberá adjuntarse el correspondiente certificado.')."</p>",
	);

	//información de trabajo
	$form['columna_centro7']['info_trabajo']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Información de trabajo')."</h2>",
	);

	$form['columna_centro7']['situacion_empleo'] = array(
		'#type' => 'radios',
		'#title' => '¿Te encontrás empleado/a?',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	$form['columna_centro7']['situacion_estado_empleo'] = array(
	'#type' =>'container',
	'#states' => array(
	'visible' => array(
		':input[name="situacion_empleo"]' => array('value' => 'si')
		),
	),
		);

	$form['columna_centro7']['situacion_estado_empleo']['tipo_situacion'] = array(
		'#type' => 'radios',
		'#title' => 'Condición laboral',
		'#attributes' => array(),
		'#options' => array(
			'empleador_patron' => t("Empleador/patrón"),
			'cuenta_propista' => t("Cuenta propista"),
			'temporal' => t("Trabajador temporario/eventual"),
			'dependencia' => t("Empleado en Relación de Dependencia"),
			'domestico' => t("Servicio Doméstico"),
			'monotributo' => t("Monotributo"),
			'voluntariado' => t("Voluntariado"),
			'no_registrado' => t("Empleada/o no registrada/o")
			),
		);

	$form['columna_centro7']['situacion_estado_empleo']['cual_empleo'] = array(
		'#type' => 'textfield',
		'#title' => 'Ocupación principal:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_centro7']['situacion_estado_empleo']['formal'] = array(
		'#type' => 'textarea',
		'#title' => '¿Tu trabajo es Formal o Informal? Tu trabajo, genera aportes jubilatorios? / ¿Te descuentan aportes jubilatorios?',
		'#size' => 30,
		'#maxlength' => 1000,
		);

	$form['columna_centro7']['situacion_estado_empleo_no'] = array(
	'#type' =>'container',
	'#states' => array(
	'visible' => array(
		':input[name="situacion_empleo"]' => array('value' => 'no')
		),
	),
		);

	$form['columna_centro7']['situacion_estado_empleo_no']['buscando'] = array(
		'#type' => 'radios',
		'#title' => '¿Estás buscando trabajo?',
		'#attributes' => array(),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	$form['columna_centro7']['situacion_estado_empleo_no']['alguna'] = array(
		'#type' => 'radios',
		'#title' => '¿Haces habitualmente algunas de las siguientes actividades: cuidar niños, ayudar en la casa con las tareas del hogar o trabajo?',
		'#attributes' => array(),
		'#options' => array(
			'no' => t("No"),
			'20_menos' => t("Si, 20 horas semanales o menos (hasta 4 hs diarias)"),
			'20_mas' => t("Si, más de 20 horas semanales (más de 4 hs diarias)")
			),
		);

	//información de vivienda
	$form['columna_centro8']['info_vivienda']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Información de vivienda')."</h2>",
	);

	$form['columna_izquierda3']['vivienda'] = array(
		'#type' => 'textfield',
		'#title' => 'Calle:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 30]'
			)
		);

	$form['columna_derecha_chica']['altura'] = array(
		'#type' => 'textfield',
		'#title' => 'Altura:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'numeric',
			'length[1, 7]'
			)
		);

	$form['columna_derecha_chica_centro']['piso'] = array(
		'#type' => 'textfield',
		'#title' => 'Piso:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'numeric',
			'length[1, 2]'
			)
		);

	$form['columna_derecha_chica_derecha']['dpto'] = array(
		'#type' => 'textfield',
		'#title' => 'Departamento:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[1, 20]'
			)
		);

	$form['columna_centro8_1']['villa'] = array(
		'#type' => 'textfield',
		'#title' => 'En villa o asentamiento. En caso afirmativo, indica cuál:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica']['manzana'] = array(
		'#type' => 'textfield',
		'#title' => 'Manzana:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica_centro']['casa'] = array(
		'#type' => 'textfield',
		'#title' => 'Casa:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica_derecha']['edificio'] = array(
		'#type' => 'textfield',
		'#title' => 'Edificio:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha_chica2']['habitacion'] = array(
		'#type' => 'textfield',
		'#title' => 'Habitación:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha_chica_centro2']['barrio'] = array(
		'#type' => 'textfield',
		'#title' => 'Barrio:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha_chica_derecha2']['comuna'] = array(
		'#type' => 'textfield',
		'#title' => 'Comuna:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica3']['provincia'] = array(
		'#type' => 'textfield',
		'#title' => 'Provincia:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica_centro3']['municipio'] = array(
		'#type' => 'textfield',
		'#title' => 'Municipio:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_izquierda_chica_derecha3']['localidad'] = array(
		'#type' => 'textfield',
		'#title' => 'Localidad:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha_chica_centro3']['cp'] = array(
		'#type' => 'textfield',
		'#title' => 'CP:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'alpha_numeric',
			'length[1, 10]'
			)
		);

	$form['columna_derecha_chica_derecha3']['fraccion'] = array(
		'#type' => 'textfield',
		'#title' => 'Fracción:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_centro10']['entre_calles'] = array(
		'#type' => 'textfield',
		'#title' => 'Entre calles:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_centro10']['info_vivienda']['tipo'] = array(
		'#type' => 'radios',
		'#title' => 'Tipo de vivienda:',
		'#attributes' => array(),
		'#options' => array(
			'casa' => t("Casa o departamento en zona urbana"),
			'villa' => t("Vivienda en asentamiento o villa"),
			'inquilinato' => t("Inquilinato"),
			'pension' => t("Pieza de hotel/pensión"),
			'hogar' => t("Hogar convivencial"),
			'construccion' => t("Construcción no destinada a la vivienda"),
			'complejo' => t("Complejo habitacional/Vivienda Social"),
			'casilla' => t("Casilla"),
			'rancho' => t("Rancho"),
			'calle' => t("Situación de calle"),
			'movil' => t("Vivienda móvil"),
			'originario' => t("Vivienda de pueblo originario")
			),
		);

	$form['columna_centro10']['info_vivienda']['ambientes'] = array(
		'#type' => 'radios',
		'#title' => '¿Cuántos ambientes tiene la casa?',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'0' => t("Ningun ambiente"),
			'1' => t("Un ambiente"),
			'2' => t("Dos ambientes"),
			'3' => t("Tres ambientes"),
			'4' => t("Cuatro o más ambientes")
			),
		);

	$form['columna_centro10']['info_vivienda']['item_titulo_ambientes'] = array(
	'#type' => 'markup',
	'#markup' => "<p class ='fa fa-info-circle'>".t(' No contar como ambientes: cocina, garaje, patios, lavadero, pasillos ni baños. En caso de tratarse de una vivienda colectiva (pensión, hotel, inquilinato, etc) considerar únicamente la cantidad de ambientes de uso exclusivo del hogar que tiene.')."</p>",
	);

	$form['columna_centro10']['info_vivienda']['dueno_vivienda'] = array(
		'#type' => 'radios',
		'#title' => 'De la vivienda en donde habitás, sos (vos o tu familia):',
		'#attributes' => array(),
		'#options' => array(
			'vivienda_terreno' => t("Propietario/a de la vivienda y el terreno"),
			'vivienda' => t("Propietario/a de la vivienda solamente"),
			'inquilino' => t("Inquilino/a"),
			'trabajo' => t("Tienen vivienda en el lugar de trabajo"),
			'prestamo' => t("Préstamo/Cesión"),
			'ocupante' => t("Ocupante de hecho"),
			'otros' => t("Otros")
			),
		);

	$form['columna_centro10']['otro'] = array(
	'#type' =>'textfield',
	'#title' => 'Especificar:',
	'#size' => 30,
	'#maxlength' => 100,
	'#states' => array(
	'visible' => array(
		':input[name="dueno_vivienda"]' => array('value' => 'otros')
		),
	),
		);

	//Conformación familiar

	$form['columna_centro10']['info_familiar']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Conformación familiar')."</h2>",
	);

	$form['columna_izquierda10']['info_familiar']['cantidad_convivientes'] = array(
        '#type' => 'select',
        '#title' => 'Cantidad de convivientes',
        '#attributes' => array(),
        '#options' => array(
        	'conviviente_cero' => t("0"),
            'conviviente_uno' => t("1"),
            'conviviente_dos' => t("2"),
            'conviviente_tres' => t("3"),
            'conviviente_cuatro' => t("4"),
            'conviviente_cinco' => t("5"),
            'conviviente_seis' => t("6"),
            'conviviente_siete' => t("7"),
            'conviviente_ocho' => t("8"),
            'conviviente_nueve' => t("9"),
            'conviviente_diez' => t("10 o mas"),
            ),
        );


	$form['columna_centro10']['info_familiar']['hijos'] = array(
		'#type' => 'radios',
		'#title' => '¿Hijos?',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No"),
			'esperando' => t("Te encontrás embarazada (si sos mujer) o esperando un bebé (en caso que seas varón)")
			),
		);

	$form['columna_izquierda_chica4']['cuantos'] = array(
	'#type' =>'textfield',
	'#title' => 'Cuántos hijos:',
	'#size' => 30,
	'#maxlength' => 100,
	'#default_value' => '0',
	'#rules' => array(
			'numeric',
			'length[1, 2]'
			),
	'#states' => array(
	'visible' => array(
		':input[name="hijos"]' => array('value' => 'si')
		),
	),
		);

	$form['columna_centro11']['info_familiar']['planes'] = array(
		'#type' => 'radios',
		'#title' => '¿Recibe tu familia planes sociales?',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t("Si"),
			'no' => t("No")
			),
		);

	//Convivientes
	$form['columna_centro11']['info_convivientes']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h3>".t('Convivientes (Jefe/a de hogar)')."</h3>",
	);

	$form['columna_izquierda4_3']['nombre1'] = array(
		'#type' => 'textfield',
		'#title' => 'Nombre:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha2_3']['apellido1'] = array(
		'#type' => 'textfield',
		'#title' => 'Apellido:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha2_2']['edad1'] = array(
		'#type' => 'textfield',
		'#title' => 'Edad:',
		'#size' => 30,
		'#maxlength' => 100,
		'#default_value' => '0',
		);

	$form['columna_derecha2_2_d']['sexo1'] = array(
		'#type' => 'textfield',
		'#title' => 'Sexo:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[1, 50]'
			)
		);

	$form['columna_izquierda5']['conviviente']['educacion1'] = array(
		'#type' => 'select',
		'#title' => 'Educación',
		'#attributes' => array(),
		'#options' => array(
			'jardin' => t("Jardín"),
			'no' => t("No asistió"),
			'primario_incompleto' => t("Primario incompleto"),
			'primario_completo' => t("Primario completo"),
			'primario_asiste' => t("Primario asiste"),
			'secundario_incompleto' => t("Secundario incompleto"),
			'secundario_completo' => t("Secundario completo"),
			'secundario_asiste' => t("Secundario asiste"),
			'terciario_incompleto' => t("Terciario incompleto"),
			'terciario_completo' => t("Terciario completo"),
			'terciario_asiste' => t("Terciario asiste"),
			'universitario_incompleto' => t("Universitario incompleto"),
			'universitario_completo' => t("Universitario completo"),
			'universitario_asiste' => t("Universitario asiste")
			),
		);

	$form['columna_centro13']['cursos_realizados_1'] = array(
		'#type' => 'textarea',
		'#title' => 'Cursos realizados:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha3']['conviviente']['vinculo1'] = array(
		'#type' => 'select',
		'#title' => 'Vínculo',
		'#attributes' => array(),
		'#options' => array(
			'abuelo' => t("Abuelo"),
			'hermano' => t("Hermano/a"),
			'papas' => t("Padre/madre"),
			'no_familiar' => t("No familiar"),
			'pareja' => t("Pareja/Cónyuge"),
			'otro' => t("Otro familiar"),
			'primo' => t("Primo/a"),
			'sobrino' => t("Sobrino/a"),
			'tio' => t("Tío/a"),
			'hijo' => t("Hijo/a")
			),
		);

	$form['columna_centro13']['conviviente']['ocupacion1'] = array(
		'#type' => 'select',
		'#title' => 'Ocupación',
		'#attributes' => array(),
		'#options' => array(
			'cuentrapropista' => t("Cuentrapropista"),
			'hogar' => t("Cuidado del Hogar (ama/o de casa)"),
			'desocupado' => t("Desocupado/a"),
			'domestico' => t("Empleado/a doméstico/a"),
			'no_registrado' => t("Empleado/a no registrado/a"),
			'dependencia' => t("Empleada/o en relación de dependencia"),
			'estudiante' => t("Estudiante"),
			'jubilado' => t("Jubilado/a"),
			'patron' => t("Patrón o empleador/a"),
			'sin_actividad' => t("Sin actividad"),
			'temporal' => t("Trabajador/a temporario o eventual"),
			'monotributo' => t("Monotributo"),
			'voluntariado' => t("Voluntariado")
			),
		);

	//más convivientes
	//segundo

	$form['columna_centro14']['info_convivientes']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h3>".t('Más convivientes')."</h3>",
	);

	$form['columna_izquierda5_3']['nombre2'] = array(
		'#type' => 'textfield',
		'#title' => 'Nombre:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha3_3']['apellido2'] = array(
		'#type' => 'textfield',
		'#title' => 'Apellido:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha3_2']['edad2'] = array(
		'#type' => 'textfield',
		'#title' => 'Edad:',
		'#size' => 30,
		'#maxlength' => 100,
		'#default_value' => '0',
		);

	$form['columna_derecha3_2_d']['sexo2'] = array(
		'#type' => 'textfield',
		'#title' => 'Sexo:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_izquierda7']['conviviente']['educacion2'] = array(
		'#type' => 'select',
		'#title' => 'Educación',
		'#attributes' => array(),
		'#options' => array(
			'jardin' => t("Jardín"),
			'no' => t("No asistió"),
			'primario_incompleto' => t("Primario incompleto"),
			'primario_completo' => t("Primario completo"),
			'primario_asiste' => t("Primario asiste"),
			'secundario_incompleto' => t("Secundario incompleto"),
			'secundario_completo' => t("Secundario completo"),
			'secundario_asiste' => t("Secundario asiste"),
			'terciario_incompleto' => t("Terciario incompleto"),
			'terciario_completo' => t("Terciario completo"),
			'terciario_asiste' => t("Terciario asiste"),
			'universitario_incompleto' => t("Universitario incompleto"),
			'universitario_completo' => t("Universitario completo"),
			'universitario_asiste' => t("Universitario asiste")
			),
		);

	$form['columna_centro16']['cursos_realizados_2'] = array(
		'#type' => 'textarea',
		'#title' => 'Cursos realizados:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha4']['conviviente']['vinculo2'] = array(
		'#type' => 'select',
		'#title' => 'Vínculo',
		'#attributes' => array(),
		'#options' => array(
			'abuelo' => t("Abuelo"),
			'hermano' => t("Hermano/a"),
			'papas' => t("Padre/madre"),
			'no_familiar' => t("No familiar"),
			'pareja' => t("Pareja/Cónyuge"),
			'otro' => t("Otro familiar"),
			'primo' => t("Primo/a"),
			'sobrino' => t("Sobrino/a"),
			'tio' => t("Tío/a"),
			'hijo' => t("Hijo/a")
			),
		);

	$form['columna_centro16']['conviviente']['ocupacion2'] = array(
		'#type' => 'select',
		'#title' => 'Ocupación',
		'#attributes' => array(),
		'#options' => array(
			'cuentrapropista' => t("Cuentrapropista"),
			'hogar' => t("Cuidado del Hogar (ama/o de casa)"),
			'desocupado' => t("Desocupado/a"),
			'domestico' => t("Empleado/a doméstico/a"),
			'no_registrado' => t("Empleado/a no registrado/a"),
			'dependencia' => t("Empleada/o en relación de dependencia"),
			'estudiante' => t("Estudiante"),
			'jubilado' => t("Jubilado/a"),
			'patron' => t("Patrón o empleador/a"),
			'sin_actividad' => t("Sin actividad"),
			'temporal' => t("Trabajador/a temporario o eventual"),
			'monotributo' => t("Monotributo"),
			'voluntariado' => t("Voluntariado")
			),
		);

	//tercero

	$form['columna_centro19']['info_convivientes']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h3>".t('Más convivientes')."</h3>",
	);

	$form['columna_izquierda7_3']['nombre3'] = array(
		'#type' => 'textfield',
		'#title' => 'Nombre:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha5_3']['apellido3'] = array(
		'#type' => 'textfield',
		'#title' => 'Apellido:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_derecha5_2']['edad3'] = array(
		'#type' => 'textfield',
		'#title' => 'Edad:',
		'#size' => 30,
		'#maxlength' => 100,
		'#default_value' => '0',
		);

	$form['columna_derecha5_2_d']['sexo3'] = array(
		'#type' => 'textfield',
		'#title' => 'Sexo:',
		'#size' => 30,
		'#maxlength' => 100,
		'#rules' => array(
			'length[3, 50]'
			)
		);

	$form['columna_izquierda9']['conviviente']['educacion3'] = array(
		'#type' => 'select',
		'#title' => 'Educación',
		'#attributes' => array(),
		'#options' => array(
			'jardin' => t("Jardín"),
			'no' => t("No asistió"),
			'primario_incompleto' => t("Primario incompleto"),
			'primario_completo' => t("Primario completo"),
			'primario_asiste' => t("Primario asiste"),
			'secundario_incompleto' => t("Secundario incompleto"),
			'secundario_completo' => t("Secundario completo"),
			'secundario_asiste' => t("Secundario asiste"),
			'terciario_incompleto' => t("Terciario incompleto"),
			'terciario_completo' => t("Terciario completo"),
			'terciario_asiste' => t("Terciario asiste"),
			'universitario_incompleto' => t("Universitario incompleto"),
			'universitario_completo' => t("Universitario completo"),
			'universitario_asiste' => t("Universitario asiste")
			),
		);

	$form['columna_centro23']['cursos_realizados_3'] = array(
		'#type' => 'textarea',
		'#title' => 'Cursos realizados:',
		'#size' => 30,
		'#maxlength' => 100,
		);

	$form['columna_derecha6']['conviviente']['vinculo3'] = array(
		'#type' => 'select',
		'#title' => 'Vínculo',
		'#attributes' => array(),
		'#options' => array(
			'abuelo' => t("Abuelo"),
			'hermano' => t("Hermano/a"),
			'papas' => t("Padre/madre"),
			'no_familiar' => t("No familiar"),
			'pareja' => t("Pareja/Cónyuge"),
			'otro' => t("Otro familiar"),
			'primo' => t("Primo/a"),
			'sobrino' => t("Sobrino/a"),
			'tio' => t("Tío/a"),
			'hijo' => t("Hijo/a")
			),
		);

	$form['columna_centro23']['conviviente']['ocupacion3'] = array(
		'#type' => 'select',
		'#title' => 'Ocupación',
		'#attributes' => array(),
		'#options' => array(
			'cuentrapropista' => t("Cuentrapropista"),
			'hogar' => t("Cuidado del Hogar (ama/o de casa)"),
			'desocupado' => t("Desocupado/a"),
			'domestico' => t("Empleado/a doméstico/a"),
			'no_registrado' => t("Empleado/a no registrado/a"),
			'dependencia' => t("Empleada/o en relación de dependencia"),
			'estudiante' => t("Estudiante"),
			'jubilado' => t("Jubilado/a"),
			'patron' => t("Patrón o empleador/a"),
			'sin_actividad' => t("Sin actividad"),
			'temporal' => t("Trabajador/a temporario o eventual"),
			'monotributo' => t("Monotributo"),
			'voluntariado' => t("Voluntariado")
			),
		);

	$form['columna_centro23']['submit_button'] = array(
		'#type' => 'submit',
		'#value' => t('Enviar'),
	);

	$form = argentinagobar_radiostyler($form);
  	return $form;

}



function argentinagobar_formularios_casadelfuturo_submit($form, &$form_state) {


	//cálculo final del coeficiente

	// 1) coeficiente escolaridad
	$coeficiente_total = 0;
	$coeficiente_escolaridad = 0;

	if ($form_state['values']['escolaridad'] == "si") {


		$fecha_de_nacimiento = dateToTimeStamp($form_state['values']['fecha_nacimiento']);

		//15 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "2000"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "2001"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 65;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}

		//16 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1999"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "2000"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 70;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 20;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}


		//17 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1998"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1999"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 80;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 45;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 20;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}

		//18 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1997"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1998"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 50;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 45;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 20;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}
		//19 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1996"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1997"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 60;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 50;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 45;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 20;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}
		//20 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1995"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1996"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 70;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 60;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 45;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 20;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 10;
						break;
				}
		}
		//21 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1994"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1995"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 70;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 60;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 45;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 20;
						break;
				}
		}

		//22 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1993"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1994"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 70;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 60;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 45;
						break;
				}
		}
		//23 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1992"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1993"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 70;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 60;
						break;
				}
		}
		//24 años
		$fecha_inicio  = array(
		    "day" => "1",
		    "month" => "7",
		    "year" => "1991"
		);
		$fecha_inicio_stamp = dateToTimeStamp($fecha_inicio);

		$fecha_fin  = array(
		    "day" => "30",
		    "month" => "6",
		    "year" => "1992"
		);
		$fecha_fin_stamp = dateToTimeStamp($fecha_fin);

		if ($fecha_de_nacimiento >= $fecha_inicio_stamp & $fecha_de_nacimiento <= $fecha_fin_stamp){
				switch ($form_state['values']['max_nivel']) {
					case 'primario':
						$coeficiente_escolaridad = 90;
						break;
					case 'primero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'segundo_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'tercero_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'cuarto_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'quinto_secundario':
						$coeficiente_escolaridad = 80;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 70;
						break;
				}
		}

		if ($form_state['values']['modalidad'] == "publica"){
			$coeficiente_escolaridad += 10;
		}elseif ($form_state['values']['modalidad'] == "privada_con_beca"){
			$coeficiente_escolaridad += 5;
		}
	}elseif($form_state['values']['escolaridad'] == "no"){
		switch ($form_state['values']['no_max_nivel']) {
					case 'sin_estudios':
						$coeficiente_escolaridad = 100;
						break;
					case 'primaria_abandonada':
						$coeficiente_escolaridad = 90;
						break;
					case 'primaria':
						$coeficiente_escolaridad = 80;
						break;
					case 'secundaria_abandonada':
						$coeficiente_escolaridad = 70;
						break;
					case 'secundaria':
						$coeficiente_escolaridad = 15;
						break;
					case 'secundaria_materias_pendientes':
						$coeficiente_escolaridad = 60;
						break;
					case 'sexto_secundario':
						$coeficiente_escolaridad = 70;
						break;
				}
	}
	$coeficiente_total += ($coeficiente_escolaridad * 25) / 100;

	//fin coeficiente escolaridad

	// 2) coeficiente salud

	$coeficiente_salud = 0;

	if ($form_state['values']['salud'] == "no"){
		$coeficiente_salud += 40;
	}elseif($form_state['values']['salud'] == "si"){
		if($form_state['values']['tipo_cobertura'] == "salud_publica"){
			$coeficiente_salud += 30;
		}elseif($form_state['values']['tipo_cobertura'] == "obra_social_mutual"){
			$coeficiente_salud += 10;
		}
		}

	if ($form_state['values']['enfermedades'] == "si"){
		$coeficiente_salud += 40;
	}
	if ($form_state['values']['enfermedades_hogar'] == "si"){
		$coeficiente_salud += 20;
	}



	$coeficiente_total += ($coeficiente_salud * 15) / 100;

	//fin coeficiente salud

	// 3) coeficiente socio-laboral
	$coeficiente_socioLaboral = 0;

	if ($form_state['values']['edad_solicitante'] >= 14 & $form_state['values']['edad_solicitante'] <= 17){
		if ($form_state['values']['situacion_empleo'] == "si"){
			$coeficiente_socioLaboral += 55;
		}
	}
	if ($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <= 24){
		if ($form_state['values']['situacion_empleo'] == "no"){
			$coeficiente_socioLaboral += 50;
		}
	}
	if ($form_state['values']['edad_solicitante'] >= 14 & $form_state['values']['edad_solicitante'] <= 17){
		if ($form_state['values']['buscando'] == "si"){
			$coeficiente_socioLaboral += 55;
		}
	}
	if ($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <= 24){
		if ($form_state['values']['buscando'] == "si"){
			$coeficiente_socioLaboral += 45;
		}
	}

	switch ($form_state['values']['tipo_situacion']) {
		case 'domestico':
		case 'temporal':
			$coeficiente_socioLaboral += 35;
		break;
		case 'no_registrado':
		case 'voluntariado':
			$coeficiente_socioLaboral += 45;
		break;
		case 'monotributo':
			$coeficiente_socioLaboral += 25;
		break;
	}

	if($form_state['values']['alguna'] == "20_menos"){
		$coeficiente_socioLaboral += 5;
	}
	if($form_state['values']['alguna'] == "20_mas"){
		$coeficiente_socioLaboral += 10;
	}

	$coeficiente_total += ($coeficiente_socioLaboral * 25) / 100;

	//fin coeficiente socio-laboral

// F

//coeficiente de vivienda

	$coeficiente_condiciones_habitacionales = 0;




				switch ($form_state['values']['tipo']) {
					case 'casa':
						$coeficiente_condiciones_habitacionales = 0;
						break;
					case 'villa':
						$coeficiente_condiciones_habitacionales = 25;
						break;
					case 'inquilinato':
						$coeficiente_condiciones_habitacionales = 15;
						break;
					case 'pension':
						$coeficiente_condiciones_habitacionales = 15;
						break;
					case 'hogar':
						$coeficiente_condiciones_habitacionales = 25;
						break;
					case 'construccion':
						$coeficiente_condiciones_habitacionales = 20;
						break;
					case 'calle':
						$coeficiente_condiciones_habitacionales = 30;
						break;
					case 'complejo':
						$coeficiente_condiciones_habitacionales = 15;
						break;
					case 'casilla':
						$coeficiente_condiciones_habitacionales = 25;
						break;
					case 'rancho':
						$coeficiente_condiciones_habitacionales = 25;
						break;
					// faltan 2 coeficientes no asignados
				}



		switch ($form_state['values']['cantidad_convivientes']) {

			case 'conviviente_uno':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
				}
			break;

			case 'conviviente_dos':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
				}
			break;

			case 'conviviente_tres':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 25;
						break;
				}
			break;

			case 'conviviente_cuatro':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 40;
						break;
				}
			break;

			case 'conviviente_cinco':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 25;
						break;
				}
			break;

			case 'conviviente_seis':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 30;
						break;
				}
			break;

			case 'conviviente_siete':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 75;
						break;
				}
			break;

			case 'conviviente_ocho':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 80;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 80;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 40;
						break;
					case '3':
						$coeficiente_condiciones_habitacionales += 25;
						break;
				}
			break;

			case 'conviviente_nueve':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 90;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 80;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '3':
						$coeficiente_condiciones_habitacionales += 45;
						break;
					case '4':
						$coeficiente_condiciones_habitacionales += 25;
						break;
				}
			break;

			case 'conviviente_diez':
				switch ($form_state['values']['ambientes']) {
					case '0':
						$coeficiente_condiciones_habitacionales += 100;
						break;
					case '1':
						$coeficiente_condiciones_habitacionales += 80;
						break;
					case '2':
						$coeficiente_condiciones_habitacionales += 70;
						break;
					case '3':
						$coeficiente_condiciones_habitacionales += 50;
						break;
					case '4':
						$coeficiente_condiciones_habitacionales += 30;
						break;
				}
			break;

		}




			switch ($form_state['values']['dueno_vivienda']) {
					case 'inquilino':
						$coeficiente_condiciones_habitacionales += 20;
						break;
					case 'prestamo':
						$coeficiente_condiciones_habitacionales += 15;
						break;
					case 'ocupante':
						$coeficiente_condiciones_habitacionales += 15;
						break;
					case 'otros':
						$coeficiente_condiciones_habitacionales += 10;
						break;
						// faltan 3 indices
				}


	//fin coeficiente de vivienda

	//coeficiente de Conformacion familiar

		$menor18=0;
		$coeficiente_conformacion_familiar = 0;
		$bandera_pareja = false;
		$bandera_otro = false;
		$entre25y64 = 0;
		$quien = 0;


		if ($form_state['values']['edad_solicitante'] >= 14 & $form_state['values']['edad_solicitante'] <=17) {

				if ($form_state['values']['edad1'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				if ($form_state['values']['edad2'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				if ($form_state['values']['edad3'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				switch ($menor18){

					case '1':
					$coeficiente_conformacion_familiar += 5;
					break;

					case '2':
					$coeficiente_conformacion_familiar += 10;
					break;

					case '3':
					$coeficiente_conformacion_familiar += 3;
					break;
			}



				if ($menor18 == 1 ){
				$coeficiente_conformacion_familiar +=15;
			}



		}


				if ($form_state['values']['vinculo1'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo2'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo3'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($bandera_pareja == true){

							if ($form_state['values']['edad1'] >= 25 & $form_state['values']['edad1'] <=64 ){
								$entre25y64++;
								}
								if ($form_state['values']['edad2'] >= 25 & $form_state['values']['edad2'] <=64){
									$entre25y64++;
								}
								if ($form_state['values']['edad3'] >= 25 & $form_state['values']['edad3'] <=64){
									$entre25y64++;
								}
								if ($entre25y64 == 0){
									$coeficiente_conformacion_familiar += 12;
								}
					}





		if ($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <=24){

			if ($form_state['values']['edad1'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
			if ($form_state['values']['edad2'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
			if ($form_state['values']['edad3'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				switch ($menor18){

					case '1':
					$coeficiente_conformacion_familiar += 5;
					break;

					case '2':
					$coeficiente_conformacion_familiar += 10;
					break;

					case '3':
					$coeficiente_conformacion_familiar += 3;
					break;;
				}



			if ($menor18 == 0 ){
				$coeficiente_conformacion_familiar += 5;
			}




			if 	($form_state['values']['vinculo1'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo2'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo3'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($bandera_pareja == true){

							if ($form_state['values']['edad1'] >= 25 & $form_state['values']['edad1'] <=64 ){
								$entre25y64++;
								}
								if ($form_state['values']['edad2'] >= 25 & $form_state['values']['edad2'] <=64){
									$entre25y64++;
								}
								if ($form_state['values']['edad3'] >= 25 & $form_state['values']['edad3'] <=64){
									$entre25y64++;
								}
								if ($entre25y64 == 0){
									$coeficiente_conformacion_familiar += 8;
								}
					}


		//chequeo el vinculo OTRO y edad entre 18 y 24


			if 	($form_state['values']['vinculo1'] == "otro"){
				$quien = 1;
			}
					if ($form_state['values']['vinculo2'] == "otro"){
				$quien = 2;
			}
					if ($form_state['values']['vinculo3'] == "otro"){
				$quien = 3;
			}
					switch ($quien) {
						case '1':
							if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24 ){
								$bandera_otro = true;
							}
							break;

						case '2':
							if ($form_state['values']['edad2'] >= 18 & $form_state['values']['edad2'] <= 24 ){
								$bandera_otro = true;
							}
							break;

						case '3':
							if ($form_state['values']['edad3'] >= 18 & $form_state['values']['edad3'] <= 24 ){
								$bandera_otro = true;
							}
							break;
					}

							if ($bandera_otro == true){
								$coeficiente_conformacion_familiar += 10;
							}




			// chequeo si la edad de OTRO es mayor o igual a 64

			$bandera_otro = false;
			$bandera_otro18 = false;



			if 	($form_state['values']['vinculo1'] == "otro"){
				$quien = 1;
			}
					if ($form_state['values']['vinculo2'] == "otro"){
				$quien = 2;
			}
					if ($form_state['values']['vinculo3'] == "otro"){
				$quien = 3;
			}


						switch ($quien) {
						case '1':
							if ($form_state['values']['edad1'] >= 64){
								$bandera_otro = true;
							}
							break;

						case '2':
							if ($form_state['values']['edad2'] >= 64){
								$bandera_otro = true;
							}
							break;

						case '3':
							if ($form_state['values']['edad3'] >= 64){
								$bandera_otro = true;
							}
							break;
						}

							if ($bandera_otro == true){

												if 	($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($bandera_otro18 == true){
													$coeficiente_conformacion_familiar += 10;
												}

							}

		}






		//aca empieza el de 18 a 24

		$bandera_papas = false;


		if ($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <=24) {

				if ($form_state['values']['edad1'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				if ($form_state['values']['edad2'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				if ($form_state['values']['edad3'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				switch ($menor18){

					case '1':
					$coeficiente_conformacion_familiar += 5;
					break;

					case '2':
					$coeficiente_conformacion_familiar += 10;
					break;

					case '3':
					$coeficiente_conformacion_familiar += 3;
					break;
			}



				if ($menor18 == 0 ){
				$coeficiente_conformacion_familiar +=5;
			}

		}


		/*		if ($form_state['values']['vinculo1'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo2'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo3'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($bandera_pareja == true){

							if ($form_state['values']['edad1'] >= 25 & $form_state['values']['edad1'] <=64 ){
								$entre25y64++;
								}
								if ($form_state['values']['edad2'] >= 25 & $form_state['values']['edad2'] <=64){
									$entre25y64++;
								}
								if ($form_state['values']['edad3'] >= 25 & $form_state['values']['edad3'] <=64){
									$entre25y64++;
								}
								if ($entre25y64 == 0){
									$coeficiente_conformacion_familiar += 12;
								}
					}
		*/


		if 	($form_state['values']['vinculo1'] == "papas"){
				$bandera_papas = true;
			}
					if ($form_state['values']['vinculo2'] == "papas"){
				$bandera_papas = true;
			}
					if ($form_state['values']['vinculo3'] == "papas"){
				$bandera_papas = true;
			}
					if ($bandera_pareja == true){
						$coeficiente_conformacion_familiar += 10;
					}





		if ($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <=24){

			if ($form_state['values']['edad1'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
			if ($form_state['values']['edad2'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
			if ($form_state['values']['edad3'] < 18 & $form_state['values']['edad1'] > 0){
				$menor18++;
				}
				switch ($menor18){

					case '1':
					$coeficiente_conformacion_familiar += 5;
					break;

					case '2':
					$coeficiente_conformacion_familiar += 10;
					break;

					case '3':
					$coeficiente_conformacion_familiar += 3;
					break;;
				}



			if ($menor18 == 0 ){
				$coeficiente_conformacion_familiar += 5;
			}




		if 	($form_state['values']['vinculo1'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo2'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($form_state['values']['vinculo3'] == "pareja"){
				$bandera_pareja = true;
			}
					if ($bandera_pareja == true){

							if ($form_state['values']['edad1'] >= 25 & $form_state['values']['edad1'] <=64 ){
								$entre25y64++;
								}
								if ($form_state['values']['edad2'] >= 25 & $form_state['values']['edad2'] <=64){
									$entre25y64++;
								}
								if ($form_state['values']['edad3'] >= 25 & $form_state['values']['edad3'] <=64){
									$entre25y64++;
								}
								if ($entre25y64 == 0){
									$coeficiente_conformacion_familiar += 8;
								}
					}


//chequeo el vinculo OTRO y edad entre 18 y 24


			if 	($form_state['values']['vinculo1'] == "otro"){
				$quien = 1;
			}
					if ($form_state['values']['vinculo2'] == "otro"){
				$quien = 2;
			}
					if ($form_state['values']['vinculo3'] == "otro"){
				$quien = 3;
			}
					switch ($quien) {
						case '1':
							if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24 ){
								$bandera_otro = true;
							}
							break;

						case '2':
							if ($form_state['values']['edad2'] >= 18 & $form_state['values']['edad2'] <= 24 ){
								$bandera_otro = true;
							}
							break;

						case '3':
							if ($form_state['values']['edad3'] >= 18 & $form_state['values']['edad3'] <= 24 ){
								$bandera_otro = true;
							}
							break;
					}

							if ($bandera_otro == true){
								$coeficiente_conformacion_familiar += 10;
							}




$bandera_otro = false;



			if 	($form_state['values']['vinculo1'] == "otro"){
				$quien = 1;
			}
					if ($form_state['values']['vinculo2'] == "otro"){
				$quien = 2;
			}
					if ($form_state['values']['vinculo3'] == "otro"){
				$quien = 3;
			}
					switch ($quien) {
						case '1':
							if ($form_state['values']['edad1'] >= 24 & $form_state['values']['edad1'] <= 64 ){
								$bandera_otro = true;
							}
							break;

						case '2':
							if ($form_state['values']['edad2'] >= 24 & $form_state['values']['edad2'] <= 64 ){
								$bandera_otro = true;
							}
							break;

						case '3':
							if ($form_state['values']['edad3'] >= 24 & $form_state['values']['edad3'] <= 64 ){
								$bandera_otro = true;
							}
							break;
					}

							if ($bandera_otro == true){
								$coeficiente_conformacion_familiar += 10;
							}





// chequeo si la edad de OTRO es mayor o igual a 64

$bandera_otro = false;
$bandera_otro18 = false;

			if 	($form_state['values']['vinculo1'] == "otro"){
				$quien = 1;
			}
					if ($form_state['values']['vinculo2'] == "otro"){
				$quien = 2;
			}
					if ($form_state['values']['vinculo3'] == "otro"){
				$quien = 3;
			}


						switch ($quien) {
						case '1':
							if ($form_state['values']['edad1'] >= 64){
								$bandera_otro = true;
							}
							break;

						case '2':
							if ($form_state['values']['edad2'] >= 64){
								$bandera_otro = true;
							}
							break;

						case '3':
							if ($form_state['values']['edad3'] >= 64){
								$bandera_otro = true;
							}
							break;
						}

							if ($bandera_otro == true){

												if 	($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($form_state['values']['edad1'] >= 18 & $form_state['values']['edad1'] <= 24){
													$bandera_otro18 = true;
												}
												if ($bandera_otro18 == true){
													$coeficiente_conformacion_familiar += 10;
												}

							}





		}









		if ($form_state['values']['hijos'] == "esperando"){

			if($form_state['values']['edad_solicitante'] >= 14 & $form_state['values']['edad_solicitante'] <=17){
					$coeficiente_conformacion_familiar += 25;
				}

			if($form_state['values']['edad_solicitante'] >= 18 & $form_state['values']['edad_solicitante'] <=24){
					$coeficiente_conformacion_familiar += 10;
				}
		}




	// nivel educacion

 $cantconvi = 0;

	if ($form_state['values']['nombre1'] != NULL){
		$cantconvi++;
	}


				switch ($form_state['values']['ocupacion1']) {
					case 'hogar':
					case 'desocupado':
					case 'sin_actividad':
					case 'voluntariado':
						$coeficiente_condiciones_habitacionales += 25;
						break;
					case 'no_registrado';
					case 'monotributo';
						$coeficiente_condiciones_habitacionales += 15;
						break;
					case 'domestico';
					case 'jubilado';
					case 'temporal';
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'estudiante';
						$coeficiente_condiciones_habitacionales += 5;
						break;
				}


				switch ($form_state['values']['educacion1']){
					case 'no':
					case 'primario_incompleto':
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'primario_completo';
						$coeficiente_condiciones_habitacionales += 6;
						break;
					case 'secundario_incompleto';
						$coeficiente_condiciones_habitacionales += 4;
						break;
					case 'secundario_completo';
						$coeficiente_condiciones_habitacionales += 2;
						break;
					case 'terciario_incompleto';
						$coeficiente_condiciones_habitacionales += 1;
						break;
				}




if ($form_state['values']['nombre2'] != NULL){
		$cantconvi++;
}

				switch ($form_state['values']['ocupacion1']) {
					case 'hogar':
					case 'desocupado':
					case 'sin_actividad':
					case 'voluntariado':
						$coeficiente_condiciones_habitacionales += 25;
						break;
					case 'no_registrado';
					case 'monotributo';
						$coeficiente_condiciones_habitacionales += 15;
						break;
					case 'domestico';
					case 'jubilado';
					case 'temporal';
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'estudiante';
						$coeficiente_condiciones_habitacionales += 5;
						break;
				}


				switch ($form_state['values']['educacion1']){
					case 'no':
					case 'primario_incompleto':
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'primario_completo';
						$coeficiente_condiciones_habitacionales += 6;
						break;
					case 'secundario_incompleto';
						$coeficiente_condiciones_habitacionales += 4;
						break;
					case 'secundario_completo';
						$coeficiente_condiciones_habitacionales += 2;
						break;
					case 'terciario_incompleto';
						$coeficiente_condiciones_habitacionales += 1;
						break;
				}




if ($form_state['values']['nombre3'] != NULL){
		$cantconvi++;

}
				switch ($form_state['values']['ocupacion1']) {
					case 'hogar':
					case 'desocupado':
					case 'sin_actividad':
					case 'voluntariado':
						$coeficiente_condiciones_habitacionales += 25;
						break;
					case 'no_registrado';
					case 'monotributo';
						$coeficiente_condiciones_habitacionales += 15;
						break;
					case 'domestico';
					case 'jubilado';
					case 'temporal';
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'estudiante';
						$coeficiente_condiciones_habitacionales += 5;
						break;
				}

				switch ($form_state['values']['educacion1']){
					case 'no':
					case 'primario_incompleto':
						$coeficiente_condiciones_habitacionales += 10;
						break;
					case 'primario_completo';
						$coeficiente_condiciones_habitacionales += 6;
						break;
					case 'secundario_incompleto';
						$coeficiente_condiciones_habitacionales += 4;
						break;
					case 'secundario_completo';
						$coeficiente_condiciones_habitacionales += 2;
						break;
					case 'terciario_incompleto';
						$coeficiente_condiciones_habitacionales += 1;
						break;
				}








   // planes sociales



		if ($form_state['values']['planes'] == "si"){
				$coeficiente_conformacion_familiar += 15;
		}

	//fin coeficiente de Conformacion familiar
// fin F
	$coeficiente_total += ($coeficiente_condiciones_habitacionales * 20) / 100;
	$coeficiente_total += ($coeficiente_conformacion_familiar * 15) / 100;


	//guardado de campos en la base de datos


	/*
	$database_info = array(
	  'host' => '192.168.30.7',
	  'database' => 'formularios_externos',
	  'username' => 'externos',
	  'password' => 'externosargentina',
	  'driver' => 'mysql',
	);

	Database::addConnectionInfo('conexion', 'formularios_externos', $database_info);
	*/

	$string_fecha_nacimiento = implode("/", $form_state['values']['fecha_nacimiento']);
	db_set_active('formularios');


	$insert = db_insert('casas_del_futuro')
		->fields(array(
			'nombre_apellido' => $form_state['values']['nombre_apellido'],
			'identidad_de_genero' => $form_state['values']['identidad_de_genero'],
			'nacionalidad' => $form_state['values']['nacionalidad'],
			'numero_cuil' => $form_state['values']['numero_cuil'],
			'edad_solicitante' => $form_state['values']['edad_solicitante'],
			'estado_civil' => $form_state['values']['estado_civil'],
			'telefono_fijo' => $form_state['values']['telefono_fijo'],
			'telefono_celular' => $form_state['values']['telefono_celular'],
			'mail' => $form_state['values']['mail'],
			'fecha_nacimiento' => $string_fecha_nacimiento,
			'tipo_documento' => $form_state['values']['tipo_documento'],
			'numero_documento' => $form_state['values']['numero_documento'],
			'escolaridad' => $form_state['values']['escolaridad'],
			'modalidad' => $form_state['values']['modalidad'],
			'turno' => $form_state['values']['turno'],
			'nivel' => $form_state['values']['nivel'],
			'max_nivel' => $form_state['values']['max_nivel'],
			'no_max_nivel' => $form_state['values']['no_max_nivel'],
			'salud' => $form_state['values']['salud'],
			'tipo_cobertura' => $form_state['values']['tipo_cobertura'],
			'cual' => $form_state['values']['cual'],
			'enfermedades' => $form_state['values']['enfermedades'],
			'enfer_cual' => $form_state['values']['enfer_cual'],
			'enfermedades_hogar' => $form_state['values']['enfermedades_hogar'],
			'enfer_hogar_cual' => $form_state['values']['enfer_hogar_cual'],
			'situacion_empleo' => $form_state['values']['situacion_empleo'],
			'tipo_situacion' => $form_state['values']['tipo_situacion'],
			'cual_empleo' => $form_state['values']['cual_empleo'],
			'formal' => $form_state['values']['formal'],
			'buscando' => $form_state['values']['buscando'],
			'alguna' => $form_state['values']['alguna'],
			'calle' => $form_state['values']['vivienda'],
			'altura' => $form_state['values']['altura'],
			'piso' => $form_state['values']['piso'],
			'dpto' => $form_state['values']['dpto'],
			'villa' => $form_state['values']['villa'],
			'manzana' => $form_state['values']['manzana'],
			'casa' => $form_state['values']['casa'],
			'edificio' => $form_state['values']['edificio'],
			'habitacion' => $form_state['values']['habitacion'],
			'barrio' => $form_state['values']['barrio'],
			'comuna' => $form_state['values']['comuna'],
			'provincia' => $form_state['values']['provincia'],
			'municipio' => $form_state['values']['municipio'],
			'localidad' => $form_state['values']['localidad'],
			'cp' => $form_state['values']['cp'],
			'fraccion' => $form_state['values']['fraccion'],
			'entre_calles' => $form_state['values']['entre_calles'],
			'tipo' => $form_state['values']['tipo'],
			'ambientes' => $form_state['values']['ambientes'],
			'dueno_vivienda' => $form_state['values']['dueno_vivienda'],
			'otro' => $form_state['values']['otro'],
			'cantidad_convivientes' => $form_state['values']['cantidad_convivientes'],
			'hijos' => $form_state['values']['hijos'],
			'cuantos' => $form_state['values']['cuantos'],
			'planes' => $form_state['values']['planes'],
			'nombre1' => $form_state['values']['nombre1'],
			'apellido1' => $form_state['values']['apellido1'],
			'edad1' => $form_state['values']['edad1'],
			'sexo1' => $form_state['values']['sexo1'],
			'educacion1' => $form_state['values']['educacion1'],
			'vinculo1' => $form_state['values']['vinculo1'],
			'ocupacion1' => $form_state['values']['ocupacion1'],
			'nombre2' => $form_state['values']['nombre2'],
			'apellido2' => $form_state['values']['apellido2'],
			'edad2' => $form_state['values']['edad2'],
			'sexo2' => $form_state['values']['sexo2'],
			'educacion2' => $form_state['values']['educacion2'],
			'vinculo2' => $form_state['values']['vinculo2'],
			'ocupacion2' => $form_state['values']['ocupacion2'],
			'nombre3' => $form_state['values']['nombre3'],
			'apellido3' => $form_state['values']['apellido3'],
			'edad3' => $form_state['values']['edad3'],
			'sexo3' => $form_state['values']['sexo3'],
			'educacion3' => $form_state['values']['educacion3'],
			'vinculo3' => $form_state['values']['vinculo3'],
			'ocupacion3' => $form_state['values']['ocupacion3'],
			'cursos_realizados' => $form_state['values']['cursos_realizados'],
			'max_nivel_alcanzado_2016' => $form_state['values']['max_nivel_alcanzado_2016'],
			'cursos_realizados_1' => $form_state['values']['cursos_realizados_1'],
			'cursos_realizados_2' => $form_state['values']['cursos_realizados_2'],
			'cursos_realizados_3' => $form_state['values']['cursos_realizados_3'],
			'coef_total' => $coeficiente_total,

		)
	)
			->execute();
			db_set_active();






			/*
			coef_escolaridad
			coef_salud
			coef_laboral
			coef_habitacionales
			coef_familiar
			coef_total
			*/

		drupal_set_message(t("Coeficiente total: " . $coeficiente_total), 'status');

	}

function dateToTimeStamp($fecha){
	return strtotime($fecha['year'] . '-' . $fecha['month'] . '-' . $fecha['day']);
}

/*
Usuarios con acceso al nodo:

Ezequiel Ventriglia (e.ventriglia@gmail.com)
Clara Maldonado (claravmaldonado@gmail.com)
Anabel Lamazou (anabellamazouts@gmail.com)
Sofia Pal (sofiagustinapal@gmail.com)
Victoria Muller (mullerv94@gmail.com)
Paula Castro (castromariapaula@gmail.com)
Fatima Lindo (fatima.lindo25@gmail.com)


eventriglia		Drupal2016
claravmaldonado	Drupal2016
anabellamazouts	Drupal2016
sofiagustinapal Drupal2016
vmuller			Drupal2016
pcastro         Drupal2016
fatimalindo		Drupal2016
*/
