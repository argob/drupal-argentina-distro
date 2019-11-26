<?php

// Plugin definition
$plugin = array(
  'title' => t('Trámite'),
  'category' => t('Argentina.gob.ar'),
  'icon' => 'tramite.png',
  'theme' => 'tramite',
  'admin css' => '../../css/bootstrap_panel.min.css',
  'regions' => array(
  	'header_full' => t('Encabezado'), 
    'content'  => t('Content'),
    'content_bottom'  => t('Content bottom'),
    'footer'  => t('Pie'),
    'footer_2'  => t('Pie 2'),
  ),
);

