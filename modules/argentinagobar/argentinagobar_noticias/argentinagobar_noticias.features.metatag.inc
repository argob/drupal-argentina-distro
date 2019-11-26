<?php
/**
 * @file
 * argentinagobar_noticias.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function argentinagobar_noticias_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:noticia.
  $config['node:noticia'] = array(
    'instance' => 'node:noticia',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'og:image' => array(
        'value' => '[node:field_featured_image]',
      ),
      'article:author' => array(
        'value' => 'https://www.facebook.com/casarosadaargentina/',
      ),
    ),
  );

  return $config;
}
