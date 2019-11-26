<?php

  class ResourceTramite extends Resource{

    function __construct(){
      $this->category = array(
        'field' => '',
        'column' => '',
        'operator' => '',
      );
    }

    function default_fields(){
      return array(
        'id',
        'alias',
        'title',
        'summary',
        'body',
        'pasos',
        'requisitos',
        'oficina',
        'acciones',
        'costo',
        'categorias',
        'download',
        'dirigido',
        'modalidad',
        'language',
        'grupo',
        'servicios_relacionados',
        'palabras_clave',
        'url',
        'vigencia',
        'duracion',
        'informacion_adicional',
        );

      //listado debería devolver:
      //return array('id', 'alias', 'title', 'body');
    }

    function create_transfer_object($nid, $fields){

      $fields = empty($fields) ? $this->default_fields() : $fields;

      $tramiteTO = new TramiteTransferObject($nid);

      foreach ($fields as $field){

        try{

          $tramiteTO->get_field($field);

        } catch (EntityMetadataWrapperException $e){
          watchdog('warning', $e);
        }

      }

      return $tramiteTO;
    }

    function get_type(){
      return 'tramite';
    }

    function get_entity_type(){
      return 'node';
    }
  }
