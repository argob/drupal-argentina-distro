<?php
/**
 * @file
 * argentinagobar_usuarios.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function argentinagobar_usuarios_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:area:add user'
  $permissions['node:area:add user'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:administer group'
  $permissions['node:area:administer group'] = array(
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:approve and deny subscription'
  $permissions['node:area:approve and deny subscription'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:create area content'
  $permissions['node:area:create area content'] = array(
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:create book content'
  $permissions['node:area:create book content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:create noticia content'
  $permissions['node:area:create noticia content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:create page content'
  $permissions['node:area:create page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:create tramite content'
  $permissions['node:area:create tramite content'] = array(
    'roles' => array(
      'editor_servicios' => 'editor_servicios',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:create webform content'
  $permissions['node:area:create webform content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:delete any area content'
  $permissions['node:area:delete any area content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:delete any book content'
  $permissions['node:area:delete any book content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete any noticia content'
  $permissions['node:area:delete any noticia content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete any page content'
  $permissions['node:area:delete any page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete any tramite content'
  $permissions['node:area:delete any tramite content'] = array(
    'roles' => array(
      'editor_servicios' => 'editor_servicios',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete any webform content'
  $permissions['node:area:delete any webform content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete own area content'
  $permissions['node:area:delete own area content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:delete own book content'
  $permissions['node:area:delete own book content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete own noticia content'
  $permissions['node:area:delete own noticia content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete own page content'
  $permissions['node:area:delete own page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete own tramite content'
  $permissions['node:area:delete own tramite content'] = array(
    'roles' => array(
      'editor_servicios' => 'editor_servicios',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:delete own webform content'
  $permissions['node:area:delete own webform content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:manage members'
  $permissions['node:area:manage members'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:manage menu'
  $permissions['node:area:manage menu'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:manage permissions'
  $permissions['node:area:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:manage roles'
  $permissions['node:area:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:subscribe'
  $permissions['node:area:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:area:subscribe without approval'
  $permissions['node:area:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:area:unsubscribe'
  $permissions['node:area:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:area:update any area content'
  $permissions['node:area:update any area content'] = array(
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update any book content'
  $permissions['node:area:update any book content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update any noticia content'
  $permissions['node:area:update any noticia content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update any page content'
  $permissions['node:area:update any page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update any tramite content'
  $permissions['node:area:update any tramite content'] = array(
    'roles' => array(
      'editor_servicios' => 'editor_servicios',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update any webform content'
  $permissions['node:area:update any webform content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update group'
  $permissions['node:area:update group'] = array(
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update own area content'
  $permissions['node:area:update own area content'] = array(
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update own book content'
  $permissions['node:area:update own book content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:update own noticia content'
  $permissions['node:area:update own noticia content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:update own page content'
  $permissions['node:area:update own page content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  // Exported og permission: 'node:area:update own tramite content'
  $permissions['node:area:update own tramite content'] = array(
    'roles' => array(
      'editor_servicios' => 'editor_servicios',
      'maquetador' => 'maquetador',
    ),
  );

  // Exported og permission: 'node:area:update own webform content'
  $permissions['node:area:update own webform content'] = array(
    'roles' => array(
      'editor' => 'editor',
      'maquetador' => 'maquetador',
      'redactor' => 'redactor',
    ),
  );

  return $permissions;
}
