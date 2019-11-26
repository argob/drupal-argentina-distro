<?php

  /**
   * Lógica para procesar los fields
   */

  $esGratuito = $field_gratuito[0]['value'];
  // Si no es gratuito busco los datos del campo field_valor
  if(!$esGratuito)
  {

    $costos = array();

    if (is_null($field_valor))
    {
      // Si no es gratuito pero $field_valor es null lo defino como un array vacío para evitar warning;
      $field_valor = array();
    }

    foreach ($field_valor as $valor)
    {
      $item = field_collection_item_load($valor['value'], $reset = FALSE);
      $precio = field_get_items('field_collection_item', $item, 'field_precio', $langcode = NULL);
      $detalle = field_get_items('field_collection_item', $item, 'field_detalle', $langcode = NULL);

      // Valido que el campo no esté vacío
      if (!empty($precio))
      {
        $costos[] = array(
          'precio' => $precio[0]['value'],
          'detalle' => check_markup($detalle[0]['value'], 'filtered_html', $langcode = '', $cache = FALSE),
        );
      }
    }
  }

  if (isset($field_observaciones)) {
    $observaciones = check_markup($field_observaciones[0]['value'], 'filtered_html', $langcode = '', $cache = FALSE);
  }

  // field_costo_tramite patch
  if(!$esGratuito && $costos == array() && !isset($observaciones)){
    drupal_add_js(drupal_get_path('theme', 'argentinagobar_theme') .'/js/servicios/field_costo_tramite.js', array('scope' => 'footer', 'weight' => 1));
  }
?>

<?php if($esGratuito ): ?>
  <p class="clearfix">
    <strong class="lead"><?= t("Gratuito") ?></strong>
  </p>

<?php else: ?>

  <?php foreach ($costos as $costo): ?>

      <?php $precio = $costo['precio']?>

        <p class="clearfix m-b-0">

          <strong class="lead"><?= $precio !== '0.00' ? '$'. $precio : t('Gratuito') ?></strong>

        <br>
    </p>

    <?= $costo['detalle'] ?>

  <?php endforeach; ?>
<?php endif ?>

<?php if (isset($observaciones)): ?>
  <div class="alert alert-warning"><?= $observaciones ?></div>
<?php endif ?>
