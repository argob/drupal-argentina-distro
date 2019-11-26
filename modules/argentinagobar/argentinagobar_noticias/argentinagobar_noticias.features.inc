<?php
/**
 * @file
 * argentinagobar_noticias.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_noticias_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function argentinagobar_noticias_node_info() {
  $items = array(
    'noticia' => array(
      'name' => t('Noticia'),
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
