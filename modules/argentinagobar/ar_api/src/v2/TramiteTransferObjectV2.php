<?php


//namespace Drupal\argentinagobar_servicios\v2;

class TramiteTransferObjectV2 extends TransferObject{

  private $host;

  protected $node_wrapper;

  function __construct($nid){

    $this->setHost();

    $this->node_wrapper = entity_metadata_wrapper('node', $nid);
  }

  function get_modalidad($node_wrapper){

    $modalidad = array(
      'modalidad_digital' => $node_wrapper->field_modalidad_digital->value(),
      'modalidad_telefonico' => $node_wrapper->field_modalidad_telefonico->value(),
      'modalidad_presencial' => $node_wrapper->field_modalidad_presencial->value(),
      'modalidad_otro' => $node_wrapper->field_modalidad_otro->value(),
      'modalidad_otro_especificar' => $node_wrapper->field_modalidad_otro_especificar->value(),
  );
      $this->modalidad = $modalidad;

  }

  function get_id($node_wrapper){

     $this->id = (string)$node_wrapper->getIdentifier();
  }

  function get_summary($node_wrapper){

     $this->summary = $node_wrapper->body->value()['summary'];
  }

  function get_informacion_adicional($node_wrapper){

     $this->informacion_adicional = $node_wrapper->field_informacion_adicional->value();
  }

  function get_vigencia($node_wrapper){

    $vigencias = array();

    if(!empty($node_wrapper->field_vigencia->value())){

      foreach($node_wrapper->field_vigencia->field_vigencia_campos->getIterator() as $item){

        $vigencias['items'][] = [
          'cantidad'  => $item->field_cantidad->value(),
          'medida'    => $item->field_medida->value(),
          'detalle'   => $this->markdownURLAbsoluta($item->field_detalle->value())
        ];

      }

    }

    $this->vigencia = !empty($vigencias) ? $vigencias : null;
  }

  function get_url($node_wrapper){

    $this->url = $node_wrapper->url->value();
  }

  function get_language($node_wrapper){

    $language = array(
      'value' => $node_wrapper->language->value(),
      'name'  => $node_wrapper->language->label()
    );

    $this->language = $language;

  }

  function get_grupo($node_wrapper){

    $groups = array();

    foreach($node_wrapper->og_group_ref->getIterator() as $group){

      $groups['items'][] = array(
        'id'    => $group->getIdentifier(),
        'title' => $group->label()
      );
    }

    $this->og_group_ref = $groups == array() ? null : $groups;

  }

  function get_title($node_wrapper){

     $this->title = $node_wrapper->label();
  }

  function get_body($node_wrapper){

    $this->body = $this->markdownURLAbsoluta($node_wrapper->body->value());

    unset($this->body['summary']);
    unset($this->body['safe_summary']);
  }

  function is_field_requested($field_name, $fields){

    return empty($fields) || in_array($field_name, $fields);
  }

  function get_oficina($node_wrapper){

    $donde = array();

    $donde[] = array(
      'oficina' => $node_wrapper->field_oficina->value(),
      'oficina_otra' => $node_wrapper->field_oficina_otra->value(),
    );

    $this->donde = $donde == array() ? null :$donde;

  }

  function get_acciones($node_wrapper){

    $acciones = array();

    foreach($node_wrapper->field_acciones->getIterator() as $accion){

      $acciones['items'][] = array(
        'url' => $accion->field_url->value()['url'],
        'accion' => $accion->field_accion->value(),
        'detalle' => $this->markdownURLAbsoluta($accion->field_detalle->value()),
      );
    }

    $this->acciones = $acciones == array() ? null : $acciones;
  }

  function get_costo($node_wrapper){

      $costos = array();

      if(!empty($node_wrapper->field_costo->value())){

        $costos['es_gratuito'] = $node_wrapper->field_costo->field_gratuito->value();

        foreach($node_wrapper->field_costo->field_valor->getIterator() as $valor){

          $costos['items'][] = array(
            'precio' =>$valor->field_precio->value(),
            'detalle' => $this->markdownURLAbsoluta($valor->field_detalle->value()),
          );

        }

        $costos['observaciones'] = $this->markdownURLAbsoluta($node_wrapper->field_costo->field_observaciones->value());

      }

      $this->costos = !empty($costos) ? $costos : null;
  }

  function get_categorias($node_wrapper){

    $categorias = array();

    foreach($node_wrapper->field_servicio_categoria->getIterator() as $categoria){

      $categoria = $categoria->value();

      $categorias['items'][] = array(
          'tid' => $categoria->tid,
          'nombre' => $categoria->name,
          'descripcion' => $categoria->description,
      );
    }

    $this->categorias = $categorias;
  }

  function get_palabras_clave($node_wrapper){

    $palabras_claves = array();

    foreach($node_wrapper->field_palabras_clave->getIterator() as $palabras){

      $palabras = $palabras->value();

      $palabras_claves['items'][] = array(
          'tid' => $palabras->tid,
          'nombre' => $palabras->name
      );
    }

    $this->palabras_clave = $palabras_claves == array() ? null : $palabras_claves;
  }

  function get_download($node_wrapper){

    $archivos = array();

    foreach($node_wrapper->field_download->getIterator() as $descarga){

      $descarga = $descarga->value();

      $archivos['items'][] = array(
        'filename' => $descarga['filename'],
        'url' => file_create_url($descarga['uri']),
      );
    }

    $this->download = $archivos == array() ? null : $archivos;
  }

  function get_duracion($node_wrapper){

    $duraciones = array();

    if(!empty($node_wrapper->field_duracion->value())){

      foreach($node_wrapper->field_duracion->field_cantidades->getIterator() as $item){

        $duraciones['items'][] = [
          'cantidad'  => $item->field_cantidad->value(),
          'medida'    => $item->field_medida->value(),
          'detalle'   => $this->markdownURLAbsoluta($item->field_detalle->value())
        ];

      }

      $this->duracion = $duraciones;

    }

    $this->duracion = !empty($duraciones) ? $duraciones : null;

  }

  function get_dirigido($node_wrapper){

    $dirigido = array();

    if(!empty($node_wrapper->field_dirigido->value())){

      $dirigido['detalle'] = $this->markdownURLAbsoluta($node_wrapper->field_dirigido->field_detalle->value());

      $dirigido['observaciones'] = $this->markdownURLAbsoluta($node_wrapper->field_dirigido->field_observaciones->value());

      $this->dirigido = $dirigido;

    } else {

      $this->dirigido = null;

    }

  }

  function get_pasos($node_wrapper){

    $pasos = array();

    foreach($node_wrapper->field_pasos->field_paso->getIterator() as $paso){

      $pasos['items'][] = $this->markdownURLAbsoluta($paso->value());
    }

    $pasos['observaciones'] = $this->markdownURLAbsoluta($node_wrapper->field_pasos->field_observaciones->value());

    $this->pasos = $pasos;
  }

  function get_alias($node_wrapper){

    $this->alias = url( $this->getHost() .'/node/' . $node_wrapper->getIdentifier(), array('absolute' => FALSE));
  }

  function get_servicios_relacionados($node_wrapper){


    $servicios = array();

    foreach($node_wrapper->field_servicios_relacionados->getIterator() as $servicio){

      $servicios['items'][] = array(
        'id' => $servicio->field_servicio->getIdentifier(),
        'alias' => url($this->getHost() .'/node/' . $servicio->field_servicio->getIdentifier(), array('absolute' => FALSE)),
        'titulo' => $servicio->field_servicio->label(),
        'detalle' => $this->markdownURLAbsoluta($servicio->field_detalle->value()),
      );

    }

    $this->servicios_relacionados = $servicios == array() ? null : $servicios;
  }

  function get_requisitos($node_wrapper){

    $requisitos = array();

    if(!empty($node_wrapper->field_requisitos_collection->value())){

      foreach($node_wrapper->field_requisitos_collection->field_requisito->getIterator() as $key => $requisito){

        $item = $requisito->value();

        $requisitos['items'][] = $this->markdownURLAbsoluta($item);

      }

      $requisitos['observaciones'] = $this->markdownURLAbsoluta($node_wrapper->field_requisitos_collection->field_observaciones->value());

    }

    $this->requisitos = !empty($requisitos) ? $requisitos : null;

  }

  function markdownURLAbsoluta($item){


      if(isset($item['value'])){
        $patron = '/(\[.*\]\()(\/.*\))/i';
        $sust = '$1'. $this->getHost() .'$2';
        $item['value'] = preg_replace($patron, $sust, $item['value']);
      }

      if(isset($item['safe_value'])){
        $patron = '/(<a href=\\")(\/.*)\">(.*)<\/a>/i';
        $sust = '$1'. $this->getHost() .'$2';
        $item['safe_value'] = preg_replace($patron, $sust, $item['safe_value']);
      }

      return $item;
  }

  public function getHost()
  {
    return $this->host;
  }


  public function setHost()
  {
    global $base_url;

    $this->host = $base_url;

  }



}
