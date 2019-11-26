<div class="panel panel-default panel-disabled">
    <div class="panel-body"> 
        <div class="row m-y-2">  
            <div class="col-md-12">
                <h3 class="h2 m-y-1">Datos del reclamo N° <?php print $ticket['id']; ?></h3>
            </div>   
            <div class="col-md-6">
                <label class="control-label">Proveedor o proveedores </label> 
                <p><?php print $ticket['proveedores']; ?></p>
                <label class="control-label">Estado del reclamo </label>
                <p><?php print $ticket['name']; ?></p>
            </div>
             <div class="col-md-6">
                <label class="control-label">Fecha de inicio </label> 
                <p><?php print $ticket['finicio']; ?></p>
                <?php if (!empty($ticket['resolucion'])) { ?>
                    <label class="control-label">Fecha de resolución </label> 
                    <p><?php print $ticket['resolucion']; ?></p>
                <?php } ?>
            </div>
        </div>
    </div>
</div>
<?php if (!empty($datos['direccion']) || !empty($datos['mails']) || !empty($datos['telefono']) || !empty($datos['horario'])) { ?>
    <div class="panel panel-default panel-disabled">
        <div class="panel-body"> 
            <div class="row m-b-2">  
                <div class="col-md-12">
                    <h3 class="h2 m-y-1">Datos de la oficina a la que se derivó tu reclamo</h3>

                    <?php if (!empty($datos['direccion'])) { ?>
                        <label class="control-label">Dirección</label>
                        <p><?php print $datos['direccion']; ?></p>
                    <?php } ?>

                    <?php if (!empty($datos['mails'])) { ?>
                        <label class="control-label">Correo electrónico</label>
                        <p><?php print $datos['mails']; ?></p>
                    <?php } ?>

                    <?php if (!empty($datos['telefono'])) { ?>
                        <label class="control-label">Teléfono</label>
                        <p><?php print $datos['telefono']; ?></p>
                    <?php } ?>

                    <?php if (!empty($datos['horario'])) { ?>
                        <label class="control-label">Horario de atención</label>
                        <p><?php print $datos['horario']; ?></p>
                    <?php } ?>

                </div>   
            </div>
        </div>
    </div>
<?php } ?>
<hr class="hr-lg"><div class="row">
    <div class="col-md-12 ">
        <div class="alert alert-success text-center">
            <h3 class="">Seguí el estado del reclamo</h3>
            <p>Ingresando con tu cuenta de <strong>Argentina.gob.ar</strong> podes ver el estado del reclamo en cualquier momento, y recibir notificaciones cuando haya actualizaciones.</p>
            <div class="m-t-2 m-b-1">
                <a class="btn btn-success" href="https://id.argentina.gob.ar"><span class="fa fa-user fa-fw"></span> Ingresar</a>
            </div>
        </div>
    </div>
</div>

<div class="col-md-12">
    <p class="m-t-3 m-b-1 text-center">
        <a id="otraConsulta" style="cursor:pointer;" class="btn btn-primary btn-block">Hacer otra consulta</a>
    </p>
</div>
