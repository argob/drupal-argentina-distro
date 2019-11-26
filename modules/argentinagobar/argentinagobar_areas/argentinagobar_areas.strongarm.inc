<?php
/**
 * @file
 * argentinagobar_areas.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function argentinagobar_areas_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_area';
  $strongarm->value = 0;
  $export['comment_anonymous_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_area';
  $strongarm->value = '2';
  $export['comment_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_area';
  $strongarm->value = 1;
  $export['comment_default_mode_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_area';
  $strongarm->value = '50';
  $export['comment_default_per_page_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_area';
  $strongarm->value = 1;
  $export['comment_form_location_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_area';
  $strongarm->value = '1';
  $export['comment_preview_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_area';
  $strongarm->value = 1;
  $export['comment_subject_field_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_area';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_area';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_area';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__area';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '13',
        ),
        'title' => array(
          'weight' => '2',
        ),
        'path' => array(
          'weight' => '12',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_area';
  $strongarm->value = '1';
  $export['i18n_node_extended_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_area';
  $strongarm->value = array(
    0 => 'current',
    1 => 'required',
  );
  $export['i18n_node_options_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_area';
  $strongarm->value = '0';
  $export['language_content_type_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_area';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_area';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_area';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_area'] = $strongarm;

  return $export;
}
