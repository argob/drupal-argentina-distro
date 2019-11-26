<?php
/**
 * @file
 * argentinagobar_areas.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function argentinagobar_areas_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoridad|node|area|form';
  $field_group->group_name = 'group_autoridad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_estructura';
  $field_group->data = array(
    'label' => 'Autoridad',
    'weight' => '6',
    'children' => array(
      0 => 'field_autoridad_cargo',
      1 => 'field_autoridad_descripcion',
      2 => 'field_autoridad_foto',
      3 => 'field_autoridad_nombre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autoridad field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_autoridad|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contacto|node|area|form';
  $field_group->group_name = 'group_contacto';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Contacto',
    'weight' => '7',
    'children' => array(
      0 => 'field_codigo_postal',
      1 => 'field_correo_electronico',
      2 => 'field_direccion',
      3 => 'field_facebook',
      4 => 'field_twitter',
      5 => 'field_instagram',
      6 => 'field_youtube',
      7 => 'field_flickr',
      8 => 'field_linkedin',
      9 => 'field_whatsapp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contacto field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_contacto|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contenedor|node|area|form';
  $field_group->group_name = 'group_contenedor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenedor',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
      1 => 'group_sedes',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-contenedor field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_contenedor|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_direccion|field_collection_item|field_sedes|form';
  $field_group->group_name = 'group_direccion';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sedes';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Direccion',
    'weight' => '1',
    'children' => array(
      0 => 'field_direccion_calle',
      1 => 'field_dir_numero',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-direccion field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_direccion|field_collection_item|field_sedes|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entrega_turnos|field_collection_item|field_sedes|form';
  $field_group->group_name = 'group_entrega_turnos';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sedes';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entrega de Turnos',
    'weight' => '6',
    'children' => array(
      0 => 'field_turnos_desde_',
      1 => 'field_turnos_detalle',
      2 => 'field_turnos_hasta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-entrega-turnos field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_entrega_turnos|field_collection_item|field_sedes|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_estructura|node|area|form';
  $field_group->group_name = 'group_estructura';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Estructura',
    'weight' => '8',
    'children' => array(
      0 => 'field_niveles_jerarquicos',
      1 => 'group_autoridad',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-estructura field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_estructura|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gelocalizacion|field_collection_item|field_sedes|form';
  $field_group->group_name = 'group_gelocalizacion';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sedes';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Geolocalizacion',
    'weight' => '8',
    'children' => array(
      0 => 'field_geolocalizacion_y',
      1 => 'field_geolocalizacion_x',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gelocalizacion field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_gelocalizacion|field_collection_item|field_sedes|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|area|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contenedor';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_featured_image',
      2 => 'field_links_relacionados',
      3 => 'field_paginas_relacionadas',
      4 => 'group_group',
      5 => 'og_group_ref',
      6 => 'field_tags',
      7 => 'metatags',
      8 => 'title',
      9 => 'path',
      10 => 'redirect',
      11 => 'xmlsitemap',
      12 => 'group_contacto',
      13 => 'group_estructura',
      14 => 'group_horario_atencion',
      15 => 'group_telefono',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horario_atencion_tel|field_collection_item|field_sedes|form';
  $field_group->group_name = 'group_horario_atencion_tel';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sedes';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horario de Atencion Telefonica',
    'weight' => '3',
    'children' => array(
      0 => 'field_atencion_tel_desde',
      1 => 'field_atencion_tel_hasta',
      2 => 'field_telefono',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horario-atencion-tel field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horario_atencion_tel|field_collection_item|field_sedes|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horario_atencion|field_collection_item|field_sedes|form';
  $field_group->group_name = 'group_horario_atencion';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sedes';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horario de Atencion',
    'weight' => '2',
    'children' => array(
      0 => 'field_atencion_desde',
      1 => 'field_atencion_hasta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horario-atencion field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horario_atencion|field_collection_item|field_sedes|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horario_atencion|node|area|form';
  $field_group->group_name = 'group_horario_atencion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Horario de Atencion',
    'weight' => '9',
    'children' => array(
      0 => 'field_atencion_desde',
      1 => 'field_atencion_hasta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horario-atencion field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horario_atencion|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sedes|node|area|form';
  $field_group->group_name = 'group_sedes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contenedor';
  $field_group->data = array(
    'label' => 'Sedes',
    'weight' => '3',
    'children' => array(
      0 => 'field_sedes',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sedes field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_sedes|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_telefono|node|area|form';
  $field_group->group_name = 'group_telefono';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Telefono',
    'weight' => '3',
    'children' => array(
      0 => 'field_telefono',
      1 => 'field_atencion_tel_desde',
      2 => 'field_atencion_tel_hasta',
      3 => 'field_es_destacado',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-telefono field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_telefono|node|area|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Autoridad');
  t('Contacto');
  t('Contenedor');
  t('Direccion');
  t('Entrega de Turnos');
  t('Estructura');
  t('General');
  t('Geolocalizacion');
  t('Horario de Atencion');
  t('Horario de Atencion Telefonica');
  t('Sedes');
  t('Telefono');

  return $field_groups;
}
