<?php

#namespace Drupal\argentinagobar_servicios;

abstract class Resource{
  abstract function create_transfer_object($node, $fields);
  abstract function get_type();
  abstract function get_entity_type();

  function retrieve($nid){

    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', $this->get_entity_type())
    ->propertyCondition('type', $this->get_type())
    ->propertyCondition('status', 1)
    ->propertyCondition('nid', $nid)
    ->execute();

    if (!empty($entities['node'])) {

      $keys = array_keys($entities['node']);
      $node = node_load(array_shift($keys));

      return $this->create_transfer_object($node, array());

    } else {

      drupal_add_http_header('Status', '404 Not Found');

      return array(
        'status' => 404,
        "developerMessage" => "Resource no encontrado",
        "userMessage" => "No encontrado",
        "errorCode" => "404",
        #"moreInfo" => "http://www.ejemplo.gob.ar/developer/path/to/help/for/444444, http://drupal.org/node/444444",
      );
    }
  }

  function index($offset, $fields, $parameters, $limit, $options){

    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', $this->get_entity_type())
    ->propertyCondition('type', $this->get_type())
    ->propertyCondition('status', 1)
    ->count();

    if($limit > 0) {
      $query->range($offset, $limit);
    }

    $count = $query->execute();

    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', $this->get_entity_type());

    $query->propertyCondition('type', $this->get_type());

    $query->propertyCondition('status', 1);

    $query->propertyOrderBy('created', $direction = 'ASC');

    if($limit > 0) {
      $query->range($offset, $limit);
    }

    $results = $query->execute();

    if (!empty($results['node'])) {

      $nodes = $results['node'];

      $response['metadata']['resultset'] = array(
        'count' => $count,
        'offset' => $offset,
        'limit' => $limit
      );

      $fields = empty($fields) ? $fields : explode(',', $fields);

      foreach (array_keys($nodes) as $key => $nid) {
        $response['results'][] = $this->create_transfer_object($nid, $fields);
      }

      return $response;

    } else {

      drupal_add_http_header('Status', '404 Not Found');

      return array(
        'status' => 404,
        "developerMessage" => "Resource no encontrado",
        "userMessage" => "No encontrado",
        "errorCode" => "404",
        #"moreInfo" => "http://www.ejemplo.gob.ar/developer/path/to/help/for/444444, http://drupal.org/node/444444",
      );
    }
  }

  function filter($entitites, $field, $column, $value, $operator){

    foreach ($filters as $filter) {

      $entities->fieldCondition($field, $column, $value, $operator);
    }
  }


}
