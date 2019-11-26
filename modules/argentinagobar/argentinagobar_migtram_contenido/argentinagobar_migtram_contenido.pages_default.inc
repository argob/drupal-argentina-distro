<?php
/**
 * @file
 * argentinagobar_migtram_contenido.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function argentinagobar_migtram_contenido_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__tr_mite_migrado';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Trámite migrado',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'tr_mite_migrado',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'argentinagobar_migtram' => 'argentinagobar_migtram',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
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
  $display->title = '';
  $display->uuid = 'f96551ba-75e5-424d-b56a-83d8f33a1f4e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-99723b38-88cc-4dbb-b267-2d37d06e94c2';
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
    $pane->uuid = '99723b38-88cc-4dbb-b267-2d37d06e94c2';
    $display->content['new-99723b38-88cc-4dbb-b267-2d37d06e94c2'] = $pane;
    $display->panels['content'][0] = 'new-99723b38-88cc-4dbb-b267-2d37d06e94c2';
    $pane = new stdClass();
    $pane->pid = 'new-9e2dfcab-3c9e-4f3c-970d-4537a6973fc8';
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
    $pane->uuid = '9e2dfcab-3c9e-4f3c-970d-4537a6973fc8';
    $display->content['new-9e2dfcab-3c9e-4f3c-970d-4537a6973fc8'] = $pane;
    $display->panels['content'][1] = 'new-9e2dfcab-3c9e-4f3c-970d-4537a6973fc8';
    $pane = new stdClass();
    $pane->pid = 'new-64c01024-5cce-4d39-8ceb-93be88997931';
    $pane->panel = 'content';
    $pane->type = 'arg_migtram_texto';
    $pane->subtype = 'arg_migtram_texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '',
        'format' => 'filtered_html',
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
    $pane->uuid = '64c01024-5cce-4d39-8ceb-93be88997931';
    $display->content['new-64c01024-5cce-4d39-8ceb-93be88997931'] = $pane;
    $display->panels['content'][2] = 'new-64c01024-5cce-4d39-8ceb-93be88997931';
    $pane = new stdClass();
    $pane->pid = 'new-a9aa6830-0c91-4c92-ad1b-d6a1eb2a566b';
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
    $pane->uuid = 'a9aa6830-0c91-4c92-ad1b-d6a1eb2a566b';
    $display->content['new-a9aa6830-0c91-4c92-ad1b-d6a1eb2a566b'] = $pane;
    $display->panels['content'][3] = 'new-a9aa6830-0c91-4c92-ad1b-d6a1eb2a566b';
    $pane = new stdClass();
    $pane->pid = 'new-c66ded85-586f-485c-85db-cd1811048332';
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
    $pane->uuid = 'c66ded85-586f-485c-85db-cd1811048332';
    $display->content['new-c66ded85-586f-485c-85db-cd1811048332'] = $pane;
    $display->panels['content'][4] = 'new-c66ded85-586f-485c-85db-cd1811048332';
    $pane = new stdClass();
    $pane->pid = 'new-a1aafa1a-a492-4b60-b2e3-ca7463e006a1';
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
    $pane->uuid = 'a1aafa1a-a492-4b60-b2e3-ca7463e006a1';
    $display->content['new-a1aafa1a-a492-4b60-b2e3-ca7463e006a1'] = $pane;
    $display->panels['content'][5] = 'new-a1aafa1a-a492-4b60-b2e3-ca7463e006a1';
    $pane = new stdClass();
    $pane->pid = 'new-024fc4af-7cce-44e2-bf24-fdc634db602d';
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
    $pane->uuid = '024fc4af-7cce-44e2-bf24-fdc634db602d';
    $display->content['new-024fc4af-7cce-44e2-bf24-fdc634db602d'] = $pane;
    $display->panels['content'][6] = 'new-024fc4af-7cce-44e2-bf24-fdc634db602d';
    $pane = new stdClass();
    $pane->pid = 'new-b6a33df5-cda3-4479-96fc-345122170bba';
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
    $pane->uuid = 'b6a33df5-cda3-4479-96fc-345122170bba';
    $display->content['new-b6a33df5-cda3-4479-96fc-345122170bba'] = $pane;
    $display->panels['content'][7] = 'new-b6a33df5-cda3-4479-96fc-345122170bba';
    $pane = new stdClass();
    $pane->pid = 'new-f30f4d04-2462-498f-b04e-1938535e9ead';
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
    $pane->uuid = 'f30f4d04-2462-498f-b04e-1938535e9ead';
    $display->content['new-f30f4d04-2462-498f-b04e-1938535e9ead'] = $pane;
    $display->panels['content'][8] = 'new-f30f4d04-2462-498f-b04e-1938535e9ead';
    $pane = new stdClass();
    $pane->pid = 'new-fc4db6c0-d498-46fb-9769-1691fb3e7a34';
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
    $pane->uuid = 'fc4db6c0-d498-46fb-9769-1691fb3e7a34';
    $display->content['new-fc4db6c0-d498-46fb-9769-1691fb3e7a34'] = $pane;
    $display->panels['content'][9] = 'new-fc4db6c0-d498-46fb-9769-1691fb3e7a34';
    $pane = new stdClass();
    $pane->pid = 'new-09ba31f7-510f-49d2-bd5b-d6800ee1186c';
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
    $pane->uuid = '09ba31f7-510f-49d2-bd5b-d6800ee1186c';
    $display->content['new-09ba31f7-510f-49d2-bd5b-d6800ee1186c'] = $pane;
    $display->panels['content'][10] = 'new-09ba31f7-510f-49d2-bd5b-d6800ee1186c';
    $pane = new stdClass();
    $pane->pid = 'new-270acbac-d089-46b1-9737-e953b713aac8';
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
    $pane->uuid = '270acbac-d089-46b1-9737-e953b713aac8';
    $display->content['new-270acbac-d089-46b1-9737-e953b713aac8'] = $pane;
    $display->panels['content'][11] = 'new-270acbac-d089-46b1-9737-e953b713aac8';
    $pane = new stdClass();
    $pane->pid = 'new-0ad5c20f-dcd2-4ef5-8592-90e76dc0f853';
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
    $pane->uuid = '0ad5c20f-dcd2-4ef5-8592-90e76dc0f853';
    $display->content['new-0ad5c20f-dcd2-4ef5-8592-90e76dc0f853'] = $pane;
    $display->panels['content'][12] = 'new-0ad5c20f-dcd2-4ef5-8592-90e76dc0f853';
    $pane = new stdClass();
    $pane->pid = 'new-5a10f591-2f71-45f7-8fc7-77d8108a0abd';
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
    $pane->uuid = '5a10f591-2f71-45f7-8fc7-77d8108a0abd';
    $display->content['new-5a10f591-2f71-45f7-8fc7-77d8108a0abd'] = $pane;
    $display->panels['content'][13] = 'new-5a10f591-2f71-45f7-8fc7-77d8108a0abd';
    $pane = new stdClass();
    $pane->pid = 'new-bc8ff425-dce1-4249-a4da-44a5bf93c2bb';
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
    $pane->uuid = 'bc8ff425-dce1-4249-a4da-44a5bf93c2bb';
    $display->content['new-bc8ff425-dce1-4249-a4da-44a5bf93c2bb'] = $pane;
    $display->panels['content'][14] = 'new-bc8ff425-dce1-4249-a4da-44a5bf93c2bb';
    $pane = new stdClass();
    $pane->pid = 'new-4ead0692-4834-44e1-a937-be3bfc6b4a6f';
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
    $pane->uuid = '4ead0692-4834-44e1-a937-be3bfc6b4a6f';
    $display->content['new-4ead0692-4834-44e1-a937-be3bfc6b4a6f'] = $pane;
    $display->panels['content'][15] = 'new-4ead0692-4834-44e1-a937-be3bfc6b4a6f';
    $pane = new stdClass();
    $pane->pid = 'new-feafb971-b78d-4727-abdf-18e3692d8828';
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
    $pane->uuid = 'feafb971-b78d-4727-abdf-18e3692d8828';
    $display->content['new-feafb971-b78d-4727-abdf-18e3692d8828'] = $pane;
    $display->panels['content'][16] = 'new-feafb971-b78d-4727-abdf-18e3692d8828';
    $pane = new stdClass();
    $pane->pid = 'new-e3a691ff-f654-4008-b06e-702ea5ddf5a1';
    $pane->panel = 'footer';
    $pane->type = 'rate_widget';
    $pane->subtype = 'rate_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => '1',
      'widget_name' => '3',
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e3a691ff-f654-4008-b06e-702ea5ddf5a1';
    $display->content['new-e3a691ff-f654-4008-b06e-702ea5ddf5a1'] = $pane;
    $display->panels['footer'][0] = 'new-e3a691ff-f654-4008-b06e-702ea5ddf5a1';
    $pane = new stdClass();
    $pane->pid = 'new-0656daef-9926-4561-8e53-81f3cfebaa40';
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
    $pane->uuid = '0656daef-9926-4561-8e53-81f3cfebaa40';
    $display->content['new-0656daef-9926-4561-8e53-81f3cfebaa40'] = $pane;
    $display->panels['header_full'][0] = 'new-0656daef-9926-4561-8e53-81f3cfebaa40';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__tr_mite_migrado'] = $handler;

  return $export;
}
