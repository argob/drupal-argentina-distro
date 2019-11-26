<?php

class ConsultaRegistroViajes extends ConsultaRegistroObsequiosViajes{

  public $client_endpoint;

  function __construct(){
    $this->client_endpoint = variable_get('consulta_viajes_client_endpoint', NULL);
  }

  function setItems($itemsFormateados){
    $this->items = $itemsFormateados;
  }

  function formatear($item) {

    $financiado_por = array();
    if(isset($item['denominacion_organismo_gub'])) {
      $financiado_por = $item['denominacion_organismo_gub'];
    }elseif(isset($item['apellidos'])) {
      $financiado_por = $item['apellidos'] . " " . $item['nombres'];;
    }elseif(isset($item['razon_social_fuente_financiami'])) {
      $financiado_por = $item['razon_social_fuente_financiami'];
    }


    return array(
      'class' => array('clickable-item'),
      'elemento' => $item,
      'onclick' => 'window.open("/anticorrupcion/obsequiosyviajes/' . $item['numero'] . '")',
      'data' => array(
        array('data' => $item['evento_participara'], 'class' => array('evento')),
        array('data' =>"<h6><a>". $item['destino_viaje']. "</a></h6>", 'class' => array('pais')),
        array('data' => $item['apellido_1'] ." ". $item['nombre_1'], 'class' => array('funcionario')),
        array('data' => $item['cargo_funcion'], 'class' => array('cargo')),
        array('data' => $item['jurisdiccioon'], 'class' => array('organismo')),
        array('data' => "Desde ".$item['date_fecha_inicio']. " hasta " .$item['date_fecha_finalizacion'], 'class' => array('fecha')),
        array('data' => $financiado_por, 'class' => array('financiamiento')),
      ),
    );
  }

  function esEstructuraDatosValida($item){
    return isset($item['numero']);
  }
}
