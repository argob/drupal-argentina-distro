<?php

function argentinagobar_formularios_form_alter(&$form, &$form_state, $form_id)
{
  $form['tarro_de_miel'] = array(
    '#type' => 'textfield',
    '#title' => t('Dejar en blanco'),
    '#prefix' => '<div style="display:none;">',
    '#suffix' => '</div>',
    '#element_validate' => array('validar_campo_vacio'),
  );
}

function validar_campo_vacio($element, &$form_state, $form) {
  if (!empty($element['#value'])) {
    form_error($element, t('No completar el campo'));
  }
  return $form;
}

function argentinagobar_formularios_forms($form_id, $args)
{
	$forms = array();

	if (preg_match('/^argobar_consulta_/', $form_id)) {

		// Build a form with a static class callback.
		$forms[$form_id] = array(
			// This will call: MyClass::generateMainForm().
			'callback' => array($args[0], 'get_form'),
			'callback arguments' => array($args[0]),
			// The base_form_id is required when the callback is a static function in
			// a class. This can also be used to keep newer code backwards compatible.
			'base_form_id' => 'argobar_consulta',
		);
	}

	return $forms;
}

function argobar_consulta_validate($form, &$form_state)
{
//  form_set_error('argobar-consulta-infoleg-consulta-avanzada', t('TEST'));
}

function argobar_consulta_submit($form, &$form_state)
{

  $consulta = unserialize($form_state['handler']['class']);

  $consulta->values = [];

  $consulta->setValues($form_state['values']);

  global $base_url;

  $form_state['redirect'] = array(
    $base_url . '/' . drupal_get_path_alias(),
    array('query' => $consulta->get_params()),
  );
}

function argobar_consulta_ajax_submit($form, &$form_state)
{
	$consulta = unserialize($form_state['handler']['class']);

	$form_id = $form_state['build_info']['form_id'];
	drupal_validate_form($form_id, $form, $form_state);

	if (form_get_errors()) {
    $commands[] = ajax_command_replace('#response', '<div id="response"></div>');
    $commands[] = ajax_command_append('#response', theme('status_messages'));
    return array('#type' => 'ajax', '#commands' => $commands);
	}

	$consulta->setValues($form_state['values']);

	if ($consulta->values['options'] == 'beneficio-anses'){

	  $consulta->values['BeneficioNro'] = $consulta->values['benef'];

    $response[] = $consulta->getBeneficios($consulta->values);

  }else{
    $response = $consulta->consultar();
  }

	return $consulta->renderResponse($form, $form_state, $response);
}
