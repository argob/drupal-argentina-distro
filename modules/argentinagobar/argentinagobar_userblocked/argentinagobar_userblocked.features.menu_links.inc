<?php
/**
 * @file
 * argentinagobar_userblocked.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function argentinagobar_userblocked_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_prune-inactive-users:admin/people/user-prune
  $menu_links['management_prune-inactive-users:admin/people/user-prune'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people/user-prune',
    'router_path' => 'admin/people/user-prune',
    'link_title' => 'Prune inactive users',
    'options' => array(
      'attributes' => array(
        'title' => 'Set rules to deal with inactive users',
      ),
      'identifier' => 'management_prune-inactive-users:admin/people/user-prune',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_people:admin/people',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Prune inactive users');

  return $menu_links;
}
