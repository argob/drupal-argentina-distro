<?php
/**
 * @file
 * argentinagobar_webform.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function argentinagobar_webform_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'administer panelizer node webform content'.
  $permissions['administer panelizer node webform content'] = array(
    'name' => 'administer panelizer node webform content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node webform context'.
  $permissions['administer panelizer node webform context'] = array(
    'name' => 'administer panelizer node webform context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node webform defaults'.
  $permissions['administer panelizer node webform defaults'] = array(
    'name' => 'administer panelizer node webform defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node webform layout'.
  $permissions['administer panelizer node webform layout'] = array(
    'name' => 'administer panelizer node webform layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node webform overview'.
  $permissions['administer panelizer node webform overview'] = array(
    'name' => 'administer panelizer node webform overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node webform settings'.
  $permissions['administer panelizer node webform settings'] = array(
    'name' => 'administer panelizer node webform settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'set webform_clear times'.
  $permissions['set webform_clear times'] = array(
    'name' => 'set webform_clear times',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'webform_clear',
  );

  // Exported permission: 'view any unpublished webform content'.
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'media',
  );

  return $permissions;
}
