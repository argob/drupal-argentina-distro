(function ($) {
  Drupal.behaviors.ocultarBoton = {
    attach: function(context, settings) {
      $('#edit-submit').submit(function(){
        $('#edit-submit').css('display','block');
        $('#edit-submit').css('display','none');
    })
  }
}
})(jQuery);
