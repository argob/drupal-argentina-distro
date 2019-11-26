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
<?php foreach ($content['field_cantidades']['#items'] as $key => $campo):

    $duracion = field_collection_item_load($campo['value'], $reset = FALSE);

  if(isset($duracion->field_cantidad['und']) && isset($duracion->field_medida['und'])):

  ?>
      <p class="clearfix">
          El trámite lleva: <strong><?= $duracion->field_cantidad['und'][0]['value'] . " " . $duracion->field_medida['und'][0]['value'] ?></strong>
          <br>
      <?php

        if(isset($duracion->field_detalle['und'])){
          $duracion = $duracion->field_detalle['und'][0]['value'];
          echo check_markup($duracion, 'filtered_html', $langcode = '', $cache = FALSE);
        }

      ?>

      </p>
  <?php else:
    // field_duracion_tramite patch
    drupal_add_js(drupal_get_path('theme', 'argentinagobar_theme') .'/js/servicios/field_duracion_tramite.js', array('scope' => 'footer', 'weight' => 1));
   ?>
 <?php endif ?>
<?php endforeach ?>
<?php if(isset($content['field_observaciones']) && !empty($content['field_observaciones']['#items'][0])): ?>
    <div class="alert alert-warning">
        <?= check_markup($content['field_observaciones']['#items'][0]['value'], 'filtered_html', $langcode = '', $cache = FALSE) ?>
     </div>
<?php endif ?>
