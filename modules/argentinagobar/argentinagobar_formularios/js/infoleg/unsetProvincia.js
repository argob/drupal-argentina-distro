(function ($) {
    Drupal.behaviors.unsetProvincia = {
        attach: function(context) {

            console.log($("#edit-jurisdiccion input"))
            $("#edit-jurisdiccion input").change(function() {

                console.log($(this).val())

                if ($(this).val() == 'nacional') {
                    $('select#edit-provincia').val('');
                }

            });

        }
    }

})(jQuery);