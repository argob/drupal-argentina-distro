<?php

abstract class Plugin implements PluginInterface{

  protected $title;

  protected $single;

  protected $description;

  protected $category;

  protected $defaults;


  function setPlugin(){
    return array(
      'title' => $this->getTitle(),
      'single' => $this->getSingle(),
      'description' => $this->getDescription(),
      'category' => $this->getCategory(),
      'defaults' => $this->getDefaults(),
    );
  }

  function getTitle(){
    return $this->title;
  }

  function getSingle(){
    return $this->single;
  }

  function getDescription(){
    return $this->description;
  }

  function getCategory(){
    return $this->category;
  }

  function getDefaults(){
    return $this->defaults;
  }
}

/*

$plugin = array(
  'single' => TRUE,
  'title' => t('Grupo de Atajos'),
  'description' => t('Los atajos se utilizan para enlazar cualquier tipo de contenido, tanto interno como externo, y con diferentes tipos de jerarquías.'),
  'category' => t('Drupar'),
  'render callback' => 'drupar_componentes_atajos_render',
  'edit form' => 'drupar_componentes_atajos_edit_form',
  'admin info' => 'drupar_componentes_atajos_admin_info',
  'defaults' => array(
    'atajos' => array(),
    'cantidadAtajos' => 1,
    'opciones' => array(
      'formato' => 'AtajoSimple',
      'columnas' => 1,
    ),
  )
);
*/
