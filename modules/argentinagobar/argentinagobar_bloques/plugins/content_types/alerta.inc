<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Alerta'),
  'description' => t('Muetra una alerta.'),
  'category' => t('Argentina.gob.ar'),
  'edit form' => 'argentinagobar_bloques_alerta_edit_form',
  'render callback' => 'argentinagobar_bloques_alerta_render',
  'admin info' => 'argentinagobar_bloques_alerta_admin_info',
  'defaults' => array(
    'tipo' => 'warning',
    'titulo' => '',
    'texto' => '',
    'con_icono' => '',
    'icono' => 'glyphicon-home',
  )
);
/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_alerta_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Alerta');
    $block->content = t('Alerta tipo @tipo.', array('@tipo' => $conf['tipo']));
    return $block;
  }
}
/**
* 'Edit form' callback for the content type.
*/
function argentinagobar_bloques_alerta_edit_form($form, &$form_state) {
  $form['tipo'] = array(
    '#title' => t('Tipo de alerta'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['tipo'],
    '#options' => array(
      'success' => t('Success'),
      'info' => t('Info'),
      'warning' => t('Warning'),
      'danger' => t('Danger'),
      'default' => t('Default'),
    ),
  );
  /*
  *Permite obtener un titulo opcional.
  */
  $form['titulo'] = array(
    '#title' => t('Título'),
    '#type' => 'textfield',
    '#default_value' => $form_state['conf']['titulo'],
    '#required' => FALSE,
  );
  /*
  *Texto de las alertas.
  */
  
  $form['texto'] = array(
    '#title' => t('Contenido'),
    '#type' => 'text_format',
    '#format' => 'filtered_html',
    '#default_value' => $form_state['conf']['texto']['value'],
    '#after_build' => array('ocultarSeleccionFormatoTexto'),
    '#required' => TRUE,
  );
  /*
  *Opcion para con icono
  */
  $form['con_icono'] = array(
  '#type' => 'checkbox',
  '#title' => t('Con icono:'),
  '#default_value' => $form_state['conf']['con_icono'],
  '#description' => t('Alerta con icono.'),
  );
  /*
  *LLama a los iconos.
  */
  $form['icono'] = array(
    '#title' => t('Ícono'),
    '#type' => 'select',
    '#default_value' => $form_state['conf']['icono'],
    '#options' => variable_get('iconos', $default = NULL),
    '#states' => array(
      'visible' => array(
        ':input [name="con_icono"]' => array('checked' => TRUE),
      ),
      'invisible' => array(
        ':input[name="con_icono"]' => array('checked' => FALSE),
      ),
    ),
  );
  return $form;
}
/**
* The submit form stores the data in $conf.
*/
function argentinagobar_bloques_alerta_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
function argentinagobar_bloques_alerta_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('argentinagobar_bloques_alerta',
  array(
    'titulo' => $conf['titulo'], 
    'tipo' => $conf['tipo'], 
    'texto' => check_markup($conf['texto']['value'], $conf['texto']['format']),
    'icono' => $conf['icono'],
    'con_icono' => $conf['con_icono'],
    )
  
  );
  return $block;
}