<?php

abstract class TransferObject{

  function __construct($node){
    $this->title = $node->title;
    $this->id = $node->nid;
    $this->language = $node->language;
    $this->body = field_get_items('node', $node, 'body', $langcode = NULL)[0]['value'];
    $this->created = isset($nodo->node_created) ? date('d'."-".'m'."-".'Y',$nodo->node_created): NULL;
    $this->alias = url('node/' . $node->nid, array('absolute' => TRUE));
  }

  function setFields($fields){
    $field_list = array();
    foreach (explode(',', $fields) as $key => $field) {
      $field_list[$field] = $this->getField($field);
    }
    return $field_list;
  }

  function getField($field){
    return $this->$field;
  }
  
  function get_field($field){
    $method = "get_" . $field;
    $this->$method($this->node_wrapper);
  }
}
