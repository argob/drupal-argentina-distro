<?php
/**
 * @file
 * argentinagobar_inicio.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function argentinagobar_inicio_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-footer-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-1',
    'module' => 'menu',
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

  $export['menu-menu-footer-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-2',
    'module' => 'menu',
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
        'region' => 'footer2',
        'status' => 1,
        'theme' => 'argentinagobar_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-3',
    'module' => 'menu',
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
        'region' => 'footer3',
        'status' => 1,
        'theme' => 'argentinagobar_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-4',
    'module' => 'menu',
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
