<?php
/**
 * @file
 * argentinagobar_media.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function argentinagobar_media_image_default_styles() {
  $styles = array();

  // Exported image style: cuadrada.
  $styles['cuadrada'] = array(
    'label' => 'Cuadrada',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: icono_aplicacion.
  $styles['icono_aplicacion'] = array(
    'label' => 'Ícono de aplicación',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 120,
          'height' => 120,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'icono_aplicacion',
        ),
        'weight' => 0,
      ),
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 240,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: jumbotron.
  $styles['jumbotron'] = array(
    'label' => 'Jumbotrón',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 720,
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'jumbotron',
        ),
        'weight' => -10,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 1080,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: listado.
  $styles['listado'] = array(
    'label' => 'Listado',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 420,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
