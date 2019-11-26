<?php

class ListadoCustom extends Listado
{
    public function crearItems($tipo_contenido, $tipo_listado, $cantidad_links = 9, $args = array())
    {
        if (count($this->conf['contenido_custom']) > 0) {

            $query = new EntityFieldQuery();

            $query->entityCondition('entity_type', 'node');

            $query->propertyCondition('nid', $this->conf['contenido_custom'], 'IN');

            if ($args['paginar']) {

                $query->pager($cantidad_links, 0);

            } else {

                $query->range(0, $cantidad_links);

            }

            $results = $query->execute();

            if (isset($results['node'])) {

                foreach ($results['node'] as $key => $result) {
                    $node = node_load($result->nid);
                    $this->agregarItem(new ItemListado($node));
                }

            }
        }

        return $this->getItems();
    }
}
