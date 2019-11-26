<?php
/**
 * @file
 * argentinagobar_areas.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function argentinagobar_areas_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:area.
  $config['node:area'] = array(
    'instance' => 'node:area',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'image_src' => array(
        'value' => '[node:field_featured_image]',
      ),
      'itemprop:image' => array(
        'value' => '[node:field_featured_image]',
      ),
      'og:type' => array(
        'value' => 'government',
      ),
      'og:image' => array(
        'value' => '[node:field_featured_image]',
      ),
      'twitter:card' => array(
        'value' => 'summary_large_image',
      ),
      'twitter:creator' => array(
        'value' => '@CasaRosada',
      ),
      'twitter:image:src' => array(
        'value' => '[node:field_featured_image]',
      ),
    ),
  );

  return $config;
}
