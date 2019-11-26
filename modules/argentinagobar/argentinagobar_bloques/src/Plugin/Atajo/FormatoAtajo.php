<?php

abstract class FormatoAtajo {

  public $container_theme;
  private $formato;
  private $isActive = FALSE;
  private $columnas = array(
    1 => 'col-md-12',
    2 => 'col-md-6',
    3 => 'col-md-4',
    4 => 'col-md-3',
  );
  abstract protected function crear_link_atajo($atajo, $conf_atajo);
  abstract protected function crear_grid_atajo($atajo, $columnas);
  abstract protected function crear_atajo($conf_atajo);
  abstract protected function crear_rows($atajos, $columnas);

  protected function getClaseColumnas($nro_columnas) {
    return array('col-xs-12', 'col-sm-6', $this->columnas[$nro_columnas]);
  }

  function getContainerTheme(){
    return $this->container_theme;
  }

  public function render($conf_atajo, $columnas){
    $atajo = $this->crear_atajo($conf_atajo);
    $atajo = $this->crear_link_atajo($atajo, $conf_atajo);
    return $this->crear_grid_atajo($atajo, $columnas);
  }
}
