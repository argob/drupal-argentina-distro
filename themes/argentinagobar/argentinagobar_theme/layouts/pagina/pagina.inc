<?php

// Plugin definition
$plugin = array(
  'title' => t('Página'),
  'category' => t('Argentina.gob.ar'),
  'icon' => 'pagina.png',
  'theme' => 'pagina',
  'admin css' => '../../css/bootstrap_panel.min.css',
  'regions' => array(
  	'header_full' => t('Ancho completo'),
    'header_contained' => t('Contenedor'),
  	'header_left' => t('Mitad izquieda'),
  	'header_right' => t('Mitad derecha'),
    'content'  => t('Contenido'),
    'navegacion_atajos' => t('Contenedor para los Atajos'),
    'content_bottom'  => t('Sección 1'),
    'section_1'  => t('Sección 2'),
    'section_2'  => t('Sección 3'),
    'section_3'  => t('Sección 4'),
    'footer'  => t('Sección 5'),
    'footer_2'  => t('Sección 6'),
    'footer_2a'  => t('Sección 6: izquierda'),
    'footer_2b'  => t('Sección 6: derecha'),
  ),
);
