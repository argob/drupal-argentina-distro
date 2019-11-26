<?php
  class JumbotronDosColumna {
    function __construct($titulo, $mostrarTitulo, $descripcion,$logo = NULL,$boton = NULL){
        $this->titulo = $titulo;
        $this->descripcion = $descripcion;
        $this->logo = $logo;
        $this->mostrarTitulo = $mostrarTitulo;
        $this->boton = array(
          'href' => $boton['href'],
          'text' => $boton['text'],
          'claseColor' => !is_null($boton) ? "btn btn-primary" . " " . $boton['color'] : "",
        );
    }
    public function render(){
      return theme("jumbotron_dos_columna", array(
        'titulo' => $this->titulo,
        'descripcion' =>$this->descripcion,
        'logo'=> $this->logo,
        'boton'=> $this->boton,
        'mostrarTitulo'=>$this->mostrarTitulo
        )
      );
    }
}
