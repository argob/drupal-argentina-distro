(function ($) {
  Drupal.behaviors.listjs = {
    attach: function(context) {

      $('#obsequios-lista tbody, #viajes-lista tbody').addClass('list');
      $('#pasos-fronterizos-lista tbody').addClass('list');

      var viajesListConfig = {
        valueNames: ['evento','pais', 'funcionario', 'cargo', 'organismo', 'fecha', 'financiamiento'],
        pagination: true,
        page: 20,
        fuzzySearch: {
          searchClass: "search",
          location: 0,
          distance: 100,
          threshold: 0.4,
          multiSearch: true
        }
      };

      var obsequiosListConfig = {
        valueNames: ['descripcion', 'funcionario', 'cargo','organismo', 'fecha', 'valor_estimado', 'destino', 'entregado_por'],
        pagination: true,
        page: 20,
        fuzzySearch: {
          searchClass: "search",
          location: 0,
          distance: 100,
          threshold: 0.4,
          multiSearch: true
        }
      };

      var pasosFronterizosListConfig = {
        valueNames: [ 'nombre', 'provincia', 'paislimitrofe'],
        pagination: true,
        page: 20,
        fuzzySearch: {
          searchClass: "searchClass",
          location: 0,
          distance: 100,
          threshold: 0.4,
          multiSearch: true
        }
      }


      var obsequiosList = new List('edit-obsequios', obsequiosListConfig);
      var viajesList = new List('edit-viajes', viajesListConfig);
      var pasosFronterizosList = new List('pasos-fronterizos-lista', pasosFronterizosListConfig)

      $('.search').keyup(function(){
          var valueSearch = $(".search").val();
          obsequiosList.fuzzySearch(valueSearch);
          viajesList.fuzzySearch(valueSearch);

      });
      $('.searchClass').keyup(function(){
          var valueSearch = $(".searchClass").val();
          pasosFronterizosList.search(valueSearch);
      });
		}
	}
})(jQuery);
