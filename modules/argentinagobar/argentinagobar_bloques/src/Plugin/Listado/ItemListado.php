<?php

class ItemListado
{
    protected $entity;
    
    public function __construct($node)
    {
        $this->setEntity($node);
    }
    
    protected function setEntity($id)
    {
        $this->entity = entity_metadata_wrapper('node', $id);
    }
    
    protected function getEntity()
    {
        return $this->entity;
    }
    
    public function getAliasUrl()
    {
        try{
            
            $url = $this->getEntity()->url->value();
            
        } catch (Exception $e) {
            
            $url = null;
            
        }
        
        return $url;
    }
    
    public function getUrl()
    {
        try {
            
            $data = 'node/' . $this->getEntity()->getIdentifier();
            
        } catch (Exception $e) {
            
            $data = null;
            
        }
        
        return $data;
    }
    
    public function getTitulo()
    {
        try{
            
            $titulo = $this->getEntity()->label();
            
        } catch (Exception $e) {
            
            $titulo = null;
            
        }
        
        return $titulo;
    }
    
    public function getResumen()
    {
        try{
            
            $resumen = $this->getEntity()->body->summary->value();
            
        } catch (Exception $e) {
            
            $resumen = null;
            
        }
        
        return $resumen;
    }
    
    public function getImagen()
    {
        try{
            
            
            $file = $this->getEntity()->field_featured_image->value();
            
            $image = image_style_url('listado', $file["uri"]);
            
            
        } catch (Exception $e) {
            
            $image = null;
            
        }
        
        return $image;
    }
    
    public function getFecha()
    {
        try{
            
            $fecha = $this->getEntity()->created->value();
            
        } catch (Exception $e) {
            
            $fecha = null;
            
        }
        
        return $fecha;
    }
}
