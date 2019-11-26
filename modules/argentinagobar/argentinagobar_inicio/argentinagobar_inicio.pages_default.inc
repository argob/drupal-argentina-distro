<?php
/**
 * @file
 * argentinagobar_inicio.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function argentinagobar_inicio_default_page_manager_handlers() {
  $export = array();

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
    $pane->pid = 'new-f048d908-8d51-4c6c-9aea-79f3584b5201';
    $pane->panel = 'middle1';
    $pane->type = 'titulo';
    $pane->subtype = 'titulo';
    $pane->shown = TRUE;
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f048d908-8d51-4c6c-9aea-79f3584b5201';
    $display->content['new-f048d908-8d51-4c6c-9aea-79f3584b5201'] = $pane;
    $display->panels['middle1'][1] = 'new-f048d908-8d51-4c6c-9aea-79f3584b5201';
    $pane = new stdClass();
    $pane->pid = 'new-2a35d86e-5860-4531-bb10-ff91286334ff';
    $pane->panel = 'middle1';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2a35d86e-5860-4531-bb10-ff91286334ff';
    $display->content['new-2a35d86e-5860-4531-bb10-ff91286334ff'] = $pane;
    $display->panels['middle1'][2] = 'new-2a35d86e-5860-4531-bb10-ff91286334ff';
    $pane = new stdClass();
    $pane->pid = 'new-8918780c-fa67-423c-ac84-4928e2727295';
    $pane->panel = 'middle1';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8918780c-fa67-423c-ac84-4928e2727295';
    $display->content['new-8918780c-fa67-423c-ac84-4928e2727295'] = $pane;
    $display->panels['middle1'][3] = 'new-8918780c-fa67-423c-ac84-4928e2727295';
    $pane = new stdClass();
    $pane->pid = 'new-1854eaa3-bda4-44b1-885a-8f40291ac417';
    $pane->panel = 'middle1';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '1854eaa3-bda4-44b1-885a-8f40291ac417';
    $display->content['new-1854eaa3-bda4-44b1-885a-8f40291ac417'] = $pane;
    $display->panels['middle1'][4] = 'new-1854eaa3-bda4-44b1-885a-8f40291ac417';
    $pane = new stdClass();
    $pane->pid = 'new-04497c80-95d5-495c-9c7a-1975a2c4e257';
    $pane->panel = 'middle2';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '04497c80-95d5-495c-9c7a-1975a2c4e257';
    $display->content['new-04497c80-95d5-495c-9c7a-1975a2c4e257'] = $pane;
    $display->panels['middle2'][0] = 'new-04497c80-95d5-495c-9c7a-1975a2c4e257';
    $pane = new stdClass();
    $pane->pid = 'new-f29d066f-3ba8-4757-bafa-9d27f2ebb0ce';
    $pane->panel = 'middle2';
    $pane->type = 'shortcut';
    $pane->subtype = 'shortcut';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'color_fondo' => 'shortcut-azul',
      'icono' => 'iconarg-mod-lupa',
      'titulo' => 'Ver todos los servicios disponibles',
      'texto' => '',
      'cuerpo' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'referencia' => FALSE,
      'link' => '/servicios',
      'formato_de_shortcut' => 'boton',
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
    $pane->uuid = 'f29d066f-3ba8-4757-bafa-9d27f2ebb0ce';
    $display->content['new-f29d066f-3ba8-4757-bafa-9d27f2ebb0ce'] = $pane;
    $display->panels['middle2'][1] = 'new-f29d066f-3ba8-4757-bafa-9d27f2ebb0ce';
    $pane = new stdClass();
    $pane->pid = 'new-04c967f8-ea9b-4ad7-9b30-eeca1ff0220c';
    $pane->panel = 'middle2';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '<div class="container margin-40">
	<div class="clearfix"></div>
	<div class="row panels-row">
		<div class="col-md-4 col-sm-6">
			<a class="panel panel-default" href="/servicios">
				<div class="panel-heading" style="background-image:url(/sites/default/files/servicios.jpg);"></div>
				<div class="panel-body">
					<h3 class="h2">Servicios</h3>
					<p class="text-muted">Todos los trámites del Estado para resolver tus necesidades fácilmente.</p>
				</div>
			</a>
		</div>
		<div class="col-md-4 col-sm-6">
			<a class="panel panel-default" href="/areas">
				<div class="panel-heading" style="background-image:url(/sites/default/files/areas_0.jpg);"></div>
				<div class="panel-body">
					<h3 class="h2">Áreas de Gobierno</h3>
					<p class="text-muted">Todas las áreas de gobierno, sus formas de contacto y sitios web.</p>
				</div>
			</a>
		</div>
		<div class="col-md-4 col-sm-6">
			<a class="panel panel-default" href="http://www.casarosada.gob.ar">
				<div class="panel-heading" style="background-image:url(/sites/default/files/casarosada.jpg);"></div>
				<div class="panel-body">
					<h3 class="h2">Casa Rosada</h3>
					<p class="text-muted">Actividades y novedades del Poder Ejecutivo Nacional.</p>
				</div>
			</a>
		</div>
	</div>

<div class="padding-40"><div class="alert alert-warning" role="alert">A partir del <strong>16 de Agosto de 2016</strong> actualizamos los <a href="/terminos-y-condiciones">términos y condiciones</a> de Argentina.gob.ar para poder ofrecerte una mejor experiencia con el Estado.</div></div>
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '04c967f8-ea9b-4ad7-9b30-eeca1ff0220c';
    $display->content['new-04c967f8-ea9b-4ad7-9b30-eeca1ff0220c'] = $pane;
    $display->panels['middle2'][2] = 'new-04c967f8-ea9b-4ad7-9b30-eeca1ff0220c';
    $pane = new stdClass();
    $pane->pid = 'new-50be2df5-713a-43ec-a49f-c745b82ae00f';
    $pane->panel = 'middle3';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
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
    $display->panels['middle3'][0] = 'new-50be2df5-713a-43ec-a49f-c745b82ae00f';
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d47d29ac-f957-43a1-bae9-11cb1f42f617';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_node_overview__default'] = $handler;

  return $export;
}
