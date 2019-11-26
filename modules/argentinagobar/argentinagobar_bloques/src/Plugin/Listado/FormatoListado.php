<?php

abstract class FormatoListado
{
    abstract protected function themeItems($items);
    protected $theme;
    public $conf;
  
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
        ]
    );
    }

    public function crearListado($items, $filtro = array())
    {
       
        $listado = null;
        
        if (count($items)) {
            
            $listado = theme(
                $this->theme . '_horizontal',
                array(
                    'titulo' => isset($this->conf["titulo"]) && !empty($this->conf["titulo"]) ? $this->conf["titulo"] : null,
                    'links' => $this->themeItems($items),
                    'boton' => $this->conf['todos_los_items'] ? crearBoton($this->conf) : null,
                    'paginador' => isset($this->conf['paginador']) && $this->conf['paginador'],
                    'destacar_primer_fila' => isset($this->conf['destacar_primer_fila']) ? $this->conf['destacar_primer_fila'] : false,
                    'filtro' => $filtro,
                )
            );
            
        }

        return $listado;
    }
}
