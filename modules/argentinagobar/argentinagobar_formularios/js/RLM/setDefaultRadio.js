(function ($) {
  Drupal.behaviors.setDefaultRadio = {
    attach: function(context) {

      $('input:radio[name="searchBy"]').filter('[value="razon"]').attr('checked', true);

    }
  }
})(jQuery);







