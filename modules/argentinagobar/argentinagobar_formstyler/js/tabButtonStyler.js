(function ($) {
  Drupal.behaviors.tabButtonStyler = {
    attach: function (context) {

	var tabBtn = jQuery(".tab_buttons").parent().prev();
	tabBtn.removeClass().addClass("btn-group btn-group-justified");
	tabBtn.attr("style","display:table; padding:0;");
	tabBtn.find('li').attr("style","display:table-cell");
	tabBtn.find("li a").addClass("btn btn-default").attr("style","width:100%");

},
    detach: function (context) {}
  };
}(jQuery));