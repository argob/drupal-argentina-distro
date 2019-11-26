(function ($) {
  Drupal.behaviors.setDefaultRadio = {
    attach: function(context) {

      $('input:radio[name="searchBy"]').filter('[value="cuit"]').attr('checked', true);
      //$('input[type="radio"]:checked').attr('checked', false);
    }
  }
})(jQuery);
