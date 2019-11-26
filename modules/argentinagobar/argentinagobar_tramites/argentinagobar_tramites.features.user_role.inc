<?php
/**
 * @file
 * argentinagobar_tramites.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function argentinagobar_tramites_user_default_roles() {
  $roles = array();

  // Exported role: relevador servicios.
  $roles['relevador servicios'] = array(
    'name' => 'relevador servicios',
    'weight' => 9,
  );

  return $roles;
}
