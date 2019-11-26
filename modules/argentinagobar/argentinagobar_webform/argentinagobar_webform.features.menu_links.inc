<?php
/**
 * @file
 * argentinagobar_webform.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function argentinagobar_webform_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_webform-clear:admin/config/content/webform_clear
  $menu_links['management_webform-clear:admin/config/content/webform_clear'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/webform_clear',
    'router_path' => 'admin/config/content/webform_clear',
    'link_title' => 'Webform Clear',
    'options' => array(
      'attributes' => array(
        'title' => 'Set up default Webform submission storage.',
      ),
      'identifier' => 'management_webform-clear:admin/config/content/webform_clear',
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
  // Exported menu link: management_webform-settings:admin/config/content/webform
  $menu_links['management_webform-settings:admin/config/content/webform'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/webform',
    'router_path' => 'admin/config/content/webform',
    'link_title' => 'Webform settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Global configuration of webform functionality.',
      ),
      'identifier' => 'management_webform-settings:admin/config/content/webform',
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
  // Exported menu link: navigation_webform:node/add/webform
  $menu_links['navigation_webform:node/add/webform'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Webform',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      ),
      'identifier' => 'navigation_webform:node/add/webform',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Webform');
  t('Webform Clear');
  t('Webform settings');

  return $menu_links;
}
