<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
  $image_url  = $row->_field_data["nid"]["entity"]->field_image["und"][0]["uri"] ;
  $situacion  = $row->_field_data["nid"]["entity"]->field_situacion["und"][0]["value"] ;
  $node_url   = strip_tags($fields["path"]->content);
  $esFemenino = substr($situacion, -1) == 'a';

  if(empty($image_url)){
    $image_url = $row->_field_data["nid"]["entity"]->field_image["es"][0]["uri"] ;
    $situacion = $row->_field_data["nid"]["entity"]->field_situacion["es"][0]["value"] ;
  }

?>
<a class="panel" href="<?= $node_url ?>">
  <div>

    <?php if(!empty($image_url)): ?>
      <img id="img-persona-buscada" class="fit-width" src="<?php echo image_style_url('imagen_persona_buscada', $image_url);?>" />
    <?php elseif ($esFemenino): ?>

      <img id="img-persona-buscada" class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/silueta-mujer.png" />
    <?php else: ?>
      <img id="img-persona-buscada" class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/silueta-hombre.png" />
    <?php endif; ?>

  </div>
  <div id="persona-buscada-name">
    <?= $fields["title"]->content ?>
  </div>
</a>
