<?php
/**
 * @file
 * ar_api.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ar_api_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer oauth2 server'.
  $permissions['administer oauth2 server'] = array(
    'name' => 'administer oauth2 server',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth2_server',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'use oauth2 server'.
  $permissions['use oauth2 server'] = array(
    'name' => 'use oauth2 server',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'oauth2_server',
  );

  return $permissions;
}
