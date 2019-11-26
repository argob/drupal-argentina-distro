<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Encabezado'),
  'description' => t(''),
  'category' => t('Argentina.gob.ar'),
  'render callback' => 'argentinagobar_bloques_imagen_destacada_render',
  'admin info' => 'argentinagobar_bloques_imagen_destacada_admin_info',
  'defaults' => array(
    'imagen_destacada' =>   NULL,
  )
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_imagen_destacada_admin_info($subtype, $conf, $contexts)
{
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = isset($conf['override_title']) ? $conf['override_title_text'] : t('Imagen destacada');
    $block->content = t('Imagen destacada.');
    return $block;
  }
}

function argentinagobar_bloques_imagen_destacada_render($subtype, $conf, $panel_args, $context = NULL){

  $block = new stdClass();
  $block->title = '';

  if (arg(0) == 'node' && is_numeric(arg(1))) {

    $node   = (arg(2) == 'revisions' && is_numeric(arg(3))) ?  node_load(arg(1), arg(3)) : node_load(arg(1));

    try {

      $block->content = theme(
        'argentinagobar_bloques_imagen_destacada_' . $node->type,
        array(
          'campos' => obtenerData($node),
          'breadcrumb' => theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()))
        )
      );
    }
    catch (EntityMetadataWrapperException $exc) {
      watchdog(
        'Imagen Destacada',
        'EntityMetadataWrapper exception in %function() <pre>@trace</pre>',
        array('%function' => __FUNCTION__, '@trace' => $exc->getTraceAsString()),
        WATCHDOG_ERROR
      );
    }


  } else {

    $block->content = false;

  }

  return $block;
}

function obtenerData($node){

  $node_wrapper = entity_metadata_wrapper('node', $node);
  
  $campos = [];
  $campos['titulo'] = $node_wrapper->label();
  $campos['resumen'] = !is_null($node_wrapper->body->value()) ? $node_wrapper->body->summary->value() : null;

  switch ($node->type) {
    
    case 'tramite':
        
      if(field_get_items('node', $node, 'field_duracion')){
        
        $duracion = array();
    
        foreach ($node_wrapper->field_duracion->field_cantidades->getIterator() as $field_collection_item) {
          $item = array();
          $item['cantidad'] = $field_collection_item->field_cantidad->value();
          $item['medida'] = $field_collection_item->field_medida->value();
          $duracion[] = $item;
        }

        $campos['duracion'] = $duracion;
      }
      else{
        $campos['duracion'] = false;
      }
  
      if (isset($node_wrapper->field_costo) && $node_wrapper->field_costo->value()){
        $campos['es_gratuito'] = $node_wrapper->field_costo->field_gratuito->value();
      } else {
        $campos['es_gratuito'] = false;
      }

      if (isset($node_wrapper->field_modalidad_digital)) {
        $campos['es_digital'] = $node_wrapper->field_modalidad_digital->value();
      }

      // Por el momento no está definido
      $campos['organismo'] = false;

      break;
  
  case 'aplicacion':

    obtenerImagenDestacada($node_wrapper, $campos);
    
    $icono = field_get_items('node', $node, 'field_icono', NULL);
    $campos['body'] = field_get_items('node', $node, 'body', NULL);
    $campos['icono'] = isset($icono[0]) ? image_style_url('icono_aplicacion', $icono[0]['uri']) : '';
    
    break;
    
  case 'noticia':

    obtenerImagenDestacada($node_wrapper, $campos);
    $campos['fecha'] = format_date($node->created, 'custom', 'l d \d\e F \d\e o');
    
    break;
    
  case 'area':

    obtenerImagenDestacada($node_wrapper, $campos);
    
    break;
  }
  
  return $campos;
}

function obtenerImagenDestacada($node_wrapper, &$campos){
  
  if (isset($node_wrapper->field_featured_image) && $file = $node_wrapper->field_featured_image->value()) {
    if ($file['type'] == 'image' && $file['filemime'] == 'image/png') {
      $campos['imagen_destacada'] = image_style_url('jumbotron', ImageHelper::png2jpg($file));
    } else {
      $campos['imagen_destacada'] = image_style_url('jumbotron', $file['uri']);
    }
  } else {
    $campos['imagen_destacada'] = null;
  }
}
