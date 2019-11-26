<?php

/**
 * @file
 * admin file for youtubechannel.
 */

/**
 * Settings form for youtube channel.
 */
function map_settings_form() {
  $form = array();

  $form['map_nac'] = array(
    '#type' => 'fieldset',
    '#title' => t('Youtube channel settings'),
    '#collapsible' => FALSE,
  );

  $form['map_nac']['map_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Key Google'),
    '#size' => 100,
    '#default_value' => variable_get('map_api_key', ''),
    '#required' => TRUE,
    '#description' => t('Api Key de Google'),
  );

  $form['map_nac']['map_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width, del mapa'),
    '#size' => 20,
    '#default_value' => variable_get('map_width', '100%'),
    '#required' => FALSE,
    '#description' => t('Width del mapa, default 100%'),
  );

  $form['map_nac']['map_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height, del mapa'),
    '#size' => 20,
    '#default_value' => variable_get('map_height', '500px'),
    '#required' => FALSE,
    '#description' => t('Height del mapa, default 500px'),
  );


  return system_settings_form($form);
}
