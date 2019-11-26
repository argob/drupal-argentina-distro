<?php
class FieldContainer extends Field{
	
	function __construct($id, $class = array()){
		$this->id = $id;
		$this->class = $class;
	}
	
	function get_id(){
		return $this->id;
	}
	
	function get_class(){
		return $this->class;
	}
	
	function get_type(){
		return 'container';
	}
	
	function get_title(){
		return '';
	}
	
	function render(){
		return array(
			'#type' => $this->get_type(),
			'#attributes' => array(
				'id' => $this->get_id(),
				'class' => $this->get_class(),
			),
		);
	}
}