<?php

class ListadoNodes extends Listado
{
    public function crearItems($tipo_contenido, $tipo_listado, $cantidad_links = 9, $args = array())
    {
        $type = $this->conf['order_by'] == 'fecha' ? 'created' : 'title';

        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node');
        $query->propertyCondition('status', NODE_PUBLISHED);

        if (!array_key_exists('order_by', $this->conf)){
            $this->conf['order_by'] = 'fecha';
          }

        if (!array_key_exists('order_type', $this->conf)){
          $this->conf['order_type'] = 'desc';
        }

        if($tipo_contenido != 'subasta'){
            $query->propertyOrderBy($type, $direction = $this->order_type);
        } elseif ($tipo_contenido == 'subasta' && $args['order_by'] == 'recientes') {
            //$query->propertyOrderBy('field_cuando_subasta', $direction = $this->order_type);
            $query->fieldOrderBy('field_cuando_subasta', 'value', $args['order_by']);
        }

        if($tipo_contenido == 'subasta'){
               if (isset($args['tipo_subasta'])) {
                    $UTCtimestamp = strtotime("now + 3 hours");

                    $ahora = date('Y-m-d\TH:i:s', $UTCtimestamp);
                    if ($args['tipo_subasta'] == 'vigente') {
                        $query->fieldCondition('field_cuando_subasta', 'value', $ahora, '>=');
                    } elseif ($args['tipo_subasta'] == 'finalizada') {
                        $query->fieldCondition('field_cuando_subasta', 'value', $ahora, '<');
                    }


                } else {
                         $UTCtimestamp = strtotime("now + 3 hours");
                         $ahora = date('Y-m-d\TH:i:s', $UTCtimestamp);
                         $query->fieldCondition('field_cuando_subasta','value', $ahora, '>=');
                         $query->fieldOrderBy('field_cuando_subasta', 'value', $args['order_by']);

                }
        }


        if (isset($args['ubicacion']) && $args['ubicacion'] != 'all') {
            $query->fieldCondition('field_domicilio_provincia_prop', 'value', $args['ubicacion'], '=');
        }

        if (isset($args['estado']) && $args['estado'] != 'all' && $args['estado']!='') {
            $query->fieldCondition('field_estados_subasta', 'value', $args['estado'], '=');
        }

        if (isset($args['tipo_inmueble']) && $args['tipo_inmueble'] != 'all') {
            $query->fieldCondition('field_tipo_inmueble', 'value', $args['tipo_inmueble'], '=');
        }

         /* inicio filtro para subastas */
        if (isset($args['order_by']) && $args['order_by'] != 'recientes') {

            $query->fieldOrderBy('field_precio_subasta', 'value', $args['order_by']);
        }

        /* FIN filtro para subastas TODO: mover a una clase externa, a una funcion o dentro del modulo de subastas */

        // Si se especifica un tipo de contenido a listar
        if ($tipo_contenido != 'all') {
            $query->propertyCondition('type', $tipo_contenido);
        }

        if ($tipo_contenido == 'noticia' && isset($this->conf['tipo_noticia']['entity_id'])) {
            $query->fieldCondition('field_categoria', 'target_id', $this->conf['tipo_noticia']['entity_id'], '=');
        }

        if ($tipo_contenido == 'servicio' && isset($this->conf['tipo_tramite']['entity_id'])) {
            $query->fieldCondition('field_servicio_categoria', 'target_id', $this->conf['tipo_tramite']['entity_id'], '=');
        }

        $groups = array();
        if(isset($this->conf['all_ga'])){

          foreach ($this->conf['all_ga'] as $key) {
            $groups[$key['entity_id']] = $key['entity_id'];
          }
        }

        if($tipo_listado == 'group_audience') {
            $groups = array_merge($this->conf['ga'],$this->conf['all_ga']);
            $query->fieldCondition('og_group_ref', 'target_id', $groups, 'IN');

        }
        // Si el tipo de listado es 'relacionados' excluye el nodo actual
        if ($tipo_listado == 'relacionados' && (esNoticia() || esTramite())) {
            $node = node_load(arg(1));
            $gids = field_get_items('node', $node, 'og_group_ref', $langcode = null);
            $query->propertyCondition('nid', arg(1), '!=');

            if ($gids != array()) {
                foreach ($gids as $key => $gid) {
                    $query->fieldCondition('og_group_ref', 'target_id', $gid, '=');
                }
            }
        }


        // Si el tipo de listado es 'relacionados' y el nodo visualizado es un grupo lista contenido que sea contenido del grupo

        //obtengo el nodo por parámetro
        $alias = drupal_get_query_parameters();

        $nid = isset($alias['nodo']) ? $alias['nodo'] : arg(1);

        // Si el tipo de listado es 'relacionados' y el nodo visualizado es un grupo lista contenido que sea contenido del grupo
        if ($tipo_listado == 'relacionados' && og_is_group('node', $nid)) {
            $query->fieldCondition('og_group_ref', 'target_id', $nid, '=');
        }

        if ($args['paginar']) {
            $query->pager($cantidad_links, 0);
        } else {
            $query->range(0, $cantidad_links);
        }
        $results = $query->execute();

        $itemListado = "ItemListado";
        $claseListado = ucfirst($tipo_contenido);
        $itemListado.= $claseListado;

        if (!class_exists($itemListado)) {
            $itemListado = "ItemListado";
        }

        if (isset($results['node'])) {
            foreach ($results['node'] as $key => $result) {
                $node = node_load($result->nid);

                $this->agregarItem(new $itemListado($node));
            }
        }
    }
}
