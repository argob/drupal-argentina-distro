(function ($) {
  Drupal.behaviors.submitShow = {
    attach: function(context) {

      if(document.getElementById("reg_soc_nuevabusqueda") != null){
        //document.getElementById("wrapper0").parentNode.style.display = "none";
        document.getElementById("frlm").style.display = "none";
        document.getElementById("reg_soc_nuevabusqueda").parentNode.style.display = "block"
      }


      }

    }

})(jQuery);
