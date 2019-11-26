<div class="container">
    <div class="row">
        <div class="col-md-12">
            <div class="row panels-row">
                <?php for ($i=0; $i < count($data["results"]); $i++) {
                    ?>
                    <div class="col-xs-12 col-sm-6 col-md-3">
                        <a class="panel panel-default panel-icon panel-secondary" href="<?php echo $base_url .'/'.drupal_get_path_alias() .'/'. $data['results'][$i]['id']; ?>">
                            <div style="background-image:url('<?php echo $data["results"][$i]["imagen"] ?>');" class="panel-heading">
                            </div>
                            <div class="panel-body">
                                <?php $data["results"][$i]["estado"] == "abierta" ? $st = "success" : $st = "danger"; ?>
                                <span class="label label-<?php echo $st; ?>"><?php echo $data["results"][$i]["estado"] ?></span>
                                <h3><?php echo $data["results"][$i]["titulo"]; ?></h3>
                                <p style="font-size: 12px;"><?php echo $data["results"][$i]["bajada"]; ?></p>
                                <?php
                                    /*Convertir el formato de la fecha
                                    2019-04-17 a 17 de abril de 2019*/
                                    setlocale (LC_TIME, "es_AR.utf8");
                                    $d = $data["results"][$i]["fecha_fin"];
                                    $fecha = strftime("%d de %B de %Y", strtotime($d));
                                ?>
                                <?php if ($data["results"][$i]["estado"] == "abierta") { ?>
                                       <hr style="margin: 10px 0px;">
                                       <p style="font-size: 12px;">Tenés tiempo hasta el <?php echo $fecha; ?></p>
                                <?php } ?>                                
                            </div>
                        </a>
                    </div>
                <?php } ?>

            </div>
        </div>
    </div>
</div>
<?php
    $itemsCultura = $data['results'];
    cache_set('cacheCultura',$itemsCultura);
    $paginador = new PaginadorCultura(0, $currentPage , $count_total, 20);
    print $paginador->render();
?>