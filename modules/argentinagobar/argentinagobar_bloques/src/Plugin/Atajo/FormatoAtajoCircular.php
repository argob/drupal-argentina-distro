<?php

class FormatoAtajoCircular extends FormatoAtajo {

  public $container_theme = "drupar_componentes_nav_icons";
  private $formato = "drupar_componentes_atajos_circular";

  function crear_atajo($conf_atajo){
    return theme($this->formato, array('atajo' => $conf_atajo));
  }

  function crear_link_atajo($atajo, $conf){

    $url = !empty($conf['link_interno']) ? drupal_get_path_alias('node/' . $conf['link_interno']['entity_id']) : $conf['link_externo'];

    $this->isActive = drupal_get_path_alias(current_path()) == $url ? TRUE : FALSE;

    return l($atajo, $url, array(
        'html' => TRUE,
      )
    );
  }

  function crear_grid_atajo($contenido, $columnas) {

    $class = $this->isActive ? array('active') : array('');

    $this->hay_atajo_activo = $this->isActive ? TRUE : FALSE;


    return theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'li',
          '#value' => $contenido,
          '#attributes' => array(
            'class' => $class,
          ),
        ),
      )
    );
  }

  function crear_rows($atajos, $columnas){
    return $atajos;
  }
}
