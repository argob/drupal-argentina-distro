(function ($) {
  Drupal.behaviors.parcheRelevamiento = {
    attach: function (context) {

	// primero se hace click en la pestania de relevamiento
	jQuery('li.horizontal-tab-button.horizontal-tab-button-1.last').find('a').click();
	// luego se oculta la pestania de general
	jQuery('li.horizontal-tab-button.horizontal-tab-button-0.first').hide();
},
    detach: function (context) {}
  };
}(jQuery));