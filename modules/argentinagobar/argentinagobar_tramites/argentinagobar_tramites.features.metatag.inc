<?php
/**
 * @file
 * argentinagobar_tramites.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function argentinagobar_tramites_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:tramite.
  $config['node:tramite'] = array(
    'instance' => 'node:tramite',
    'config' => array(
      'keywords' => array(
        'value' => '[node:field_palabras_clave]',
      ),
    ),
  );

  return $config;
}
