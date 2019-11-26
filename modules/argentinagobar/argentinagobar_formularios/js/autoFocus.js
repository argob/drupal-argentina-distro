(function ($) {
  Drupal.behaviors.autoFocus = {
    attach: function(context) {

      $("input.autofocus").focus();

    }
  }

})(jQuery);
