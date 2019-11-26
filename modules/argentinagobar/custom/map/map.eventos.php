
<script src="js/jquery.min.js"></script>

<link rel="stylesheet" href="css/bootstrap.min.css" >
<script src="js/bootstrap.min.js"></script>
<script src="http://maps.googleapis.com/maps/api/js?key=AIzaSyAFt8T1qY9LEY8AymnVx1Pz4xBMboeyFI0"></script>

<link rel="stylesheet" href="css/estilos.css">


<div class="col-md-4 col-sm-6 col-xs-6 col-lg-4">
	<!-- Información Punto Digital -->
	<div class="" style="background-color: white;border-radius: 4px;padding: 20px;">
		<h3 data-nombre-pd></h3>
		<p data-direccion-pd>           
		</p>
		<p data-telefono-pd style="font-weight: 600"></p>
		<a data-email-pd href="mailto:palpala@puntodigital.gob.ar"></a>
	</div>
	<!-- Mapa -->
	<div class="" style="background-color: white; text-align: center;">
        <div class="col-md-8">
            <div id="map-canvas" style='width:400px;height:500px'></div>
        </div>
    </div>
</div>
<div class="col-md-8 col-sm-6 col-xs-6 col-lg-8" style="background-color: white;padding: 20px;">
	<!-- Imagen cabecera -->
	<img data-imagen-pd class="img-responsive" src="http://186.33.211.56/poncho/sites/default/files/pd-cabecera-interior.jpg">
    <table class="table table-striped table-hover table-condensed table-responsive">
	    <thead>
		    <tr>
			    <th colspan="3">
				    <h4><small data-lapso-fechas-eventos style="font-weight: 600;"></small></h4>
			    </th>
		    </tr>
	    </thead>
	    <tbody id="tblEventos">
		    <tr>
			    <td>
				    martes
			    </td>
			    <td>&nbsp;</td>
			    <td>
				    22 de noviembre de 2016
			    </td>
		    </tr>
		    <tr>
			    <td>9:00 - 13:00</td>
			    <td>
				    <a data-toggle="modal" data-target="#myModal">Python 3 — Paso a paso</a>
			    </td>
			    <td>&nbsp;</td>
		    </tr>
		    <tr>
			    <td>
				    jueves

			    </td>
			    <td>&nbsp;</td>
			    <td>
				    24 de noviembre de 2016
			    </td>
		    </tr>
		    <tr>
			    <td>9:00 - 13:00</td>
			    <td>Python 3 — Paso a paso</td>
			    <td>&nbsp;</td>
		    </tr>
		    <tr>
			    <td>&nbsp;</td>
			    <td>&nbsp;</td>
			    <td>&nbsp;</td>
		    </tr>
	    </tbody>
    </table>
<!-- 
	////////////////////////
	/Calendario
	////////////////////////
-->
</div>




<!-- Modal -->
<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header" style="border: 0;padding-bottom: 0;">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>
            </div>

            <div class="modal-body" style="padding-bottom: 0;padding-top: 0;">
                <article class="content_format col-md-12">
                    <h1 data-evento-titulo></h1>
                    <hr>
                    <p data-evento-resumen></p>
                    <!--
                    <figure data-evento-img>
                        <img class="img-responsive img-full" src="#">
                    </figure>
                    -->
                    <p style="margin-bottom:5px; margin-top:10px; font-weight:bold">
                        Espacio de Capacitación                                            
                    </p>
                    <ul data-ul-evento-detalles>
                    </ul>
                    <blockquote data-evento-descripcion>
                    </blockquote>                            
                </article>  
            </div>
            <div class="modal-footer" style="border-top: 0;">
                <button type="button" class="btn btn-secondary" data-dismiss="modal">Cerrar</button>
            </div>
                </div>
    </div>
</div>




<script>
var map;
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

function initialize(pd) {
    var myLatlng = new google.maps.LatLng(pd.lat, pd.long);
    var options = {
        center: myLatlng,
        zoom: 17,
        mapTypeControl: true,
        mapTypeControlOptions: {
            style: google.maps.MapTypeControlStyle.HORIZONTAL_BAR,
            position: google.maps.ControlPosition.BOTTOM_LEFT
        },
    };

    var div = document.getElementById('map-canvas');
    map = new google.maps.Map(div, options);

    icon = "img/nac.svg";
    
    new google.maps.Marker({
        position: new google.maps.LatLng(
            pd.lat, pd.long
        ),
        map: map,
        icon: icon 
    });
    
    
}


$(function(){

    <?php
    if (!isset($_GET["id"]) || empty($_GET["id"])) {?> 
        window.close();
    <?php
    } ?>

    
    $.post(
        "https://servicios.puntodigital.paisdigital.modernizacion.gob.ar/ws/ws-eventos.php", 
        {nac_id : "<?php echo $_GET["id"]?>"}, 
        function(data){
            pd = data.aPD;
            initialize(pd);
            
            $("h3[data-nombre-pd]").text("Punto Digital " + pd.nombre);
            $("p[data-direccion-pd]").html(
                pd.calle + "<br>" + pd.provincia + "<br>" + pd.localidad
            );
            $("p[data-telefono-pd").text(pd.telefono);
            $("a[data-email-pd")
                .attr("href", "mailto:"+pd.email)            
                .text(pd.email)
            ;
            /*
            $img = $("img[data-imagen-pd]");
            if (pd.imagen != null)
                $img.attr("href", pd.imagen).show();
            else
                $img.hide();
            */

            oFechaInicio = new Date(data.aLapsoFechas.fecha_inicio);
            lblFechaInicio = oFechaInicio.getDate() + " de " + monthNames[oFechaInicio.getMonth()] + " de " + oFechaInicio.getFullYear();
            
            oFechaFin = new Date(data.aLapsoFechas.fecha_fin);
            lblFechaFin = oFechaFin.getDate() + " de " + monthNames[oFechaFin.getMonth()] + " de " + oFechaFin.getFullYear();

            $("small[data-lapso-fechas-eventos]").text(lblFechaInicio + " / " + lblFechaFin);

            aEventos = data.aEventos;
            
            $tbl = $("#tblEventos");
            $tbl.find("tr").remove();

            for (fecha in aEventos) {
                allEventosFecha = aEventos[fecha];

                oFecha = new Date(fecha);
                lblFechaDia = weekDays[oFecha.getDay()];
                lblFechaEvento = oFecha.getDate() + " de " + monthNames[oFecha.getMonth()] + " de " + oFecha.getFullYear();

                $trFecha = $("<tr>");
                $tdDia = $("<td>").text(lblFechaDia);
                $tdBlank = $("<td>").html('&nbsp;');
                $tdFecha = $("<td>").text(lblFechaEvento);

                $trFecha.append($tdDia).append($("<td>")).append($tdFecha);
                $trFecha.css("background-color", "#f9f9f9");
                $tbl.append($trFecha);

                for (i = 0; i < allEventosFecha.length; i++) {
                    evento = allEventosFecha[i];
                    $trEvento = $("<tr style='background-color:#FFFFFF !IMPORTANT'>");
                
                    hInicio = evento.duracion_inicio.substr(0, 5);
                    hFin = evento.duracion_fin.substr(0, 5);
                    $tdHorario = $("<td>").text(hInicio + " - "+ hFin);
                    $tdNombre = $("<td>").html("<a style='cursor:pointer;' data-event-modal='"+evento.id+"'>" + evento.nombre + "</a>");

                    $trEvento.append($tdHorario).append($tdNombre).append($("<td>"));

                    $tbl.append($trEvento);
                }
            }


        },
        "json"
    );

    $(document).on("click", "a[data-event-modal]", function(){
        $.post(
            "https://servicios.puntodigital.paisdigital.modernizacion.gob.ar/ws/ws-eventos.php", 
            {
                nac_id : "<?php echo $_GET["id"]?>",
                method : "getEventoById",
                eventoID : $(this).attr("data-event-modal")
            }, 
            function(data){
                aEvento = data.aEvento;
                datos = JSON.parse(aEvento.datos);

                lblDias = [];
                if (datos.lun == "1") 
                    lblDias.push("Lunes");

                if (datos.mar == "1") 
                    lblDias.push("Martes");

                if (datos.mie == "1") 
                    lblDias.push("Miercoles");

                if (datos.jue == "1") 
                    lblDias.push("Jueves");

                if (datos.vie == "1") 
                    lblDias.push("Viernes");

                if (datos.sab == "1") 
                    lblDias.push("Sábados");

                if (datos.dom == "1") 
                    lblDias.push("Domingos");
                
                lblDias = lblDias.join(" , ");

                oFechaInicio = new Date(aEvento.fecha_desde);
                lblInicia = weekDays[oFechaInicio.getDay()];
                lblInicia = oFechaInicio.getDate() + " de " + monthNames[oFechaInicio.getMonth()] + " de " + oFechaInicio.getFullYear();

                oFechaFin = new Date(aEvento.fecha_hasta);
                lblFinaliza = weekDays[oFechaFin.getDay()];
                lblFinaliza = oFechaFin.getDate() + " de " + monthNames[oFechaFin.getMonth()] + " de " + oFechaFin.getFullYear();

                $("h1[data-evento-titulo]").html(datos.nombre);
                $("p[data-evento-resumen]").html(datos.resumen);
                $("blockquote[data-evento-descripcion]").html(datos.descripcion);

                $ul = $("ul[data-ul-evento-detalles]");
                $ul.empty();    

                $ul.append("<li>Dias: " + lblDias + "</li>");
                $ul.append("<li>Duración: " + aEvento.duracion + "</li>");
                $ul.append("<li>Inicia: " + lblInicia + "</li>");
                $ul.append("<li>Finaliza: " + lblFinaliza + "</li>");
                $ul.append("<li>Cantidad de clases: " + aEvento.cant_clases + "</li>");
                $ul.append("<li>Tiempo por cursada: " + aEvento.tiempo_cursada + "</li>");
                $ul.append("<li>Cantidad de horas: " + aEvento.total_horas + "</li>");

                $("#myModal").modal("show");

            }, "json"
        );


    });
});
</script>

