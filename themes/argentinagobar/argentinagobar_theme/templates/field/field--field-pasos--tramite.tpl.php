<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<!--
THIS FILE IS NOT USED AND IS HERE AS A STARTING POINT FOR CUSTOMIZATION ONLY.
See http://api.drupal.org/api/function/theme_field/7 for details.
After copying this file to your theme's folder and customizing it, remove this
HTML comment.
-->
<div class="media-left hidden-xs">
</div>
<div class="media-body">
	<div class="steps clearfix">
		<?php foreach ($element['#items'] as $delta => $item): ?>
		<?php $item = field_collection_item_load($item['value'], $reset = FALSE); ?>
		<?php $pasos = field_get_items('field_collection_item', $item, 'field_paso'); ?>
		<?php $observaciones = field_get_items('field_collection_item', $item, 'field_observaciones'); ?>
		<?php foreach ($pasos as $key => $paso) { ?>
			<div class="step">
				<div>
					<div class="circle"><?php print $key + 1; ?></div>
					<div class="line"></div>
				</div>
				<div>
					<div class="description">
						<?php print check_markup($paso['value'], 'filtered_html', $langcode = '', $cache = FALSE); ?>
					</div>
				</div>
			</div>
		<?php } ?>
		<?php endforeach; ?>
	</div>
</div>
 <div class="media clearfix">
	<?php if(isset($observaciones[0])){ ?>
	<div class="alert alert-warning">
		<?php print check_markup($observaciones[0]['value'], 'filtered_html', $langcode = '', $cache = FALSE); ?>
	</div>
	<?php } ?>
</div>
