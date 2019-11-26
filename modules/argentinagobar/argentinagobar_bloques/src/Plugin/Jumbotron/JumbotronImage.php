<?php
  class JumbotronImage extends Jumbotron {
    function __construct($configuracion,$columna){
      $this->configuracion = $configuracion;
      $this->columna = $columna;
      $this->theme = "argentinagobar_jumbotron";
      $this->backgroundType = array(
        'link'  => $this->configuracion['imagen_destacada'],
        'align' => $this->configuracion['align'],
        'class' => "jumbotron ",
      );
    }
  }
