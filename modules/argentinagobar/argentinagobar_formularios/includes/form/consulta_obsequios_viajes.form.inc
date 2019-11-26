<?php

function consulta_obsequios_viajes($form, &$form_state) {

  if(empty($viajes) or empty($obsequios)) {
    _consultaRegistroObsequiosViajes();
    $viajes = cache_get('viajes')->data;
    $obsequios = cache_get('obsequios')->data;
  }

  $form = array();


  $form['#attached']['js'][] = array(
    'type' => 'file',
    'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/scripts.js',
  );

  $form['#attached']['js'][] = array(
    'type' => 'external',
    'data' => '//cdnjs.cloudflare.com/ajax/libs/list.js/1.5.0/list.min.js',
  );

  $form['contenedor'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'contenedor',
      ),
  );

  $form['contenedor']['buscador']['busqueda'] = array(
    '#type' => 'textfield',
    '#title' => 'Buscar',
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array('search')
    ),
    '#prefix' => '<div class="row"><div class="m-b-3 col-md-8 col-md-offset-2">',
    '#suffix' => '</div></div>',
  );

  $form['contenedor']['response'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'response'
    ),
  );

  $form['contenedor']['response']['opciones'] = array(
    '#type' => 'vertical_tabs',
    '#description' => t('opciones de obsequios o Viajes'),
  );

  $form['contenedor']['response']['tabs']['obsequios'] = array(
    '#type' => 'fieldset',
    '#title' => t('Obsequios'),
    '#group' => 'opciones',
  );

  $form['contenedor']['response']['tabs']['viajes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Viajes financiados por terceros'),
    '#group' => 'opciones',
  );

  $header_viajes = array(
    'Evento',
    'Destino',
    'Funcionario',
    'Cargo',
    'Organismo',
    'Fecha inicio y fin',
    'Financiado por'
  );

  $header_obsequios = array(
    'Descripción',
    'Funcionario',
    'Cargo',
    'Organismo',
    'Fecha recepción',
    'Valor estimado',
    'Destino',
    'Entregado por'
  );

  $form['contenedor']['response']['tabs']['viajes']['tabla-viajes'] = array(
    '#type' => 'markup',
    '#markup' => theme(
      'table',
      array(
        'header' => $header_viajes,
        'rows' => $viajes,
        'attributes' => array('id' => 'viajes-lista'),
        'sticky' => FALSE,
        'empty' => t('No hay @items disponibles', array('@items' => 'viajes')),
      )
    ),
    '#group' => 'opciones',
  );

  $form['contenedor']['response']['tabs']['obsequios']['tabla-obsequios'] = array(
    '#type' => 'markup',
    '#markup' => theme(
      'table',
      array(
        'header' => $header_obsequios,
        'rows' => $obsequios,
        'attributes' => array('id' => 'obsequios-lista'),
        'sticky' => FALSE,
        'empty' => t('No hay @items disponibles.', array('@items' => 'obsequios')),
      )
    ),
    '#group' => 'opciones',
  );

  $form['contenedor']['response']['tabs']['obsequios']['pagination'] = array(
    '#type' => 'markup',
    '#markup' => '<nav class="text-center"><ul class="pagination"></ul></nav>',
  );

  $form['contenedor']['response']['tabs']['viajes']['pagination'] = array(
    '#type' => 'markup',
    '#markup' => '<nav class="text-center"><ul class="pagination"></ul></nav>',
  );
  return $form;
}
