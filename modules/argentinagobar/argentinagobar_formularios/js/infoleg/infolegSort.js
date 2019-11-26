(function ($) {
  Drupal.behaviors.listjs = {
    attach: function(context) {


      $('#listado-infoleg-lista tbody').addClass('list');

      var listadoInfolegListConfig = {
        valueNames: ['numero', 'fecha', 'descripcion','titulo'],

      }

      var listadoInfolegList = new List('normas', listadoInfolegListConfig)
      listadoInfolegList.sort('numero','descripcion','titulo')

		}
	}
})(jQuery);
