<?php
/**
 * @file
 * argentinagobar_libros.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_libros_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
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
 * Implements hook_views_api().
 */
function argentinagobar_libros_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function argentinagobar_libros_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Página de libro'),
      'base' => 'node_content',
      'description' => t('<em>Los libros</em> tienen una navegación interna jerarquizada. Úselos para cosas como manuales o tutoriales.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
