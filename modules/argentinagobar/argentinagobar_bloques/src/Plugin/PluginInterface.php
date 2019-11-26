<?php

interface PluginInterface{
  function render_callbak();
  function admin_info();
  function edit_form();
  function setPlugin();
  function getTitle();
  function getSingle();
  function getDescription();
  function getCategory();
  function getDefaults();
}


/*

$plugin = array(
  'single' => TRUE,
  'title' => t('Grupo de Atajos'),
  'description' => t('Los atajos se utilizan para enlazar cualquier tipo de contenido, tanto interno como externo, y con diferentes tipos de jerarquías.'),
  'category' => t('Drupar'),
  'render callback' => 'drupar_componentes_atajos_render',
  'edit form' => 'drupar_componentes_atajos_edit_form',
  'admin info' => 'drupar_componentes_atajos_admin_info',
  'defaults' => array(
    'atajos' => array(),
    'cantidadAtajos' => 1,
    'opciones' => array(
      'formato' => 'AtajoSimple',
      'columnas' => 1,
    ),
  )
);

*/
