(function ($) {
	Drupal.behaviors.disable = {
		attach: function (context) {

			CKEDITOR.on('instanceReady', function(ev) {

				var editor = CKEDITOR.instances["edit-texto-value"];

				if(jQuery('#edit-sobreescribir').is(':checked')){
					editor.setReadOnly(false);
				}else{
					editor.setReadOnly(true);
				}

				jQuery('#edit-sobreescribir').change(function(e){

					if(editor.readOnly==true){
						editor.setReadOnly(false);
					}else{
						editor.setReadOnly(true);
					}

				});
			});

		},
		detach: function (context) {}
	};
}(jQuery));