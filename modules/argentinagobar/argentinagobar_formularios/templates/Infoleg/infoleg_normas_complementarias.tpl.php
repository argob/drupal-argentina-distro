<?php global $base_url ?>
<?= $breadcrumb; ?>

<section>
  <div class="row">
    <div class="col-md-12">

      <div class="m-t-2">
      <?php foreach ($norma['idNormas'] as  $conjunta): ?>
        <?php if(isset($norma['provincia'])): ?>
              <div class="label label-default"><?= $norma['provincia'] ?></div>
        <?php endif ?>
        <h1 class="h5 m-b-0"> <?= $conjunta['titulo'] . ' ' . $conjunta['ramaDigesto'] ?></h1>
        <p class="lead m-b-0"><small><?= $norma['estado'] ?></small></p>
        <p class="lead m-b-0"><small><?= $conjunta['dependencia'] ?></small></p>
      <?php endforeach ?>
        <time class="text-muted"><strong><?= date('d-m-Y', strtotime($norma['sancion'])) ?></strong></time>
      </div>

      <div class="m-y-2" id="normas">
        <table class="table table-spaced table-striped table-mobile">
          <thead>
            <tr>
              <th><a class="sort" style="min-width:220px" data-sort="numero">Normativa / Número <span class="caret"></span></a></th>
              <th style="min-width: 180px;"><a class="sort" data-sort="fecha">Fecha publicación <span class="caret"></span></a></th>
              <th><a class="sort" data-sort="descripcion">Descripción <span class="caret"></span></a></th>
            </tr>
          </thead>
          <tbody class="list">

            <!-- Normas Complementarias Nacionales -->
            <?php if (isset($normasComplementariasNac)): ?>
              <?php foreach ($normasComplementariasNac as $normaComplementaria): ?>

               <tr>
                 <td class="numero">
                     <span class="td-label">Normativa / Número</span>
                     <?php foreach ($normaComplementaria['idNormas'] as $key => $value) : ?>
                       <a href="<?= $url = (bool) strpos($normaComplementaria['url'], 'S/N') ? str_replace('S/N', 'S-N', $normaComplementaria['url']) :  $normaComplementaria['url'] ?>"><?= $normaComplementaria['idNormas'][$key]['titulo'] ?></a></h6>
                       <p>
                         <?= $normaComplementaria['idNormas'][$key]['dependencia'] ?>
                       </p>


                     <?php endforeach ?>
                 </td>
                 <td class="fecha">
                     <span class="td-label">Fecha publicación</span>
                     <?php if (isset($normaComplementaria['publicacion'])): ?>
                       <?= format_date(intval(strtotime($normaComplementaria['publicacion'])), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
                     <?php endif; ?>
                 </td>
                 <td class="descripcion">
                     <span class="td-label">Descripción</span>
                     <h6><?= $normaComplementaria['tituloResumido'] ?></h6>
                     <p>
                       <?= $normaComplementaria['textoResumido'] ?>
                     </p>
                     <p>
                       <?= $normaComplementaria['estado'] ?>
                     </p>
                 </td>
               </tr>
              <?php endforeach; ?>
             <?php endif; ?>


            <!-- Normas Complementarias Provinciales sin uuid o UrlApi -->
            <?php if (isset($normasComplementariasSinID)): ?>

              <?php foreach ($normasComplementariasSinID as $normaComplementariaSinID): ?>
                <tr>
                  <td>
                    <span class="td-label">Efecto sobre Ley</span>
                    <h3 class="h5 m-b-0">Efecto sobre la norma</h3>
                    <p class="lead m-b-0">
                    <?= str_replace('_', ' ', $normaComplementariaSinID['agrupacion'])?>
                    </p>
                  </td>
                </tr>

                <?php for ($i=0; $i<count($normaComplementariaSinID['groupeddata']); $i++):?>

                <tr>
                  <td class="numero">
                      <span class="td-label">Normativa / Número</span>
                      <?= $normaComplementariaSinID['groupeddata'][$i]['titulo']?></a>
                  </td>
                  <td class="fecha">
                      <span class="td-label">Fecha publicación</span>
                      <?php if (isset($normaComplementariaSinID['groupeddata'][$i]['fecha'])): ?>
                        <?= format_date(intval(strtotime($normaComplementariaSinID['groupeddata'][$i]['fecha'])), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
                      <?php endif; ?>
                  </td>
                  <td class="descripcion">
                      <span class="td-label">Descripción</span>
                      <h6><?= $normaComplementariaSinID['groupeddata'][$i]['descripcion'] ?></h6>
                      <?php if (isset($normaComplementariaSinID['groupeddata'][$i]['provincia'])): ?>
                        <h6><?= $normaComplementariaSinID['groupeddata'][$i]['provincia'] ?></h6>
                      <?php endif; ?>
                  </td>
                </tr>

                <?php endfor ?>

              <?php endforeach ?>

            <?php endif; ?>

            <!-- Normas Complementarias Provinciales con uuid o UrlApi -->
            <?php if (isset($normasComplementarias)): ?>

              <?php foreach ($normasComplementarias as $normaComplementaria): ?>

                <tr>
                  <td>
                    <!-- <span class="td-label">Efecto sobre Ley</span> -->
                    <h3 class="h5 m-b-0">Efecto sobre la norma </h3>
                    <p class="lead m-b-0">
                    <?= str_replace('_', ' ', $normaComplementaria['agrupacion'])?>
                    </p>
                  </td>
                </tr>

                <?php for ($i=0; $i<count($normaComplementaria['groupeddata']); $i++):?>
                  <tr>
                    <td class="numero">
                        <span class="td-label">Normativa / Número</span>

                        <?php if($normaComplementaria['groupeddata'][$i]['idNormas'][0]['titulo'] == 'Ley  0'): ?>
                          <h6> <a href="<?= $normaComplementaria['groupeddata'][$i]['url'] ?>">S/N</a></h6>
                          <p>
                            <?= $normaComplementaria['groupeddata'][$i]['idNormas'][0]['dependencia'] ?>
                          </p>
                        <?php else: ?>
                          <h6> <a href="<?= $normaComplementaria['groupeddata'][$i]['url'] ?>"><?= $normaComplementaria['groupeddata'][$i]['idNormas'][0]['titulo'] ?></a></h6>
                          <p>
                            <?= $normaComplementaria['groupeddata'][$i]['idNormas'][0]['dependencia'] ?>
                          </p>
                        <?php endif; ?>
                    </td>
                    <td class="fecha">
                        <span class="td-label">Fecha publicación</span>
                        <?php if (isset($normaComplementaria['groupeddata'][$i]['publicacion'])): ?>
                          <?= format_date(intval(strtotime($normaComplementaria['groupeddata'][$i]['publicacion'])), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
                        <?php endif; ?>
                    </td>
                    <td class="descripcion">
                        <span class="td-label">Descripción</span>
                        <h6><?= $normaComplementaria['groupeddata'][$i]['tituloResumido'] ?></h6>
                        <p>
                          <?= $normaComplementaria['groupeddata'][$i]['textoResumido'] ?>
                        </p>
                        <p>
                          <?= $normaComplementaria['groupeddata'][$i]['estado'] ?>
                        </p>
                    </td>
                  </tr>
                <?php endfor ?>

              <?php endforeach; ?>

            <?php endif; ?>
          </tbody>
        </table>
      </div>
        <a href="<?= $url = (bool) strpos($norma['url'], 'S/N') ? str_replace('S/N', 'S-N', $norma['url']) :  $norma['url'] ?>" class="btn btn-default">Volver</a>
    </div>
  </div>
</section>
