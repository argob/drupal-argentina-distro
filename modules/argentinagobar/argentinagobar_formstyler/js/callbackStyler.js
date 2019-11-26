/**
 * Special Effects AJAX framework command.
 */
Drupal.ajax.prototype.commands.consultaAfter =  function(ajax, response, status) {
(function ($) {
	var formConsulta = $('#'+response.data.form_id).parent().parent();

	formConsulta.removeClass('state-loading');

	// Quita los erorres marcados en el formulario
	formConsulta.find('.form-item').each(function(){
		_removeError($(this));
	});

	// Quita los erorres al escribir o hacer click en los campos
	formConsulta.find('.form-item').each(function(){

		// INPUT TEXT
		if($(this).find('input').attr('type') == 'text') {

			$(this).on('focusin', function(e) {
				var field = $(this);
				_removeError(field);
				field.find(".btn-group").each(function() { 
					$(this).find('.btn').css('borderColor', 'none'); 
				});
				field.find('div[class^="error"]').hide();
			}).on('focusout',{valor: $(this).find('input').val()}, function(e) {
				var field = $(this);
		    	if (e.data.valor == field.find('input').val()) {
		    		field.find('div[class^="error"]').show();
		    	}else{
		    		field.find('div[class^="error"]').hide();
		    	}

			});

		}

		// SELECT
		if($(this).find('select')){
			$(this).find('select').on('change', function(e){
				_removeError($(this).parent());
			})
		}

		// TEXT AREA
		if($(this).find('textarea')){
			$(this).on('focusin', function(e) {
				var field = $(this);
				_removeError(field);
				field.find(".btn-group").each(function() { 
					$(this).find('.btn').css('borderColor', 'none'); 
				});
				field.find('div[class^="error"]').hide();
			}).on('focusout',{valor: $(this).find('input').val()}, function(e) {
				var field = $(this);
		    	if (e.data.valor == field.find('input').val()) {
		    		field.find('div[class^="error"]').show();
		    	}else{
		    		field.find('div[class^="error"]').hide();
		    	}

			});
		}

		// RADIO
		if($(this).find('input')){
			$(this).on('click', function(e){
				_removeError($(this));
			})
		}
		
	});


	if (response.messages === undefined || response.messages === null || response.messages === '') {

		formConsulta.find('#test-ajax .messages').remove();
		formConsulta.find('.panel-body:first').addClass('formSelected');
		formConsulta.find('.panel-body').hide();

		formConsulta.append(response.data.respuesta);

		var formID = $('#'+response.data.form_id).attr('id');

		// Requieren paneles separados
		if (formID == 'argentinagobar-consultadc-form') {
			$('.panel-disabled.margin-60').removeClass('panel-disabled');
		}

		// Piden ocultar jumbotron en response
		if (formID == 'argentinagobar-defensaconsumidor-form') {
			//$('.alert.alert-success').hide();
			$('.jumbotron').hide();
		}

		// Comportamiento al hacer click en otra consulta
		formConsulta.find( "#otraConsulta" ).click(function() {

			if (response.data.multiple == false) {
				location.reload();
			} else {
				formConsulta.find('.responseFormatted').remove();
				$('#'+response.fid).find('#response').html('');
				formConsulta.find('.formSelected').toggle( "fast", function() {
					$('.alert.alert-success').show();
					$('.jumbotron').show();
				});
			}

		});

	} else {

		var error = 0;

		// Por cada mensaje genera el error en el campo
		$.each( response.messages, function( i, val ) {
			i = i.replace("][", "-").replace("_", "-").toLowerCase();
			var field = $('div').find('.form-item-'+i).first(); //$('[id ^=aName][id $=EditMode]') $(this).parent('div[class*=status_]') $("[id ^=aName]").add("[id $=EditMode]")

			error++;
			if (error==1 && i!='localidad'){
				$('html, body').animate({
		        	scrollTop: field.offset().top - 150
		    	}, 500);
			}

			field.addClass('has-error');
			field.append( '<div class="error-' + i + ' text-danger">' + val + '</div>' );

		});

	}

})(jQuery);
}

function _removeError(field){
	field.removeClass('has-error has-feedback');
	field.find('.form-control-feedback').remove();
	field.find('div[class^="error"]').remove();
}