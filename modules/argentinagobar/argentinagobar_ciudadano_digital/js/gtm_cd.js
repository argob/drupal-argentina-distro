(function ($) {
  Drupal.behaviors.gtm_cd = {
    attach: function(context) {
			$('#edit-openid-connect-client-generic-login--2').on('click', function() {
				dataLayer.push({
				  'event': 'UAtracking',
				  'ua-category': 'ingresar',
				  'ua-action': 'FOR',
				  'ua-label': 'FOR_INGRESAR'
				});
			});

			$('#argentinagobar-id-mi-argentina').on('click', function() {
				dataLayer.push({
				  'event': 'UAtracking',
				  'ua-category': 'mi argentina',
				  'ua-action': 'FOR',
				  'ua-label': 'FOR_MI ARGENTINA'
				});
			});
		}
	}
})(jQuery);
