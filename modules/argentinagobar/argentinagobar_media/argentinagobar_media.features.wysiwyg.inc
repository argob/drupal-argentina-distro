<?php
/**
 * @file
 * argentinagobar_media.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function argentinagobar_media_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: full_html
  $profiles['full_html'] = array(
    'format' => 'full_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Blockquote' => 1,
          'Source' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'RemoveFormat' => 1,
          'Styles' => 1,
          'SelectAll' => 1,
          'Maximize' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => 'Título enrorme=h1
Título grande=h2
Título mediano=h3
Título chico=h4
Título mini=h5
Cita=blockquote
Párrafo=p
Texto chico=small',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: plain_text
  $profiles['plain_text'] = array(
    'format' => 'plain_text',
    'editor' => 'ckeditor',
    'settings' => FALSE,
    'rdf_mapping' => array(),
  );

  return $profiles;
}
