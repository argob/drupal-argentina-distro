<?php

class FormatoListadoPersonaBuscada extends FormatoListado
{
  function __construct($conf){
    $this->conf = $conf;
    $this->theme = 'argentinagobar_bloques_listado_persona_buscada';
  }

    static public function estaDisponible($tipoContenido)
    {
        return in_array(
            $tipoContenido,
            [
                'persona_buscada',
            ]
        );
    }

  function themeItems($items){
    $themedItems = array();
    if(!empty($items)){
      foreach ($items as $key => $item) {
        $themedItems[] = l(
          theme(
            $this->theme . "_horizontal_item",
            array(
              'nombre' => $item->getNombre() . " " . $item->getTitulo(),
              'imagen_path' => isset($this->conf['mostrar_imagen']) && $this->conf['mostrar_imagen'] ? $item->getImagen() : NULL,
            )
          ),
          $item->getUrl(),
          array(
            'html' => TRUE,
            'attributes' => array(
              'class' => array('panel panel-default panel-icon panel-secondary')
            ),
          )
        );
      }
    }
    return $themedItems;
  }
}
