<?php
/**
 * @file
 * argentinagobar_tramites.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function argentinagobar_tramites_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_a_quien_esta_dirigido|node|tramite|form';
  $field_group->group_name = 'group_a_quien_esta_dirigido';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => '¿A quién está dirigido?',
    'weight' => '5',
    'children' => array(
      0 => 'field_dirigido',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '¿A quién está dirigido?',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-a-quien-esta-dirigido field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_a_quien_esta_dirigido|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_acciones|node|tramite|form';
  $field_group->group_name = 'group_acciones';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Acciones',
    'weight' => '16',
    'children' => array(
      0 => 'field_acciones',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Acciones',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-acciones field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_acciones|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_como_hago|node|tramite|form';
  $field_group->group_name = 'group_como_hago';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => '¿Cómo hago?',
    'weight' => '8',
    'children' => array(
      0 => 'field_pasos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-como-hago field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_como_hago|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_configuracion|node|tramite|form';
  $field_group->group_name = 'group_configuracion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Configuración',
    'weight' => '15',
    'children' => array(
      0 => 'field_servicio_categoria',
      1 => 'field_palabras_clave',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Configuración',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-configuracion field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_configuracion|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cual_costo_tramite|node|tramite|form';
  $field_group->group_name = 'group_cual_costo_tramite';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => '¿Cuál es el costo del trámite?',
    'weight' => '10',
    'children' => array(
      0 => 'field_costo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '¿Cuál es el costo del trámite?',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cual-costo-tramite field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_cual_costo_tramite|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descargas|node|tramite|form';
  $field_group->group_name = 'group_descargas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Descargas',
    'weight' => '17',
    'children' => array(
      0 => 'field_download',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Descargas',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-descargas field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_descargas|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_donde|node|tramite|form';
  $field_group->group_name = 'group_donde';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '¿Dónde?',
    'weight' => '9',
    'children' => array(
      0 => 'field_oficina_otra',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '¿Dónde?',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-donde field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_donde|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_es_migrado|node|tramite|form';
  $field_group->group_name = 'group_es_migrado';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Es Migrado',
    'weight' => '1',
    'children' => array(
      0 => 'field_es_migrado',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-es-migrado field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_es_migrado|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_especificar|node|tramite|form';
  $field_group->group_name = 'group_especificar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Especificar',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-especificar field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_especificar|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|tramite|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Información general',
    'weight' => '1',
    'children' => array(
      0 => 'field_id_migracion',
      1 => 'metatags',
      2 => 'path',
      3 => 'redirect',
      4 => 'xmlsitemap',
      5 => 'group_a_quien_esta_dirigido',
      6 => 'group_acciones',
      7 => 'group_como_hago',
      8 => 'group_configuracion',
      9 => 'group_cual_costo_tramite',
      10 => 'group_descargas',
      11 => 'group_groups_audience',
      12 => 'group_informacion_adicional',
      13 => 'group_modalidad',
      14 => 'group_que_necesito',
      15 => 'group_requisitos_colection',
      16 => 'group_requisitos',
      17 => 'group_tiempo_lleva_tramite',
      18 => 'group_titulo_descripcion',
      19 => 'group_tramites_relacionados',
      20 => 'group_vigencia',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_groups_audience|node|tramite|form';
  $field_group->group_name = 'group_groups_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Groups audience',
    'weight' => '13',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Groups audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-groups-audience field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_groups_audience|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_informacion_adicional|node|tramite|form';
  $field_group->group_name = 'group_informacion_adicional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Para uso interno',
    'weight' => '19',
    'children' => array(
      0 => 'field_informacion_adicional',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Para uso interno',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-informacion-adicional field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_informacion_adicional|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_modalidad|node|tramite|form';
  $field_group->group_name = 'group_modalidad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Modalidad',
    'weight' => '14',
    'children' => array(
      0 => 'field_modalidad_digital',
      1 => 'field_modalidad_otro',
      2 => 'field_modalidad_otro_especificar',
      3 => 'field_modalidad_presencial',
      4 => 'field_modalidad_telefonico',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Modalidad',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-modalidad field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_modalidad|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oficina|node|tramite|form';
  $field_group->group_name = 'group_oficina';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'oficina',
    'weight' => '2',
    'children' => array(
      0 => 'field_oficina',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'oficina',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-oficina field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_oficina|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_que_necesito|node|tramite|form';
  $field_group->group_name = 'group_que_necesito';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => '¿Qué necesito?',
    'weight' => '7',
    'children' => array(
      0 => 'field_requisitos_collection',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-que-necesito field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_que_necesito|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relevamiento|node|tramite|form';
  $field_group->group_name = 'group_relevamiento';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relevamiento',
    'weight' => '3',
    'children' => array(
      0 => 'field_formulario_digital',
      1 => 'field_notificaciones',
      2 => 'field_pago_electronico_list',
      3 => 'field_pago_requerido_list',
      4 => 'field_posee_notificaciones',
      5 => 'field_relevamiento_observaciones',
      6 => 'field_resumen_nivel',
      7 => 'field_transaccion_tipo',
      8 => 'field_turno_digital',
      9 => 'field_turno_requerido',
      10 => 'field_descargas_obligatorias',
      11 => 'field_digitalizacion_medir',
      12 => 'field_digitalizacion_observacion',
      13 => 'field_fecha_de_actualizacin',
      14 => 'field_identificacion_digital',
      15 => 'field_lista_requiere_turno',
      16 => 'field_texto_servicio',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relevamiento',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-relevamiento field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_relevamiento|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_requisitos_colection|node|tramite|form';
  $field_group->group_name = 'group_requisitos_colection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Requisitos',
    'weight' => '6',
    'children' => array(
      0 => 'field_requisitos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Requisitos',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-requisitos-colection field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_requisitos_colection|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_requisitos|node|tramite|form';
  $field_group->group_name = 'group_requisitos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Información complementaria',
    'weight' => '12',
    'children' => array(
      0 => 'field_texto_requisitos_tramite',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Información complementaria',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-requisitos field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_requisitos|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|tramite|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tiempo_lleva_tramite|node|tramite|form';
  $field_group->group_name = 'group_tiempo_lleva_tramite';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => '¿Cuánto tiempo lleva hacer el trámite?',
    'weight' => '9',
    'children' => array(
      0 => 'field_duracion',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '¿Cuánto tiempo lleva hacer el trámite?',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-tiempo-lleva-tramite field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_tiempo_lleva_tramite|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_titulo_descripcion|node|tramite|form';
  $field_group->group_name = 'group_titulo_descripcion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Título, resumen y descripción',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_field_texto_observacion_de',
      2 => 'language',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Título, resumen y descripción',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-titulo-descripcion field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_titulo_descripcion|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tramites_relacionados|node|tramite|form';
  $field_group->group_name = 'group_tramites_relacionados';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Trámites relacionados',
    'weight' => '18',
    'children' => array(
      0 => 'field_servicios_relacionados',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Trámites relacionados',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-tramites-relacionados field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_tramites_relacionados|node|tramite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vigencia|node|tramite|form';
  $field_group->group_name = 'group_vigencia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tramite';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Vigencia',
    'weight' => '11',
    'children' => array(
      0 => 'field_vigencia',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vigencia',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-vigencia field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_vigencia|node|tramite|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Acciones');
  t('Configuración');
  t('Descargas');
  t('Es Migrado');
  t('Especificar');
  t('Groups audience');
  t('Información complementaria');
  t('Información general');
  t('Modalidad');
  t('Para uso interno');
  t('Relevamiento');
  t('Requisitos');
  t('Tabs');
  t('Trámites relacionados');
  t('Título, resumen y descripción');
  t('Vigencia');
  t('oficina');
  t('¿A quién está dirigido?');
  t('¿Cuál es el costo del trámite?');
  t('¿Cuánto tiempo lleva hacer el trámite?');
  t('¿Cómo hago?');
  t('¿Dónde?');
  t('¿Qué necesito?');

  return $field_groups;
}
