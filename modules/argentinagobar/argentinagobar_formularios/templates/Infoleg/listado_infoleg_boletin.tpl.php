<div id="response">
    <div class="m-y-2">
        <p>
            <?php if(isset($numero)): ?>
                Sumario del Boletín Oficial Nº <?= $numero ?> <br>
            <?php else: ?>
                Sumario del Boletín Provincial <br>
            <?php endif; ?>
            Fecha de Publicación: <?= format_date(strtotime($fechaPublicacion), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
        </p>
    </div>

    <div id="normas">
        <table class="table table-spaced table-striped table-mobile">
            <thead>
            <tr>
            <th><a class="sort" data-sort="numero">Normativa / Número <span class="caret"></span></a></th>
            <th><a class="sort" data-sort="descripcion">Descripción <span class="caret"></span></a></th>
            <th style="width: 70px;">Página </th>
            </tr>
            </thead>
            <tbody class="list">
            <?php foreach ($items as $item): ?>
                <tr>

                    <td class="numero">
                        <span class="td-label">Normativa / Número</span>
                        <?php foreach ($item['idNormas'] as $conjunta) : ?>
                          <h6><a href="<?= $item['url'] ?>"><?= $conjunta['titulo'] ?></a></h6>
                          <p><?php print $conjunta['dependencia'];?> </p>
                        <?php endforeach ?>
                    </td>

                    <td class="descripcion">

                        <span class="td-label">Descripción</span>

                      <?php if($item['provincia']): ?>
                          <div class="label label-default" style="display:inline-block; margin-bottom:8px"><?= $item['provincia'] ?></div>
                      <?php endif ?>

                        <?php if(isset($item['tituloSumario']) && $item['tituloSumario'] != null): ?>
                            <div><strong><?= $item['tituloSumario']; ?></strong></div>
                        <?php endif; ?>

                        <div><?= $item['tituloResumido']; ?></div>

                    </td>

                    <td class="pagina">

                      <?php if ($item['numeroPagina'] > 0): ?>
                        <span class="td-label">Página</span>
                        <?= $item['numeroPagina'] ?>
                      <?php endif; ?>

                    </td>
                </tr>
            <?php endforeach; ?>
            </tbody>
        </table>
        <?php
            $paginador = new Paginador(0, $offset, $paginas, 3);
            print $paginador->render();
        ?>
        <?php if(isset($numero)): ?>
        <div class="m-y-2">
            <a class="btn btn-primary m-r-1" href="<?= $anterior ?>">Ver boletin del dia anterior</a>
            <?php if(!empty($siguiente)): ?>
            <a class="btn btn-primary" href="<?= $siguiente ?>">Ver boletin del dia posterior</a>
          <?php endif ?>
        </div>
        <?php endif ?>
    </div>
</div>
