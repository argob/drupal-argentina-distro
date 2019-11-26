<?php
/**
 * @file
 * argentinagobar_bloques_votacion.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function argentinagobar_bloques_votacion_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    3 => (object) array(
      'name' => 'caritas',
      'tag' => 'vote',
      'title' => '¿Es clara la norma?',
      'node_types' => array(
        0 => 'argentinagobar_migtram',
        1 => 'tramite',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => 1,
          1 => '1',
        ),
        1 => array(
          0 => 2,
          1 => '2',
        ),
        2 => array(
          0 => 3,
          1 => '3',
        ),
        3 => array(
          0 => 4,
          1 => '4',
        ),
        4 => array(
          0 => 5,
          1 => '5',
        ),
      ),
      'template' => 'caritas',
      'node_display' => '2',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        34 => 1,
        4 => 1,
        21 => 1
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => '',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'option',
      'theme' => 'argentinagobar_bloques_votacion_caritas',
      'css' => 'profiles/argentinagobar/modules/argentinagobar/argentinagobar_bloques/argentinagobar_bloques_votacion/templates/caritas/caritas.css',
      'js' => 'profiles/argentinagobar/modules/argentinagobar/argentinagobar_bloques/argentinagobar_bloques_votacion/templates/caritas/caritas.js',
      'translate' => TRUE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
