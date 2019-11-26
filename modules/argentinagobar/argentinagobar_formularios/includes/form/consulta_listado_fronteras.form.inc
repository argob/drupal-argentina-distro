<?php

  function consulta_listado_fronteras($form, &$form_state){

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

    $form['contenedor']['busqueda'] = array(
      '#type' => 'textfield',
      '#title' => 'Buscar',
      '#title_display' => 'invisible',
      '#attributes' => array(
        'class' => array('searchClass')
      ),
      '#prefix' => '<div class="row"><div class="m-b-3 col-md-8 col-md-offset-2">',
      '#suffix' => '</div></div>',
    );
    $header = array(
      'Estado',
      'Nombre',
      'Pais Limitrofe',
      'Provincia',
      'Tipo',
    );

    $pasos_fronterizos = variable_get('pasos_fronterizos',array());

    $form['contenedor']['response'] = array(
      '#type' => 'markup',
      '#markup' => theme('consulta_pasos_fronterizos', array(
        'pasos_fronterizos'=> $pasos_fronterizos
      )),
    );

    $form['contenedor']['response']['pagination'] = array(
      '#type' => 'markup',
      '#markup' => '<nav class="text-center"><ul class="pagination"></ul></nav>',
    );
  return $form;
}
