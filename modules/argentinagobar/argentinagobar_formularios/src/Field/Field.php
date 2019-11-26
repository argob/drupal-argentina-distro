<?php
abstract class Field{

	public $title;
	static $type;
	public $class = array();

  protected $required = FALSE;

	abstract function get_type();
	abstract function get_title();

	function __construct()
  {
		$this->set_required(FALSE);
	}

	function render()
  {

		return array(
			'#type' => $this->get_type(),
			'#title' => $this->get_title(),
			'#required' => $this->is_required(),
		);
	}


	function set_required($bool)
  {
		$this->required = $bool;
	}

	function is_required()
  {
		return $this->required;
	}

	function getClass()
  {
    return $this->class;
  }

  function addClass($class)
  {
    $this->class[] = $class;
  }

}
