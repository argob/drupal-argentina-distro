<?php
/**
 * @file
 * argentinagobar_webform.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_webform_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:webform:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'webform';
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
      'navegacion_atajos' => NULL,
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
  $display->uuid = '59624d94-3211-4a0c-bb7a-81bbe0c6a8a3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f5461a03-1b8a-4000-a245-e7ade459dbc0';
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
    $pane->uuid = 'f5461a03-1b8a-4000-a245-e7ade459dbc0';
    $display->content['new-f5461a03-1b8a-4000-a245-e7ade459dbc0'] = $pane;
    $display->panels['content'][0] = 'new-f5461a03-1b8a-4000-a245-e7ade459dbc0';
    $pane = new stdClass();
    $pane->pid = 'new-41030322-8024-4814-aad5-eeaf0edf3ffb';
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
    $pane->uuid = '41030322-8024-4814-aad5-eeaf0edf3ffb';
    $display->content['new-41030322-8024-4814-aad5-eeaf0edf3ffb'] = $pane;
    $display->panels['content'][1] = 'new-41030322-8024-4814-aad5-eeaf0edf3ffb';
    $pane = new stdClass();
    $pane->pid = 'new-ebb4a97d-77ba-46b4-9170-045f52b61e1d';
    $pane->panel = 'content';
    $pane->type = 'redes_sociales';
    $pane->subtype = 'redes_sociales';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'titulo' => 'Redes Sociales',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ebb4a97d-77ba-46b4-9170-045f52b61e1d';
    $display->content['new-ebb4a97d-77ba-46b4-9170-045f52b61e1d'] = $pane;
    $display->panels['content'][2] = 'new-ebb4a97d-77ba-46b4-9170-045f52b61e1d';
    $pane = new stdClass();
    $pane->pid = 'new-239b7b1b-06c7-4af4-b352-5e2ddaf58735';
    $pane->panel = 'content';
    $pane->type = 'separador';
    $pane->subtype = 'separador';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'linea' => 1,
      'override_title' => 1,
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
    $pane->uuid = '239b7b1b-06c7-4af4-b352-5e2ddaf58735';
    $display->content['new-239b7b1b-06c7-4af4-b352-5e2ddaf58735'] = $pane;
    $display->panels['content'][3] = 'new-239b7b1b-06c7-4af4-b352-5e2ddaf58735';
    $pane = new stdClass();
    $pane->pid = 'new-e01a40cf-e3b9-44b0-8e97-fa0fdcb291de';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e01a40cf-e3b9-44b0-8e97-fa0fdcb291de';
    $display->content['new-e01a40cf-e3b9-44b0-8e97-fa0fdcb291de'] = $pane;
    $display->panels['content'][4] = 'new-e01a40cf-e3b9-44b0-8e97-fa0fdcb291de';
    $pane = new stdClass();
    $pane->pid = 'new-1ada99a0-1cac-4294-8dd5-1f4192f28d49';
    $pane->panel = 'content';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:webform';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->uuid = '1ada99a0-1cac-4294-8dd5-1f4192f28d49';
    $display->content['new-1ada99a0-1cac-4294-8dd5-1f4192f28d49'] = $pane;
    $display->panels['content'][5] = 'new-1ada99a0-1cac-4294-8dd5-1f4192f28d49';
    $pane = new stdClass();
    $pane->pid = 'new-2cc027e3-632f-406e-9017-36a3deae6aa2';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_creditos';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '2cc027e3-632f-406e-9017-36a3deae6aa2';
    $display->content['new-2cc027e3-632f-406e-9017-36a3deae6aa2'] = $pane;
    $display->panels['content'][6] = 'new-2cc027e3-632f-406e-9017-36a3deae6aa2';
    $pane = new stdClass();
    $pane->pid = 'new-943a678b-b42f-4a30-9602-78399f3a35e3';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '943a678b-b42f-4a30-9602-78399f3a35e3';
    $display->content['new-943a678b-b42f-4a30-9602-78399f3a35e3'] = $pane;
    $display->panels['content'][7] = 'new-943a678b-b42f-4a30-9602-78399f3a35e3';
    $pane = new stdClass();
    $pane->pid = 'new-11f17bfb-c49c-4771-b5d5-0cee8aa0d3c5';
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
    $pane->uuid = '11f17bfb-c49c-4771-b5d5-0cee8aa0d3c5';
    $display->content['new-11f17bfb-c49c-4771-b5d5-0cee8aa0d3c5'] = $pane;
    $display->panels['header_contained'][0] = 'new-11f17bfb-c49c-4771-b5d5-0cee8aa0d3c5';
    $pane = new stdClass();
    $pane->pid = 'new-2220f944-b4bb-4ea6-8623-74f507b13acf';
    $pane->panel = 'header_full';
    $pane->type = 'imagen_destacada';
    $pane->subtype = 'imagen_destacada';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'formato' => 'JumbotronUnaColumna',
      'tipo_background' => 'JumbotronImage',
      'patron' => 0,
      'align' => 'align-top',
      'overlay' => 0,
      'visualizacion_titulo' => 1,
      'showIcono' => 0,
      'logotipo' => 0,
      'mostrar_boton' => TRUE,
      'texto_boton' => '',
      'href' => '',
      'color_boton' => 'btn-default',
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
    $pane->uuid = '2220f944-b4bb-4ea6-8623-74f507b13acf';
    $display->content['new-2220f944-b4bb-4ea6-8623-74f507b13acf'] = $pane;
    $display->panels['header_full'][0] = 'new-2220f944-b4bb-4ea6-8623-74f507b13acf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:webform:default'] = $panelizer;

  return $export;
}
