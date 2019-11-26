var preguntaActual = 0;

(function ($) {
  Drupal.behaviors.accionesEncuestaSatisfaccion = {
    attach: function(context) {
    	
		jQuery("[name='conoce_argobar']").click(function(){
			dataLayer.push({ 'event':'UAtracking','eventCategory':'Interacción','eventAction':'ENC_Satisfacción_FIN_' + jQuery(this).val(),'eventLabel':'{{Page Path}}'});
		})

    }
  }

})(jQuery);
