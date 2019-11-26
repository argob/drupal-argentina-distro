(function ($) {
	Drupal.behaviors.facetapi_style = {
		attach: function(context) {
      //Agrega clases a limit link que queda contraintuitivo como un link
      jQuery('.facetapi-limit-link').each(function(){
        jQuery(this).addClass('btn btn-primary btn-sm col-md-12 margin-20');
      })

      var remove = window.location.href.split('?')[0];
      remove = remove.replace(/\/$/, "");

      jQuery("ul.facetapi-facetapi-links").addClass("nav").addClass("nav-pills").addClass("nav-stacked");

      //Agrega para todos los resultados no existe en facetapi por default y no merece un módulo para eso
      jQuery("ul.facetapi-facet-bundle").prepend("<li class=todos><a href="+remove+">Todos los resultados</a></li>");
      if(jQuery("li a.facetapi-active").length!=0){
        jQuery("li a.facetapi-active").parent().addClass("active");
      }else{
        jQuery("ul.facetapi-facet-bundle li.todos").addClass("active");
      }
		}
	};

  Drupal.applyLimit = function(settings) {
    if (settings.limit > 0 && !$('ul#' + settings.id).hasClass('facetapi-processed')) {
      // Only process this code once per page load.
      $('ul#' + settings.id).addClass('facetapi-processed');

      // Ensures our limit is zero-based, hides facets over the limit.
      var limit = settings.limit - 1;
      $('ul#' + settings.id).find('li:gt(' + limit + ')').hide();

      // Adds "Show more" / "Show fewer" links as appropriate.
      $('ul#' + settings.id).filter(function() {
        return $(this).find('li').length > settings.limit;
      }).each(function() {
        $('<a href="#" class="facetapi-limit-link"></a>').text(Drupal.t(settings.showMoreText)).click(function() {
          if ($(this).prev('ul').find('li:hidden').length > 0) {
            //$(this).siblings().find('li:gt(' + limit + ')').slideDown();
            $(this).prev('ul').find('li:gt(' + limit + ')').slideDown();
            $(this).addClass('open').text(Drupal.t(settings.showFewerText));
          }
          else {
            //$(this).siblings().find('li:gt(' + limit + ')').slideUp();
            $(this).prev('ul').find('li:gt(' + limit + ')').slideUp();
            $(this).removeClass('open').text(Drupal.t(settings.showMoreText));
          }
          return false;
        }).insertAfter($(this));
      });
    }
  }

})(jQuery);
