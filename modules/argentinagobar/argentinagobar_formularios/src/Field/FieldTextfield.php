<?php

class FieldTextfield extends Field{

	public $title;
  protected $maxlength = 128;

	function __construct($title = 'Texto'){
		parent::__construct();
		$this->set_title($title);
		$this->set_size(60);
	}

	function get_type(){
		return 'textfield';
	}

	function get_title(){
		return $this->title;
	}

	function set_title($title){
		$this->title = t($title);
	}

	function set_size($size){
		$this->size = $size;
	}

	function set_maxlength($length){
		$this->maxlength = $length;
	}

	function get_maxlength(){
		return $this->maxlength;
	}

	function get_size(){
		return $this->size;
	}

	function get_rules(){
		return array();
	}

	function render(){
		return array(
			'#type' => $this->get_type(),
			'#title' => $this->get_title(),
			'#required' => $this->is_required(),
			'#maxlength' => $this->get_maxlength(),
			'#size' => $this->get_size(),
			'#rules' => $this->get_rules(),
		);
	}
}
