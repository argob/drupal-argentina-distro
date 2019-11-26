Drupal.ajax.prototype.beforeSubmit = function (form_values, element, options) {
	//Si se requiere una funcionalidad al devolver respuestas

	jQuery(element).parent().parent().addClass('state-loading');

}