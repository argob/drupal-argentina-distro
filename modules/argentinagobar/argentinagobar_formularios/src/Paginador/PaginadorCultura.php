<?php

class PaginadorCultura
{
  function __construct($inicio, $actual, $total, $intervalo)
  {
    $this->inicio = $inicio;
    $this->actual = $actual;
    $this->total = $total;
    $this->intervalo = $intervalo;
  }

  function renderSiguiente($texto = 'Siguiente', $conIcono = true)
  {

    if ($conIcono) {
      $html = true;
      $texto = '<span aria-hidden="true">&raquo;</span><span class="sr-only">$texto</span>';
    } else {
      $html = false;
    }

    $opciones = array(
      'attributes' => array(
        'aria-label' => $texto,
        'class' => array(
          'page-link',
        ),
      ),
      'html' => $html,
    );

    $link = l($texto, $url, $opciones);

    return '<li class="page-item">' . $link . '</li>';
  }

  function anterior()
  {
    $anterior = array();

    if ($this->actual == 1) {
      $anterior['isDisabled'] = true;
    }

    $anterior['valor'] = (($this->actual - 1) * 20) - 20;

    return $anterior;
  }

  function siguiente()
  {
    $siguiente = array();

    if ($this->actual + 1 > $this->total) {
      $siguiente['isDisabled'] = true;
    }

    $siguiente['valor'] = (($this->actual + 1) * 20) - 20;

    return $siguiente;
  }

  function actual()
  {
    return $this->actual;
  }

  function itemsAnteriores()
  {
    $potencial = $this->actual() - $this->intervalo;

    return array(
      'desde' => $potencial <= 1 ? 1 : $potencial,
      'hasta' => $this->actual()
    );
  }

  function itemsSiguientes()
  {
    $potencial = $this->actual() + $this->intervalo;

    return array(
      'desde' => $this->actual(),
      'hasta' => $potencial >= $this->total ? $this->total : $potencial,
    );
  }

  function items()
  {
    return array(
      'anteriores' => $this->itemsAnteriores(),
      'actual' => $this->actual(),
      'siguientes' => $this->itemsSiguientes(),
    );
  }

  function getParametros()
  {
    return drupal_get_query_parameters($query = NULL, $exclude = array('q'), $parent = '');
  }

  function getURL()
  {
    return base_path() . drupal_get_path_alias();
  }

  function render()
  {
    return theme(
      'cultura_paginador',
      array(
        'anterior' => $this->anterior(),
        'siguiente' => $this->siguiente(),
        'items' => $this->items(),
        'url' => array(
          'base' => $this->getURL(),
          'parametros' => $this->getParametros(),
        )
      )
    );
  }
}