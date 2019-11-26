<?php

class ListadoNodesPersonaBuscada extends ListadoNodes
{
    public function crearItems($tipo_contenido, $tipo_listado, $cantidad_links = 9, $args = array())
    {
        $nid = arg(1);

      $type = $this->conf['order_by'] == 'fecha' ? 'created' : 'title';

        $query = new EntityFieldQuery();

        $query->entityCondition('entity_type', 'node')

            ->fieldCondition(OG_AUDIENCE_FIELD, 'target_id', $nid)

            ->propertyCondition('status', NODE_PUBLISHED)

            ->propertyCondition('type', 'persona_buscada')

            ->propertyOrderBy($type, $direction = $this->order_type);


        if ($args['paginar']) {

            $query->pager($cantidad_links, 0);

        } else {

            $query->range(0, $cantidad_links);

        }


        $results = $query->execute();

        $result = $tipo_contenido;

        $result = str_replace("_", " ", $result);

        $result = ucwords($result);

        $result = str_replace(" ", "", $result);



        $itemListado = "ItemListado";

        $claseListado = ucfirst($result);

        $itemListado.= $claseListado;


        foreach ($results['node'] as $key => $result)
        {
            $node = node_load($result->nid);

            $this->agregarItem(new $itemListado($node));

        }
    }
}
