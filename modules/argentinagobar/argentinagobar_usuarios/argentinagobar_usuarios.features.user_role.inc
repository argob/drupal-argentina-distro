<?php
/**
 * @file
 * argentinagobar_usuarios.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function argentinagobar_usuarios_user_default_roles() {
  $roles = array();

  // Exported role: administrador drupal.
  $roles['administrador drupal'] = array(
    'name' => 'administrador drupal',
    'weight' => 8,
  );

  // Exported role: administrador usuarios.
  $roles['administrador usuarios'] = array(
    'name' => 'administrador usuarios',
    'weight' => 9,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 7,
  );

  // Exported role: editor servicios.
  $roles['editor servicios'] = array(
    'name' => 'editor servicios',
    'weight' => 14,
  );

  // Exported role: maquetador.
  $roles['maquetador'] = array(
    'name' => 'maquetador',
    'weight' => 13,
  );

  // Exported role: moderador.
  $roles['moderador'] = array(
    'name' => 'moderador',
    'weight' => 10,
  );

  // Exported role: seguidor.
  $roles['seguidor'] = array(
    'name' => 'seguidor',
    'weight' => 11,
  );

  return $roles;
}
