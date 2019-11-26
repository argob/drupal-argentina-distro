<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>


 <?php
$campos = array();

    foreach ($content['field_vigencia_campos']['#items'] as $key => $item) {
         $item = field_collection_item_load($item['value'], $reset = FALSE);
         $detalles = field_get_items('field_collection_item', $item, 'field_detalle');
         $cantidades = field_get_items('field_collection_item', $item, 'field_cantidad');
         $medidas = field_get_items('field_collection_item',$item, 'field_medida');
    ?>

      <p class="clearfix m-b-0">
        <strong class="lead"><?php print $cantidades['0']['value'] ?> <?php print $medidas['0']['value'] ?></strong>
        <br>
        <?php print check_markup($detalles['0']['value'], 'filtered_html', $langcode = '', $cache = FALSE); ?>
   <?php }

if (isset($content['field_observaciones'])){ ?>
            <div class="alert alert-warning">
        <?php print check_markup($content['field_observaciones']['#items']['0']['value'], 'filtered_html', $langcode = '', $cache = FALSE); ?>
      </div>
            <?php } ?>
