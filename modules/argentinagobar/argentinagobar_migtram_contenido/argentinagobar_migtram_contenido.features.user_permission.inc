<?php
/**
 * @file
 * argentinagobar_migtram_contenido.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function argentinagobar_migtram_contenido_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_flag'.
  $permissions['create field_flag'] = array(
    'name' => 'create field_flag',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_flag'.
  $permissions['edit field_flag'] = array(
    'name' => 'edit field_flag',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_flag'.
  $permissions['edit own field_flag'] = array(
    'name' => 'edit own field_flag',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_flag'.
  $permissions['view field_flag'] = array(
    'name' => 'view field_flag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_flag'.
  $permissions['view own field_flag'] = array(
    'name' => 'view own field_flag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
