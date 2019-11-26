<?php
/**
 * @file
 * argentinagobar_usuarios.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function argentinagobar_usuarios_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_rules:admin/config/workflow/rules
  $menu_links['management_rules:admin/config/workflow/rules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/rules',
    'router_path' => 'admin/config/workflow/rules',
    'link_title' => 'Rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage reaction rules and rule components.',
      ),
      'identifier' => 'management_rules:admin/config/workflow/rules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_workflow:admin/config/workflow',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Rules');

  return $menu_links;
}
