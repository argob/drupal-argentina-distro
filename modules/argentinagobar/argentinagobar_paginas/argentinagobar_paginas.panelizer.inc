<?php
/**
 * @file
 * argentinagobar_paginas.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_paginas_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:page:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'page';
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
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
      'header_contained' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
      'navegacion_atajos' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '08021731-2f17-4129-9865-0c943028b9c4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6938e619-15ea-4783-bf6b-f66fd24651a6';
    $pane->panel = 'content';
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
    $pane->uuid = '6938e619-15ea-4783-bf6b-f66fd24651a6';
    $display->content['new-6938e619-15ea-4783-bf6b-f66fd24651a6'] = $pane;
    $display->panels['content'][0] = 'new-6938e619-15ea-4783-bf6b-f66fd24651a6';
    $pane = new stdClass();
    $pane->pid = 'new-9d835c63-b11b-4bc9-bf2e-43b075007ba7';
    $pane->panel = 'content';
    $pane->type = 'titulo';
    $pane->subtype = 'titulo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tag' => 'h1',
      'texto' => '',
      'sobreescribir_titulo' => 0,
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
    $pane->uuid = '9d835c63-b11b-4bc9-bf2e-43b075007ba7';
    $display->content['new-9d835c63-b11b-4bc9-bf2e-43b075007ba7'] = $pane;
    $display->panels['content'][1] = 'new-9d835c63-b11b-4bc9-bf2e-43b075007ba7';
    $pane = new stdClass();
    $pane->pid = 'new-10f1c203-356b-4e64-b165-34e9bf915516';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_summary_or_trimmed',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '1',
      ),
      'context' => 'panelizer',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '10f1c203-356b-4e64-b165-34e9bf915516';
    $display->content['new-10f1c203-356b-4e64-b165-34e9bf915516'] = $pane;
    $display->panels['content'][2] = 'new-10f1c203-356b-4e64-b165-34e9bf915516';
    $pane = new stdClass();
    $pane->pid = 'new-6b7a393a-0c9d-4a29-89d2-cbd4ff69c992';
    $pane->panel = 'content';
    $pane->type = 'redes_sociales';
    $pane->subtype = 'redes_sociales';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'titulo' => 'Compartir en<br> redes sociales',
      'tipo_widget' => 'share',
      'tipo_widget_timeline' => 'facebook',
      'fb_page_url' => '',
      'fb_altura' => '70',
      'fb_mostrar_post' => 1,
      'fb_mostrar_fotos_amigos' => 1,
      'fb_ocultar_portada' => 0,
      'tw_widget_id' => '',
      'tw_screen_name' => '',
      'widget_share_alineacion' => 'izquierda',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6b7a393a-0c9d-4a29-89d2-cbd4ff69c992';
    $display->content['new-6b7a393a-0c9d-4a29-89d2-cbd4ff69c992'] = $pane;
    $display->panels['content'][3] = 'new-6b7a393a-0c9d-4a29-89d2-cbd4ff69c992';
    $pane = new stdClass();
    $pane->pid = 'new-5a11eb1c-752e-46df-8403-27f8afac92f6';
    $pane->panel = 'content';
    $pane->type = 'separador';
    $pane->subtype = 'separador';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'linea' => 1,
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
    $pane->uuid = '5a11eb1c-752e-46df-8403-27f8afac92f6';
    $display->content['new-5a11eb1c-752e-46df-8403-27f8afac92f6'] = $pane;
    $display->panels['content'][4] = 'new-5a11eb1c-752e-46df-8403-27f8afac92f6';
    $pane = new stdClass();
    $pane->pid = 'new-fa5a26c0-b85f-4d6a-bfa1-87433f97900b';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'fa5a26c0-b85f-4d6a-bfa1-87433f97900b';
    $display->content['new-fa5a26c0-b85f-4d6a-bfa1-87433f97900b'] = $pane;
    $display->panels['content'][5] = 'new-fa5a26c0-b85f-4d6a-bfa1-87433f97900b';
    $pane = new stdClass();
    $pane->pid = 'new-66e04016-3d7e-423e-878d-e48ec4214f7a';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_download';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '66e04016-3d7e-423e-878d-e48ec4214f7a';
    $display->content['new-66e04016-3d7e-423e-878d-e48ec4214f7a'] = $pane;
    $display->panels['content'][6] = 'new-66e04016-3d7e-423e-878d-e48ec4214f7a';
    $pane = new stdClass();
    $pane->pid = 'new-a49cfa98-7791-40f6-935b-b005566776fe';
    $pane->panel = 'header_contained';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a49cfa98-7791-40f6-935b-b005566776fe';
    $display->content['new-a49cfa98-7791-40f6-935b-b005566776fe'] = $pane;
    $display->panels['header_contained'][0] = 'new-a49cfa98-7791-40f6-935b-b005566776fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:page:default'] = $panelizer;

  return $export;
}
