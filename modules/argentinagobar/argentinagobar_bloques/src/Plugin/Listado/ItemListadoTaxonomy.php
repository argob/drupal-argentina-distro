<?php

class ItemListadoTaxonomy{
  private $url;
  private $titulo;
  private $resumen;
  private $imagen;
  private $fecha;

  function __construct($url, $titulo, $resumen, $imagen, $fecha){
    $this->url = $url;
    $this->titulo = $titulo;
    $this->resumen = $resumen;
    $this->imagen = $imagen;
    $this->fecha = $fecha;
  }

  function getUrl(){
    return $this->url;
  }
  function getTitulo(){
    return $this->titulo;
  }
  function getResumen(){
    return $this->resumen;
  }
  function getImagen(){
    return $this->imagen;
  }
  function getFecha(){
    return $this->fecha;
  }
}
