<div class="row responseFormatted">
    <div class="col-md-8 col-md-offset-2">
        <div class="text-center">
            <h1 class="text-success"><i class="fa <?php print $icono ?> fa-3x"></i></h1>
            <h1>Tu reclamo ya fue creado con el número <?php print $id_response ?></h1>
            <p>Le derivamos tu reclamo al organismo correspondiente. <br>Ellos se comunicarán con vos.</p>
            <p>Línea gratuita de orientación al consumidor 0800-666-1518.</p>
            <p><a id="otraConsulta" style="cursor:pointer;" href=<?php request_uri(); ?>>Hacer otro reclamo.</a>
            </p>
            <div class="alert alert-success m-y-4">
                <h3 class="">Seguí el estado tu reclamo</h3>
                <p>Entra a tu cuenta de <strong>Mi Argentina</strong> para seguir el estado del reclamo y tener tus datos personales actualizados para futuros trámites.</p>
                <div class="m-t-2 m-b-1">
                    <a class="btn btn-success" id="<?php print $register['id'] ?>" href="<?php print $register['url'] ?>"><span class="fa fa-user fa-fw"></span>Ingresar</a>
                </div>
            </div>
        </div>
    </div>
</div>
<script>
    jQuery('.jumbotron').hide();
    jQuery('.alert.alert-success:first').hide();
</script>
