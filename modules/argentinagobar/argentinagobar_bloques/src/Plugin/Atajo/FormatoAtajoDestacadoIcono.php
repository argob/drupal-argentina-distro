<?php

class FormatoAtajoDestacadoIcono extends FormatoAtajo {

  public $container_theme = "drupar_componentes_panels_row";
  private $formato = "drupar_componentes_atajos_destacado_icono";

  function crear_atajo($conf_atajo){
    return theme($this->formato, array('atajo' => $conf_atajo));
  }

  function crear_link_atajo($atajo, $conf){
    $clases = 'panel panel-default';
    $clases = isset($conf['color_fondo']) ? $clases . ' panel-icon ' . str_replace("bg-","panel-",$conf['color_fondo']) : $clases;
    $url = !empty($conf['link_interno']) ? drupal_get_path_alias('node/' . $conf['link_interno']['entity_id']) : $conf['link_externo'];

    return l($atajo, $url, array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array($clases),
        ),
      )
    );
  }

  function crear_grid_atajo($contenido, $columnas) {
    return theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'div',
          '#attributes' => array(
            'class' => $this->getClaseColumnas($columnas),
            ),
          '#value' => $contenido,
        )
      )
    );
  }

  function crear_rows($atajos, $columnas){
    return array_chunk($atajos, $columnas);
  }
}
