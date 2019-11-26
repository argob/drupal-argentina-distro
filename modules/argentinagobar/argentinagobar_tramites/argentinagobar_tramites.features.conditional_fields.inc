<?php
/**
 * @file
 * argentinagobar_tramites.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function argentinagobar_tramites_conditional_fields_default_fields() {
  $items = array();

  $items["node:tramite:0"] = array(
    'entity' => 'node',
    'bundle' => 'tramite',
    'dependent' => 'field_modalidad_otro_especificar',
    'dependee' => 'field_modalidad_otro',
    'options' => array(
      'state' => 'visible',
      'condition' => 'checked',
      'grouping' => 'AND',
      'values_set' => 1,
      'value' => array(),
      'values' => array(),
      'value_form' => array(),
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
        2 => 0,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
    ),
  );

  return $items;
}
