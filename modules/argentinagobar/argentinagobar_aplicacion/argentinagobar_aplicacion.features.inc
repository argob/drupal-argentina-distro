<?php
/**
 * @file
 * argentinagobar_aplicacion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_aplicacion_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function argentinagobar_aplicacion_node_info() {
  $items = array(
    'aplicacion' => array(
      'name' => t('Aplicación'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
