<?php

abstract class Filtro{

  function __construct($listado){
    $this->listado = $listado;
  }

  abstract function crear_form($form, &$form_state);
}
