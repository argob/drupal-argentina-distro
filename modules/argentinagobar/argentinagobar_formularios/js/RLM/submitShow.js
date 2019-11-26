(function ($) {
  Drupal.behaviors.submitShow = {
    attach: function(context) {


      document.getElementById("paginaHidden").parentNode.style.display = "none";

      if(document.getElementById("rlm_nuevabusqueda") != null){
        document.getElementById("wrapper").parentNode.parentNode.style.display = "none";
        document.getElementById("frlm").style.display = "none";
      }

      if(document.getElementsByClassName("alert alert-block alert-danger messages error")[0] != null){
        
        if(document.getElementById("wrapper2").style.display != ""){
          document.getElementById("wrapper2").appendChild(document.getElementsByClassName("alert alert-block alert-danger messages error")[0]);
        }
        else{

          if(document.getElementById("pagina_vacia_error_warning") != null){
            document.getElementsByClassName("alert alert-block alert-danger messages error")[0].style.display = "none";
          }
        }
      }

      if(document.getElementById('edit-captcha-response') == null){
        location.reload();
      }

      document.getElementById('rlm_pagina_anterior').onclick = function(){

        moverCaptcha('anterior');
        if(getValorPagina() != 1){
          document.getElementById("paginaHidden").setAttribute('value', getValorPagina()-1);
        }
      }

      document.getElementById('rlm_pagina_siguiente').onclick = function(){
        
        moverCaptcha('siguiente');
        document.getElementById("paginaHidden").setAttribute('value', getValorPagina()+1);
        
      }

      function getValorPagina(){
        return parseInt(document.getElementById("paginaHidden").value);
      }

      function moverCaptcha(paginaCap){

        document.getElementById("texto_nuevapagina_captcha").innerHTML = "Ingrese el valor del Captcha para obtener informacion de la "+paginaCap+" pagina";
        document.getElementById("rlm_nuevapagina_captcha").appendChild(document.getElementById("edit-captcha-response").parentNode);

        if(document.getElementById("edit-submit--2") != null){
          document.getElementById("rlm_nuevapagina_captcha").appendChild(document.getElementById("edit-submit--2").parentNode);
        }

        if(document.getElementById("edit-submit") != null){
          document.getElementById("rlm_nuevapagina_captcha").appendChild(document.getElementById("edit-submit").parentNode);
        }
        
      }

    }
  }
})(jQuery);


