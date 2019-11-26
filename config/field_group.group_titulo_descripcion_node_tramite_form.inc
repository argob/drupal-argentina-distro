<?php
/**
 * @file
 * field_group.group_titulo_descripcion_node_tramite_form.inc
 */

$api = '2.0.0';

$data = $field_group = new stdClass();
$field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
$field_group->api_version = 1;
$field_group->identifier = 'group_titulo_descripcion|node|tramite|form';
$field_group->group_name = 'group_titulo_descripcion';
$field_group->entity_type = 'node';
$field_group->bundle = 'tramite';
$field_group->mode = 'form';
$field_group->parent_name = 'group_general';
$field_group->data = array(
  'label' => 'Título y Descripción',
  'weight' => '4',
  'children' => array(
    0 => 'title',
  ),
  'format_type' => 'fieldset',
  'format_settings' => array(
    'formatter' => 'collapsible',
    'instance_settings' => array(
      'description' => '',
      'classes' => 'group-titulo-descripcion field-group-fieldset',
      'required_fields' => 1,
      'id' => '',
    ),
  ),
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'field_group',
);
