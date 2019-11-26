<?php

abstract class Listado
{
    protected $formatoListado;

    public $conf;
    public $form;
    public $items;
    public $tipo_contenido;
    public $tipo_listado;

    abstract protected function crearItems($tipo_contenido, $tipo_listado, $cantidad_links = 9, $args = array());

    public function __construct($formatoListado, $conf)
    {
        $parts = explode('/', $_SERVER['REQUEST_URI']); 
    
        for($i=0; $i < sizeof($parts); $i++){
            if($parts[$i] != 'argentina.gob.ar' && $parts[$i] != 'noticias'){
               $last_node .= $parts[$i].'/';
            }
        }
        
        $last_node = implode("/", array_filter(explode("/", $last_node))); 
        
        $last_conf = end($parts);
        
        if($last_conf == 'noticias'){
            $argN = drupal_get_normal_path($last_node);
            $_GET['q'] = $argN.'/'.$last_conf;
        }
        
        $this->conf = $conf;
        $this->formatoListado = $formatoListado;
        $this->tipo_contenido = $conf['tipos_de_contenido'];
        $this->order_by = $conf['order_by'];
        $this->order_type = strtoupper($conf['order_type']);
        $this->tipo_listado = $conf['tipo_de_listado'];
        $this->filtro  = isset($conf['filtro']) ? $conf['filtro'] : null;
        $this->ga = isset($conf['ga']) ? $conf['ga'] : null;
        $this->all_ga = isset($conf['all_ga']) ? $conf['all_ga'] : null ;
        $this->tipo_listado = $conf['tipo_de_listado'];
        $this->filtro = isset($conf['filtro']) ? $conf['filtro'] : null;
    }


    public static function formatos()
    {
        $formatos['FormatoListadoTarjeta'] = t('Tarjeta');
        $formatos['FormatoListadoLista'] = t('Lista simple');
        $formatos['FormatoListadoPersonaBuscada'] = t('Persona Buscada');

        foreach (module_invoke_all('listado_agregar_formato') as $key => $formato_label) {
            if (class_exists($key) && !array_key_exists($key, $formatos)) {
                $formatos[$key] = $formato_label;
            }
        }

        return $formatos;
    }

    public function getItems()
    {
        return $this->items;
    }

    public function agregarItem($item)
    {
        $this->items[] = $item;
    }

    public function render()
    {
        return $this->formatoListado->crearListado($this->getItems(), $this->filtro());
    }

    public function hayItems()
    {
        return !empty($this->items) && sizeof($this->items) > 0;
    }

    public function filtro()
    {
        return $this->filtro;
    }

    public function getCantidadItems()
    {
        return $this->conf['cantidad_links'];
    }
}
