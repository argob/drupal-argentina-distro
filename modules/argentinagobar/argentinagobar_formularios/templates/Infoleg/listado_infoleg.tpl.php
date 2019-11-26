<?php global $base_url; ?>

<div id="response">
    <div class="row">
        <div class="m-b-2"><strong><?= $cantidad ?></strong> <?= format_plural($cantidad, 'norma encontrada', 'normas encontradas'); ?> en <strong><?= $paginas; ?></strong> <?= format_plural($paginas, 'página', 'páginas'); ?></div>
        <div id="normas">
            <table class="table table-spaced table-striped table-mobile">
                <thead>
                <tr>
                    <th style="min-width: 220px;"><a class="sort" data-sort="numero"style="min-width:220px">Normativa / Número <span class="caret"></span></a></th>
                    <th style="min-width: 220px;"><a class="sort" data-sort="fecha">Fecha publicación <span class="caret"></span></a></th>
                    <th><a class="sort" data-sort="descripcion">Descripción <span class="caret"></span></a></th>
                </tr>
                </thead>
                <tbody class="list">
                <?php foreach ($items as $item): ?>
                  <tr>
                    <td class="numero">
                        <span class="td-label">Normativa / Número</span>

                        <?php foreach ($item['idNormas'] as $conjunta): ?>
                          <a href="<?= $item['url'] ?>">
                            <?php if($conjunta['titulo'] == 'Ley  0'): ?>
                              <?= 'S/N'.' ' . $conjunta['ramaDigesto'] ?>
                            <?php else: ?>
                              <?= $conjunta['titulo'] . ' ' . $conjunta['ramaDigesto'] ?>
                            <?php endif; ?>
                          </a>
                          <p><?= $conjunta['dependencia'] ?></p>

                <?php endforeach ?>

                    </td>
                    <td class="fecha">
                      <span class="td-label">Fecha publicación</span>
                        <?php if (isset($item['publicacion'])): ?>
                            <?= format_date(strtotime($item['publicacion']), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
                        <?php endif; ?>
                    </td>
                    <td class="descripcion">
                        <span class="td-label">Descripción</span>

                          <?php if(isset($item['provincia']) && $item['provincia'] != null): ?>

                              <div class="label label-default" style="display:inline-block; margin-bottom:8px"><?= $item['provincia'] ?></div>

                          <?php endif ?>

                          <?php if(isset($item['tituloSumario']) && $item['tituloSumario'] != null): ?>
                              <div><strong><?= $item['tituloSumario']; ?></strong></div>
                          <?php endif; ?>

                          <div><?= $item['tituloResumido'] ?></div>

                        <?php if ($textoResumido = mb_substr($item['textoResumido'], 0 , 120)): ?>
                          <div><?= $textoResumido . "...";?></div>
                          <div><?= $item['estado']?></div>
                        <?php endif ?>
                    </td>
                  </tr>
                <?php endforeach; ?>

                </tbody>
            </table>

            <?php
            $paginador = new Paginador(0, $offset, $paginas, 3);
            print $paginador->render();
            ?>
        </div>
    </div>
</div>
