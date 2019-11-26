<?php
function argentinagobar_search_menu_alter(&$items) {

  $items['admin/config/search/settings']['type']=MENU_NORMAL_ITEM;

  $items['admin/config/search/settings/main'] = array(
    'title' => 'Settings',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );

  return $items;
}


/**
 * Implements hook_menu().
 */
function argentinagobar_search_menu() {

  $items['admin/config/search/settings/lookandfeel'] = array(
    'title' => 'Look and feel',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'weight' => 1,
    'access arguments' => array('administer users'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_lookandfeel_form'),
  );

  $items['admin/config/search/settings/facets'] = array(
    'title' => 'Facets',
    'description' => 'Elegir que facets mostrar en la búsqueda',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'access arguments' => array('administer users'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_form'),
    'weight' => 3,
  );

  $items['admin/config/search/settings/facets_config'] = array(
    'title' => 'Configurar facets',
    'description' => 'Elegir que facets mostrar en la búsqueda',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'access arguments' => array('administer users'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_facets_config_form'),
    'weight' => 5,
  );

   $items['admin/config/search/settings/regex'] = array(
    'title' => 'Expresiones Regulares',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'weight' => 2,
    'access arguments' => array('administer users'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_regex_form'),
  );

  $items['admin/config/search/settings/facets_order_1'] = array(
    'title' => 'Ordenar Facets',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_node_page_reorder', 1),
    'access callback' => '_argentinagobar_search_tab_access',
    'access arguments' => array(1),
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'weight' => 4,
    'type' => MENU_LOCAL_TASK,
    'file' => 'argentinagobar_search_reorder.inc',
  );

  $items['admin/config/search/settings/autocomplete'] = array(
    'title' => 'Autocomplete',
    'description' => 'Comportamiento del autocomplete',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_INLINE|MENU_LOCAL_TASK,
    'access arguments' => array('administer users'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('argentinagobar_search_autocomplete_form'),
    'weight' => 6,
  );

  return $items;
}

function argentinagobar_search_autocomplete_form($form, &$form_state){

  $query = db_select('apachesolr_environment', 'ae');
  $query->fields('ae', array('url', 'env_id'));
  $result = $query->execute();
  $records = $result->fetchAll();

  foreach ($records as $record) {
    $options[$record->url] = $record->env_id;
  }

  $form['environment'] = array(
    '#type' => 'select',
    '#title' => 'SolR Environment',
    '#description' => 'De que environment toma el dato para el autocompletar',
    '#options' => $options,
    //'#required' => TRUE,
    //'#default_value' => ,
  );

  $form['recrear_autocomplete'] = array(
    '#title' => 'Recrear autocomplete',
    '#options' => array(0 => 0, 1 => 1),
    '#description' => 'Reconstruye el archivo autocomplete',
    '#type' => 'checkbox',
    '#default_value' => null,
  );

  $form['#submit'][] = 'argentinagobar_search_autocomplete_form_submit';

  return system_settings_form($form);

  //return $form;
}

function argentinagobar_search_autocomplete_form_submit($form, &$form_state){

  variable_set('current_solr_environment', $form_state['values']['environment']);

  if($form_state['values']['recrear_autocomplete'] == 1 && function_exists('argentinagobar_search_cron')){
    argentinagobar_search_cron();
  }
}

/**
 * Custom access callback function for reorder tab.
 */
function _argentinagobar_search_tab_access($node) {
  return true;
}

/**
 * Returns HTML for a table.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: An array of form fields for reorder menu items.
 */
function argentinagobar_search_orderfacets($variables) {
  $form = $variables['form'];

  $rows = array();

  foreach (element_children($form['menu_items']) as $id) {

    $form['menu_items'][$id]['weight']['#attributes']['class'] = array(
      'menu-item-weight',
    );

    $rows[] = array(
      'data' => array(
        drupal_render($form['menu_items'][$id]['link_title']),
        drupal_render($form['menu_items'][$id]['weight']),
      ),
      'class' => array('draggable', 'menu-item-row-' . $id),
    );
  }

  $header = array(t('Menu Items'), t('Weight'));

  $table_id = 'menu-items-reorder-table';
  $output = '';
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'caption' => t('Please drag and drop the menus to reorder.'),
    'empty' => t('No menu items found!'),
    'attributes' => array('id' => $table_id),
      )
  );

  $output .= drupal_render_children($form);

  drupal_add_tabledrag($table_id, 'order', 'sibling', 'menu-item-weight');

  return $output;
}

/**
 * Implements hook_form().
 * Admin form to configurable migrar_nodos message
 */
function argentinagobar_search_form($form, &$form_state) {

  $query = db_select('apachesolr_environment', 'ae');
  $query->fields('ae', array('env_id'));
  $result = $query->execute();
  $records = $result->fetchAll();
  $links = '<h1>Agregar facets</h1>';
  foreach ($records as $record) {
    $links .= '(+) Facets para environment <a href="../../../../admin/config/search/apachesolr/settings/'.$record->env_id.'/facets?destination=admin/config/search/settings/facets">'.$record->env_id.'</a><br><br>';
  }

  $blocks = _block_rehash('argentinagobar');

  foreach ($blocks as $block) {
    if ($block['module'] == 'facetapi') {
      $info = explode(':', $block['info']);
      $info_text = END($info);
      $options[$block['delta']] = trim($info_text);
    }
  }

  $form['add_facets'] = array(
    '#type' => 'markup',
    '#markup' => $links
  );

  $form['facets'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('facets'),
    '#title' => 'Seleccionar los facets',
    '#description' => 'Seleccionar los facets que se mostrarán en la página de búsqueda búsqueda /buscar/argumentos',
  );

  foreach ($options as $key => $value) {

    $form[$key.'title'] = array(
      '#type' => 'textfield',
      '#title' => $value,
      '#default_value' => variable_get($key.'title'),
      '#description' => 'Titulo a mostrar para el facet dejar vacío para no mostrar',
      '#states' => array(
        'visible' => array(
          ':input[name="facets['.$key.']"]' => array('checked' => TRUE),
        ),
      ),
    );

  }

  $form['#submit'][] = 'argentinagobar_search_facets_submit';

  return system_settings_form($form);
}

function argentinagobar_search_facets_submit($form, &$form_state){
  $facets = array();
  $c = 0;
  foreach ($form_state['values']['facets'] as $key => $value) {
    if(!empty($value)){
      $facets[] = array(
        'id' => $key,
        'title' => $form_state['values'][$value.'title'],
        'weight' => $c,
      );
      $c++;
    }
  }
  variable_set('facetas', $facets);
}

function argentinagobar_search_facets_config_form($form, &$form_state) {

  $facet_config=variable_get('facet_config');
  
  $form['vermas_facets'] = array(
      '#type' => 'textfield',
      '#title' => 'Ver más',
      '#description' => 'Texto que se muestra cuando los facets son mas que el limite bajo',
      '#default_value' => $facet_config['vermas_facets'],
  );

  $form['vermenos_facets'] = array(
      '#type' => 'textfield',
      '#title' => 'Ver menos',
      '#description' => 'Texto que se muestra para replegar el anterior menú',
      '#default_value' => $facet_config['vermenos_facets'],
  );

  $form['limite'] = array(
    '#type' => 'fieldset',
    '#title' => t('Límites de los facets'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
  
  // To make these fields required
  $form['limite']['soft'] = array(
    '#type' => 'select',
    '#title' => t('Límite bajo'),
    '#description' => 'Máximo numero de items antes de mostrar ver más en las búsquedas',
    '#attributes' => array(
        'data-type' => 'number',
    ),
    '#width' => '30%',
    '#align' => 'center',
    '#maxlength' => 100,
    '#default_value' => $facet_config['soft_limit'],
    '#options' => array(5=>5,10=>10,15=>15,20=>20,30=>30,50=>50,-1=>'Sin límite')
  );

  // To make these fields required
  $form['limite']['hard'] = array(
    '#type' => 'select',
    '#title' => t('Límite alto'),
    '#description' => 'Máximo numero de items a mostrar',
    '#attributes' => array(
        'data-type' => 'number',
    ),
    '#width' => '30%',
    '#align' => 'center',
    '#maxlength' => 100,
    '#default_value' => $facet_config['hard_limit'],
    '#options' => array(5=>5,10=>10,15=>15,20=>20,30=>30,50=>50,-1=>'Sin límite')
  );

  $form['#submit'][] = 'argentinagobar_search_facetconfig';
  $form = system_settings_form($form);

  return $form;
}

function argentinagobar_search_facetconfig($form, &$form_state) {

  $facet_config['vermas_facets']=$form_state['values']['vermas_facets'];
  $facet_config['vermenos_facets']=$form_state['values']['vermenos_facets'];
  $facet_config['hard_limit']=$form_state['values']['hard'];
  $facet_config['soft_limit']=$form_state['values']['soft'];
  variable_set('facet_config',$facet_config);

  $result = db_select('facetapi', 'fa')
  ->fields('fa', array('settings','name'))
  ->condition('settings', '%hard%', 'like')
  ->range(0,10)
  ->execute();

  while($record = $result->fetchAssoc()) {

        $settings = unserialize($record['settings']);
        $settings['hard_limit'] = $facet_config['hard_limit'];

        db_update('facetapi')
        ->fields(array('settings' => serialize($settings)))
        ->condition('name', $record['name'], '=')
        ->execute();

        drupal_set_message('Se actualizó facetapi');
  }
  
}

function argentinagobar_search_lookandfeel_form($form, &$form_state) {

  $form['titulo_buscador'] = array(
    '#type' => 'textfield',
    '#title' => t('Título'),
    '#default_value' => variable_get('titulo_buscador'),
    '#description' => 'Título a mostrar en la home page',
  );

  // Use the #managed_file FAPI element to upload an image file.
  $form['backimage_buscador'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('Esta imagen será mostrada como background en el buscador'),
    '#default_value' => variable_get('backimage_buscador'),
    '#upload_location' => 'public://backimage_buscador/',
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'argentinagobar_search_lookandfeel_change_status';

  return $form;
}

function argentinagobar_search_lookandfeel_change_status($form, &$form_state) {
  if(!empty($form_state['values']['backimage_buscador'])){
    global $user;
    $file = file_load($form_state['values']['backimage_buscador']);
    $file->status = FILE_STATUS_PERMANENT;
    file_usage_add($file, 'argentinagobar_search', 'user', $user->uid);
    file_save($file);
    drupal_set_message('La imagen de fondo del buscador ha sido permanentemente guardada', 'status', TRUE);
  }
}

function argentinagobar_search_regex_form($form, &$form_state) {

  $tipos = array(
    1=>'DNI',
    2=>'Patente',
    3=>'Patente de moto',
    4=>'CUIT',
    5=>'Teléfono fijo',
    6=>'Teléfono móvil'
  );

  $search_regex = variable_get('search_regex');

  foreach($search_regex as $key => $value){$sel[]=$key;}

  $form['regex'] = array(
    '#type' => 'checkboxes',
    '#options' => $tipos,
    '#default_value' => $sel,
    '#title' => 'Seleccionar las expresiones a utilizar',
    '#description' => 'Seleccionar las expresiones que interceptarán las búsquedas',
  );

  foreach ($tipos as $key => $value) {

    $form['regex'.$key] = array(
      '#type' => 'textfield',
      '#title' => $value.' buscar',
      '#default_value' => $search_regex[$key]['regex'.$key],
      '#description' => 'Escribir una expresión regular',
      '#states' => array(
        'visible' => array(
          ':input[name="regex['.$key.']"]' => array('checked' => TRUE)
        ),
      ),
    );

    $form['regex_replace'.$key] = array(
      '#type' => 'textfield',
      '#title' => $value.' reemplazar',
      '#default_value' => $search_regex[$key]['regex_replace'.$key],
      '#description' => 'Reemplazo, agregar solo las palabras separadas por espacios. Se sumarán a la cadena de búsqueda pero no serán visibles en la búsqueda',
      '#states' => array(
        'visible' => array(
          ':input[name="regex['.$key.']"]' => array('checked' => TRUE)
        ),
      ),
    );

  }

  $form['submit'] = array('#type' => 'submit', '#value' => t('Guardar expresiones'));

  return $form;

}

function argentinagobar_search_regex_form_submit($form, &$form_state) {

  foreach($form_state['values']['regex'] as $key => $value){

    if($value!=0){
      
      $search_regex[$value] = array(
        'regex'.$value => $form_state['values']['regex'.$value],
        'regex_replace'.$value => $form_state['values']['regex_replace'.$value]
      );

      drupal_set_message('Se ingresó la expresión <b>'.$form_state['values']['regex'.$value].'</b> por <b>'.$form_state['values']['regex_replace'.$value].'</b>' , 'status', FALSE);

    }
  }

  variable_set('search_regex', $search_regex);

}