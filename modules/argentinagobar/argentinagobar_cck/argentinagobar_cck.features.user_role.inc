<?php
/**
 * @file
 * argentinagobar_cck.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function argentinagobar_cck_user_default_roles() {
  $roles = array();

  // Exported role: Editor de Contenido.
  $roles['Editor de Contenido'] = array(
    'name' => 'Editor de Contenido',
    'weight' => 2,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
