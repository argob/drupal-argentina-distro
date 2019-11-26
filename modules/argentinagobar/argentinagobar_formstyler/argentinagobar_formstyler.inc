<?php

function argentinagobar_formstyler(&$form, $options){

	drupal_add_css(drupal_get_path('module', 'argentinagobar_formstyler') . '/css/tabs.css');
	$form['#attached']['js'][] = drupal_get_path('module', 'argentinagobar_formstyler') . '/js/responseFormStyler.js';
	$form['#attached']['js'][] = drupal_get_path('module', 'argentinagobar_formstyler') . '/js/tabButtonStyler.js';

	if(isset($options['progress']) && $options['progress'] == true){
		drupal_add_js(drupal_get_path('module', 'argentinagobar_formstyler') . '/js/progressStyler.js');
	}

	if(isset($options['subtitle'])){
		$options['subtitle'] = (!empty($options['subtitle'])) ? '<p>'.$options['subtitle'].'</p>' : '';
		$form['#prefix'] = '<div class="responseFormStyler"><h3 class="margin-10">'.$options['title'].'</h3>'.$options['subtitle'].'';
		$form['#suffix'] = '</div>';
	}
	
	if (!isset($options['ajax']) || $options['ajax'] == TRUE){

		$form["wrapper"] = array("#markup" => "<div id='test-ajax'></div>");
		$form['#attached']['js'][] = drupal_get_path("module", "argentinagobar_formstyler")."/js/callbackStyler.js" ;
		$form['submit']['#ajax']=array('callback' => $form['#name']."_consultar", "wrapper" => "test-ajax");
		$form['submit']['#attributes']=array('class'=>array('btn','btn-success','btn-block'));
		$form['submit']['#suffix']="<div id='response'></div>";
		
	}

	$form['#validate'][] = $form['#name'].'_validar';

	return $form;
}
