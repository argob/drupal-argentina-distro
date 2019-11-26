<?php
/**
 * @file
 * argentinagobar_cck.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function argentinagobar_cck_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'argentinagobar_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'argentinagobar_theme',
        'weight' => -13,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'argentinagobar_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'argentinagobar_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
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
        'weight' => 5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
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
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
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
        'weight' => 6,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
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
        'weight' => 11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
