<?php
/**
 * @file
 * argentinagobar_migtram_contenido.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_migtram_contenido_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:argentinagobar_migtram:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'argentinagobar_migtram';
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
  $display->layout = 'tramite';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_full' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '599a9442-6918-4b0c-af4c-d973f9c7f090';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed03db66-825a-4271-9ff5-bf7c0bd7d737';
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
    $pane->uuid = 'ed03db66-825a-4271-9ff5-bf7c0bd7d737';
    $display->content['new-ed03db66-825a-4271-9ff5-bf7c0bd7d737'] = $pane;
    $display->panels['content'][0] = 'new-ed03db66-825a-4271-9ff5-bf7c0bd7d737';
    $pane = new stdClass();
    $pane->pid = 'new-b6d8e4f7-4ecb-4200-874e-e6b8134c9700';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'acciones',
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
    $pane->uuid = 'b6d8e4f7-4ecb-4200-874e-e6b8134c9700';
    $display->content['new-b6d8e4f7-4ecb-4200-874e-e6b8134c9700'] = $pane;
    $display->panels['content'][1] = 'new-b6d8e4f7-4ecb-4200-874e-e6b8134c9700';
    $pane = new stdClass();
    $pane->pid = 'new-0ed345bd-bb5f-4336-bc59-87fed577df27';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_texto';
    $pane->subtype = 'arg_migtram_texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'sobreescribir' => 0,
      'cuerpo_o_resumen' => 'body',
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
    $pane->uuid = '0ed345bd-bb5f-4336-bc59-87fed577df27';
    $display->content['new-0ed345bd-bb5f-4336-bc59-87fed577df27'] = $pane;
    $display->panels['content'][2] = 'new-0ed345bd-bb5f-4336-bc59-87fed577df27';
    $pane = new stdClass();
    $pane->pid = 'new-409481da-8fe0-43f3-a1fa-08dc82d3f2bc';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'requisitos',
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
    $pane->uuid = '409481da-8fe0-43f3-a1fa-08dc82d3f2bc';
    $display->content['new-409481da-8fe0-43f3-a1fa-08dc82d3f2bc'] = $pane;
    $display->panels['content'][3] = 'new-409481da-8fe0-43f3-a1fa-08dc82d3f2bc';
    $pane = new stdClass();
    $pane->pid = 'new-9542340a-a5b1-43b1-8d00-d7a9fb8c1e68';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'comosehace',
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
    $pane->uuid = '9542340a-a5b1-43b1-8d00-d7a9fb8c1e68';
    $display->content['new-9542340a-a5b1-43b1-8d00-d7a9fb8c1e68'] = $pane;
    $display->panels['content'][4] = 'new-9542340a-a5b1-43b1-8d00-d7a9fb8c1e68';
    $pane = new stdClass();
    $pane->pid = 'new-c5e3a0f9-720e-46ac-ac3f-8a6e8f4a07a7';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'costo',
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
    $pane->uuid = 'c5e3a0f9-720e-46ac-ac3f-8a6e8f4a07a7';
    $display->content['new-c5e3a0f9-720e-46ac-ac3f-8a6e8f4a07a7'] = $pane;
    $display->panels['content'][5] = 'new-c5e3a0f9-720e-46ac-ac3f-8a6e8f4a07a7';
    $pane = new stdClass();
    $pane->pid = 'new-74b6218c-dc3b-4c0b-b254-11f94f1b2f40';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'vigencia',
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
    $pane->uuid = '74b6218c-dc3b-4c0b-b254-11f94f1b2f40';
    $display->content['new-74b6218c-dc3b-4c0b-b254-11f94f1b2f40'] = $pane;
    $display->panels['content'][6] = 'new-74b6218c-dc3b-4c0b-b254-11f94f1b2f40';
    $pane = new stdClass();
    $pane->pid = 'new-5913a959-6b23-4d9f-83cf-b40459aaceb6';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'asistencias',
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
    $pane->uuid = '5913a959-6b23-4d9f-83cf-b40459aaceb6';
    $display->content['new-5913a959-6b23-4d9f-83cf-b40459aaceb6'] = $pane;
    $display->panels['content'][7] = 'new-5913a959-6b23-4d9f-83cf-b40459aaceb6';
    $pane = new stdClass();
    $pane->pid = 'new-0e13d0e0-82a5-4914-8ce3-97414b7c9748';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'tiempo_de_entrega',
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '0e13d0e0-82a5-4914-8ce3-97414b7c9748';
    $display->content['new-0e13d0e0-82a5-4914-8ce3-97414b7c9748'] = $pane;
    $display->panels['content'][8] = 'new-0e13d0e0-82a5-4914-8ce3-97414b7c9748';
    $pane = new stdClass();
    $pane->pid = 'new-fb48c810-02d5-4765-b8bf-0279025620f6';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'observaciones',
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
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'fb48c810-02d5-4765-b8bf-0279025620f6';
    $display->content['new-fb48c810-02d5-4765-b8bf-0279025620f6'] = $pane;
    $display->panels['content'][9] = 'new-fb48c810-02d5-4765-b8bf-0279025620f6';
    $pane = new stdClass();
    $pane->pid = 'new-329e224c-6e12-439e-bd99-6887e46d8c51';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'donde',
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
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '329e224c-6e12-439e-bd99-6887e46d8c51';
    $display->content['new-329e224c-6e12-439e-bd99-6887e46d8c51'] = $pane;
    $display->panels['content'][10] = 'new-329e224c-6e12-439e-bd99-6887e46d8c51';
    $pane = new stdClass();
    $pane->pid = 'new-60539122-e412-448d-a440-2bbe00cca5a5';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'cuando',
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
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '60539122-e412-448d-a440-2bbe00cca5a5';
    $display->content['new-60539122-e412-448d-a440-2bbe00cca5a5'] = $pane;
    $display->panels['content'][11] = 'new-60539122-e412-448d-a440-2bbe00cca5a5';
    $pane = new stdClass();
    $pane->pid = 'new-07ddf3db-7485-4603-99a5-1011a3588954';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'sms',
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
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = '07ddf3db-7485-4603-99a5-1011a3588954';
    $display->content['new-07ddf3db-7485-4603-99a5-1011a3588954'] = $pane;
    $display->panels['content'][12] = 'new-07ddf3db-7485-4603-99a5-1011a3588954';
    $pane = new stdClass();
    $pane->pid = 'new-d763a5e2-8262-451b-ace8-80537d928e1d';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'carta_compromiso',
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
    $pane->position = 13;
    $pane->locks = array();
    $pane->uuid = 'd763a5e2-8262-451b-ace8-80537d928e1d';
    $display->content['new-d763a5e2-8262-451b-ace8-80537d928e1d'] = $pane;
    $display->panels['content'][13] = 'new-d763a5e2-8262-451b-ace8-80537d928e1d';
    $pane = new stdClass();
    $pane->pid = 'new-2f1e5f61-22cd-4169-a62b-73aaec792aab';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_campo';
    $pane->subtype = 'arg_migtram_campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'acciones',
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
    $pane->position = 14;
    $pane->locks = array();
    $pane->uuid = '2f1e5f61-22cd-4169-a62b-73aaec792aab';
    $display->content['new-2f1e5f61-22cd-4169-a62b-73aaec792aab'] = $pane;
    $display->panels['content'][14] = 'new-2f1e5f61-22cd-4169-a62b-73aaec792aab';
    $pane = new stdClass();
    $pane->pid = 'new-42f61003-2dc5-4f51-b8ac-84350fe8c4c2';
    $pane->panel = 'content';
    $pane->type = 'campo';
    $pane->subtype = 'campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'download',
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
    $pane->position = 15;
    $pane->locks = array();
    $pane->uuid = '42f61003-2dc5-4f51-b8ac-84350fe8c4c2';
    $display->content['new-42f61003-2dc5-4f51-b8ac-84350fe8c4c2'] = $pane;
    $display->panels['content'][15] = 'new-42f61003-2dc5-4f51-b8ac-84350fe8c4c2';
    $pane = new stdClass();
    $pane->pid = 'new-fca1bc27-66f6-471d-9c4e-8356efd64059';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'argentinagobar_bloques_reportes-formulario_reportes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 16;
    $pane->locks = array();
    $pane->uuid = 'fca1bc27-66f6-471d-9c4e-8356efd64059';
    $display->content['new-fca1bc27-66f6-471d-9c4e-8356efd64059'] = $pane;
    $display->panels['content'][16] = 'new-fca1bc27-66f6-471d-9c4e-8356efd64059';
    $pane = new stdClass();
    $pane->pid = 'new-74612403-0f84-40d6-aa79-45cd778df8e4';
    $pane->panel = 'header_full';
    $pane->type = 'arg_migtram_imagen_destacada';
    $pane->subtype = 'arg_migtram_imagen_destacada';
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
    $pane->uuid = '74612403-0f84-40d6-aa79-45cd778df8e4';
    $display->content['new-74612403-0f84-40d6-aa79-45cd778df8e4'] = $pane;
    $display->panels['header_full'][0] = 'new-74612403-0f84-40d6-aa79-45cd778df8e4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:argentinagobar_migtram:default'] = $panelizer;

  return $export;
}
