<?php
   abstract class Jumbotron {
     public $data;
     function __construct($configuracion,$columna){
      $this->configuracion = $configuracion;
      $this->columna = $columna;
    }
    public function render(){
      $this->data = array(
        'overlay' => $this->configuracion['overlay'],
        'menuBar' => $this->configuracion['menuBar'],
        'showTitle' => $this->configuracion['visualizacion_titulo'],
        'descripcion' => $this->configuracion['resumen'],
        'columna' => $this->columna,
      );
    return theme($this->theme,array(
      'data' => $this->data,
      'breadcrumb' => $this->configuracion['breadcrumb'],
      'menu' => $this->configuracion['menuBar'],
      'background' => $this->backgroundType,
      ));
    }
  }
