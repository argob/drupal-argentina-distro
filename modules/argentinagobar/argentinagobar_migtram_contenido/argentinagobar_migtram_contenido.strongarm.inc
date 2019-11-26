<?php
/**
 * @file
 * argentinagobar_migtram_contenido.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function argentinagobar_migtram_contenido_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_argentinagobar_migtram';
  $strongarm->value = 0;
  $export['comment_anonymous_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_argentinagobar_migtram';
  $strongarm->value = '2';
  $export['comment_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_argentinagobar_migtram';
  $strongarm->value = 1;
  $export['comment_default_mode_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_argentinagobar_migtram';
  $strongarm->value = '50';
  $export['comment_default_per_page_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_argentinagobar_migtram';
  $strongarm->value = 1;
  $export['comment_form_location_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_argentinagobar_migtram';
  $strongarm->value = '1';
  $export['comment_preview_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_argentinagobar_migtram';
  $strongarm->value = 1;
  $export['comment_subject_field_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__argentinagobar_migtram';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '24',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '22',
        ),
        'redirect' => array(
          'weight' => '21',
        ),
        'xmlsitemap' => array(
          'weight' => '23',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_argentinagobar_migtram';
  $strongarm->value = '0';
  $export['language_content_type_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_argentinagobar_migtram';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_argentinagobar_migtram';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_argentinagobar_migtram';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_argentinagobar_migtram';
  $strongarm->value = '1';
  $export['node_preview_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_argentinagobar_migtram';
  $strongarm->value = 1;
  $export['node_submitted_argentinagobar_migtram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_argentinagobar_migtram';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 0,
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
  $export['panelizer_defaults_node_argentinagobar_migtram'] = $strongarm;

  return $export;
}
