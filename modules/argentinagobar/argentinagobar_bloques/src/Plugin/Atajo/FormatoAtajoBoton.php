<?php

class FormatoAtajoBoton extends FormatoAtajo {

  public $container_theme = "drupar_componentes_row";
  private $formato = "drupar_componentes_atajos_boton";

  function crear_atajo($conf_atajo){
    return theme($this->formato, array('atajo' => $conf_atajo));
  }

  function crear_link_atajo($atajo, $conf){
    $clases = 'btn';
    $clases = isset($conf['destacar']) && $conf['destacar'] ? $clases . ' btn-lg' : $clases;
    $clases = isset($conf['color_boton']) ? $clases . ' ' . $conf['color_boton'] : $clases;
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
    return $contenido;
  }

  function crear_rows($atajos, $columnas){
    return $atajos;
  }
}
