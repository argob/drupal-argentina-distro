(function ($) {
  Drupal.behaviors.emptyFieldsRegSoc = {
    attach: function(context) {
      $('#edit-razon').focus(function() {
          $('#edit-cuit').val("")
      })

      $('#edit-cuit').focus(function() {
          $('#edit-razon').val("")
      })
    }
  }
})(jQuery);
