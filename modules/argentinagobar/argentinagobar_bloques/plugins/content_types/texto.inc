<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Texto'),
  'description' => t('Crea un párrafo.'),
  'category' => t('Argentina.gob.ar'),
  'edit form' => 'argentinagobar_bloques_texto_edit_form',
  'render callback' => 'argentinagobar_bloques_texto_render',
  'admin info' => 'argentinagobar_bloques_texto_admin_info',
  'defaults' => array(
    'destacado' => 0,
    'texto' => NULL,
    'sobreescribir' => 0,
    'cuerpo_o_resumen' => 'body'
  )
);

function argentinagobar_bloques_texto_edit_form($form, &$form_state){

  $form['destacado'] = array(
    '#type' => 'checkbox',
    '#title' => t('Texto destacado'),
  );
  $form['cuerpo_o_resumen'] = array(
    '#type' => 'radios',
    '#title' => t('Cantidad de texto'),
    '#default_value' => $form_state['conf']['cuerpo_o_resumen'],
    '#options' => array('body' => 'Texto completo', 'summary' => 'Resumen'),
  );
  $form['sobreescribir'] = array(
    '#title' => t('¿Personalizar texto?'),
    '#type' => 'checkbox',
    '#default_value' => $form_state['conf']['sobreescribir'],
  );
  $form['texto'] = array(
    '#title' => t('Contenido'),
    '#type' => 'text_format',
    '#format' => $form_state['conf']['texto']['format'],
    '#default_value' => $form_state['conf']['texto']['value'],
    '#required' => FALSE,
    '#states' => array(
      'disabled' => array(
        ':input[name="sobreescribir"]' => array('checked' => FALSE),
      ),
      'required' => array(
        ':input[name="sobreescribir"]' => array('checked' => TRUE),
      )
    ),
  );

  return $form;
}

/**
* The submit form stores the data in $conf.
*/
function argentinagobar_bloques_texto_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function argentinagobar_bloques_texto_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $esNodoORevisionDeNodo = esNodo() || esRevisionDeNodo();
  $sobreescribir = $conf['sobreescribir'];
  if($esNodoORevisionDeNodo){
    $body = !esNodo() ? field_get_items('node', node_load(arg(1)), 'body', NULL) : field_get_items('node', node_load(arg(1), arg(3)), 'body', NULL);
  }
  $texto = !$sobreescribir && $esNodoORevisionDeNodo ? $body : $conf['texto'];
  $texto = !$sobreescribir && $esNodoORevisionDeNodo ? procesarBody($texto, $conf) : check_markup($texto['value'],$texto['format']);
  $block->content = theme(
    'argentinagobar_bloques_texto',
    array(
      'tag' => theme(
        'html_tag',
        array(
          'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
              'class' => $conf['destacado'] ? 'lead' : ''
            ),
            '#value' => $texto,
          ),
        )
      )
    )
  );

  return $block;
}

function argentinagobar_bloques_texto_admin_info($subtype, $conf, $contexts){

  $campos['contenido_texto'] = $conf['texto']['value'];
  $campos['contenido_texto'] = limpiar_javascript($campos['contenido_texto']);
  $campos['contenido_texto'] = limpiar_espacios($campos['contenido_texto']);
  $campos['contenido_texto'] = strip_tags($campos['contenido_texto']);
  strlen($campos['contenido_texto']) == 0 ?  $campos['contenido_texto'] = "sin contenido" : $campos['contenido_texto']."...";
  $campos['destacado']  = traducir_true_false($conf['destacado']);

  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : substr($campos['contenido_texto'],0,40)."...";
    $block->content = theme('argentinagobar_bloques_admin_info', array('campos' => $campos));
    return $block;
  }

}

