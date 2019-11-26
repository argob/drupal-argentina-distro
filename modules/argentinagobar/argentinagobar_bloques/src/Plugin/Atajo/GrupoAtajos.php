<?php

class GrupoAtajos extends Plugin{
  private $hay_atajo_activo = FALSE;
  private $atajos = array();
  protected $single = TRUE;
  protected $title = 'Grupo de Atajos';
  protected $description = 'Los atajos se utilizan para enlazar cualquier tipo de contenido, tanto interno como externo, y con diferentes tipos de jerarquías.';
  protected $category = 'Drupar';
  protected $defaults = array(
    'atajos' => array(),
    'cantidadAtajos' => 1,
    'opciones' => array(
      'formato' => 'AtajoSimple',
      'columnas' => 1,
    ),
  );

  function __construct($formato){
    $this->formato = $formato;
  }

  function getFormato(){
    return $this->formato;
  }

  function render_callbak(){

  }
  function admin_info(){

  }
  function edit_form(){
  }

  function addAtajo($atajo){
    $this->atajos[] = $atajo;
  }

  function getAtajos(){
    return $this->atajos;
  }

  function crear_atajos($atajos = array(), $opciones){
    $lista_atajos = array();
    $formato = $this->getFormato();

    foreach ($atajos as $key => $conf_atajo) {
      $formatoAtajo = new $formato();
      $atajo = $formatoAtajo->render($conf_atajo, $opciones['columnas']);

      $isActive = (is_object($formatoAtajo) && property_exists($formatoAtajo, 'isActive')) ? $formatoAtajo->isActive : false;

      $this->hay_atajo_activo = $this->hay_atajo_activo || $isActive;
      $this->addAtajo($atajo);

    }
    return $formatoAtajo->crear_rows($this->getAtajos(), $opciones['columnas']);
  }

  function isHayAtajoActivo(){
    return $this->hay_atajo_activo;
  }

  function render($atajos, $opciones){

    // no modificar el orden
    $crearAtajos  = $this->crear_atajos($atajos, $opciones);    
    $hayActivo    = $this->isHayAtajoActivo();

    return theme(
      $this->formato->getContainerTheme(),
      array('rows' => $crearAtajos, 'hay_atajo_activo' => $hayActivo)
    );
  }

}
