(function ($) {
  Drupal.behaviors.onKeyPressEnterSubmitForm = {
    attach: function(context) {

      $('.submit-with-enter').keypress(function(event) {
        if (event.which == 13) {
          this.form.submit();
        }
      });
    }
  }

})(jQuery);
