<?php

#namespace Drupal\argentinagobar_servicios;

class NoticiaTransferObject extends TransferObject{

  function __construct($node){
    $this->title = $node->title;
    $this->id = $node->nid;
    $this->language = $node->language;
    $this->body = field_get_items('node', $node, 'body', $langcode = NULL)[0]['value'];
    $this->created = isset($nodo->node_created) ? date('d'."-".'m'."-".'Y',$nodo->node_created): NULL;
    $this->alias = url('node/' . $node->nid, array('absolute' => TRUE));
  }
}
