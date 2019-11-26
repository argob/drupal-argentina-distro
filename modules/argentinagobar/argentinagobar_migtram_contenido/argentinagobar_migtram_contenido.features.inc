<?php
/**
 * @file
 * argentinagobar_migtram_contenido.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_migtram_contenido_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_node_info().
 */
function argentinagobar_migtram_contenido_node_info() {
  $items = array(
    'argentinagobar_migtram' => array(
      'name' => t('Migración de trámite'),
      'base' => 'node_content',
      'description' => t('Guarda todos los tramites publicados de la versión antigua de tramites.gob.ar'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
