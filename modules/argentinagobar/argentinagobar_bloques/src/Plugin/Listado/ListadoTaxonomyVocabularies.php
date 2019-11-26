<?php

class ListadoTaxonomyVocabularies extends Listado
{
    public function crearItems($tipo_contenido, $tipo_listado, $cantidad_links = 9, $args = array())
    {
        $query = new EntityFieldQuery();
    
        $query->entityCondition('entity_type', 'taxonomy_term');
      
        $query->propertyCondition('vid', $this->conf['taxonomy_vocabularies']);

        if ($args['paginar']) {
            
            $query->pager($cantidad_links, 0);
            
        } else {
            
            $query->range(0, $cantidad_links);
            
        }
      
        $results = $query->execute();
      
        if (isset($results['taxonomy_term'])) {
            
            foreach ($results['taxonomy_term'] as $key => $result) {
                $term = taxonomy_term_load($result->tid);
                $this->agregarItem(new ItemListadoTaxonomy('taxonomy/term/' . $term->tid, $term->name, $term->description, $imagen = null, $fecha = null));
            }
            
        }

        return $this->getItems();
    }
}
