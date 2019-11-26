<?php

class FormatoAtajoDestacadoImagen extends FormatoAtajo {

  public $container_theme = "drupar_componentes_panels_row";
  public $formato = "drupar_componentes_atajos_destacado_imagen";

  function crear_atajo($conf_atajo) {
    $conf_atajo['imagen'] = file_load($conf_atajo['imagen']['fid']);
    $conf_atajo['imagen'] = image_style_url('listado', $conf_atajo['imagen']->uri);
    return theme($this->formato, array('atajo' => $conf_atajo));
  }

  function crear_link_atajo($atajo, $conf){
    $clases = 'panel panel-default';
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
