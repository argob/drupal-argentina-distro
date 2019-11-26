<?php

class FiltroSubasta extends Filtro{
	
  function crear_form($form, &$form_state){
      
      if(empty($form_state['handler'])) {
          $form_state['handler'] = serialize($this->listado);
      }
      
      
	$form['filter_form_container'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'filter_form_container',
			'class' => array('row'),
		),
	);
	
	$form['filter_form_container']['filter_form_container_col_12'] = array(
			'#type' => 'container',
			'#attributes' => array(
					'id' => 'filter_form_container',
					'class' => array('col-md-12'),
			),
	);
	
	$form['filter_form_container']['tipo_inmueble'] = array(
		'#type' => 'select',
		'#title' => t('Tipo de inmueble'),
		'#options' => array(
			'all' => t('Todos'),
			0 => t('Edificios'),
            1 => t('Grandes Fracciones'),
            2 => t('Campos'),
            3 => t('Lotes'),
            4 => t('Galpones'),
            5 => t('Locales'),
            6 => t('Oficinas'),
            7 => t('Viviendas'),
		),
	
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
			'wrapper' => 'filter_form_response',
			'method' => 'replace',
			'effect' => 'fade',
			'progress' => array('type' => 'none'),
		),
      '#prefix' => '<div class="col-md-3">',
      '#suffix' => '</div>',
	);


	$form['filter_form_container']['ubicación'] = array(
		'#type' => 'select',
		'#title' => t('Ubicación'),
		'#options' => array(
			'all' => t('Todos'),
			0 => 'Buenos Aires',
			1 => 'Ciudad Autónoma de Buenos Aires',
			2 => 'Catamarca',
			3 => 'Chaco',
			4 => 'Chubut',
			5 => 'Córdoba',
			6 => 'Corrientes',
			7 => 'Entre Ríos',
			8 => 'Formosa',
			9 => 'Jujuy',
			10 => 'La Pampa',
			11 => 'La Rioja',
			12 => 'Mendoza',
			13 => 'Misiones',
			14 => 'Neuquén',
			15 => 'Río Negro',
			16 => 'Salta',
			17 => 'San Juan',
			18 => 'San Luis',
			19 => 'Santa Cruz',
			20 => 'Santa Fe',
			21 => 'Santiago del Estero',
			22 => 'Tierra del Fuego, Antártida e Islas del Atlántico Sur',
			23 => 'Tucumán',
		),
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
			'wrapper' => 'filter_form_response',
			'method' => 'replace',
			'effect' => 'fade',
			'progress' => array('type' => 'none'),
		),
		'#prefix' => '<div class="col-md-3">',
		'#suffix' => '</div>',
    );

	$form['filter_form_container']['tipo_subasta'] = array(
		'#type' => 'select',
                '#attributes' => array('onchange' => array('disabledEstado()')),
		'#title' => t('Publicación'),
		'#options' => array(
			'vigente' => t('Vigente'),
			'finalizada' => t('Finalizada'),
		),
		'#prefix' => '<div class="col-md-3">',
		'#suffix' => '</div>',
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
			'wrapper' => 'filter_form_response',
			'method' => 'replace',
			'effect' => 'fade',
			'progress' => array('type' => 'none'),
		)
	);

	$form['filter_form_container']['estado'] = array(
		'#type' => 'select',
		'#title' => t('Estado'),
		'#options' => array(
                        'all' => t('Todos'),
			'subastado' => t('Subastado'),
			'adjudicado' => t('Adjudicado'),
			'finalizado' => t('Finalizada'),
		),
		'#prefix' => '<div class="col-md-3">',
		'#suffix' => '</div>',
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
			'wrapper' => 'filter_form_response',
			'method' => 'replace',
			'effect' => 'fade',
			'progress' => array('type' => 'none'),
		)
	);
	
	$form['filter_form_container']['modalidad'] = array(
		'#type' => 'select',
		'#title' => t('Modalidad'),
		'#options' => array(
			'presencial' => t('Presencial'),
			'virtual' => t('Virtual'),
			
		),
		'#prefix' => '<div class="col-md-3">',
		'#suffix' => '</div>',
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
			'wrapper' => 'filter_form_response',
			'method' => 'replace',
			'effect' => 'fade',
			'progress' => array('type' => 'none'),
		)
	);


	$form['filter_form_container']['order_by'] = array(
		'#type' => 'select',
		'#title' => t('Ordenar por'),
		'#options' => array(
			'recientes' => t('Fecha más reciente'),
			'DESC' => t('Mayor precio'),
			'ASC' => t('Menor precio'),
		),
		'#prefix' => '<div class="col-md-3">',
		'#suffix' => '</div>',
		'#ajax' => array(
				'event' => 'change',
				'callback' => 'argentinagobar_bloques_filtro_form_submit_ajax',
				'wrapper' => 'filter_form_response',
				'method' => 'replace',
				'effect' => 'fade',
				'progress' => array('type' => 'none'),
		),
 );
	
    return $form;
  }
}