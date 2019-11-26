<?php
/**
 * @file
 * field.field_collection_item.field_medida.field_cantidades.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'settings' => array(
      'allowed_values' => array(
        'minutos' => 'minutos',
        'horas' => 'horas',
        'días' => 'días',
        'meses' => 'meses',
        'años' => 'años',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_medida' => array(
              'value' => 'field_medida_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_medida' => array(
              'value' => 'field_medida_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'field_name' => 'field_medida',
    'type' => 'list_text',
    'module' => 'list',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => NULL,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'label' => 'Medida',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'field_name' => 'field_medida',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_cantidades',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'list',
  2 => 'options',
);
