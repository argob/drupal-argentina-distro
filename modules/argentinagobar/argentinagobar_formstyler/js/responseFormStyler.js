function style(){
	jQuery(".responseFormStyler").parent().removeClass().addClass('panel-disabled margin-60');
	jQuery(".responseFormStyler .panel-body").removeClass('panel-body');
	jQuery(".responseFormStyler").removeClass().addClass('panel-body');

	jQuery("fieldset").removeClass('panel panel-default');

}

jQuery(document).ready(function () {
	style();
});

jQuery(document).ajaxComplete(function() {
	style();
});