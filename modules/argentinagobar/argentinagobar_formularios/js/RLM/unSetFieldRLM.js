(function ($) {
  Drupal.behaviors.unSetFieldRLM = {
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
