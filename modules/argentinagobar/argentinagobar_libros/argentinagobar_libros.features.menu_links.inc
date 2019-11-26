<?php
/**
 * @file
 * argentinagobar_libros.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function argentinagobar_libros_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_panelizer:admin/config/content/panelizer
  $menu_links['management_panelizer:admin/config/content/panelizer'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/panelizer',
    'router_path' => 'admin/config/content/panelizer',
    'link_title' => 'Panelizer',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure panelizer availability and defaults',
      ),
      'identifier' => 'management_panelizer:admin/config/content/panelizer',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Panelizer');

  return $menu_links;
}
