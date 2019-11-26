<?php
function argentinagobar_formularios_postulaciones($form, &$form_state) {
$requerido = TRUE	;

$form['contenedor'] = array(
	'#type' => 'container',
	'#attributes' => array(
		'id' => 'contenedor',
		)
	);


 $form['columna_centro'] = array(
 	'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-12'
			)
		)
 	);

	$form['columna_izquierda'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
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

$form['columna_derecha'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
	);

$form['columna_derecha2'] = array(
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
				'col-xs-12', 'col-sm-12'
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


	$form['columna_izquierda3'] = array(
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

	$form['columna_derecha4'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'class' => array(
				'col-xs-12', 'col-sm-6'
			)
		)
	);

	$form['contenedor']['columna_centro']['datos_personales'] = array(
		'#type' => 'container',
		'#attributes' => array(
			)
	);

	$form['contenedor']['columna_centro']['datos_personales']['item_titulo'] = array(
		'#type' => 'markup',
		'#markup' => "<h2>".t('Datos Personales')."</h2><p>". t("Agregá tu información personal para ser parte de nuestra base de datos")."</p>" ."<p>" . t("(*) Campos obligatorios para completar.") . "</p>",
	);

// step 1 - Datos Personales ###################
	// Preg1.1 Apellido



	 	$form['contenedor']['columna_izquierda2']['datos_personales']['nombres'] = array(
		//'#element_validate'=> array('element_validate_integer_positive'),
		'#type' => 'textfield',
		'#title' => 'Nombres',
		'#size' => 10,
		'#maxlength' => 100,
	  '#required' => $requerido,
		'#rules' => array(
			'length[2, 50]',
			'texto_con_espacios',
	),'#filters' => array(
		'trim',

	),
		'#default_value' => autocompletarCiudadanoDigital('given_name')
	);




	$form['contenedor']['columna_izquierda']['datos_personales']['apellido'] = array(
		'#type' => 'textfield',
		'#title' => 'Apellido',
		'#size' => 30,
		'#maxlength' => 100,
	  '#required' => $requerido,
		'#rules' => array(
			'length[2, 50]',
			'texto_con_espacios',
	),'#filters' => array(
		'trim',

			),
		'#default_value' => autocompletarCiudadanoDigital('family_name')
	);



	$form['contenedor']['columna_derecha']['datos_personales']['telefono'] = array(
		'#type' => 'textfield',
		'#title' => 'Teléfono',
		'#size' => 30,
		'#maxlength' => 15,
		'#required' => $requerido,
		'#rules' => array('numeric', 'length[6, 15]'),
		);


	$form['contenedor']['columna_derecha']['datos_personales']['dni'] = array(
		'#type' => 'textfield',
		'#title' => 'DNI',
		'#size' => 30,
		'#maxlength' => 8,
		'#required' => $requerido,
		'#rules' => array('numeric', 'length[6, 8]'),
		);

		$form['contenedor']['columna_derecha2']['datos_personales']['mail'] = array(
 		'#type' => 'textfield',
 		'#title' => 'Correo Electrónico',
 		'#size' => 10,
		'#maxlength' => 100,
		'#required' => $requerido,
		'#rules' => array('email'),
		'#default_value' => autocompletarCiudadanoDigital('email')
 		);

	$form['contenedor']['columna_centro2']['datos_personales']['pais_residencia'] = array(
		'#type' => 'radios',
		'#title' => 'País de residencia',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'argentina' => t("Argentina"),
			'otro_pais' => t("Otro País")
			),

	);


$form['contenedor']['columna_centro2']['datos_personales']['provincia'] = array(
		'#type'=> 'select',
		'#title'=>t("Provincia de residencia actual"),
		'#options' => array(
      'buenos_aires'=> t("Buenos Aires"),
			'capital_federal' => t("Capital Federal"),
			'catamarca'=> t("Catamarca"),
			'chaco'=> t("Chaco"),
			'chubut'=> t("Chubut"),
			'cordoba'=> t("Córdoba"),
			'corrientes'=> t("Corrientes"),
			'entre_rios'=> t("Entre Ríos"),
			'formosa'=> t("Formosa"),
			'jujuy'=> t("Jujuy"),
			'la_pampa'=> t("La Pampa"),
			'la_rioja'=> t("La Rioja"),
			'mendoza'=> t("Mendoza"),
			'misiones'=> t("Misiones"),
			'neuquen'=> t("Neuquén"),
			'rio_negro'=> t("Río Negro"),
			'salta'=> t("Salta"),
			'san_juan'=> t("San Juan"),
			'san_luis'=> t("San Luís"),
			'santa_cruz'=> t("Santa Cruz"),
			'santa_fe'=> t("Santa Fe"),
			'santiago_del_estero'=> t("Santiago del Estero"),
			'tierra_del_fuego'=> t("Tierra del Fuego"),
			'tucuman'=> t("Tucumán"),
			),
			'#states' => array(
			'visible' => array(
        ':input[name="pais_residencia"]' => array('value' => 'argentina'),
				),
			),
		);


	$form['contenedor']['columna_centro2']['datos_personales']['pais'] = array(
		'#title' => t("¿Qué país?"),
		'#type' => 'textfield',
		'#size' => 30,
		'#maxlength' => 100,
		'#description' => t('Recordá que necesitás tener ciudadanía argentina o visa de trabajo para poder postularte'),
		'#states' => array(
			'visible' => array(
        ':input[name="pais_residencia"]' => array('value' => 'otro_pais'),
				),
			),
		);

	$form['contenedor']['columna_centro2']['datos_personales']['localidad'] = array(
		'#title' => t("Localidad/Municipio de residencia actual"),
		'#type' => 'textfield',
		'#size' => 30,
		'#maxlength' => 50,
		'#states' => array(
			'visible' => array(
        ':input[name="pais_residencia"]' => array('value' => 'argentina'),
				),
			),
		);

		// Preg1.5 Fecha de nacimiento
	$form['contenedor']['columna_centro2']['datos_personales']['fecha_nacimiento'] = array(
		'#type' => 'date',
		'#title' => 'Fecha de Nacimiento',
		 '#date_format' => 'd-m-Y',
		'#default_value' => formatearFecha(autocompletarCiudadanoDigital('birthdate'))
	);


	 $form['contenedor']['columna_centro2']['datos_personales']['genero'] = array(
			'#title' => t("Género"),
			'#type' => 'radios',
			'#theme' => array('form_element_radios_btn'),
			'#options' => array(
				'M' => t("Masculino"),
				'F' => t("Femenino"),
				'O' => t("Otro"),
			),
			'#default_value' => autocompletarCiudadanoDigital('gender')
		);


$form['contenedor']['columna_centro2']['separador'] = array(
	'#type' => 'markup',
	'#markup' => "<hr>",
	);

$form['contenedor']['columna_centro2']['educacion'] = array(
		'#type' => 'container',
		'#attributes' => array()
	);

$form['contenedor']['columna_centro2']['educacion']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Educación')."</h2><p>". t("Describinos tu perfil académico.")."</p>" ,
	);

 $form['contenedor']['columna_centro2']['educacion']['nivel_de_estudio'] = array(
		'#title' => t("Maximo nivel alcanzado"),
		'#type' => 'select',
		'#options' => array(
			'No Especifica' => t("No Especifica"),
			'secundaria_completo'=> t("Secundaria Completo"),
			'terciario_incompleto' => t("Terciario Incompleto"),
			'terciario_completo' => t("Terciario Completo"),
			'universitario_incompleto' => t("Universitario Incompleto"),
			'universitario_completo' => t("Universitario Completo"),
			'especializacion_completo' => t("Especialización Completo"),
			'maestria_completo' => t("Maestría Completo"),
			'doctorado_completo' => t("Doctorado Completo"),
		)
	);



$form['contenedor']['columna_centro2']['educacion']['titulo_obtenido'] = array(
		'#title' => t("Título Completo"),
		'#type' => 'textfield',
		'#size' => 30,
		'#maxlength' => 50,
		'#rules' => array(
			'length[2, 50]',
			'texto_con_espacios',
	),'#filters' => array(
		'trim',

	),
		);



	$form['contenedor']['columna_centro2']['educacion']['area_de_estudio']= array(
		'#title'=> t('Área de Estudio del máximo nivel alcanzado'),
		'#type' => 'select',
  		'#options' => array(
  			'elegir' => t("No Especifica"),
  			'opcion_actuario'=> t("Actuario"),
  			'acuicultura'=> t('Acuicultura'),
  			'adm_agropecuaria'=> t('Adm. Agropecuaria'),
  			'adm_de_empresas'=> t('Adm. de Empresas'),
  			'adm_y_gestion_publica'=> t('Adm. Y Gestión Pública'),
  			'agrimensor'=> t('Agrimensor'),
  			'analisis_de_sistemas'=> t('Análisis de Sistemas'),
  			'antropologia'=> t('Antropología'),
  			'arqueologia'=> t('Arqueología'),
  			'arquitectura'=> t('Arquitectura'),
  			'astronomia'=> t('Astronomía'),
  			'bacteriologia'=> t('Bacteriología'),
  			'bellas_artes'=> t('Bellas Artes'),
  			'bibliotecologia'=> t('Bibliotecología'),
  			'biofisica'=> t('Biofísica'),
  			'bioingenieria'=> t('Bioingenieria'),
  			'biologia'=> t('Biología'),
  			'bioquimica'=> t('Bioquímica'),
  			'cartografia'=> t('Cartografía'),
  			'ceremonial_y_protocolo'=> t('Ceremonial y Protocolo'),
  			'ciencias_de_la_educacion'=> t('Ciencias de la Educación'),
  			'ciencias_fisicas'=> t('Ciencias Físicas'),
  			'ciencias_politicas'=> t('Ciencias Políticas'),
  			'comercio_internacional_exterior'=> t('Comercio Internacional/Exterior'),
  			'computacion'=> t('Computación'),
  			'comunicacion_audiovisual'=> t('Comunicación Audiovisual'),
  			'comunicacion_social'=> t('Comunicación Social'),
  			'contabilidad_aditoria'=> t('Contabilidad/Auditoria'),
  			'derecho'=> t('Derecho'),
  			'derecho_esp_administrativo'=> t('Derecho esp. Administrativo'),
  			'derecho_esp_ambiental'=> t('Derecho esp. Ambiental'),
  			'derecho_esp_civil'=> t('Derecho esp. Civil'),
  			'derecho_esp_administrativo'=> t('Derecho esp. Administrativo'),
  			'derecho esp_laboral'=> t('Derecho esp. Laboral'),
  			'derecho_esp_penal'=> t('Derecho esp. Penal'),
  			'derecho_esp_societario'=> t('Derecho esp. Societario'),
  			'derecho_espt_ributario'=> t('Derecho esp. Tributario Electrónica'),
  			'dibujo_tecnico'=> t('Dibujo Técnico'),
  			'disenio_de_imagen_y_sonido'=> t('Diseño de Imagen y Sonido Mecánica'),
  			'disenio_de_vestuario_textil_moda'=> t('Diseño de Vestuario/Téxtil/Moda'),
  			'disenio_grafico'=> t('Diseño Gráfico'),
  			'diseño_industrial'=> t('Diseño Industrial'),
  			'diseño_multimedial'=> t('Diseño Multimedial'),
  			'diseño_web'=> t('Diseño Web'),
  			'ecologia'=> t('Ecología'),
  			'economia'=> t('Economía'),
  			'editor'=> t('Editor'),
  			'educacion'=> t('Educación'),
  			'educacion_fisica'=> t('Educación Física'),
  			'enfermeria'=> t('Enfermeria'),
  			'enologia'=> t('Enología'),
  			'escribania'=> t('Escribanía'),
  			'farmacia'=> t('Farmacia'),
  			'filosofia'=> t('Filosofía'),
  			'finanzas'=> t('Finanzas'),
  			'fisioterapia'=> t('Fisioterapia'),
  			'fonoaudiologia'=> t('Fonoaudiología'),
  			'fotografia'=> t('Fotografía'),
  			'gastronomia_cocina'=> t('Gastronomía/Cocina'),
  			'geofisica'=> t('Geofísica'),
  			'geografia'=> t('Geografía'),
  			'geologia_geomensura_topografia'=> t('Geología/Geomensura/Topografía'),
  			'higiene_y_seguridad_en_el_trabajo' => ('Higiene y Seguridad en el Trabajo'),
  			'histopatologia' => t('Histopatología'),
  			'historia' => t('Historia'),
  			'hoteleria' => t('Hotelería'),
  			'ing_aeroespacial' => ('Ing. Aeroespacial'),
  			'ing_aeronautica' => t('Ing. Aeronautica'),
  			'ing_aronoma_agropecuaria' => t('Ing. Agronoma/Agropecuaria'),
  			'ing_alimentos' => t('Ing. Alimentos'),
  			'ing_ambiental' => t('Ing. Ambiental'),
  			'ing_civil' => t('Ing. Civil'),
  			'ing_electrica' => t('Ing. Electrica'),
  			'ing_electromecanica' => t ('Ing. Electromecánica'),
  			'ing_electronica' => t('Ing. Electrónica'),
  			'ing_en_mineria' => t('Ing. en Minería'),
  			'ing_forestal' => t('Ing. Forestal'),
  			'ing_hidraulica' => t('Ing. Hidráulica'),
  			'ing_industrial' => t('Ing. Industrial'),
  			'ing_informatica_sistemas' => t('Ing. Informática/Sistemas'),
  			'ing_matematica' => t('Ing. Matemática'),
  			'ing_materiales' => t('Ing. Materiales'),
  			'ing_mecanica_metalurgica' => t('Ing. Mecánica/Metalurgica'),
  			'ing_mecatronica' => t('Ing. Mecatrónica'),
  			'ing_naval' => t('Ing. Naval'),
  			'ing_nuclear' => t('Ing. Nuclear'),
  			'ing_pesquera_cultivos_marinos' => t('Ing. Pesquera/Cultivos Marinos'),
  			'ing_petroleo' => t('Ing. Petróleo'),
  			'ing_quimica' => t('Ing. Química'),
  			'ing_recursos_hidricos' => t('Ing. Recursos Hidricos'),
  			'ing_sonido' => t('Ing. Sonido'),
  			'ing_telecomunicaciones' => t('Ing. Telecomunicaciones'),
  			'ing_textil' => t('Ing. Textil'),
  			'interprete' => t('Intérprete'),
  			'kinesiologia' => t('Kinesiología'),
  			'letras' => t('Letras'),
  			'literatura' => t('Literatura'),
  			'marketing_comercializacion' => t('Marketing/Comercialización'),
  			'martillero_publico_tasador_corredor' => t('Martillero Público/Tasador/Corredor'),
  			'matematicas' => t('Matemáticas'),
  			'medicina' => t('Medicina'),
  			'medio_ambiente' => t('Medio Ambiente'),
  			'microbiologia' => t('Microbiología'),
  			'musica' => t('Música'),
  			'negociacion' => t('Negociación'),
  			'nutricion' => t('Nutrición'),
  			'oceanografia' => t('Oceanografía'),
  			'odontologia' => t('Odontología'),
  			'organizacion_de_eventos' => t('Organización de Eventos'),
  			'organizacion_industrial' => t('Organización Industrial'),
				'otro' => t('Otro'),
  			'paisajismo' => t('Paisajismo'),
  			'periodismo' => t('Periodismo'),
  			'programacion' => t('Programación'),
  			'psicologia' => t('Psicología'),
  			'psicopedagogia' => t('Psicopedagogía'),
  			'publicidad' => t('Publicidad'),
  			'quimica' => t('Química'),
  			'quimico_farmaceutico' => t('Químico Farmaceútico'),
  			'recursos_humanos_relaciones_laborales' => t('Recursos Humanos/Relaciones Laborales'),
  			'redes' => t('Redes'),
  			'relaciones_institucionales' => t('Relaciones Institucionales'),
  			'relaciones_internacionales'=> t('Relaciones Internacionales'),
  			'relaciones_publicas' => t('Secretariado'),
  			'seguridad' => t('Seguridad'),
  			'seguridad_industrial' => t('Seguridad Industrial'),
  			'sistemas_de_informacion' => t('Sistemas de Información'),
  			'sistemas_tecnologia' => t('Sistemas/Tecnología'),
  			'sociologia' => t('Sociología'),
  			'tecn_electricidad' => t('Tecn. Electricidad'),
  			'tecn_electronica'=> t('Tecn. Electrónica'),
  			'tecn_mecanica' => t('Tecn. Mecánica'),
  			'tecn_optico' => t('Tecn. Óptico'),
  			'tecn_telecomunicaciones' => t('Tecn. Telecomunicaciones'),
  			'tecnico'=> t('Técnico'),
  			'tecnologia_de_alimentos' => t('Tecnología de Alimentos'),
  			'terapia_ocupacional' => t('Terapia Ocupacional'),
  			'trabajo_social'=> t('Trabajo Social'),
  			'traduccion' => t('Traducción'),
  			'transporte' => t('Transporte'),
  			'turismo' => t('Turismo'),
  			'veterinaria' => t('Veterinaria')
  			),
		'#states' => array(
			'visible' => array(
				array(
					':input[name="nivel_de_estudio"]' => array('value' => 'especializacion_completo'),
					),
					array(
						':input[name="nivel_de_estudio"]' => array('value' => 'especializacion_incompleto'),
						),
				array(
					':input[name="nivel_de_estudio"]' => array('value' => 'universitario_completo'),
					),
					array(
						':input[name="nivel_de_estudio"]' => array('value' => 'universitario_incompleto'),
						),
				array(
					':input[name="nivel_de_estudio"]' => array('value' => 'posgrado_completo'),
					),
					array(
						':input[name="nivel_de_estudio"]' => array('value' => 'posgrado_incompleto'),
						),
				array(
					':input[name="nivel_de_estudio"]' => array('value' => 'maestria_completo'),
					),
					array(
						':input[name="nivel_de_estudio"]' => array('value' => 'maestria_incompleto'),
						),
					array(
					':input[name="nivel_de_estudio"]' => array('value' => 'doctorado_completo'),
					),
					array(
					':input[name="nivel_de_estudio"]' => array('value' => 'doctorado_incompleto'),
					),
				)
			)
  	);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


$form['contenedor']['columna_centro2']['educacion']['otro_estudio'] = array(
	'#type' => 'fieldset',
	'#title' => t('Si querés podes agregar otro estudio que tengas'),
	 '#collapsible' => TRUE,
	   '#collapsed' => TRUE
	);

$form['contenedor']['columna_centro2']['educacion']['otro_estudio']['nivel_de_estudio2'] = array(
		'#title' => t("Otro Estudio a Destacar"),
		'#type' => 'select',
		'#options' => array(
			'elegir' => t("No Especifica"),
			'universitario_completo' => t("Universitario Completo"),
			'especializacion_completo' => t("Especialización Completo"),
			'maestria_completo' => t("Maestría Completo"),
			'doctorado_completo' => t("Doctorado Completo"),
		)
	);



$form['contenedor']['columna_centro2']['educacion']['otro_estudio']['titulo_obtenido2'] = array(
		'#title' => t("Título Completo"),
		'#type' => 'textfield',
		'#size' => 30,
		'#maxlength' => 50,
		'#rules' => array(
			'texto_con_espacios'
			),
		);




	$form['contenedor']['columna_centro2']['educacion']['otro_estudio']['area_de_estudio2']= array(
		'#title'=> t('Área de Estudio'),
		'#type' => 'select',
  		'#options' => array(
  			'elegir' => t("No Especifica"),
  			'opcion_actuario'=> t("Actuario"),
  			'acuicultura'=> t('Acuicultura'),
  			'adm_agropecuaria'=> t('Adm. Agropecuaria'),
  			'adm_de_empresas'=> t('Adm. de Empresas'),
  			'adm_y_gestion_publica'=> t('Adm. Y Gestión Pública'),
  			'agrimensor'=> t('Agrimensor'),
  			'analisis_de_sistemas'=> t('Análisis de Sistemas'),
  			'antropologia'=> t('Antropología'),
  			'arqueologia'=> t('Arqueología'),
  			'arquitectura'=> t('Arquitectura'),
  			'astronomia'=> t('Astronomía'),
  			'bacteriologia'=> t('Bacteriología'),
  			'bellas_artes'=> t('Bellas Artes'),
  			'bibliotecologia'=> t('Bibliotecología'),
  			'biofisica'=> t('Biofísica'),
  			'bioingenieria'=> t('Bioingenieria'),
  			'biologia'=> t('Biología'),
  			'bioquimica'=> t('Bioquímica'),
  			'cartografia'=> t('Cartografía'),
  			'ceremonial_y_protocolo'=> t('Ceremonial y Protocolo'),
  			'ciencias_de_la_educacion'=> t('Ciencias de la Educación'),
  			'ciencias_fisicas'=> t('Ciencias Físicas'),
  			'ciencias_politicas'=> t('Ciencias Políticas'),
  			'comercio_internacional_exterior'=> t('Comercio Internacional/Exterior'),
  			'computacion'=> t('Computación'),
  			'comunicacion_audiovisual'=> t('Comunicación Audiovisual'),
  			'comunicacion_social'=> t('Comunicación Social'),
  			'contabilidad_aditoria'=> t('Contabilidad/Auditoria'),
  			'derecho'=> t('Derecho'),
  			'derecho_esp_administrativo'=> t('Derecho esp. Administrativo'),
  			'derecho_esp_ambiental'=> t('Derecho esp. Ambiental'),
  			'derecho_esp_civil'=> t('Derecho esp. Civil'),
  			'derecho_esp_administrativo'=> t('Derecho esp. Administrativo'),
  			'derecho esp_laboral'=> t('Derecho esp. Laboral'),
  			'derecho_esp_penal'=> t('Derecho esp. Penal'),
  			'derecho_esp_societario'=> t('Derecho esp. Societario'),
  			'derecho_espt_ributario'=> t('Derecho esp. Tributario Electrónica'),
  			'dibujo_tecnico'=> t('Dibujo Técnico'),
  			'disenio_de_imagen_y_sonido'=> t('Diseño de Imagen y Sonido Mecánica'),
  			'disenio_de_vestuario_textil_moda'=> t('Diseño de Vestuario/Téxtil/Moda'),
  			'disenio_grafico'=> t('Diseño Gráfico'),
  			'diseño_industrial'=> t('Diseño Industrial'),
  			'diseño_multimedial'=> t('Diseño Multimedial'),
  			'diseño_web'=> t('Diseño Web'),
  			'ecologia'=> t('Ecología'),
  			'economia'=> t('Economía'),
  			'editor'=> t('Editor'),
  			'educacion'=> t('Educación'),
  			'educacion_fisica'=> t('Educación Física'),
  			'enfermeria'=> t('Enfermeria'),
  			'enologia'=> t('Enología'),
  			'escribania'=> t('Escribanía'),
  			'farmacia'=> t('Farmacia'),
  			'filosofia'=> t('Filosofía'),
  			'finanzas'=> t('Finanzas'),
  			'fisioterapia'=> t('Fisioterapia'),
  			'fonoaudiologia'=> t('Fonoaudiología'),
  			'fotografia'=> t('Fotografía'),
  			'gastronomia_cocina'=> t('Gastronomía/Cocina'),
  			'geofisica'=> t('Geofísica'),
  			'geografia'=> t('Geografía'),
  			'geologia_geomensura_topografia'=> t('Geología/Geomensura/Topografía'),
  			'higiene_y_seguridad_en_el_trabajo' => ('Higiene y Seguridad en el Trabajo'),
  			'histopatologia' => t('Histopatología'),
  			'historia' => t('Historia'),
  			'hoteleria' => t('Hotelería'),
  			'ing_aeroespacial' => ('Ing. Aeroespacial'),
  			'ing_aeronautica' => t('Ing. Aeronautica'),
  			'ing_aronoma_agropecuaria' => t('Ing. Agronoma/Agropecuaria'),
  			'ing_alimentos' => t('Ing. Alimentos'),
  			'ing_ambiental' => t('Ing. Ambiental'),
  			'ing_civil' => t('Ing. Civil'),
  			'ing_electrica' => t('Ing. Electrica'),
  			'ing_electromecanica' => t ('Ing. Electromecánica'),
  			'ing_electronica' => t('Ing. Electrónica'),
  			'ing_en_mineria' => t('Ing. en Minería'),
  			'ing_forestal' => t('Ing. Forestal'),
  			'ing_hidraulica' => t('Ing. Hidráulica'),
  			'ing_industrial' => t('Ing. Industrial'),
  			'ing_informatica_sistemas' => t('Ing. Informática/Sistemas'),
  			'ing_matematica' => t('Ing. Matemática'),
  			'ing_materiales' => t('Ing. Materiales'),
  			'ing_mecanica_metalurgica' => t('Ing. Mecánica/Metalurgica'),
  			'ing_mecatronica' => t('Ing. Mecatrónica'),
  			'ing_naval' => t('Ing. Naval'),
  			'ing_nuclear' => t('Ing. Nuclear'),
  			'ing_pesquera_cultivos_marinos' => t('Ing. Pesquera/Cultivos Marinos'),
  			'ing_petroleo' => t('Ing. Petróleo'),
  			'ing_quimica' => t('Ing. Química'),
  			'ing_recursos_hidricos' => t('Ing. Recursos Hidricos'),
  			'ing_sonido' => t('Ing. Sonido'),
  			'ing_telecomunicaciones' => t('Ing. Telecomunicaciones'),
  			'ing_textil' => t('Ing. Textil'),
  			'interprete' => t('Intérprete'),
  			'kinesiologia' => t('Kinesiología'),
  			'letras' => t('Letras'),
  			'literatura' => t('Literatura'),
  			'marketing_comercializacion' => t('Marketing/Comercialización'),
  			'martillero_publico_tasador_corredor' => t('Martillero Público/Tasador/Corredor'),
  			'matematicas' => t('Matemáticas'),
  			'medicina' => t('Medicina'),
  			'medio_ambiente' => t('Medio Ambiente'),
  			'microbiologia' => t('Microbiología'),
  			'musica' => t('Música'),
  			'negociacion' => t('Negociación'),
  			'nutricion' => t('Nutrición'),
  			'oceanografia' => t('Oceanografía'),
  			'odontologia' => t('Odontología'),
  			'organizacion_de_eventos' => t('Organización de Eventos'),
  			'organizacion_industrial' => t('Organización Industrial'),
				'otro' => t('Otro'),
  			'paisajismo' => t('Paisajismo'),
  			'periodismo' => t('Periodismo'),
  			'programacion' => t('Programación'),
  			'psicologia' => t('Psicología'),
  			'psicopedagogia' => t('Psicopedagogía'),
  			'publicidad' => t('Publicidad'),
  			'quimica' => t('Química'),
  			'quimico_farmaceutico' => t('Químico Farmaceútico'),
  			'recursos_humanos_relaciones_laborales' => t('Recursos Humanos/Relaciones Laborales'),
  			'redes' => t('Redes'),
  			'relaciones_institucionales' => t('Relaciones Institucionales'),
  			'relaciones_internacionales'=> t('Relaciones Internacionales'),
  			'relaciones_publicas' => t('Secretariado'),
  			'seguridad' => t('Seguridad'),
  			'seguridad_industrial' => t('Seguridad Industrial'),
  			'sistemas_de_informacion' => t('Sistemas de Información'),
  			'sistemas_tecnologia' => t('Sistemas/Tecnología'),
  			'sociologia' => t('Sociología'),
  			'tecn_electricidad' => t('Tecn. Electricidad'),
  			'tecn_electronica'=> t('Tecn. Electrónica'),
  			'tecn_mecanica' => t('Tecn. Mecánica'),
  			'tecn_optico' => t('Tecn. Óptico'),
  			'tecn_telecomunicaciones' => t('Tecn. Telecomunicaciones'),
  			'tecnico'=> t('Técnico'),
  			'tecnologia_de_alimentos' => t('Tecnología de Alimentos'),
  			'terapia_ocupacional' => t('Terapia Ocupacional'),
  			'trabajo_social'=> t('Trabajo Social'),
  			'traduccion' => t('Traducción'),
  			'transporte' => t('Transporte'),
  			'turismo' => t('Turismo'),
  			'veterinaria' => t('Veterinaria'),
  			),
  		);






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

$form['contenedor']['columna_centro2']['separador2'] = array(
	'#type' => 'markup',
	'#markup' => "<hr>",
	);

$form['contenedor']['columna_centro2']['experiencia'] = array(
	'#type' => 'container',
	'#attributes' => array()
	);
$form['contenedor']['columna_centro2']['separador3'] = array(
	'#type' => 'markup',
	'#markup' => "<hr>",
	);

$form['contenedor']['columna_centro2']['experiencia']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Experiencia Laboral')."</h2><p>". t("")."</p>" ,
	);

$form['contenedor']['columna_centro2']['experiencia']['años_de_experiencia_laboral_en_apn'] = array(
	'#title' => t("Años de Experiencia Laboral"),
	'#type' => 'select',
	'#options' => array(
		'elegir' => t("No Especifica"),
		'0-3_anios' => t("0 - 3 Años"),
		'4-6_anios' => t("4 - 6 Años"),
		'7_o_mas_anios' => t("7 ó más Años"),
		)
);



$form['contenedor']['columna_centro2']['experiencia']['trabajo_en_sector_publico'] = array(
		'#title' => t("¿Trabajaste en el Sector Público?"),
		'#type' => 'radios',
		'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si_trabaje' => t("Sí Trabajé"),
			'no_trabaje' => t("No Trabajé"),
			)
		);


	$form['contenedor']['columna_centro2']['experiencia']['en_donde'] = array(
		'#title' => t("¿En Dónde?"),
		'#type' => 'textfield',
		'#size' => 30,
		'#maxlength' => 100,
		'#states' => array(
			'visible' => array(
        ':input[name="trabajo_en_sector_publico"]' => array('value' => 'si_trabaje'),
				),
			),
		);


$form['contenedor']['columna_centro2']['experiencia']['trabaja_actualmente'] = array(
	'#type' => 'radios',
	'#title' => t('¿Trabaja actualmente?'),
	'#theme' => array('form_element_radios_btn'),
	'#options' => array(
		'si' => t('Si'),
		'no' => t('No'),
 		),
	);



$form['contenedor']['columna_centro2']['experiencia']['nombre_organizacion'] = array(
	'#type' => 'textfield',
	'#title' => t('Nombre de la Organización'),
		'#states' => array(
			'visible' => array(
        ':input[name="trabaja_actualmente"]' => array('value' => 'si'),
				),
			),
	'#maxlength' => 100,
	);


$form['contenedor']['columna_centro2']['experiencia']['jerarquia'] = array(
	'#type' => 'select',
	'#title' => t('Jerarquía del Puesto'),
		'#states' => array(
			'visible' => array(
        ':input[name="trabaja_actualmente"]' => array('value' => 'si'),
				),
			),
	'#options' => array(
		'elegir' => t("No Especifica"),
		'independiente' => t("Independiente"),
		'alta_direccion' => t('Alta Dirección'),
		'gerente' => t('Gerente'),
		'jefe_superior' => t('Jefe/Superior'),
		'coordinador' => t('Coordinador'),
		'asesor_consultor' => t('Asesor/Consultor'),
		'analista' => t('Analista'),
		'docente_investigador' => t('Docente o Investigador'),
		'asistente_colaborador' => t('Asistente/Colaborador'),
		'administrativo' => t('Administrativo'),
		'pasante' => t('Pasante'),
		'encargado' => t('Encargado'),
		'joven_profesional' => t('Joven Profesional'),
		'otro' => t('Otro'),
		),
	);

$form['contenedor']['columna_centro2']['experiencia']['fecha_ingreso'] = array(
	'#type' => 'date',
	'#title' => t('Fecha de Ingreso'),
		'#states' => array(
			'visible' => array(
        ':input[name="trabaja_actualmente"]' => array('value' => 'si'),
				),
			),
	);

$form['contenedor']['columna_centro2']['perfil_laboral'] = array(
		'#type' => 'container',
		'#attributes' => array()
	);


$form['contenedor']['columna_centro2']['perfil_laboral']['item_titulo'] = array(
	'#type' => 'markup',
	'#markup' => "<h2>".t('Perfil Laboral')."</h2><p>". t("Agregá tu perfil profesional y los deseos que tenés para tu postulación.")."</p>" ,
	);



	$form['contenedor']['columna_centro2']['perfil_laboral']['provincia_donde_trabajar'] = array(
			'#type'=> 'select',
			'#title'=>t("Provincia donde deseo Trabajar"),
			'#options' => array(
	      'cualquier_provincia' => t("Cualquier Provincia"),
				'buenos_aires'=> t("Buenos Aires"),
				'capital_federal' => t("Capital Federal"),
				'catamarca'=> t("Catamarca"),
				'chaco'=> t("Chaco"),
				'chubut'=> t("Chubut"),
				'cordoba'=> t("Córdoba"),
				'corrientes'=> t("Corrientes"),
				'entre_rios'=> t("Entre Ríos"),
				'formosa'=> t("Formosa"),
				'jujuy'=> t("Jujuy"),
				'la_pampa'=> t("La Pampa"),
				'la_rioja'=> t("La Rioja"),
				'mendoza'=> t("Mendoza"),
				'misiones'=> t("Misiones"),
				'neuquen'=> t("Neuquén"),
				'rio_negro'=> t("Río Negro"),
				'salta'=> t("Salta"),
				'san_juan'=> t("San Juan"),
				'san_luis'=> t("San Luís"),
				'santa_cruz'=> t("Santa Cruz"),
				'santa_fe'=> t("Santa Fe"),
				'santiago_del_estero'=> t("Santiago del Estero"),
				'tierra_del_fuego'=> t("Tierra del Fuego"),
				'tucuman'=> t("Tucumán"),
				),
		);


$form['contenedor']['columna_centro2']['discapacidad'] = array(
	'#title' => t('¿Posee algún tipo de discapacidad?'),
	'#type' => 'radios',
	'#theme' => array('form_element_radios_btn'),
		'#options' => array(
			'si' => t('Si'),
			'no' => t('No'),
		),
	);

$form['contenedor']['columna_centro2']['discapacidad_cont'] = array(
	'#type' =>'container',
	'#states' => array(
		'visible' => array(
			':input[name="discapacidad"]' => array('value' => 'si')
		),
	),
		);

$form['contenedor']['columna_centro2']['discapacidad_cont']['texto_discapacidad'] = array(
	'#type' => 'markup',
	'#markup' =>  "<p>".t("SISTEMA DE PROTECCION INTEGRAL DE LOS DISCAPACITADOS
Ley Nº 22.43 / Decreto Reglamentario 312/2010
El Estado Nacional está obligado a ocupar personas discapacitadas que reúnan condiciones de idoneidad para el cargo, en una proporción no inferior al CUATRO POR CIENTO (4%) de la totalidad de su personal y a establecer reservas de puestos de trabajo a ser exclusivamente ocupados por ella"."</p>"
	),
);

$form['contenedor']['columna_centro2']['discapacidad_cont']['discapacidad_certificado'] = array(
	'#type' => 'radios',
	'#title' => t('¿Posee Certificado Único de Discapacidad (CUD)?'),
	'#theme' => array('form_element_radios_btn'),
	'#options' => array(
		'si' => t('Si'),
		'no' => t('No'),
		),
	);




	$form['contenedor']['columna_centro3']['tipos_de_trabajo'] = array(
		'#type' => 'container',
		'#attributes' => array()
		);

	$form['contenedor']['columna_centro3']['tipos_de_trabajo']['item_titulo'] = array(
		'#type' => 'markup',
		'#markup' => "<h4>". t('Postulaciones Preferenciales')."</h4>",
		);

$form['contenedor']['columna_centro3']['columna_izquierda3']['tipos_de_trabajo']['postulaciones_preferenciales_fieldset']= array(
	'#type' => 'fieldset',
	'#title' => t('Elegí en que Ministerios querés ser tenido en cuenta'),
	 '#collapsible' => TRUE,
	   '#collapsed' => TRUE
	);


	$form['contenedor']['columna_centro3']['columna_izquierda3']['tipos_de_trabajo']['postulaciones_preferenciales_fieldset']['postulaciones_preferenciales'] = array(
		'#type' => 'checkboxes',
		'#options' => array(
			'minsiterio_de_agroindustria'=> t("Ministerio de Agroindustria"),
			'ministerio_de_ambiente_y_desarrollo_sustentable'=> t("Ministerio de Ambiente y Desarrollo Sustentable"),
			'ministerio_de_ciencia_tecnologia_e_innovación'=> t("Ministerio de Ciencia, Tecnología e Innovación"),
			'ministerio_de_comunicaciones'=> t("Ministerio de Comunicaciones"),
			'minsitrerio_de_cultura'=> t("Ministerio de Cultura"),
			'ministerio_de_defensa'=> t("Ministerio de Defensa"),
			'ministerio_de_desarrollo_social'=> t("Ministerio de Desarrollo Social"),
			'ministerio_de_educacion_y_deporte'=> t("Ministerio de Educación y Deporte"),
			'ministerio_de_energia_y_mineria'=> t("Ministerio de Energía y Minería"),
			'ministerio_de_hacienda_y_finanazas_publicas'=> t("Ministerio de Hacienda y Finanzas Públicas"),
			'ministerio_de_justicia_y_derechos_humanos'=> t("Ministerio de Justicia y Derechos Humanos"),
			'ministerio_de_modernizacion'=> t("Ministerio de Modernización"),
			'ministerio_de_produccion'=> t("Ministerio de Producción"),
			'ministerio_de_relaciones_exteriores_y_culto'=> t("Ministerio de Relaciones Exteriores  y Culto"),
			'ministerio_de_salud'=> t("Ministerio de Salud"),
			'ministerio_de'=> t("Ministerio de Seguridad"),
			'ministerio_de_trabajo_empleo_y_seguridad_social'=> t("Ministerio de Trabajo, Empleo y Seguridad Social"),
			'ministerio_de_transporte'=> t("Ministerio de Transporte"),
			'ministerio_de_turismo'=> t("Ministerio de Turísmo"),
			'ministerio_del_interior_vivienda_y_obras_publicas'=> t("Ministerio del Interior, Vivienda y Obras Públicas")
			)
		);

$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']= array(
	'#type' => 'fieldset',
	'#title' => t('Elegí entre los roles comunes a toda la APN aquellos más acordes a tu idoneidad y experiencia profesional.'),
	 '#collapsible' => TRUE,
	   '#collapsed' => TRUE
	);



$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_asuntos_legales'] = array(
		'#type' => 'checkboxes',
		'#title' => t("Roles del Área de Asuntos Legales"),
		'#options' => array(
			'asuntos_juridicos' => t("Asuntos Jurídicos"),
			'asuntos_judiciales' => t("Asuntos Judiciales")
			)
		);

	$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_del_area_administrativa_contable'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Roles del Área Administrativa Contable'),
		'#options' => array(
			'finanzas' => t("Finanzas"),
			'presupuesto' => t("Presupuesto"),
			'contable' => t("Contable"),
			'tesoreria' => t("Tesorería"),
			'planeamiento_y_control_de_gestion' => t("Planeamiento y Control de Gestión"),
			'compras_y_contrataciones' => t("Compras y Contrataciones")
			)
		);

	$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_institucionales_y_comunicacion'] =array(
		'#type' => 'checkboxes',
		'#title' => t('Roles del Área de Institucionales y Comunicación'),
		'#options' => array(
			'eventos_ceremonial_y_protocolos' => t("Eventos,Ceremonial y Protocolo"),
			'comunicacion_interna' => t("Comunicación Interna"),
			'comunicacion_externa' => t("Comunicación Externa"),
			'cooperacion_internacional_y_convenios' => t("Cooperación Internacional y Convenios"),
			)
		);

$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_recursos_humanos'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Roles del Área de Recursos Humanos'),
		'#options' => array(
			'administracion_personal' => t("Administración de Personal"),
			'capacitacion_y_desarrollo' => t("Capacitación y Desarrollo"),
			'seleccion_de_personal' => t("Selección de Personal y Evaluación de Desempeño"),
			'relaciones_laborales' => t("Relaciones Laborales"),
			)
		);

$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_de_secretarias_recepcionistas'] = array(
	'#type' => 'checkboxes',
	'#title' => t('Roles de Secretarias / Recepcionistas'),
	'#options' => array(
		'secretaria_privada' => t("Secretaría Privada"),
		'recepcionistas'=> t("Recepcionistas"),
		'telefonista' => t("Telefonista"),
		)
	);

	$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_servicios_generales'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Roles del Área de Servicios Generales'),
		'#options' => array(
			'mantenimiento' => t("Mantenimiento"),
			'patrimonio' => t("Patrimonio"),
			'mesa_de_entradas' => t("Mesa de Entradas"),
			'cedeteria' => t("Cadeteria"),
			'gestion_edilicia' => t("Gestión Edilicia"),
			'seguridad' => t("Seguridad"),
			'chofer' => t("Chofer")
			)
		);

	$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_sistemas'] = array(
			'#type' => 'checkboxes',
			'#title' => t('Roles del Área Sistemas'),
			'#options' => array(
				'administracion_base_de_datos' => t("Administración Base de Datos"),
				'analisis_funcional' => t("Análisis Funcional"),
				'data_warehousing' => t("Data Warehousing"),
				'insfraestructura' => t("Infraestructura"),
				'programacion' => t("Programación"),
				'redes' => t("Redes"),
				'seguridad_informatica' => t("Seguridad Informática"),
				'soporte_tecnico' => t("Soporte Técnico"),
				'testing' => t("Testing/QA/QC"),
				'capacitador_informatico' => t("Capacitador Informático (e-learning)"),
				'arquitectura_soluciones' => t("Arquitectura Soluciones"),
				'operadores_NOC' => t("Operadores NOC"),
				'telefonia_IP' => t("Telefonía IP"),
				)
			);

	$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_auditoria'] = array(
			'#type' => 'checkboxes',
			'#title' => t("Roles del Área de Auditoria"),
			'#options' => array(
				'auditoria_contable' => t("Auditoria Contable"),
				'auditoria_legal' => t("Auditoria Legal"),
				'auditoria_de_sistemas' => t("Auditoria de Sistemas"),
				)
			);

$form['contenedor']['columna_centro3']['columna_derecha4']['tipos_de_trabajo']['postulaciones_comunes_a_apn']['roles_procesos'] = array(
			'#type' => 'checkboxes',
			'#title' => t("Roles de Procesos"),
			"#options" => array(
				'analista_funcional' => t("Analista Funcional"),
				'project_manager' => t("Project Manager"),
				'reingenieria_de_procesos' => t("Reingeniería de Procesos"),
				'bussines_intelligence' => t("Bussines Intelligence"),
				)
			);

	$form['contenedor']['columna_centro4']['curriculum'] = array(
		'#type' => 'container',
		'#atributes' => array()
		);


$form['contenedor']['columna_centro3']['separador5'] = array(
	'#type' => 'markup',
	'#markup' => "<hr>",
	);

	$form['contenedor']['columna_centro4']['curriculum']['item_titulo'] = array(
		'#type' => 'markup',
			'#markup' => "<h2>".t('Curriculum Vitae')."</h2><p>". t(" Mandanos tu CV para tener tus datos completos. (Solo se permite formato PDF)")."</p>" ,

		);

	//$form = array();
  // If this #attribute is not present, upload will fail on submit
  $form['contenedor']['columna_centro4']['cv'] = array(
    '#title' => t('Adjuntar archivo:'),
    '#type' => 'managed_file',
    '#upload_validators' => array('file_validate_extensions' => array('pdf')),
    '#upload_location' => 'public://cv/',
    '#process' => array('argentinagobar_formularios_my_file_element_process'),
    '#required' => TRUE,
    );



	$form['contenedor']['columna_centro4']['comentario'] = array(
	'#title' => t('Datos adicionales que quieras agregar:'),
	'#type' => 'textarea',
	'#maxlength' => 1000,
	'#size' => 500,
	);

  $form['contenedor']['columna_centro4']['terminos_y_condiciones'] = array(
	'#type' => 'checkbox',
	'#title' => t('He leído y acepto los ') . l('Terminos y Condiciones', 'node/1530'),
	'#required' => TRUE,
	);

	$form['contenedor']['columna_centro4']['submit_button'] = array(
			'#type' => 'submit',
			'#value' => t('Enviar mis Datos'),
	 	/*	'#ajax' => array(
				'callback' => 'argentinagobar_formularios_postulaciones_submit',
				'wrapper' => 'contenedor',
				'method' => 'replace',
				'effect' => 'fade',
			),*/
		);


	$form['fecha_postulacion'] = array(
		'#type' => 'date',
		'#access' => FALSE,
	);

  return $form;
}




function argentinagobar_formularios_postulaciones_submit($form, &$form_state) {
	global $base_root;

 if(!empty($form_state['values']['cv'])){
    $file = file_load($form_state['values']['cv']);
    $file->status = FILE_STATUS_PERMANENT;
  	$archivo = file_save($file);
  	$archivo2 = file_usage_add($file, 'argentinagobar_formularios', 'file', $file->uid);
		$file_url = $base_root . "/cv/" . substr($file->uri,12,strlen($file->uri));

    drupal_set_message('Tus datos y tu CV han se han guardado correctamente.', 'status', TRUE);

  }




 $valores_preferenciales = implode(", ",array_filter($form_state['values']['postulaciones_preferenciales']));
 $valores_legales = implode(", ",array_filter($form_state['values']['roles_asuntos_legales']));
 $valores_contable = implode(", ", array_filter($form_state['values']['roles_del_area_administrativa_contable']));
 $valores_comunicacion = implode(", ", array_filter($form_state['values']['roles_institucionales_y_comunicacion']));
 $valores_recursos_humanos = implode(", ", array_filter($form_state['values']['roles_recursos_humanos']));
 $valores_secretarias = implode(", ", array_filter($form_state['values']['roles_de_secretarias_recepcionistas']));
 $valores_generales = implode(", ", array_filter($form_state['values']['roles_servicios_generales']));
 $valores_sistemas = implode(", ", array_filter($form_state['values']['roles_sistemas']));
 $valores_auditorias = implode(", ", array_filter($form_state['values']['roles_auditoria']));
 $valores_procesos = implode(", " , array_filter($form_state['values']['roles_procesos']));
 $string_fecha_postualcion = implode("/", $form_state['values']['fecha_postulacion']);
 $string_fecha_nacimiento = implode("/", $form_state['values']['fecha_nacimiento']);
 $string_fecha_ingreso = implode("/", $form_state['values']['fecha_ingreso']);
 $string_fecha_inicial = implode("/", array("1","1","1900"));
 $valores_roles = $valores_legales .",". $valores_contable . $valores_comunicacion . $valores_recursos_humanos . $valores_secretarias . $valores_generales . $valores_sistemas.$valores_auditorias. $valores_procesos;

#Database::addConnectionInfo('conexion', 'default', $database_info);

db_set_active('formularios');
$insert = db_insert('postulantes')
	->fields(array(
		'apellido' => $form_state['values']['apellido'],
		'nombres' => $form_state['values']['nombres'],
		'telefono' => $form_state['values']['telefono'],
		'mail' => $form_state['values']['mail'],
		'dni' => $form_state['values']['dni'],
		'pais_residencia'=> $form_state['values']['pais_residencia'],
		'provincia' => $form_state['values']['provincia'] == "elegir" ? "" : $form_state['values']['provincia'],
		'localidad' => $form_state['values']['localidad'],
		'pais' => $form_state['values']['pais'],
		'genero' => $form_state['values']['genero'],
		'fecha_nacimiento' => $form_state['values']['fecha_nacimiento'] == $form_state['values']['fecha_postulacion'] ? "" : $string_fecha_nacimiento ,
		'nivel_de_estudio1' => $form_state['values']['nivel_de_estudio'] == "elegir" ? "" : $form_state['values']['nivel_de_estudio'],
		'titulo_obtenido1' => $form_state['values']['titulo_obtenido'],
		'area_de_estudio1' => $form_state['values']['area_de_estudio'] == "elegir" ? "" : $form_state['values']['area_de_estudio'],
		'nivel_de_estudio2' => $form_state['values']['nivel_de_estudio2'] == "elegir" ? "": $form_state['values']['nivel_de_estudio2'],
		'titulo_obtenido2' => $form_state['values']['titulo_obtenido2'],
		'area_de_estudio2' => $form_state['values']['area_de_estudio2'] == "elegir" ? "" : $form_state['values']['area_de_estudio2'],
		'trabaja_actualmente' => $form_state['values']['trabaja_actualmente'],
		'nombre_organizacion' => $form_state['values']['nombre_organizacion'],
		'jerarquia' => $form_state['values']['jerarquia'] == "elegir" ? "" : $form_state['values']['jerarquia'],
		'fecha_ingreso' => $form_state['values']['fecha_ingreso'] == $form_state['values']['fecha_postulacion'] ? "" : $string_fecha_ingreso,
		'certificado_discapacidad' => $form_state['values']['discapacidad'],
		'años_de_experiencia_laboral_en_apn' => $form_state['values']['años_de_experiencia_laboral_en_apn'] == "elegir" ? "" : $form_state['values']['años_de_experiencia_laboral_en_apn'] ,
		'lugar_laboral_deseado' => $form_state['values']['provincia_donde_trabajar'],
		'experiencia_apn' => $form_state['values']['trabajo_en_sector_publico'],
		'trabajo_anterior_apn' => $form_state['values']['en_donde'],
		'preferencias_por_tematica' =>  $valores_preferenciales,
		'preferencias_por_roles' => $valores_roles,
		'url_cv' => $file_url,
		'comentario' => $form_state['values']['comentario'],
		'fecha_postulacion' => $string_fecha_postualcion,
		)
	)
			->execute();
	db_set_active();
	  // return '<div id="contenedor">' . $response . '</div>';
}
