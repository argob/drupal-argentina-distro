<?php
/**
 * @file
 * argentinagobar_libros.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function argentinagobar_libros_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['book-navigation'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'book',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'argentinagobar_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'argentinagobar_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
