<?php
/**
 * @file
 * argentinagobar_reglas.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function argentinagobar_reglas_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'setup own tfa'.
  $permissions['setup own tfa'] = array(
    'name' => 'setup own tfa',
    'roles' => array(
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
      'moderador' => 'moderador',
    ),
    'module' => 'tfa_basic',
  );

  return $permissions;
}
