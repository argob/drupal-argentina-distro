(function ($) {
    Drupal.behaviors.unSetCampoEnOtroTab = {
      attach: function(context) {
        $('a[data-toggle="tab"]').click(function() {

          if($(this).attr("href") == '#modo-busqueda-fecha'){
              $('input#edit-numero').val('')
            }
          if($(this).attr("href") == '#modo-busqueda-numero'){
              $('input#edit-fecha-publicacion-datepicker-popup-0').val('')
            }
          })
      }
    }
})(jQuery);
