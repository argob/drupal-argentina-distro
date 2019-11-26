(function ($) {
    Drupal.behaviors.unsetSancionEnTipoNormaLey = {
        attach: function(context) {

            $("select#edit-tipo-norma").change(function() {

                if ($(this).val() == 'leyes') {
                    $('input#edit-sancion').val('');
                }

            });

        }
    }

})(jQuery);
