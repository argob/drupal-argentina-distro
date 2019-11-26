<?php
/**
 * @file
 * argentinagobar_organismo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_organismo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function argentinagobar_organismo_node_info() {
  $items = array(
    'organismo' => array(
      'name' => t('Organismo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
