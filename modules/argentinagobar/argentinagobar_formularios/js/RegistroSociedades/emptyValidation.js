(function ($) {
  Drupal.behaviors.emptyValidation = {
    attach: function(context) {

      $('#edit-submit').attr('disabled', true);

      $('#edit-razon').change(function(){
        if($('#edit-razon').val() != "") {
          $('#edit-submit').attr('disabled', false)
        }else{
          $('#edit-submit').attr('disabled', true)
        }
      })

      $('#edit-cuit').change(function(){
        if($('#edit-cuit').val() != "") {
          $('#edit-submit').attr('disabled', false)
        }else{
          $('#edit-submit').attr('disabled', true)
        }
      })
    }
  }
})(jQuery);


