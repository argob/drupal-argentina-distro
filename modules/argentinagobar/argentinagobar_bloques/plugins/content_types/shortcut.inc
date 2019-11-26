<?php

$plugin = array(
  'single' => TRUE,
  'title' => 'Atajo, no valido utilice Drupar/Grupo de atajos',
  'description' => t('Utilice Grupo de atajos este contenido ya no tiene mantenimiento'),
  'category' => t('Argentina.gob.ar'),
  'render callback' => 'argentinagobar_bloques_shortcut_render',
  'edit form' => 'argentinagobar_bloques_shortcut_edit_form',
  'admin info' => 'argentinagobar_bloques_shortcut_admin_info',
  'defaults' => array(
    'color_fondo' => 'shortcut-azul',
    'icono' => 'glyphicon-home',
    'titulo' => '',
    'texto' => '',
    'cuerpo' => '',
    'referencia' => '',
    'link' => '',
    'formato_de_shortcut' => ''
  )
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_shortcut_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : $conf['titulo'];
    $block->content = $conf['texto'];
    return $block;
  }
}

/**
* 'Edit form' callback for the content type.
*/
function argentinagobar_bloques_shortcut_edit_form($form, &$form_state) {


  $form['titulo'] = array(
    '#title' => t('Título'),
    '#type' => 'textfield',
    '#default_value' => $form_state['conf']['titulo'],
    '#required' => TRUE,
  );
  $form['texto'] = array(
    '#title' => t('Texto'),
    '#type' => 'textfield',
    '#default_value' => $form_state['conf']['texto'],
    '#required' => FALSE,
    '#maxlength' => 500,
  );


  $form['color_fondo'] = array(
    '#title' => t('Color de fondo'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['color_fondo'],
    '#options' => array(
      'shortcut-naranja' => t('Naranja'),
      'shortcut-azul' => t('Azul'),
      'shortcut-rojo' => t('Rojo'),
      'shortcut-verde' => t('Verde')
    ),
  );

 $form['formato_de_shortcut'] = array(
    '#type' => 'select',
    '#title' => t('Formato de atajo'),
    '#options' => array(
      'simple' => t('Ícono simple y título'),
      'destacado' => t('Ícono destacado y título'),
      'destacado_html' => t('Ícono destacado y título con texto html'),
      'boton' => t('Botón'),
      'boton_con_descripcion' => t('Botón con Descripción')
    ),
    '#default_value' => $form_state['conf']['formato_de_shortcut'],
    '#description' => t('Cada tipo de atajo tiene un comportamiento diferente'),
  );


  $form['icono'] = array(
    '#title' => t('Ícono'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['icono'],
    '#options' => variable_get('iconos', $default = NULL)
  );

  $form['cuerpo'] = array(
      '#title' => t('Contenido'),
      '#type' => 'text_format',
      '#format' => 'full_html',
      '#default_value' => $form_state['conf']['cuerpo']['value'],
      '#required' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="formato_de_shortcut"]' => array(
            'value' => "argentinagobar_bloques_shortcut_destacado_html"
          ),
        )

      ),
    );

  $form['referencia'] = array(
    '#type' => 'entityreference',
    '#title' => t('Página, trámite o noticia'),
    '#default_value' => $form_state['conf']['referencia'],
    '#required' => FALSE,
    '#era_entity_type' => 'node',  // Mandatory.
    '#era_bundles' => array(), // Optional (Any bundle by default).
    '#era_cardinality' => 1,       // Optional (1 By default).
    '#states' => array(
      'invisible' => array(
        ':input[name="link"]' => array('filled' => TRUE),
      ),
    ),
    '#description' => t('Usar este campo para referenciar contenido'),
  );
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#default_value' => $form_state['conf']['link'],
    '#required' => FALSE,
    '#states' => array(
      'invisible' => array(
        ':input[name="referencia"]' => array('filled' => TRUE),
      ),
    ),
    '#description' => t('Usar este campo para crear un link personalizado'),
  );
  return $form;
}

/**
* The submit form stores the data in $conf.
*/
function argentinagobar_bloques_shortcut_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
function argentinagobar_bloques_shortcut_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $block->content = theme(
    'argentinagobar_bloques_shortcut_' . $conf["formato_de_shortcut"],
    array(
      "link" => crearLinkDestacado($conf)
    )
  );

  return $block;
}

function crearLinkDestacado ($conf) {
  return (
    !empty($conf['referencia']) || !empty($conf['link']) ? l(
      theme(
        'argentinagobar_bloques_shortcut_' . $conf["formato_de_shortcut"] . '_item',
        array(
          'color' => $conf['color_fondo'],
          'icono' => $conf['icono'],
          'texto' => $conf['texto'],
          'cuerpo' => (!empty($conf['cuerpo']))?($conf['cuerpo']["value"]) :"",
          'titulo' => $conf['titulo'],
          'css' => ''
        )
      ),
      !empty($conf['referencia']) ? 'node/' . $conf['referencia']['entity_id'] : $conf['link'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => $conf["formato_de_shortcut"] == 'boton' ? array(
            'btn',
            'btn-primary',
            'btn-lg'
          ) : array(
            'panel',
            'panel-default',
            'panel-icon'
          ),
          //'target' => empty($conf['referencia']) ? '_blank' : '_self'
        ),
      )
    ) : theme(
      'argentinagobar_bloques_shortcut_' . $conf["formato_de_shortcut"] ,
      array(
        'color' => $conf['color_fondo'],
        'icono' => $conf['icono'],
        'texto' => $conf['texto'],
        'cuerpo' => (!empty($conf['cuerpo'])) ? ($conf['cuerpo']["value"]) : "",
        'titulo' => $conf['titulo'],
        'css' => 'col-sm-6 col-md-3'
      )
    )
  );
}
