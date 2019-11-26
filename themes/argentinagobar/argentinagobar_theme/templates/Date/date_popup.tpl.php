<?php
$attributes = !empty($element['#wrapper_attributes']) ? $element['#wrapper_attributes'] : array('class' => array());
$element['#title'] = null;
//$attributes['class'][] = 'container-inline-date';
// If there is no description, the floating date
// elements need some extra padding below them.
$wrapper_attributes = array('class' => array('date-padding'));
if (empty($element['date']['#description'])) {
  $wrapper_attributes['class'][] = 'clearfix';
}
$wrapper_attributes =  array();
// Add an wrapper to mimic the way a single value field works,
// for ease in using #states.
if (isset($element['#children'])) {
  $element['#children'] = '<div id="' . $element['#id'] . '" ' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
}
?>

<div <?= drupal_attributes($attributes) ?>>
  <?= theme('form_element', $element) ?>
</div>
