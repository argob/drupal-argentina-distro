<?php

/**
 * Implements hook_menu().
 */
function argentinagobar_forms_menu() {
	// Forms wizzard
	$items['admin/structure/argentinagobar_forms/form'] = array(
	  'title'             => t('Formularios'),
	  'description'       => t('Administrar formularios de Argentinagobar Forms'),
	  'page callback'     => 'drupal_get_form',
	  'page arguments'    => array('argentinagobar_forms_form'),
	  'access arguments'  => array('administer argentinagobar_forms_forms entities'),
	);

	$items['admin/structure/argentinagobar_forms/form/%argentinagobar_forms_form/edit'] = array(
	  'title' => 'Editar',
	  'page callback' => 'drupal_get_form',
	  'page arguments' => array('argentinagobar_forms_form', 4),
	  'access arguments' => array('edit any argentinagobar_forms_fields entity'),
	  'type' => MENU_LOCAL_TASK,
	);
	$items['admin/structure/argentinagobar_forms/form/%argentinagobar_forms_form/delete'] = array(
	  'title' => 'Eliminar',
	  'page callback' => 'drupal_get_form',
	  'page arguments' => array('argentinagobar_forms_form_delete', 4),
	  'access arguments' => array('delete any argentinagobar_forms_forms entity'),
	  'type' => MENU_LOCAL_TASK,
	);

	return $items;
}