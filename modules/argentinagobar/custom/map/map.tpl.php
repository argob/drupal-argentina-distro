<div class="col-md-12" id="map-canvas">
    <div class="col-md-4">
        <input id="myInput" onkeyup="searchPD()" placeholder="Buscá tu Punto Digital" type="text" title="buscá tu punto digital">
        <ul id="myUL">
        </ul>
    </div>
    <div class="hidden" style="z-index: 1;" id="eventosContent">
	    <table class="table table-bordered table-responsive" id="tblPDInfo">
		    <thead>
			    <tr>
				    <th style="background-color: #0072bc;border: 1px solid #0072bc;color: white;">Centro Municipal</th>
			    </tr>
		    </thead>
		    <tbody>
		    </tbody>
	    </table>
	    <table class="table table-bordered table-responsive" id="tblPDEventos">
		    <thead>
			    <tr>
				    <th colspan="2" style="background-color: #0072bc;border: 1px solid #0072bc;color:white;">Actividades</th>
			    </tr>
		    </thead>
		    <tbody id="bodyEvents">
		    </tbody>
	    </table>
	    <button id="cerrar" type="button" class="btn btn-primary">Cerrar</button>
    </div>
    <div class="col-md-8" id="mapaContent">
        <div id="ref-pd">
	        <img src="<?php echo base_path() . path_to_theme()?>/img/icono-activo.svg" width="18px">
	        <p class="color-activo"> Activos</p>
	        <img src="<?php echo base_path() . path_to_theme()?>/img/icono-prox.svg" width="18px">
	        <p class="color-prox"> Próximamente</p>	
	        <img src="<?php echo base_path() . path_to_theme()?>/img/icono-cerrado.svg" width="18px">
	        <p class="color-cerrado"> Temp. cerrados</p>
        </div>
      <div id="map" style="width:auto;height:508px"></div>
        <div class="col-md-12 downMap">       
            <a href="https://servicios.puntodigital.paisdigital.modernizacion.gob.ar/ws/ws-eventos.php?method=getCsv">Descargá la información de los PD</a>
        </div>
    </div>  
</div>


<script>
var map;
var aMarkers = {};
var $tblPDInfo = jQuery("#tblPDInfo");
var $tblPDEventos = jQuery("#tblPDEventos");

var monthNames = [
  "Enero", "Febrero", "Marzo",
  "Abril", "Mayo", "Junio", "Julio",
  "Agosto", "Septiembre", "Octubre",
  "Noviembre", "Diciembre"
];

var weekDays = [
    "Domingo",
    "Lunes",
    "Martes",
    "Miercoles",
    "Jueves",
    "Viernes",
    "Sábado"
];

var aDiasPD = {
    "1" : "Lunes",
    "2" : "Martes",
    "3" : "Miercoles",
    "4" : "Jueves",
    "5" : "Viernes",
    "6" : "Sábado",
    "7" : "Domingo",
};

var oInfoDiv = 
    '<div id="info-nac" class="infowindow-nac" >'
       + '<div class="datos-nac">'
       +    '<h1 class="nac" data-tituloNac></h1>'
       +     '<p class="direccion-nac">'
       +         '<div data-institucionNac></div>'
       +         '<div data-calleNac></div>'
       +         '<div style="text-transform: capitalize;" data-localidadNac></div>'
       +    '</p>'
       +    '<p class="contacto-nac">'
       +         '<strong data-emailNac></strong>'
       +         '<div data-facebook></div>'
       +     '</p>'
       +     '<div style="margin-top:10px;">'
       +        '<table class="head-horarios table table-striped table-responsive" data-content-horarios>'
       +            '<thead><tr><th>Día</th><th>Horario</th></tr></thead>'
	   +		'</table>'
       +     '</div>'
       + '</div>'
   + '</div>'
;

function setList() {    
    $ul = jQuery("#myUL");
    indice = 0;
    for (var provincia in aPDs) {
        $li = jQuery("<li>").append("<a class='header'>"+provincia+"</a>");
        $ul.append($li);
        for(var iNac in aPDs[provincia]) { 
            nac = aPDs[provincia][iNac];
            if (!nac["lat"] || !nac["long"]) continue;

            nombre = nac.nombre.replace("NAC ", "Punto Digital ");
	        lbl = nombre;
	        if (nac.calle != "")
                lbl+= " ("+nac.calle+") "; 

            $li = jQuery("<li data-key-marker='"+indice+"'>").append("<a>"+lbl+"</a>");
            $li.css("cursor", "pointer");
            $ul.append($li);
            indice++;
        }
    }
}

function searchPD() {
    // Declare variables
    var input, filter, ul, li, a, i;
    input = document.getElementById('myInput');
    filter = input.value.toUpperCase();
    ul = document.getElementById("myUL");
    li = ul.getElementsByTagName('li');

    // Loop through all list items, and hide those who don't match the search query
    for (i = 0; i < li.length; i++) {
        a = li[i].getElementsByTagName("a")[0];
        if (a.innerHTML.toUpperCase().indexOf(filter) > -1) {
            li[i].style.display = "";
        } else {
            li[i].style.display = "none";
        }
    }
}

jQuery(document).on("click", "li[data-key-marker]", function(){
    indice = jQuery(this).attr("data-key-marker");       
    if (indice != "" && indice != null) {
        showMarker(indice);
    }
})    

function showMarker(i) {
    aMarkers[i].fire("click");
}
var test;
function showEvents(e) {
    idPD = e.target.options.idPD;
    jQuery("#eventosDetalles").attr("data-id-pd", "").hide();


    jQuery.post(
        "https://servicios.puntodigital.paisdigital.modernizacion.gob.ar/ws/ws-eventos.php", 
        {
            nac_id :idPD,
            limit : 150
        }, 
        function(data) {            
            $tblPDInfo.find("tbody").empty();
            $tblPDEventos.find("tbody").empty();
            
            pd = data.aPD;

            if (pd.nombre != null) {
                $trNombrePD = jQuery("<tr>");
                $trNombrePD.append("<td>" + pd.nombre + "</td>");
                $tblPDInfo.append($trNombrePD);
            }

            if (pd.calle != null) {
                $trDireccionPD = jQuery("<tr>");
                $trDireccionPD.append("<td>" + pd.calle + "</td>");
                $tblPDInfo.append($trDireccionPD);
            }

            if (pd.telefono != null) {
                $trTelefonoPD = jQuery("<tr>");
                $trTelefonoPD.append("<td>" + pd.telefono + "</td>");
                $tblPDInfo.append($trTelefonoPD);
            }
    

            if (pd.email != null) {
                $trEmailPD = jQuery("<tr>");
                $aEmail = jQuery("<a>")
                    .attr("href", "mailto:"+pd.email)            
                    .text(pd.email)
                ;

                $tdEmail = jQuery("<td>");
                $tdEmail.append($aEmail);
                $trEmailPD.append($tdEmail);
                $tblPDInfo.append($trEmailPD);
            }
   
            aEventos = data.aEventos;   


            $tblPDEventos.find("tbody").removeClass();
            if (jQuery(aEventos).length > 0) {
                $tblPDEventos.find("tbody").addClass("conEventos");
                for (fecha in aEventos) {
                    allEventosFecha = aEventos[fecha];

                    oFecha = new Date(fecha + "  00:00:00 UTC -3");
                    lblFechaDia = weekDays[oFecha.getDay()];
                    lblFechaEvento = oFecha.getDate() + " de " + monthNames[oFecha.getMonth()] + " de " + oFecha.getFullYear();

                    $trFecha = jQuery('<tr style="font-weight: bold;">');
                    $tdDia = jQuery('<td style="background: #ddd;">').text(lblFechaDia);
                    $tdFecha = jQuery('<td style="background: #ddd;">').text(lblFechaEvento);

                    $trFecha.append($tdDia).append($tdFecha);
                    $trFecha.css("background-color", "#f9f9f9");
                    $tblPDEventos.append($trFecha);

                    for (i = 0; i < allEventosFecha.length; i++) {
                        evento = allEventosFecha[i];
                        $trEvento = jQuery("<tr>");
                    
                        hInicio = evento.duracion_inicio.substr(0, 5);
                        hFin = evento.duracion_fin.substr(0, 5);
                        $tdHorario = jQuery('<td style="font-weight: 600;">').text(hInicio + " - "+ hFin);
                        $tdNombre = jQuery("<td>").text(evento.nombre);

                        $trEvento.append($tdHorario).append($tdNombre);

                        $tblPDEventos.append($trEvento);
                    }
                }

                //jQuery("#eventosDetalles").attr("data-id-pd", nac_id).show();
            } else {
                $tblPDEventos.find("tbody").addClass("sinEventos");
                $tblPDEventos.find("tbody").append("<tr><td>Próximamente...</td></tr>");
            }

            if (jQuery('#eventosContent').hasClass("hidden")) {
                jQuery('#eventosContent').toggleClass('col-md-4 hidden');
                jQuery('#mapaContent').toggleClass('col-md-4 col-md-8');
      

        
                map.invalidateSize();
                map.setView(e.target.getLatLng());

          }
        },
        "json"
    );
}

jQuery(function() {

    /*
        map = L.map('map', {
            center: [-38.600, -60.436],
            zoom: 4
        });

        L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png?{foo}', {foo: 'bar'}).addTo(map);
    */


	// Mapa base actual de ArgenMap (Geoserver)
		argenmap = L.tileLayer('http://wms.ign.gob.ar/geoserver/gwc/service/tms/1.0.0/capabaseargenmap@EPSG%3A3857@png/{z}/{x}/{y}.png', {
			tms: true,
			maxZoom: 15,
			attribution: 'Mapa del <a href="http://www.ign.gob.ar">Instituto Geográfico Nacional</a>, ' +
				'capa de calles por colaboradores de &copy; <a href="http://openstreetmap.org">OpenStreetMap</a>'
		});

		//Construye el mapa
		var map = L.map('map', {
		    center: [-40, -59],
		    zoom: 4,
		    layers:[argenmap]
		});


    iMarker = 0;


    jQuery.get(
        "https://servicios.puntodigital.paisdigital.modernizacion.gob.ar/ws/ws-edificios.php", 
        "", 
        function(data){
            aPDs = data;

            for (provincia in aPDs) {
                for(i in aPDs[provincia]) {
                    nac = aPDs[provincia][i];
                    if (!nac["lat"] || !nac["long"]) continue;

                    oHtml = jQuery(oInfoDiv).clone();
                    oHtml.css({display:""});
                    
                    jQuery(oHtml)
                        .find("h1[data-tituloNac]")
                        .text(nac["nombre"].replace("NAC ", "Punto Digital "))
                    ;

                    partido = '';
                    if (nac.localidad != null)
                        partido+= nac.localidad.toLowerCase()+', ';

                    if (nac.provincia != null)
                        partido+= nac.provincia.toLowerCase();

                    jQuery(oHtml).find("div[data-institucionNac]").text(nac["institucion"].replace("NAC ", "Punto Digital "));
                    jQuery(oHtml).find("div[data-calleNac]").text(nac["calle"]);
                    jQuery(oHtml).find("div[data-localidadNac]").text(partido);
                    //jQuery(oHtml).find("strong[data-telNac]").text(nac["telefono"]);

                    if (nac["email"] != null && nac["email"] != "" ) {
                        email = nac["email"].replace("nac.gob.ar", "puntodigital.gob.ar");    
                        jQuery(oHtml).find("strong[data-emailNac]").text(email).show();
                    } else {
                        jQuery(oHtml).find("strong[data-emailNac]").text("").hide();
                    }

                    if (nac["link_facebook"] != null && nac["link_facebook"] != "" ) {
                        fb = nac["link_facebook"];
	
                        jQuery(oHtml).find("div[data-facebook]").html("<a data-link-facebook href='"+fb+"' target='_blank'><i class='fa fa-facebook-square'></i></a>").show();
                    } else {
                        jQuery(oHtml).find("div[data-facebook]").html("").hide();
                    }

                    if (nac.horario != undefined && nac.horario != "" ) {
                        aHorarios = nac.horario;
                        aHorarios = aHorarios.split("<>");
                        $tblContentHorarios = jQuery(oHtml).find("table[data-content-horarios]");
                        
                        for (i in aHorarios) {
                            aDataHorario = aHorarios[i].split(",");
                            dia = aDiasPD[aDataHorario[0]];
                            horaInicio = aDataHorario[1].substr(0, 5);
                            horaFin = aDataHorario[2].substr(0, 5);
                        
                            if ($tblContentHorarios.find("tr[data-pd-dia='"+dia+"']").length > 0) {
                                $td = jQuery($tblContentHorarios.find("tr[data-pd-dia='"+dia+"']").find("td")[1]);
			                    $td.append(" y "+horaInicio+" - "+horaFin);
                            } else {
                                $tr = jQuery("<tr data-pd-dia='"+dia+"'>");
			                    $tr.append("<td>"+dia+"</td>");
			                    $tr.append("<td>"+horaInicio+" - "+horaFin+"</td>");
                                $tblContentHorarios.append($tr);   
                            }
                        }
                    }


                    switch (nac.estado_funcionamiento) {
                        case "0":
                            icon = "icono-cerrado.svg";
                            break;
                        case "1":
                        case "2":
                            icon = "icono-activo.svg";
                            break;
                        case "3":
                            icon = "icono-prox.svg";
                            break;
                        

                    }
                    icon = "<?php echo base_path() . path_to_theme()?>/img/"+icon;

                    aMarkers[iMarker] = 
                        new L.marker(
                            [nac["lat"].replace(",","."), nac["long"].replace(",",".")], 
                            {   
                                idPD : nac.id_pd,
                                icon : new L.icon({
                                    iconUrl : icon,
                                    iconAnchor: [18, 21],
                                    popupAnchor:  [-9, -18]
                                })
                            }
                        ).bindPopup(oHtml.html())
                        .on("click", showEvents)
                        .addTo(map)
                    ;

                    iMarker++;
                }
            }

            setList();
        },
        "json"
    );

    jQuery('#cerrar').click(function() {
        jQuery('#mapaContent').toggleClass('col-md-4 col-md-8');
        jQuery('#eventosContent').toggleClass('col-md-4 hidden');
        map.invalidateSize();
    });


});

</script>


