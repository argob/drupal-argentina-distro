<?php
/**
 * @file
 * argentinagobar_webform.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function argentinagobar_webform_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_webform-comment_body'
  $field_instances['comment-comment_node_webform-comment_body'] = array(
    'bundle' => 'comment_node_webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-webform-body'
  $field_instances['node-webform-body'] = array(
    'bundle' => 'webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-webform-field_creditos'
  $field_instances['node-webform-field_creditos'] = array(
    'bundle' => 'webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_creditos',
    'label' => 'Créditos',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-webform-field_download'
  $field_instances['node-webform-field_download'] = array(
    'bundle' => 'webform',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_download',
    'label' => 'Descarga',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => '',
      'file_extensions' => 'txt pdf zip doc docx xlsx xls jpg png',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => array(
          0 => 'auto',
        ),
        'insert_styles' => array(
          0 => 'auto',
        ),
        'insert_width' => '',
        'markdown_insert' => FALSE,
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-webform-field_featured_image'
  $field_instances['node-webform-field_featured_image'] = array(
    'bundle' => 'webform',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_featured_image',
    'label' => 'Imagen destacada',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => array(
          0 => 'auto',
        ),
        'insert_styles' => array(
          0 => 'auto',
        ),
        'insert_width' => '',
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 0,
        'manualcrop_filter_insert' => TRUE,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'markdown_insert' => FALSE,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-webform-field_tags'
  $field_instances['node-webform-field_tags'] = array(
    'bundle' => 'webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-webform-og_group_ref'
  $field_instances['node-webform-og_group_ref'] = array(
    'bundle' => 'webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => FALSE,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Comment');
  t('Créditos');
  t('Descarga');
  t('Groups audience');
  t('Imagen destacada');
  t('Tags');

  return $field_instances;
}
