<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Datos de contacto'),
  'description' => t('Muestra los datos de contacto de un área.'),
  'category' => t('Argentina.gob.ar'),
  'render callback' => 'argentinagobar_bloques_area_contacto_render',
  'admin info' => 'argentinagobar_bloques_area_contacto_admin_info',
  'defaults' => array()
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_area_contacto_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Datos de contacto');
    $block->content = t('Datos de contacto');
    return $block;
  }
}
function argentinagobar_bloques_area_contacto_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  if(esArea()) {
    $node = node_load(arg(1));
    $contacto = new stdClass;
    $contacto->direccion = field_get_items('node', $node, 'field_direccion', NULL);
    $contacto->direccion = isset($contacto->direccion[0]) && !empty($contacto->direccion[0]) ? $contacto->direccion[0]['safe_value'] : NULL;
    $contacto->codigo_postal = field_get_items('node', $node, 'field_codigo_postal', NULL);
    $contacto->codigo_postal = isset($contacto->codigo_postal[0]) && !empty($contacto->codigo_postal[0]) ? $contacto->codigo_postal[0]['safe_value'] : NULL;
    $contacto->telefono = field_get_items('node', $node, 'field_telefono', NULL);
    $contacto->telefono = isset($contacto->telefono[0]) && !empty($contacto->telefono[0]) ? $contacto->telefono[0]['safe_value'] : NULL;
    $contacto->correo_electronico = field_get_items('node', $node, 'field_correo_electronico', NULL);
    $contacto->correo_electronico = isset($contacto->correo_electronico[0]) && !empty($contacto->correo_electronico[0]) ? $contacto->correo_electronico[0]['email'] : NULL;

    $contacto->whatsapp = field_get_items('node', $node, 'field_whatsapp', NULL);
    $contacto->whatsapp = isset($contacto->whatsapp[0]) && !empty($contacto->whatsapp[0]) ? $contacto->whatsapp[0]['safe_value'] : NULL;

    $contacto->facebook = field_get_items('node', $node, 'field_facebook', NULL);
    $contacto->facebook = isset($contacto->facebook[0]) && !empty($contacto->facebook[0]) ? l('<span class="sr-only">Facebook</span><i class="fa fa-facebook" aria-hidden="true"></i>',
      'http://www.facebook.com/' . $contacto->facebook[0]['safe_value'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank'
        ),
      )
    ) : NULL;

    $contacto->twitter = field_get_items('node', $node, 'field_twitter', NULL);
    $contacto->twitter = isset($contacto->twitter[0]) && !empty($contacto->twitter[0]) ?
    l('<span class="sr-only">Twitter</span><i class="fa fa-twitter" aria-hidden="true"></i>',
      'http://www.twitter.com/' . $contacto->twitter[0]['safe_value'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank'
        ),
      )
    ) : NULL;

    $contacto->instagram = field_get_items('node', $node, 'field_instagram', NULL);
    $contacto->instagram = isset($contacto->instagram[0]) && !empty($contacto->instagram[0]) ?
    l('<span class="sr-only">Instagram</span><i class="fa fa-instagram" aria-hidden="true"></i>',
      'http://www.instagram.com/' . $contacto->instagram[0]['safe_value'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank'
        ),
      )
    ) : NULL;

    $contacto->youtube = field_get_items('node', $node, 'field_youtube', NULL);
    $contacto->youtube = isset($contacto->youtube[0]) && !empty($contacto->youtube[0]) ?
    l('<span class="sr-only">Youtube</span><i class="fa fa-youtube" aria-hidden="true"></i>',
      'http://www.youtube.com/' . $contacto->youtube[0]['safe_value'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank'
        ),
      )
    ) : NULL;

    $contacto->flickr = field_get_items('node', $node, 'field_flickr', NULL);
    $contacto->flickr = isset($contacto->flickr[0]) && !empty($contacto->flickr[0]) ?
      l('<span class="sr-only">Compartir en flickr</span><i class="fa fa-flickr" aria-hidden="true"></i>',
        'http://www.flickr.com/' . $contacto->flickr[0]['safe_value'],
        array(
          'html' => TRUE,
          'attributes' => array(
            'target' => '_blank'
          ),
        )
      ) : NULL;
    
    $contacto->linkedin = field_get_items('node', $node, 'field_linkedin', NULL);
    $contacto->linkedin = isset($contacto->linkedin[0]) && !empty($contacto->linkedin[0]) ?
    l('<span class="sr-only">LinkedIn</span><i class="fa fa-linkedin" aria-hidden="true"></i>',
      'http://www.linkedin.com/' . $contacto->linkedin[0]['safe_value'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank'
        ),
      )
    ) : NULL;

    $block->content = estaSeteadoContacto($contacto) ? theme('argentinagobar_bloques_area_contacto', array('contacto' => $contacto)) : NULL;
  } else {
    $block->content = NULL;
  }

  return $block;
}

function estaSeteadoContacto($contacto){
  return(
    isset($contacto->direccion) || isset($contacto->codigo_postal)|| isset($contacto->telefono) || isset($contacto->correo_electronico) || isset($contacto->direccion) || isset($contacto->facebook) || isset($contacto->twitter)|| isset($contacto->youtube) || isset($contacto->instagram) || isset($contacto->flickr)
  );
}
