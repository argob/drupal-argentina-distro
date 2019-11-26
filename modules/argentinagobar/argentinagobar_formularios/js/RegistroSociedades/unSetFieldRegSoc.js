(function ($) {
  Drupal.behaviors.unSetFieldRegSoc = {
    attach: function(context) {
      $('#edit-searchby-cuit').click(function() {
          $('#edit-razon').val('')
      })

      $('#edit-searchby-razon').click(function() {
          $('#edit-cuit').val('')
      })
    }
  }
})(jQuery);
