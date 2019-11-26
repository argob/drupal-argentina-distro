<?php

class ResourceNoticia extends Resource{

  function __construct(){
    $this->entity_type = 'node';
    $this->type = 'noticia';
    $this->category = array(
      'field' => '',
      'column' => '',
      'operator' => '',
    );
  }

  function createTransferObject($node){
    return new NoticiaTransferObject($node);
  }
}
