<?php

/**
 * @file
 * provides the drag and drop interface for menu items.
 */

/**
 * Callback function for reorder tab.
 */
function argentinagobar_search_node_page_reorder($form, &$form_state, $node) {

  $form['menu_items']['#tree'] = TRUE;
  $facets = variable_get('facetas');
  $rows = '';

  foreach ($facets as $facet) {
    $form['menu_items'][$facet['id']] = array(
      'link_title' => array(
        '#markup' => $facet['title'].' ('.$facet['id'].')',
      ),
      'weight' => array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $facet['weight'],
        '#delta' => 10,
        '#title-display' => 'invisible',
      ),
    );
  }
  
  $form['menu_name'] = array(
    '#type' => 'hidden',
    '#value' => 'facets',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
  );
  return $form;
}

/**
 * Returns HTML for a table.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: An array of form fields for reorder menu items.
 */
function theme_argentinagobar_search_node_page_reorder($variables) {
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

  $header = array(t('Facet menu items'), t('Weight'));

  $table_id = 'menu-items-reorder-table';
  $output = '<h1>Determinar el orden en que aparecen los facets</h1>';
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
 * Implements hook_submit().
 */
function argentinagobar_search_node_page_reorder_submit($form, &$form_state) {
  $orden = $form_state['values']['menu_items'];
  $facetas = variable_get('facetas');

  $newFacetas = array();
  foreach ($facetas as $key => $value){
    $value['weight'] = $orden[$value['id']]['weight'];
    $newFacetas[$orden[$value['id']]['weight']] = $value;
  }

  ksort($newFacetas);

  variable_set('facetas', $newFacetas);
}
