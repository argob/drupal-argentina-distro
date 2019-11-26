<?php
/**
 * @file
 * argentinagobar_usuarios.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function argentinagobar_usuarios_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:area:editor'.
  $roles['node:area:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'area',
    'name' => 'editor',
  );

  // Exported OG Role: 'node:area:editor_servicios'.
  $roles['node:area:editor_servicios'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'area',
    'name' => 'editor_servicios',
  );

  // Exported OG Role: 'node:area:maquetador'.
  $roles['node:area:maquetador'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'area',
    'name' => 'maquetador',
  );

  // Exported OG Role: 'node:area:redactor'.
  $roles['node:area:redactor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'area',
    'name' => 'redactor',
  );

  return $roles;
}
