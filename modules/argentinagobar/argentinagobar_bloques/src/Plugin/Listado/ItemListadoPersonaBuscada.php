<?php

class ItemListadoPersonaBuscada extends ItemListado{

  function getNombre()
  {

    $nombre = $this->getEntity()->field_nombre->value();
    return  $nombre;
  }

  function getImagen()
  {
    $imagen = $this->getEntity()->field_image->value();
    return $imagen ? image_style_url('listado', $imagen["uri"]) : NULL;
  }


}
