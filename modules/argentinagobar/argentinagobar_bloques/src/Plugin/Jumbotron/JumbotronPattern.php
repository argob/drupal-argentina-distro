<?php
  class JumbotronPattern extends Jumbotron{
    function __construct($configuracion,$columna){
      $this->configuracion = $configuracion;
      $this->columna = $columna;
      $this->theme = "argentinagobar_jumbotron";
      $this->backgroundType = array(
          'link'  => array_key_exists('patron', $this->configuracion) ? $this->configuracion['patron'] : "",
          'align' => array_key_exists('align',  $this->configuracion) ? $this->configuracion['align']  : "",
          'class' => "jumbotron jumbotron-pattern",
        );
    }
  }
