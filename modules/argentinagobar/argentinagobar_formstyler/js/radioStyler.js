function radioStyle(){

	jQuery( ".radioStyler.form-radios" ).each(function( index ) {
	  if(jQuery( this ).find(".control-label").length > 2){
	  	//Restyle radios cuando son más de 2
	  	jQuery( this ).find(".control-label").find("input[type=radio]").css('display','none');

	  	jQuery( this ).find(".control-label").unwrap().removeClass().addClass("btn btn-default").css('width','48%').css('marginLeft','2%').css('borderRight','none');
	  	
	  	jQuery( this ).removeClass().addClass("btn-group btn-group-justified").attr("data-toggle","buttons");
	  	
	  	var lis = jQuery( this ).find(".btn");
	  	jQuery( this ).find(".btn").each(function( index, element ) {
	  		if (index % 2 === 0) { 
	  			lis.slice(index, index+2).wrapAll("<div></div>");
	  		}
	  	});

	  }else{
		//Restyle radios cuando son 2

		jQuery( this ).find(".control-label").unwrap().removeClass().addClass("btn btn-default");

		jQuery( this ).find(".btn.btn-default").each(function( index, element ) {
			if(jQuery( this ).find('input').attr('checked')=='checked'){
				jQuery( this ).addClass("active");
			}
		});


		jQuery( this ).removeClass().addClass("btn-group btn-group-justified").attr("data-toggle","buttons");

	  }

	});
	
}

jQuery(document).ready(function () {
	radioStyle();
});

jQuery(document).ajaxComplete(function() {
	radioStyle();
});