<?php
$plugin = array(
  'single' => true,
  'title' => t('Listado'),
  'description' => t('Crea un listado de contenido configurable'),
  'category' => t('Argentina.gob.ar'),
  'render callback' => 'argentinagobar_bloques_listado_render',
  'edit form' => 'argentinagobar_bloques_listado_edit_form',
  'admin info' => 'argentinagobar_bloques_listado_admin_info',
  'defaults' => array(
    'destacar_primer_fila' => false,
    'mostrar_fecha' => false,
    'mostrar_resumen' => false,
    'mostrar_imagen' => false,
    'cantidad_links' => 8,
    'tipo_de_listado' => 'recientes',
    'contenido_custom' => true,
    'ga' => '',
    'all_ga' => '',
    'entity_types' => 'ListadoNodes',
    'taxonomy_vocabularies' => '',
    'tipos_de_contenido' => 'all',
    'formato_de_listado' => 'argentinagobar_bloques_listado_tarjeta_con_imagen',
    'titulo' => t('Listado'),
    'icono' => '',
    'tipo_noticia' => '',
    'tipo_tramite' => '',
    'orientacion_de_listado' => 'horizontal',
    'order_by' => 'fecha',
    'order_type' => 'desc',
    'todos_los_items' => false,
    'paginador' => false,
    'filtro' => false,
  )
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_listado_admin_info($subtype, $conf, $contexts)
{
    $array_custom = array();
    if (isset($conf['contenido_custom'])) {
        $array_custom = array_keys($conf['contenido_custom']);

        foreach ($array_custom as $key => $item) {
            $array_custom[$key] = $conf['contenido_custom'][$item]['entity_label'];
        }
    }

    $titulo = empty($conf['titulo']) ? t("Sin título") : $conf['titulo'];
    $campos['tipo_de_listado'] = $conf['tipo_de_listado'];
    $campos['el_contenido_custom_es']  = $array_custom;

    $tipo_de_contenido_custom = "";
    foreach ($campos['el_contenido_custom_es'] as $key => $item) {
        $tipo_de_contenido_custom = isset($array_custom) ? $tipo_de_contenido_custom."<br>".$item : $tipo_de_contenido_custom.$item;
        $campos['el_contenido_custom_es'] = $tipo_de_contenido_custom;
    }



    $campos['entidad'] = isset($conf['entity_types']) ? ucfirst(str_replace("_", " ", $conf['entity_types'])) : "";
    $campos['tipo_de_contenido']  = isset($conf['tipos_de_contenido']) ? $conf['tipos_de_contenido'] : "";
    $campos['categoria_de_noticias'] =  empty($conf['tipo_noticia']['entity_label']) ? t("Sin Categoría de noticia") : $conf['tipo_noticia']['entity_label'];
    $campos['formato_de_listado'] = ucfirst(str_replace("_", " ", str_replace("argentinagobar_bloques_listado_", "", $conf['formato_de_listado'])));
    $campos['orientacion']  = isset($conf['orientacion_de_listado']) ? $conf['orientacion_de_listado'] : "";
    $campos['cantidad']     = isset($conf['cantidad_links']) ? $conf['cantidad_links'] : "";
    $campos['destacar_primer_fila']    = isset($conf['destacar_primer_fila']) ? traducir_true_false($conf['destacar_primer_fila']) : "";
    $campos['mostrar_la_fecha']        = isset($conf['mostrar_fecha']) ? traducir_true_false($conf['mostrar_fecha']) : "";
    $campos['mostrar_el_resumen']      = isset($conf['mostrar_resumen']) ? traducir_true_false($conf['mostrar_resumen']) : "";
    $campos['mostrar_todos_los_items'] = isset($conf['todos_los_items']) ? traducir_true_false($conf['todos_los_items']) : "";
    $campos['mostrar_paginador']       = isset($conf['paginador']) ? traducir_true_false($conf['paginador']) : "";

    if (!empty($conf)) {
        $block = new stdClass;
        $block->title = $conf['override_title'] ? $conf['override_title_text'] : $titulo;
        $block->content = theme('argentinagobar_bloques_admin_info', array('campos' => $campos));
        return $block;
    }
}

/**
* 'Edit form' callback for the content type.   tipo_de_listado
*/

function argentinagobar_bloques_listado_edit_form($form, &$form_state)
{
    ctools_form_include($form_state, 'content');

    form_load_include($form_state, 'inc', 'argentinagobar_bloques','plugins/content_types/listado');

    $form['contenedor'] = array(
        '#type' => 'container',
        '#attributes' => array(
            'id' => 'ctools_edit_form_container'
        ),
    );

    $tiposDeContenido['all'] = t('Todos');
    foreach (node_type_get_types() as $item) {
        $tiposDeContenido[$item->type] = $item->name;
    }

    $form['#id'] = 'ar_bloques_edit_form';

    $form['contenedor']['configuracion'] = array(
        '#type' => 'fieldset',
        '#title' => t('Configuración del listado'),
        '#weight' => 1,
        '#collapsible' => true,
        '#collapsed' => false,
    );

    $form['contenedor']['configuracion']['titulo'] = array(
        '#title' => t('Título'),
        '#type' => 'textfield',
        '#default_value' => $form_state['conf']['titulo'],
        '#required' => false,
    );

    $form['contenedor']['configuracion']['entity_types'] = array(
        '#title' => t('¿Qué listar?'),
        '#type' => 'radios',
        '#default_value' => $form_state['conf']['entity_types'],
        '#required' => true,
        '#options' => array(
            'ListadoNodes' => t('Listar nodos (noticias, áreas, páginas, servicios)'),
            'ListadoTaxonomyVocabularies' => t('Listar vocabularios de taxonomías (categorías, tags)'),
            'ListadoCustom' => t('Elegir cada elemento a listar personalmente'),
        ),
    );

    $string_concontenidos = "";

    if (isset($form_state['conf']['contenido_custom']) && !empty($form_state['conf']['contenido_custom'])) {

        foreach ($form_state['conf']['contenido_custom'] as $n_contenido => $a_cont) {

            $idContenido    = $form_state['conf']['contenido_custom'][$n_contenido]['entity_id'];
            $labelContenido = $form_state['conf']['contenido_custom'][$n_contenido]['entity_label'];

            $contCustom = $labelContenido." (".$idContenido.")";
            $string_concontenidos = $string_concontenidos.$contCustom.",";
        }

    }

    $form['contenedor']['configuracion']['contenido_custom'] = array(
        '#type' => 'entityreference',
        '#title' => t('Elegir el contenido de argentina.gob.ar a listar'),
        '#description' => t('Separar cada item a listar con comas'),
        '#default_value' => $string_concontenidos,
        '#required' => false,
        '#states' => array(
            'visible' => array(
                ':input[name="entity_types"]' => array('value' => 'ListadoCustom'),
            ),
        ),
        '#era_entity_type' => 'node',
        '#era_bundles' => array(),
        '#era_cardinality' => ERA_CARDINALITY_UNLIMITED,
    );

    $form['contenedor']['configuracion']['tipos_de_contenido'] = array(
        '#title' => t('Tipo de contenido'),
        '#type' => 'select',
        '#default_value' => $form_state['conf']['tipos_de_contenido'],
        '#required' => false,
        '#options' => $tiposDeContenido,
        '#description' => t('Tipo de contenido a listar'),
        '#states' => array(
            'disabled' => array(
                ':input[name="tipo_de_listado"]' => array('value' => 'ListadoCustom'),
            ),
            'visible' => array(
                ':input[name="entity_types"]' => array('value' => 'ListadoNodes'),
            ),
        ),
        '#ajax' => array(
            'callback' => 'tipoContenidoElegido',
            'event' => 'change',
            'wrapper' => 'ctools_edit_form_container',
            'method' => 'replace'
        ),
    );

    if (sizeof(obtenerTaxonomyVocabularies()) > 0) {

        $form['contenedor']['configuracion']['taxonomy_vocabularies'] = array(
            '#title' => t('Taxonomías'),
            '#type' => 'select',
            '#default_value' => $form_state['conf']['taxonomy_vocabularies'],
            '#required' => false,
            '#options' => obtenerTaxonomyVocabularies(),
            '#description' => t('Vocabulario a listar'),
            '#states' => array(
                'disabled' => array(
                    ':input[name="tipo_de_listado"]' => array('value' => 'ListadoCustom'),
                ),
                'visible' => array(
                    ':input[name="entity_types"]' => array('value' => 'ListadoTaxonomyVocabularies'),
                ),
            ),
        );

    }

    $form['contenedor']['configuracion']['tipo_tramite'] = array(
        '#type' => 'entityreference',
        '#title' => t('Filtrar por tipo de trámite.'),
        '#description' => t('Dejar vacío para listar todos los trámites'),
        '#default_value' => $form_state['conf']['tipo_tramite'],
        '#required' => false,
        '#states' => array(
            'visible' => array(
                array(
                    array(':input[name="tipos_de_contenido"]' => array('value' => 'tramite')),
                    'OR',
                    array(':input[name="tipos_de_contenido"]' => array('value' => 'argentinagobar_migtram')),
                ),
                ':input[name="entity_types"]' => array('value' => 'ListadoNodes')
            ),
        ),
        '#era_entity_type' => 'taxonomy_term',  // Mandatory.
        '#era_bundles' => array('tramites'), // Optional (Any bundle by default).
        '#era_cardinality' => 2,       // Optional (1 By default).
    );

    $form['contenedor']['configuracion']['tipo_noticia'] = array(
        '#type' => 'entityreference',
        '#title' => t('Filtrar por categoría de Noticias'),
        '#default_value' => $form_state['conf']['tipo_noticia'],
        '#description' => t('Dejar vacío para listar todos los noticias'),
        '#required' => false,
        '#states' => array(
            'visible' => array(
                ':input[name="tipos_de_contenido"]' => array('value' => 'noticia'),
                ':input[name="entity_types"]' => array('value' => 'ListadoNodes')
            ),
        ),
        '#era_entity_type' => 'taxonomy_term',  // Mandatory.
        '#era_bundles' => array('noticias'), // Optional (Any bundle by default).
        '#era_cardinality' => 1,       // Optional (1 By default).
    );

    $form['contenedor']['configuracion']['tipo_de_listado'] = array(
        '#type' => 'select',
        '#title' => t('¿Cómo listar el contenido?'),
        '#options' => array(
            'recientes' => t('Últimos cargados'),
            'relacionados' => t('Relacionados al contenido actual'),
            'group_audience' => t('Seleccionar group audience'),
        ),
        '#default_value' => $form_state['conf']['tipo_de_listado'],
        '#required' => true,
        '#description' => t('Cada tipo de listado tiene un comportamiento diferente'),
    );

    $form['contenedor']['configuracion']['ga'] = array(
        '#type' => 'select',
        '#title'=> t('Tus Grupos'),
        '#id' => 'ga',
        '#default_value' => $form_state['conf']['ga'],
        '#options' => getGroupsAudience(),
        '#multiple' => 'true',
        '#states' => array(
            'visible' => array(
                array(
                    array(':input[name="tipo_de_listado"]' => array('value' => 'group_audience')),
                ),
            ),
        ),
    );

    global $user;
    $u = user_load($user->uid);

    if (in_array('administrator', $u->roles) || in_array('administrador drupal', $u->roles)) {

        $form['contenedor']['configuracion']['all_ga'] = array(
            '#type' => 'entityreference',
            '#title' => t('Groups Audience'),
            '#default_value' => defaultValueReference($form_state['conf']['all_ga']),
            '#description' => t('Dejar vacío para listar todos los noticias'),
            '#era_entity_type' => 'node',  // Mandatory.
            '#era_bundles' => array('area'), // Optional (Any bundle by default).
            '#era_cardinality' => 10,       // Optional (1 By default).
            '#states' => array(
                'visible' => array(
                    array(
                        array(':input[name="tipo_de_listado"]' => array('value' => 'group_audience')),
                    ),
                ),
            ),
        );
    }

    argentinagobar_bloques_listado_opciones_de_visualizacion($form, $form_state);

    return $form;
}

function tipoContenidoElegido($form, &$form_state)
{
    return $form['contenedor'];
}

function argentinagobar_bloques_listado_opciones_de_visualizacion(&$form, &$form_state)
{
    $form['contenedor']['opciones_de_visualizacion'] = array(
        '#type' => 'fieldset',
        '#title' => t('Opciones de visualización'),
        '#weight' => 5,
        '#collapsible' => true,
        '#collapsed' => false,
        '#id' => 'opciones_de_visualizacion'
    );

    $tipoContenidoElegido = isset($form_state['values']) ? $form_state['values']['tipos_de_contenido'] : $form_state['conf']['tipos_de_contenido'];

    $form['contenedor']['opciones_de_visualizacion']['formato_de_listado'] = array(
        '#type' => 'select',
        '#title' => t('Formato de listado'),
        '#options' => argentinagobar_bloques_listado_obtener_formatos($tipoContenidoElegido),
        '#default_value' => $form_state['conf']['formato_de_listado'],
        '#description' => t('Cada tipo de listado tiene un comportamiento diferente'),
    );

    $form['contenedor']['opciones_de_visualizacion']['orientacion_de_listado'] = array(
        '#title' => t('Orientación'),
        '#type' => 'radios',
        '#default_value' => $form_state['conf']['orientacion_de_listado'],
        '#required' => true,
        '#options' => array(
            'vertical' => t("Vertical"),
            'horizontal' => t("Horizontal")
        ),
    );

    $form['contenedor']['opciones_de_visualizacion']['destacar_primer_fila'] = array(
        '#type' => 'checkbox',
        '#title' => t('Destacar primer fila'),
        '#default_value' => $form_state['conf']['destacar_primer_fila'],
        '#description' => t("Los items de la primer fila se verán más grandes"),
        '#states' => array(
            'visible' => array(
                array(
                    array(':input[name="formato_de_listado"]' => array('value' => 'FormatoListadoTarjeta')),
                ),
            ),
        ),
    );

    $form['contenedor']['opciones_de_visualizacion']['mostrar_imagen'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar imagen'),
        '#default_value' => $form_state['conf']['mostrar_imagen'],
        '#description' => t("Si se tilda el listado mostrará la imagen destacada de cada contenido"),
    );

    $form['contenedor']['opciones_de_visualizacion']['mostrar_fecha'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar fecha'),
        '#default_value' => $form_state['conf']['mostrar_fecha'],
        '#description' => t("Si se tilda el listado mostrará la fecha de cada contenido"),
        '#states' => array(
            'visible' => array(
                array(
                    array(':input[name="formato_de_listado"]' => array('value' => 'FormatoListadoTarjeta')),
                ),
            ),
        ),
    );

    $form['contenedor']['opciones_de_visualizacion']['mostrar_resumen'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar resumen'),
        '#default_value' => $form_state['conf']['mostrar_resumen'],
        '#description' => t("Si se tilda el listado mostrará un resumen cada contenido"),
    );

    $form['contenedor']['opciones_de_visualizacion']['todos_los_items'] = array(
        '#type' => 'checkbox',
        '#title' => t('Incluír opción "Todos los items"'),
        '#default_value' => $form_state['conf']['todos_los_items'],
        '#description' => t('Si está tildado se mostrará un link a todos los items del tipo de contenido seleccionado'),
    );

    $form['contenedor']['opciones_de_visualizacion']['paginador'] = array(
        '#type' => 'checkbox',
        '#title' => t('Mostrar paginador'),
        '#default_value' => $form_state['conf']['paginador'],
        '#description' => t('Si está tildado y el número de resultados es mayor a la cantidad de items a mostrar por página, se mostrará un paginador'),
    );

    $form['contenedor']['opciones_de_visualizacion']['cantidad_links'] = array(
        '#type' => 'textfield',
        '#title' => t('Cantidad de items'),
        '#default_value' => $form_state['conf']['cantidad_links'],
        '#element_validate' => array('element_validate_integer_positive'),
        '#description' => t('Cantidad de items por página'),
    );

    $form['contenedor']['opciones_de_visualizacion']['orden'] = array(
        '#type' => 'item',
        '#title' => t('Orden'),
        '#description' => t('Seleccionar si ordenar el listado por Fecha de creacion o por Titulo'),

    );

    $form['contenedor']['opciones_de_visualizacion']['order_by'] = array(
        '#type' => 'radios',
        '#description' => t('Seleccionar si ordenar de forma Ascendente o Descendente'),
        '#default_value' => is_null($form_state['conf']['order_by']) ? 'fecha' : $form_state['conf']['order_by'] ,
        '#options' => array(
            'fecha' => 'Por fecha de creación',
            'title' => 'Por título',
        ),
    );


    $form['contenedor']['opciones_de_visualizacion']['order_type'] = array(
        '#type' => 'radios',
        '#default_value' =>is_null($form_state['conf']['order_type']) ? 'desc' : $form_state['conf']['order_type'],
        '#options' => array(
            'asc' => 'Ascendente',
            'desc' => 'Descendente',
        ),

    );

    // TODO: agregar desde jgm_subastas

    $form['contenedor']['opciones_de_visualizacion']['filtro'] = array(
        '#type' => 'checkbox',
        '#title' => t('Exponer filtro'),
        '#default_value' => $form_state['conf']['filtro'],
        '#description' => t(''),
        '#states' => array(
            'visible' => array(
                ':input[name="tipos_de_contenido"]' => array('value' => 'subasta')
            ),
        ),
    );

    // foreach (obtener_campos_filtros() as $key => $value) {
    // $form['configurar_filtro'][$key] = array(
    //   '#type' => 'fieldset',
    //   '#title' => t('Configurar filtro'),
    //   '#weight' => 10,
    //   '#collapsible' => TRUE,
    //   '#collapsed' => FALSE,
    //   '#states' => array(
    //     'visible' => array(
    //       ':input[name="filtro"]' => array('checked' => TRUE),
    //     ),
    //   ),
    // );
    // }

    // TODO: implementar hook que permita agregar configuracion

    return $form;
}

function argentinagobar_bloques_listado_obtener_formatos($tipoContenidoElegido)
{
    $formatos = [];

    foreach (Listado::formatos() as $formato => $label)
    {
        if ($formato::estaDisponible($tipoContenidoElegido)) {
            $formatos[$formato] = $label;
        }
    }

    return $formatos;
}

/**
* The submit form stores the data in $conf.
*/
function argentinagobar_bloques_listado_edit_form_submit($form, &$form_state)
{
    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}

function argentinagobar_bloques_listado_render($subtype, $conf, $panel_args, $context = null)
{

    // Adapto datos guardados en versiones anteriores del modulo
    $conf['formato_de_listado'] = $conf['formato_de_listado'] == 'argentinagobar_bloques_listado_tarjeta_simple' || $conf['formato_de_listado'] == 'argentinagobar_bloques_listado_tarjeta_con_imagen' ? 'FormatoListadoTarjeta' : $conf['formato_de_listado'];
    $conf['formato_de_listado'] = $conf['formato_de_listado'] == 'argentinagobar_bloques_listado_con_imagen' ? 'FormatoListadoTarjeta' : $conf['formato_de_listado'];
    $conf['formato_de_listado'] = $conf['formato_de_listado'] == 'argentinagobar_bloques_listado_lista_simple' ? 'FormatoListadoLista' : $conf['formato_de_listado'];
    $conf['entity_types'] = !isset($conf['entity_types']) || $conf['entity_types'] == 'nodes' ? 'ListadoNodes' : $conf['entity_types'];
    $conf['entity_types'] = $conf['entity_types'] == 'taxonomy_vocabularies' ? 'ListadoTaxonomyVocabularies' : $conf['entity_types'];
    $conf['entity_types'] = $conf['tipo_de_listado'] == 'custom' ? 'ListadoCustom' : $conf['entity_types'];
    $conf['mostrar_imagen'] = !isset($conf['mostrar_imagen']) ? true : $conf['mostrar_imagen'];
    $conf['paginador'] = isset($conf['paginador']) ? $conf['paginador'] : false;
    $conf['order_by'] = isset($conf['order_by']) ? $conf['order_by'] : 'fecha';
    $conf['order_type'] = isset($conf['order_type']) ? $conf['order_type'] : 'desc';

  if ($conf['tipos_de_contenido'] == 'noticia') {
        $conf['mostrar_fecha'] = !isset($conf['mostrar_fecha']) ? true : $conf['mostrar_fecha'];
    }

    $formato = new $conf['formato_de_listado']($conf);
    $tipo_contenido = $conf['tipos_de_contenido'] == "persona_buscada" ? formatPersonaBuscada($conf['tipos_de_contenido'])  : $conf['tipos_de_contenido'] ;

    if (class_exists($conf['entity_types'] . ucfirst($tipo_contenido))) {
        $class = $conf['entity_types'] . ucfirst($tipo_contenido);
        $listado = new $class($formato, $conf);
    } else {
        $class = $conf['entity_types'];
        $listado = new $conf['entity_types']($formato, $conf);
    }

    if (isset($conf['filtro']) && $conf['filtro']) {
        $filtro = new FiltroSubasta($listado);
        $listado->filtro = drupal_get_form('argentinagobar_bloques_filtro_form', $filtro);
    }

    $listado->crearItems(
        $conf['tipos_de_contenido'],
        $conf['tipo_de_listado'],
        $conf["cantidad_links"],
        [
            'paginar' => $conf['paginador']
        ]
    );
//	echo "<pre>";
//        print_r($values);
//        print_r($args);
//        echo "</pre>";
//	die();
    $block = new stdClass();
    $block->title = '';
    $block->content = $listado->render();

    return $block;
}

function formatPersonaBuscada($tipoDeContenido)
{
    $result = $tipoDeContenido;
    $result = str_replace("_", " ", $result);
    $result = ucwords($result);
    $result = str_replace(" ", "", $result);

    return $result;
}

function getGroupsAudience()
{
    global $user;
    $u = user_load($user->uid);
    $gids = $u->og_user_node['und'];

    $result = array();

    foreach ($gids as $gid => $value) {
        $node = node_load($value['target_id']);
         $results[$value['target_id']] = $node->title;

    }
    return $results;
}

function defaultValueReference($value)
{
    $string = array();
    foreach ($value as $key) {
        $string[] = $key['entity_label'] . ' ' . '('.$key['entity_id'].'),';
    }
    return $string;
}

// function getAllGroupAudience()
// {
//     $gids = og_get_all_group();
//
//     $result = db_select('node', 'n')
//       ->fields('n', ['nid', 'title'])
//       ->condition('nid', $gids,'IN')
//       ->condition('status', NODE_PUBLISHED)
//       ->orderBy('title')
//       ->execute();
//
//       while($record = $result->fetchAssoc()) {
//           $array[$record['nid']] = $record['title'];
//       }
//
//
//       return $array;
//
// }
