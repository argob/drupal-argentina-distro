<?php
/**
 * @file
 * argentinagobar_aplicacion.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_aplicacion_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:aplicacion:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'aplicacion';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'pagina';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_full' => NULL,
      'header_contained' => NULL,
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '086e108a-f5dc-414e-878b-f2b417bab58d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bd6179b3-1f30-4d54-8aca-020b20ed039e';
    $pane->panel = 'content';
    $pane->type = 'imagen_destacada';
    $pane->subtype = 'imagen_destacada';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'imagen_destacada' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bd6179b3-1f30-4d54-8aca-020b20ed039e';
    $display->content['new-bd6179b3-1f30-4d54-8aca-020b20ed039e'] = $pane;
    $display->panels['content'][0] = 'new-bd6179b3-1f30-4d54-8aca-020b20ed039e';
    $pane = new stdClass();
    $pane->pid = 'new-8a4fdbaf-cd2b-4d5d-a251-8cfe4725ef44';
    $pane->panel = 'content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8a4fdbaf-cd2b-4d5d-a251-8cfe4725ef44';
    $display->content['new-8a4fdbaf-cd2b-4d5d-a251-8cfe4725ef44'] = $pane;
    $display->panels['content'][1] = 'new-8a4fdbaf-cd2b-4d5d-a251-8cfe4725ef44';
    $pane = new stdClass();
    $pane->pid = 'new-ad9baae6-b1b1-472c-94e3-1cc739ab5a9e';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ad9baae6-b1b1-472c-94e3-1cc739ab5a9e';
    $display->content['new-ad9baae6-b1b1-472c-94e3-1cc739ab5a9e'] = $pane;
    $display->panels['content'][2] = 'new-ad9baae6-b1b1-472c-94e3-1cc739ab5a9e';
    $pane = new stdClass();
    $pane->pid = 'new-3762e7a6-b8f2-44b6-95b9-85610ced989c';
    $pane->panel = 'content';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3762e7a6-b8f2-44b6-95b9-85610ced989c';
    $display->content['new-3762e7a6-b8f2-44b6-95b9-85610ced989c'] = $pane;
    $display->panels['content'][3] = 'new-3762e7a6-b8f2-44b6-95b9-85610ced989c';
    $pane = new stdClass();
    $pane->pid = 'new-0665370d-7b43-46c0-95b7-6d9ef96955f4';
    $pane->panel = 'content';
    $pane->type = 'campo';
    $pane->subtype = 'campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'store',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0665370d-7b43-46c0-95b7-6d9ef96955f4';
    $display->content['new-0665370d-7b43-46c0-95b7-6d9ef96955f4'] = $pane;
    $display->panels['content'][4] = 'new-0665370d-7b43-46c0-95b7-6d9ef96955f4';
    $pane = new stdClass();
    $pane->pid = 'new-0c3d7b3a-1c62-4702-a6b2-4544491c644a';
    $pane->panel = 'header_full';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0c3d7b3a-1c62-4702-a6b2-4544491c644a';
    $display->content['new-0c3d7b3a-1c62-4702-a6b2-4544491c644a'] = $pane;
    $display->panels['header_full'][0] = 'new-0c3d7b3a-1c62-4702-a6b2-4544491c644a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ad9baae6-b1b1-472c-94e3-1cc739ab5a9e';
  $panelizer->display = $display;
  $export['node:aplicacion:default'] = $panelizer;

  return $export;
}
