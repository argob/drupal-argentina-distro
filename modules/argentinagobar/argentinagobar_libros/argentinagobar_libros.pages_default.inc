<?php
/**
 * @file
 * argentinagobar_libros.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function argentinagobar_libros_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__libro';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Libro',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'libro',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'book' => 'book',
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
  $display->layout = 'pagina-navegacion';
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
      'aside' => NULL,
    ),
    'header_full' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a106ca8c-47c0-4673-91fe-fef4dda467a3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-334cc1b3-d972-4240-a52e-ca345dd42aa5';
    $pane->panel = 'aside';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '334cc1b3-d972-4240-a52e-ca345dd42aa5';
    $display->content['new-334cc1b3-d972-4240-a52e-ca345dd42aa5'] = $pane;
    $display->panels['aside'][0] = 'new-334cc1b3-d972-4240-a52e-ca345dd42aa5';
    $pane = new stdClass();
    $pane->pid = 'new-3753bb20-ad33-4d4c-ae6f-fb36d93829ac';
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
    $pane->uuid = '3753bb20-ad33-4d4c-ae6f-fb36d93829ac';
    $display->content['new-3753bb20-ad33-4d4c-ae6f-fb36d93829ac'] = $pane;
    $display->panels['content'][0] = 'new-3753bb20-ad33-4d4c-ae6f-fb36d93829ac';
    $pane = new stdClass();
    $pane->pid = 'new-85e94f46-c0bd-4293-b808-7ddca568ffe2';
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
    $pane->uuid = '85e94f46-c0bd-4293-b808-7ddca568ffe2';
    $display->content['new-85e94f46-c0bd-4293-b808-7ddca568ffe2'] = $pane;
    $display->panels['content'][1] = 'new-85e94f46-c0bd-4293-b808-7ddca568ffe2';
    $pane = new stdClass();
    $pane->pid = 'new-e5d120e9-4e78-4392-9c88-79e7165cd23a';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e5d120e9-4e78-4392-9c88-79e7165cd23a';
    $display->content['new-e5d120e9-4e78-4392-9c88-79e7165cd23a'] = $pane;
    $display->panels['content'][2] = 'new-e5d120e9-4e78-4392-9c88-79e7165cd23a';
    $pane = new stdClass();
    $pane->pid = 'new-3904a970-5ed3-473c-823c-2770d5132b71';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3904a970-5ed3-473c-823c-2770d5132b71';
    $display->content['new-3904a970-5ed3-473c-823c-2770d5132b71'] = $pane;
    $display->panels['content'][3] = 'new-3904a970-5ed3-473c-823c-2770d5132b71';
    $pane = new stdClass();
    $pane->pid = 'new-dae20dd8-d646-4ef3-b4c0-bbbb929d1381';
    $pane->panel = 'content';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'dae20dd8-d646-4ef3-b4c0-bbbb929d1381';
    $display->content['new-dae20dd8-d646-4ef3-b4c0-bbbb929d1381'] = $pane;
    $display->panels['content'][4] = 'new-dae20dd8-d646-4ef3-b4c0-bbbb929d1381';
    $pane = new stdClass();
    $pane->pid = 'new-8b928fec-89c8-40ca-b400-81f08eb509a3';
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
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '8b928fec-89c8-40ca-b400-81f08eb509a3';
    $display->content['new-8b928fec-89c8-40ca-b400-81f08eb509a3'] = $pane;
    $display->panels['content'][5] = 'new-8b928fec-89c8-40ca-b400-81f08eb509a3';
    $pane = new stdClass();
    $pane->pid = 'new-5cd82171-f802-4a11-8ebc-401bfc79c5e0';
    $pane->panel = 'content';
    $pane->type = 'token';
    $pane->subtype = 'node:field-creditos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '5cd82171-f802-4a11-8ebc-401bfc79c5e0';
    $display->content['new-5cd82171-f802-4a11-8ebc-401bfc79c5e0'] = $pane;
    $display->panels['content'][6] = 'new-5cd82171-f802-4a11-8ebc-401bfc79c5e0';
    $pane = new stdClass();
    $pane->pid = 'new-2f4f072e-ffeb-4de3-a5fd-c74f472fe59c';
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
    $pane->uuid = '2f4f072e-ffeb-4de3-a5fd-c74f472fe59c';
    $display->content['new-2f4f072e-ffeb-4de3-a5fd-c74f472fe59c'] = $pane;
    $display->panels['header_contained'][0] = 'new-2f4f072e-ffeb-4de3-a5fd-c74f472fe59c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-85e94f46-c0bd-4293-b808-7ddca568ffe2';
  $handler->conf['display'] = $display;
  $export['node_view__libro'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_node_overview__default';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'node_overview';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'pagina-principal-argentina';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'middle1' => NULL,
      'middle2' => NULL,
      'middle3' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Home';
  $display->uuid = 'c812f401-3466-49d0-9799-721bdb84fee5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a35d86e-5860-4531-bb10-ff91286334ff';
    $pane->panel = 'bottom';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacar_primer_fila' => 0,
      'mostrar_fecha' => 0,
      'mostrar_resumen' => 1,
      'mostrar_imagen' => 1,
      'cantidad_links' => '8',
      'tipo_de_listado' => 'recientes',
      'contenido_custom' => array(
        2853 => array(
          'entity_id' => '2853',
          'entity_label' => 'Tramitar el DNI',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
        2407 => array(
          'entity_id' => '2407',
          'entity_label' => 'Tramitar el pasaporte',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
      ),
      'entity_types' => 'ListadoCustom',
      'taxonomy_vocabularies' => '4',
      'tipos_de_contenido' => 'all',
      'formato_de_listado' => 'FormatoListadoTarjeta',
      'titulo' => 'Servicios más consultados',
      'icono' => '',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'paginador' => 0,
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
    $pane->uuid = '2a35d86e-5860-4531-bb10-ff91286334ff';
    $display->content['new-2a35d86e-5860-4531-bb10-ff91286334ff'] = $pane;
    $display->panels['bottom'][0] = 'new-2a35d86e-5860-4531-bb10-ff91286334ff';
    $pane = new stdClass();
    $pane->pid = 'new-66656723-8302-4707-ba74-4e32fb2fbc21';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<div class="row">
      <div class="col-md-8 col-md-offset-2">
        <a id="appAlert" class="alert alert-info visible-xs" href="/app">
          <div class="media">
            <div class="media-left media-middle">
              <i class="fa fa-mobile fa-fw fa-3x"></i>
            </div>
            <div class="media-body media-middle">
              <h5 class="m-y-0">Descargá la aplicación.</h5>
              <p id="appAlertText" class="m-y-0">Disponible para Android y iOS.</p>
            </div>
          </div>
        </a>  
      </div>
    </div> 

    <script>
      var userAgent = navigator.userAgent || navigator.vendor || window.opera;

      if (/android/i.test(userAgent)) {
        document.getElementById(\'appAlert\').href = "https://play.google.com/store/apps/details?id=ar.gob.argentinagobar";
        document.getElementById(\'appAlertText\').innerHTML = "Disponible para Android.";
      }

      if (/iPad|iPhone|iPod/.test(userAgent) && !window.MSStream) {
        document.getElementById(\'appAlert\').href = "https://itunes.apple.com/us/app/argentina.gob.ar/id1107620792?l=es&mt=8";
        document.getElementById(\'appAlertText\').innerHTML = "Disponible para iOS.";
      }
    </script>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '66656723-8302-4707-ba74-4e32fb2fbc21';
    $display->content['new-66656723-8302-4707-ba74-4e32fb2fbc21'] = $pane;
    $display->panels['middle1'][0] = 'new-66656723-8302-4707-ba74-4e32fb2fbc21';
    $pane = new stdClass();
    $pane->pid = 'new-12aaed3d-d45d-40a3-b3b6-7d34cf52ec7b';
    $pane->panel = 'middle1';
    $pane->type = 'atajos';
    $pane->subtype = 'atajos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'atajos' => array(
        1 => array(
          'titulo' => 'Chat Crecer: el chat del embarazo',
          'texto' => array(
            'value' => 'Recordatorio de turnos e información confiable sobre tu embarazo y el primer año de tu bebé.',
            'format' => 'filtered_html',
          ),
          'link_interno' => FALSE,
          'link_externo' => 'https://www.facebook.com/chatcrecer/',
          'imagen' => array(
            'fid' => '2126816',
            'upload_button' => 'Subir archivo',
            'remove_button' => 'Eliminar',
            'upload' => '',
          ),
          'icono' => 'sin_icono',
          'color_icono' => 'text-primary',
          'color_fondo' => 'panel-primary',
          'color_boton' => 'btn-default',
        ),
        2 => array(
          'titulo' => 'DNI en tu Celular',
          'texto' => array(
            'value' => 'Ahora podés tener el DNI en tu Celular en Mi Argentina.',
            'format' => 'filtered_html',
          ),
          'link_interno' => FALSE,
          'link_externo' => 'https://www.argentina.gob.ar/interior/dni-en-tu-celular',
          'imagen' => array(
            'fid' => '3155375',
            'upload_button' => 'Subir archivo',
            'remove_button' => 'Eliminar',
            'upload' => '',
          ),
          'icono' => 'sin_icono',
          'color_icono' => 'text-primary',
          'color_fondo' => 'panel-primary',
          'color_boton' => 'btn-default',
        ),
        3 => array(
          'titulo' => 'Las papeles de tu vehículo en Mi Argentina',
          'texto' => array(
            'value' => 'Accedé a tu cédula, licencia y seguro digital de tu vehículo.',
            'format' => 'filtered_html',
          ),
          'link_interno' => FALSE,
          'link_externo' => 'https://www.argentina.gob.ar/miargentina/servicios/papeles-del-vehiculo',
          'imagen' => array(
            'fid' => '3155312',
            'upload_button' => 'Subir archivo',
            'remove_button' => 'Eliminar',
            'upload' => '',
          ),
          'icono' => 'sin_icono',
          'color_icono' => 'text-primary',
          'color_fondo' => 'panel-primary',
          'color_boton' => 'btn-default',
        ),
        4 => array(
          'titulo' => 'Alerta Sarampión',
          'texto' => array(
            'value' => 'Recomendaciones y consejos para prevenir la reintroducción de esta enfermedad en nuestro país.',
            'format' => 'filtered_html',
          ),
          'link_interno' => FALSE,
          'link_externo' => 'https://www.argentina.gob.ar/salud/sarampion',
          'imagen' => array(
            'fid' => '3155321',
            'upload_button' => 'Subir archivo',
            'remove_button' => 'Eliminar',
            'upload' => '',
          ),
          'icono' => 'sin_icono',
          'color_icono' => 'text-primary',
          'color_fondo' => 'panel-primary',
          'color_boton' => 'btn-default',
        ),
      ),
      'cantidadAtajos' => 4,
      'opciones' => array(
        'formato' => 'FormatoAtajoDestacadoImagen',
        'columnas' => '4',
        'destacar' => 0,
      ),
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
    $pane->uuid = '12aaed3d-d45d-40a3-b3b6-7d34cf52ec7b';
    $display->content['new-12aaed3d-d45d-40a3-b3b6-7d34cf52ec7b'] = $pane;
    $display->panels['middle1'][1] = 'new-12aaed3d-d45d-40a3-b3b6-7d34cf52ec7b';
    $pane = new stdClass();
    $pane->pid = 'new-aa3a6ada-bb7c-4198-a3e9-17917886d500';
    $pane->panel = 'middle1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Listado con Noche Espacial',
      'title' => '',
      'body' => '<div class="row panels-row"><div class="col-xs-12 col-sm-6 col-md-3"><a href="/noche-espacial" class="panel panel-default"><div style="background-image:url(https://www.argentina.gob.ar/sites/default/files/noche_espacial.png);" class="panel-heading"></div><div class="panel-body"><h4>Noche Espacial</h4><div class="text-muted"><p>Lanzamiento del Satélite Argentino de Observación con Microondas SAOCOM 1A.</p></div></div></a></div><div class="col-xs-12 col-sm-6 col-md-3"><a href="/vacunas/sarampionrubeola" class="panel panel-default"><div style="background-image:url(https://www.argentina.gob.ar/sites/default/files/styles/listado/public/imagenAtajo/sarampio-rubeola-destacado_2_1.jpg?itok=eol-TBJn);" class="panel-heading"></div><div class="panel-body"><h4>Campaña Nacional de Vacunación contra Sarampión y Rubéola</h4><div class="text-muted"><p>Del 1 de octubre al 30 de noviembre en todo el país.</p></div></div></a></div><div class="col-xs-12 col-sm-6 col-md-3"><a href="/mi_argentina" class="panel panel-default"><div style="background-image:url(https://www.argentina.gob.ar/sites/default/files/styles/listado/public/imagenAtajo/mi-argentina.jpg?itok=2irqiktI);" class="panel-heading"></div><div class="panel-body"><h4>Mi Argentina</h4><div class="text-muted"><p>Descargá tu constancia de CUIL con un solo clic y otros servicios personalizados.</p></div></div></a></div><div class="col-xs-12 col-sm-6 col-md-3"><a href="/planenia" class="panel panel-default"><div style="background-image:url(https://www.argentina.gob.ar/sites/default/files/styles/listado/public/imagenAtajo/enia.jpg?itok=SwztkTw7);" class="panel-heading"></div><div class="panel-body"><h4>Plan ENIA</h4><div class="text-muted"><p>Plan Nacional de Prevención del Embarazo No Intencional en la Adolescencia</p></div></div></a></div></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'aa3a6ada-bb7c-4198-a3e9-17917886d500';
    $display->content['new-aa3a6ada-bb7c-4198-a3e9-17917886d500'] = $pane;
    $display->panels['middle1'][2] = 'new-aa3a6ada-bb7c-4198-a3e9-17917886d500';
    $pane = new stdClass();
    $pane->pid = 'new-2cf1f5c3-0610-4b1b-9551-e7da391e2ea9';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '            <section class="m-y-0 p-y-1">
               <div class="">
                  <h2>Este mes te puede interesar</h2>
                  <div class="row panels-row m-t-2">
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="tema/adultosmayores">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i
                                       class="fa icono-arg-jubilado fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Adultos mayores</h3>
                                    <p>Consejos, servicios y orientación para realizar trámites de jubilaciones y
                                       pensiones.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="/tema/cuidarlasalud">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i
                                       class="fa icono-arg-medicamentos fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Cuidar la salud</h3>
                                    <p>Vacunas obligatorias, primeros auxilios ante emergencias y consejos para una vida
                                       saludable.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="argentinos-en-el-exterior">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i
                                       class="fa icono-arg-exterior fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Argentinos en el mundo</h3>
                                    <p>Si te encontrás en otro país o vas a hacer un viaje, chequeá información útil.
                                    </p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                  </div>
               </div>
            </section>
            <section class="m-y-0 p-y-1">
               <div class="">
                  <h2>Trámites y servicios</h2>
                  <div class="row panels-row m-t-2">
                        <div class="col-xs-12 col-sm-6 col-md-4">
                           <a class="panel panel-default" href="estudiar">
                              <div class="panel-body">
                                 <div class="media">
                                    <div class="media-left padding-20"> <i
                                          class="fa icono-arg-educacion fa-fw fa-2x text-primary"></i></div>
                                    <div class="media-body">
                                       <h3>Estudiar</h3>
                                       <p>Niveles y modalidades educativas, programas, becas y reválida de títulos.</p>
                                    </div>
                                 </div>
                              </div>
                           </a>
                        </div>
                        <div class="col-xs-12 col-sm-6 col-md-4">
                           <a class="panel panel-default" href="emprender-innovar-crecer">
                              <div class="panel-body">
                                 <div class="media">
                                    <div class="media-left padding-20"> <i
                                          class="fa fa-line-chart fa-fw fa-2x text-primary"></i></div>
                                    <div class="media-body">
                                       <h3>Emprender, innovar, crecer</h3>
                                       <p>Herramientas de financiamiento y capacitación para emprendedores y PyMEs.</p>
                                    </div>
                                 </div>
                              </div>
                           </a>
                        </div>
                        <div class="col-xs-12 col-sm-6 col-md-4">
                           <a class="panel panel-default" href="/tema/extranjeros">
                              <div class="panel-body">
                                 <div class="media">
                                    <div class="media-left padding-20"> <i
                                          class="fa icono-arg-social fa-fw fa-2x text-primary"></i></div>
                                    <div class="media-body">
                                       <h3>Extranjeros en Argentina</h3>
                                       <p>Información y servicios para los que viajan, estudian, trabajan y viven en la
                                          Argentina.</p>
                                    </div>
                                 </div>
                              </div>
                           </a>
                        </div>
                        <div class="col-xs-12 col-sm-6 col-md-4">
                           <a class="panel panel-default" href="/automotor">
                              <div class="panel-body">
                                 <div class="media">
                                    <div class="media-left padding-20"> <i
                                          class="fa fa-2x icono-arg-auto text-primary fa-fw fa-2x text-primary"></i>
                                    </div>
                                    <div class="media-body">
                                       <h3>Tránsito y automotor</h3>
                                       <p>Información para circular en vía pública y para comprar, registrar, permutar,
                                          asegurar o vender tu auto o moto.</p>
                                    </div>
                                 </div>
                              </div>
                           </a>
                        </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="tema/culturaytiempolibre/arteycultura">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa icono-arg-cultura fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Beneficios para artistas</h3>
                                    <p>Beneficios para artistas y agenda de actividades para disfrutar.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="/tema/vacaciones">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-2x icono-arg-avion fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Salir de vacaciones</h3>
                                    <p>Información, servicios y asesoramiento para planificar tu viaje.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="tema/hogar">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa icono-arg-hogar-y-familia fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Pareja y familia</h3>
                                    <p>Trámites relacionados con estar en pareja, tener un hijo o enfrentar el fallecimiento de un ser querido.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="tema/emergencias">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-2x fa-ambulance text-primary fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Emergencias</h3>
                                    <p>Te ofrecemos una lista de números y consejos a seguir.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="trabajar">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa icono-arg-trabajador fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Trabajar</h3>
                                    <p>Todos los servicios por si sos empleado, monotributista, querés capacitarte o estás buscando trabajo.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="identidad">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-id-card-o fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Documentación ciudadana</h3>
                                    <p>Te guiamos en trámites tales como sacar el DNI o pasaporte y cambio de género, entre otros.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="/tema/consumidores">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-2x icono-arg-carrito text-primary fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Consumidores</h3>
                                    <p>Información sobre tus derechos, herramientas para comprar o contratar servicios, y pautas para hacer un reclamo.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="discapacidad">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="icono-arg-discapacidad fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Personas con discapacidad</h3>
                                    <p>Servicios para atención de la salud, asignaciones familiares, viajar gratis y más trámites.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="violencia-y-abuso">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-exclamation-triangle fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Violencia y abuso</h3>
                                    <p>Ante una situación de violencia o abuso no dudes en llamar y denunciar.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                     <div class="col-xs-12 col-sm-6 col-md-4">
                        <a class="panel panel-default" href="/tema/acceder-una-vivienda">
                           <div class="panel-body">
                              <div class="media">
                                 <div class="media-left padding-20"> <i class="fa fa-2x icono-arg-vivienda text-primary fa-fw fa-2x text-primary"></i></div>
                                 <div class="media-body">
                                    <h3>Acceder a una vivienda</h3>
                                    <p>Información sobre créditos, programas de vivienda para compra o mejoras y derechos de inquilinos y propietarios.</p>
                                 </div>
                              </div>
                           </div>
                        </a>
                     </div>
                  </div>
               </div>
            </section>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2cf1f5c3-0610-4b1b-9551-e7da391e2ea9';
    $display->content['new-2cf1f5c3-0610-4b1b-9551-e7da391e2ea9'] = $pane;
    $display->panels['middle1'][3] = 'new-2cf1f5c3-0610-4b1b-9551-e7da391e2ea9';
    $pane = new stdClass();
    $pane->pid = 'new-4d513dab-d54d-481f-994b-b347322c9bb8';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<div class="">
               <h2 class="h3 m-b-2">Más consultados</h2>
               <div class="row row-flex">
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="modernizacion/tramites-a-distancia">
                        <h3 class="h5">Trámites a distancia</h3>
                     </a>
                     <p class="text-muted">Realizá tus trámites de manera virtual ante la Administración Pública Nacional.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="turnosparaanses">
                        <h3 class="h5">Tramitar turnos para ANSES</h3>
                     </a>
                     <p class="text-muted">Cómo hacer si tenés que sacar, consultar o cancelar turnos para los servicios de ANSES.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="consultar-calendario-de-pago-de-anses">
                        <h3 class="h5">Consultar el calendario de pago de ANSES</h3>
                     </a>
                     <p class="text-muted">Si sos jubilado o pensionado, o recibís algún tipo de subsidio o prestación de ANSES.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="seguir-el-estado-de-tramite-del-dni">
                        <h3 class="h5">Seguir el estado de trámite del DNI</h3>
                     </a>
                     <p class="text-muted">Si ya tramitaste tu DNI, podés hacer el seguimiento en línea.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="certificacionnegativa ">
                        <h3 class="h5">Obtener certificación negativa de ANSES</h3>
                     </a>
                     <p class="text-muted">Si te pidieron un comprobante de que no estás recibiendo otros aportes de ANSES.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="consultar-donde-esta-radicado-un-auto-moto-o-maquinaria">
                        <h3 class="h5">Consultar radicación de automotor</h3>
                     </a>
                     <p class="text-muted">Si estás por comprar un vehículo, necesitás saber cuál es el Registro Automotor en el que está radicado.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="obtener-tu-constancia-de-cuil">
                        <h3 class="h5">Obtener tu constancia de CUIL</h3>
                     </a>
                     <p class="text-muted">Es un número personalizado, por el cual quedan registrados todos tus aportes laborales.</p>
                  </div>
                  <div class="col-xs-12 col-sm-6 col-lg-3 m-b-2">
                     <a href="solicitar-certificado-de-antecedentes-penales">
                        <h3 class="h5">Certificado de Antecedentes Penales</h3>
                     </a>
                     <p class="text-muted">Es un documento en formato electrónico que certifica que no tenés antecedentes.</p>
                  </div>
               </div>
            </div>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4d513dab-d54d-481f-994b-b347322c9bb8';
    $display->content['new-4d513dab-d54d-481f-994b-b347322c9bb8'] = $pane;
    $display->panels['middle1'][4] = 'new-4d513dab-d54d-481f-994b-b347322c9bb8';
    $pane = new stdClass();
    $pane->pid = 'new-f048d908-8d51-4c6c-9aea-79f3584b5201';
    $pane->panel = 'middle1';
    $pane->type = 'titulo';
    $pane->subtype = 'titulo';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'tag' => 'h3',
      'texto' => 'Servicios más consultados',
      'sobreescribir_titulo' => 1,
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
    $pane->uuid = 'f048d908-8d51-4c6c-9aea-79f3584b5201';
    $display->content['new-f048d908-8d51-4c6c-9aea-79f3584b5201'] = $pane;
    $display->panels['middle1'][5] = 'new-f048d908-8d51-4c6c-9aea-79f3584b5201';
    $pane = new stdClass();
    $pane->pid = 'new-795b4e52-88e7-4aae-8db6-614f85ba8828';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<div class=""><div class="container">
    
    <div class="row panels-row">

      <div class="col-xs-12 col-sm-6 col-md-3">
        <a class="panel panel-default" href="procrear">
          <div style="background-image:url(\'sites/default/files/styles/listado/public/procrear_landing_header_0.jpg\');" class="panel-heading"></div>
          <div class="panel-body">
            <h2 class="h3">ProCreAr</h2>
            <p class="text-muted">Accedé a créditos para tu primera casa propia.</p>
          </div>
        </a>
      </div>

      <div class="col-xs-12 col-sm-6 col-md-3">
        <a class="panel panel-default" href="elestadoentubarrio">
          <div style="background-image:url(\'sites/default/files/styles/listado/public/eetb_header_home_0.jpg\');" class="panel-heading"></div>
          <div class="panel-body">
            <h2 class="h3">El Estado en tu Barrio</h2>
            <p class="text-muted">Resolvé tus trámites cerca de tu casa.</p>
          </div>
        </a>
      </div>

      <div class="col-xs-12 col-sm-6 col-md-3">
        <a class="panel panel-default" href="elecciones2017">
          <div style="background-image:url(\'sites/default/files/imagenAtajo/cargos_4.jpg\');" class="panel-heading"></div>
          <div class="panel-body">
            <h2 class="h3">Elecciones legislativas 2017</h2>
            <p class="text-muted">Averiguá toda la información que necesitás. </p>
          </div>
        </a>
      </div>

      <div class="col-xs-12 col-sm-6 col-md-3">
        <a class="panel panel-default" href="hacer-un-reclamo-por-internet-en-la-ventanilla-unica-federal-de-defensa-del-consumidor">
          <div style="background-image:url(\'sites/default/files/styles/listado/public/consumidor.jpg\');" class="panel-heading"></div>
          <div class="panel-body">
            <h2 class="h3">Defensa del Consumidor</h2>
            <p class="text-muted">Reclamá si tenés problemas con un producto o servicio.</p>
          </div>
        </a>
      </div>

    </div>
  </div></div>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '795b4e52-88e7-4aae-8db6-614f85ba8828';
    $display->content['new-795b4e52-88e7-4aae-8db6-614f85ba8828'] = $pane;
    $display->panels['middle1'][6] = 'new-795b4e52-88e7-4aae-8db6-614f85ba8828';
    $pane = new stdClass();
    $pane->pid = 'new-8918780c-fa67-423c-ac84-4928e2727295';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<div class="row panels-row">
				<div class="col-xs-12 col-sm-6">
			<a href="/dni" class="panel panel-default m-b-0"><div style="background-image:url(https://www.argentina.gob.ar/sites/default/files/styles/listado/public/dni1.jpg?itok=nrqk0vIW);" class="panel-heading"></div>
<div class="panel-body">
    <h3>Tramitar el DNI</h3>  <p class="text-muted">El Documento Nacional de Identidad (DNI) es el documento principal de identificación con que contamos los argentinos (en el país o en el exterior)  y los extranjeros con domicilio en nuestro...</p></div>
</a>		</div>
				<div class="col-xs-12 col-sm-6">
			<a href="/pasaporte" class="panel panel-default m-b-0"><div style="background-image: url(https://www.argentina.gob.ar/sites/default/files/tarjeta_pasaporte_0.jpg?itok=cp9oYZEs);" class="panel-heading"></div>
<div class="panel-body">
    <h3>Tramitar el pasaporte</h3>  <p class="text-muted">Si vas a viajar al extranjero, es obligatorio tener el pasaporte al día, salvo que vayas a los países limítrofes donde solo te exigen el DNI.</p></div>
</a>		</div>
				
			</div>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '8918780c-fa67-423c-ac84-4928e2727295';
    $display->content['new-8918780c-fa67-423c-ac84-4928e2727295'] = $pane;
    $display->panels['middle1'][7] = 'new-8918780c-fa67-423c-ac84-4928e2727295';
    $pane = new stdClass();
    $pane->pid = 'new-1854eaa3-bda4-44b1-885a-8f40291ac417';
    $pane->panel = 'middle1';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacar_primer_fila' => 1,
      'cantidad_links' => '7',
      'tipo_de_listado' => 'recientes',
      'contenido_custom' => array(
        6927 => array(
          'entity_id' => '6927',
          'entity_label' => 'Jubilados y Pensionados',
          'entity_type' => 'node',
          'entity_bundle' => 'area',
        ),
        6202 => array(
          'entity_id' => '6202',
          'entity_label' => 'Discapacidad',
          'entity_type' => 'node',
          'entity_bundle' => 'area',
        ),
        2855 => array(
          'entity_id' => '2855',
          'entity_label' => 'Monotributistas',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
        1525 => array(
          'entity_id' => '1525',
          'entity_label' => 'Obtener Certificación Negativa de ANSES',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
        1528 => array(
          'entity_id' => '1528',
          'entity_label' => 'Turnos para ANSES',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
        1417 => array(
          'entity_id' => '1417',
          'entity_label' => 'Consultar el calendario de pago de ANSES',
          'entity_type' => 'node',
          'entity_bundle' => 'page',
        ),
        5451 => array(
          'entity_id' => '5451',
          'entity_label' => 'Registrar una pyme para obtener los beneficios de la Ley PyME',
          'entity_type' => 'node',
          'entity_bundle' => 'argentinagobar_migtram',
        ),
      ),
      'entity_types' => 'ListadoCustom',
      'taxonomy_vocabularies' => '4',
      'tipos_de_contenido' => 'page',
      'formato_de_listado' => 'FormatoListadoTarjeta',
      'titulo' => '',
      'icono' => 'iconarg-mod-lupa',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'paginador' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'mostrar_fecha' => 0,
      'mostrar_resumen' => 1,
      'mostrar_imagen' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '1854eaa3-bda4-44b1-885a-8f40291ac417';
    $display->content['new-1854eaa3-bda4-44b1-885a-8f40291ac417'] = $pane;
    $display->panels['middle1'][8] = 'new-1854eaa3-bda4-44b1-885a-8f40291ac417';
    $pane = new stdClass();
    $pane->pid = 'new-2c020c37-745f-4762-83d3-fe681ff41f5b';
    $pane->panel = 'middle1';
    $pane->type = 'separador';
    $pane->subtype = 'separador';
    $pane->shown = FALSE;
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
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '2c020c37-745f-4762-83d3-fe681ff41f5b';
    $display->content['new-2c020c37-745f-4762-83d3-fe681ff41f5b'] = $pane;
    $display->panels['middle1'][9] = 'new-2c020c37-745f-4762-83d3-fe681ff41f5b';
    $pane = new stdClass();
    $pane->pid = 'new-27365cb3-f138-436c-b404-9d80ce333899';
    $pane->panel = 'middle1';
    $pane->type = 'separador';
    $pane->subtype = 'separador';
    $pane->shown = FALSE;
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
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '27365cb3-f138-436c-b404-9d80ce333899';
    $display->content['new-27365cb3-f138-436c-b404-9d80ce333899'] = $pane;
    $display->panels['middle1'][10] = 'new-27365cb3-f138-436c-b404-9d80ce333899';
    $pane = new stdClass();
    $pane->pid = 'new-50be2df5-713a-43ec-a49f-c745b82ae00f';
    $pane->panel = 'middle2';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacar_primer_fila' => 0,
      'cantidad_links' => '20',
      'tipo_de_listado' => 'recientes',
      'contenido_custom' => array(),
      'entity_types' => 'taxonomy_vocabularies',
      'taxonomy_vocabularies' => '2',
      'tipos_de_contenido' => 'aplicacion',
      'formato_de_listado' => 'argentinagobar_bloques_listado_lista_simple',
      'titulo' => 'Categorías de servicios',
      'icono' => 'iconarg-mod-lupa',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'paginador' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'mostrar_fecha' => 0,
      'mostrar_resumen' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '50be2df5-713a-43ec-a49f-c745b82ae00f';
    $display->content['new-50be2df5-713a-43ec-a49f-c745b82ae00f'] = $pane;
    $display->panels['middle2'][0] = 'new-50be2df5-713a-43ec-a49f-c745b82ae00f';
    $pane = new stdClass();
    $pane->pid = 'new-d47d29ac-f957-43a1-bae9-11cb1f42f617';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'argentinagobar_search-ApacheSolrInput';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd47d29ac-f957-43a1-bae9-11cb1f42f617';
    $display->content['new-d47d29ac-f957-43a1-bae9-11cb1f42f617'] = $pane;
    $display->panels['top'][0] = 'new-d47d29ac-f957-43a1-bae9-11cb1f42f617';
    $pane = new stdClass();
    $pane->pid = 'new-2bfb8846-61b5-4fb7-bd13-1413fd448e55';
    $pane->panel = 'top';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<section class="jumbotron" style="background-image:url(https://www.argentina.gob.ar/sites/default/files/styles/jumbotron/public/backimage_buscador/dsc_6377_paisaje_jujuy.jpg?itok=08iW_ZPN);"><div class="jumbotron_body jumbotron_body-lg"><div class="container"><div class="row"><div class="col-md-12"><h2 class="text-center">&iquest;Qué estás buscando?</h2></div></div><div class="row"><div class="col-md-8 col-md-offset-2" id="buscador">&nbsp;</div></div></div></div><div class="overlay">&nbsp;</div></section>',
        'format' => 'full_html',
      ),
      'sobreescribir' => 1,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2bfb8846-61b5-4fb7-bd13-1413fd448e55';
    $display->content['new-2bfb8846-61b5-4fb7-bd13-1413fd448e55'] = $pane;
    $display->panels['top'][1] = 'new-2bfb8846-61b5-4fb7-bd13-1413fd448e55';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d47d29ac-f957-43a1-bae9-11cb1f42f617';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_node_overview__default'] = $handler;

  return $export;
}
