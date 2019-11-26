(function ($) {
  Drupal.behaviors.searchInput = {
    attach: function (context) {

  if($("#block-system-main").find('div.search').length){
    $("#block-system-main").find('form').hide();
  }

  $('#block-system-main form.search-form.main-form').hide();

	//evita que determinados caracteres pasen del textbox
	$('#apachesolrsearchcustomform').submit(function(e){
		for( i=0; i < charDisabled.length ; i++ ){
			e.target[1].value = e.target[1].value.replace(new RegExp(/[<>\/\?¿\*%;]+/), '');
		}
    });

	//BUSCAR
	$('#search-form #edit-keys').keypress( function(e) {
    	if ($.inArray(e.key, charDisabled) >= 0) {
    		return false;
    	}
    });

},
    detach: function (context) {}
  };
}(jQuery));