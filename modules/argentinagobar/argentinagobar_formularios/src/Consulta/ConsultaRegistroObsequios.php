<?php

class ConsultaRegistroObsequios extends ConsultaRegistroObsequiosViajes{

  public $client_endpoint;

  function __construct(){
    $this->client_endpoint = variable_get('consulta_obsequios_client_endpoint', NULL);
  }

  function setItems($itemsFormateados){
    $this->items = $itemsFormateados;
  }

  function formatear($item) {

      $item['combo_valor_estimado'] = isset($item['combo_valor_estimado']) == "Inferior a 4 módulos." ? $item['combo_valor_estimado'] : "Valor institucional.";

      $item['destino'] = isset($item['destino']) ? $item['destino'] : '';

        $entregado_por = array();
        if(isset($item['denominacion_organismo'])) {
          $entregado_por = $item['denominacion_organismo'];
        }elseif(isset($item['apellidos_a'])) {
          $entregado_por = $item['apellidos_a'] . " " . $item['nombres_a'];;
        }elseif(isset($item['razon_social'])) {
          $entregado_por = $item['razon_social'];
        }elseif(isset($item['descripcion_a'])) {
          $entregado_por = $item['descripcion_a'];
        }

    return array(
      'class' => array('clickable-item'),
      'elemento' => $item,
      'onclick' => 'window.open("/anticorrupcion/obsequiosyviajes/' . $item['numero'] . '")',
      'data' => array(
        array('data' => "<h6><a>". $item['descripcion'] . "</a></h6>", 'class' => array('descripcion'), 'data-descripcion' => $item['descripcion']),
        array('data' => $item['apellidos'] . " " . $item['nombres'], 'class' => array('funcionario')),
        array('data' => $item['cargo_funcion'], 'class' => array('cargo')),
        array('data' => $item['bandbox_jurisidccion'], 'class' => array('organismo')),
        array('data' => $item['fecha_recepcion'], 'class' => array('fecha')),
        array('data' => $item['combo_valor_estimado'], 'class' => array('valor_estimado')),
        array('data' => $item['destino'], 'class' => array('destino')),
        array('data' => $entregado_por, 'class' => array('entregado_por')),
      ),
    );
  }

  function esEstructuraDatosValida($item){
    return isset($item['numero']);
  }
}
