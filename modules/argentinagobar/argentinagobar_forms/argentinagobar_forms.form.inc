<?php
/**
 * Implements hook_forms().
 */
function argentinagobar_forms_forms($form_id, $args){
  if(preg_match('/^argentinagobar_forms_render/', $form_id)) {
    return array(
      $form_id => array(
        'callback' => 'argentinagobar_forms_render',
      )
    );
  }
}
