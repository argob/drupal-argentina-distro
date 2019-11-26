
function jsRemoveWindowLoad() {
	// eliminamos el div que bloquea pantalla
    jQuery("#WindowLoad").remove();

}

function jsShowWindowLoad(mensaje) {
	//eliminamos si existe un div ya bloqueando
    jsRemoveWindowLoad();
   
    //si no enviamos mensaje se pondra este por defecto
    if (mensaje === undefined) mensaje = "Procesando la información<br>Espere por favor";
   
    //centrar imagen gif
    height = 20;//El div del titulo, para que se vea mas arriba (H)
    var ancho = 0;
    var alto = 0;
	
	//obtenemos el ancho y alto de la ventana de nuestro navegador, compatible con todos los navegadores
    if (window.innerWidth == undefined) ancho = window.screen.width;
    else ancho = window.innerWidth;
    if (window.innerHeight == undefined) alto = window.screen.height;
    else alto = window.innerHeight;
    
	//operación necesaria para centrar el div que muestra el mensaje
    var heightdivsito = alto/2 - parseInt(height)/2;//Se utiliza en el margen superior, para centrar
	
   //imagen que aparece mientras nuestro div es mostrado y da apariencia de cargando
    imgCentro = "<div style='text-align:center;height:" + alto + "px;'><div  style='color:#000;margin-top:" + heightdivsito + "px; font-size:20px;font-weight:bold' class='state-loading'"/* + mensaje*/ + "</div></div>";

        //creamos el div que bloquea grande------------------------------------------
        div = document.createElement("div");
        div.id = "WindowLoad"
        div.style.width = ancho + "px";
        div.style.height = alto + "px";
        jQuery("body").append(div);

        //creamos un input text para que el foco se plasme en este y el usuario no pueda escribir en nada de atras
        input = document.createElement("input");
        input.id = "focusInput";
        input.type = "text"

		//asignamos el div que bloquea
        jQuery("#WindowLoad ").append(input);
        
		//asignamos el foco y ocultamos el input text 
        jQuery("#focusInput").focus();
        jQuery("#focusInput").hide();
		
		//centramos el div del texto
        jQuery("#WindowLoad").html(imgCentro);

}

jQuery(document).ajaxComplete(function(event, xhr, settings) {
    jsRemoveWindowLoad();
});