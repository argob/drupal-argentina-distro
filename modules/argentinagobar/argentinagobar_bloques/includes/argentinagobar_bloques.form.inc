<?php

function argentinagobar_bloques_forms($form_id, $args){

	// Build a form with a static class callback.
  if($form_id == 'argentinagobar_bloques_filtro_form') {
  	
    // example = array('updates' => array('status' => 0)),
  	$form = isset($form) ? $form : "";
  	$form_state = isset($form_state) ? $form_state : array();

    $forms['argentinagobar_bloques_filtro_form'] = array(
      // This will call: MyClass::generateMainForm().
      'callback' => array($args[0], 'crear_form'),
      'callback arguments' => array($form, $form_state),
      // The base_form_id is required when the callback is a static function in
      // a class. This can also be used to keep newer code backwards compatible.
      'base_form_id' => 'argentinagobar_bloques_filtro_form',
    );
  	return $forms;
  }
}

function argentinagobar_bloques_filtro_form_submit_ajax($form, &$form_state){
		
	$values = $form_state['values'];
	$listado = unserialize($form_state['handler']);
        if(isset($values['ubicacion'])){
            $ubicacion = $values['ubicacion'];
        }elseif(isset($values['ubicación'])){
            $ubicacion = $values['ubicación'];
        }
            
	$args = [
		'tipo_inmueble' => $values['tipo_inmueble'],
		'tipo_subasta' => $values['tipo_subasta'],
		'ubicacion' => $ubicacion,
                'estado' => $values['estado'],
		'order_by' => $values['order_by'],
	];
	
        $listado->crearItems('subasta', 'recientes', $listado->getCantidadItems(), $args);
           
         
        if(sizeof($listado->items)==0){
            $res = '<div id="filter_form_response">
                        <div class="col-md-12">
                            <p>No se encontraron resultados</p>
                        </div>
                    </div>';
        }else{
            $res = $listado->render();
        }
        
        return $res;
}
