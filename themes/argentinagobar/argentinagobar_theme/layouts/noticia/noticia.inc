<?php

// Plugin definition
$plugin = array(
  'title' => t('Noticia'),
  'category' => t('Argentina.gob.ar'),
  'icon' => 'noticia.png',
  'theme' => 'noticia',
  'admin css' => '../../css/bootstrap_panel.min.css',
  'regions' => array(
  	'header_full' => t('Encabezado'), 
  	'header_left' => t('Header Left'), 
  	'header_right' => t('Header Right'),
    'content'  => t('Content'),
    'footer'  => t('Pie'),
  ),
);

