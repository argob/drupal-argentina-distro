<?php

	function jsonGetLocalidades($form, $form_state){

	  $form_state['triggering_element'];
	  $fieldset = reset($form_state['triggering_element']['#parents']);

	  $form_state['rebuild'];
	  return $form[$fieldset]['localidad'];

	}

	function argentinagobar_localidad(&$form, &$form_state, $options, $provincias){

	  $identificarCampo = [
	    'personales' => ' del domicilio',
	    'reclamo' => ' de compra o contratación',
	    'uso' => ' de uso del producto o servicio',
	    'proveedor1' => ' del proveedor',
	    'proveedor2' => ' del proveedor',
	    'proveedor3' => ' del proveedor',
	    'proveedor4' => ' del proveedor',
	    'proveedor5' => ' del proveedor',
	  ];

	  if(!empty($provincias)){

	    $form[$options['fieldset']]['caption'] = array(
	      '#markup' => (!empty($options['caption'])) ? '<label class="control-label">'.$options['caption'].'</label><br><br>' : '',
	    );

	    $form[$options['fieldset']]['provincia'] = array(
	      '#type' => 'select',
	      '#title' => '<span class="text-muted" style="font-weight:normal;">Provincia' . $identificarCampo[$options['fieldset']] . '</span>',
	      '#options' => $provincias,
              '#attributes' => array('onchange' => array("jsShowWindowLoad('Espere por favor');")),
	      '#empty_option' => t('- Select -'),
	      '#required' => $options['required'],
	      '#ajax' => array(
	        'callback' => 'jsonGetLocalidades',
	        'event' => 'change',
	        'wrapper' => $options['fieldset'].'_localidades',
	        'method' => 'replace',
	        'effect' => 'none',
	        'progress' => FALSE
	      ),
	    );

            drupal_add_js(drupal_get_path('module', 'argentinagobar_formularios') . '/js/changeFormProvincia.js');
            drupal_add_css(drupal_get_path('module', 'argentinagobar_formularios') . '/css/fromProvincia.css');

	    if(!empty($form_state['values'][$options['fieldset']]['provincia'])){

	      $provincia = $form_state['values'][$options['fieldset']]['provincia'];
				$consultaLocalidades = new ConsultaGeoRefLocalidades;
				if(!function_exists($localidades)){
	      	$localidades = $consultaLocalidades->get_select_options($provincia);
				}
	      $disabled = false;

	    }
	    else{

	      $disabled = true;
	      $localidades = array();

	    }

	    $form[$options['fieldset']]['localidad'] = array(
	      '#type' => 'select',
	      '#title' => '<span class="text-muted" style="font-weight:normal;">Localidad, municipio o barrio' . $identificarCampo[$options['fieldset']] . '</span>',
	      '#options' => $localidades,
	      '#empty_option' => t('- Select -'),
	      '#required' => $options['required'],
	      '#prefix' => '<div id="'.$options['fieldset'].'_localidades">',
	      '#suffix' => '</div>',
	      '#disabled' => $disabled
	    );

	    $form['submit_disabled'] = false;



	  } else {

	    $form['submit_disabled'] = true;
	    $form['submit_tooltip'] = 'El formulario no puede ser enviado momentáneamente';

	  }


	  return $form;

	}

	function _explodeMails($string){
	  if (strpos($string, '/') !== false) {
	    foreach( explode('/', $string) as $mail ){
	      $mails .= '<a href="mailto:'.$mail.'">'.$mail.'</a><br>';
	    }
	  } else {
	    $mails .= '<a href="mailto:'.$string.'">'.$string.'</a><br>';
	  }
	  return $mails;
	}

	function jsonGETURL(){
	  $opciones = variable_get('DC_opciones');
	  if (!empty($opciones)){
	    return $opciones['destination'].'/';
	  } else {
	    return 'ip';
	  }
	}

	function _fecha_redapi($fecha){
	  $f = explode('/', $fecha); return $f[2].'-'.$f[1].'-'.$f[0];
	}
