<?php

class FormatoListadoLista extends FormatoListado
{
    public function __construct($conf)
    {
        $this->conf = $conf;
        $this->theme = 'argentinagobar_bloques_listado_lista_simple';
    }
    
    public static function estaDisponible($tipoContenido)
    {
        return in_array(
            $tipoContenido,
            [
                'noticia',
                'area',
                'aplicacion',
                'book',
                'tramite',
                'page',
                'webform',
                'all',
                'argentinagobar_migtram',
            ]
        );
    }

    public function themeItems($items)
    {
        $themedItems = array();
        if (!empty($items)) {
            foreach ($items as $key => $item) {
                $themedItems[] = l(
                    theme(
                        $this->theme . '_horizontal_item',
                        array(
                            'titulo' => $item->getTitulo(),
                            'texto' => isset($this->conf['mostrar_resumen']) && $this->conf['mostrar_resumen'] ? views_trim_text(
                                array(
                                    'max_length' => 200,
                                    'ellipsis' => true,
                                    'word_boundary' => true,
                                    'html' => true,
                                ),
                                $item->getResumen()
                            ) : null,
                            'imagen_path' => $item->getImagen(),
                            'fecha' => isset($this->conf['mostrar_fecha']) && $this->conf['mostrar_fecha'] ? format_date($item->getFecha(), 'custom', 'd \d\e F \d\e o') : null
                        )
                    ),
                    $item->getUrl(),
                    array('html' => true)
                );
            }
        }
        return $themedItems;
    }
}
