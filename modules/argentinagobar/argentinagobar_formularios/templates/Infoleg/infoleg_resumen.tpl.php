<?php global $base_url; ?>

<?= $breadcrumb; ?>

<section>
    <div class="row">
        <div class="col-md-12">
            <div class="m-t-2">
              <?php foreach ($norma['idNormas'] as  $conjunta): ?>
                  <?php if(isset($norma['provincia'])): ?>
                      <div class="label label-default"><?= $norma['provincia'] ?></div>
                  <?php endif ?>
                <h1 class="h5 m-b-0"> <?= $titulo = $conjunta['titulo'] == 'Ley  0' ? 'S/N' : $conjunta['titulo'] . ' ' . $conjunta['ramaDigesto'] ?></h1>
                <p class="lead m-b-0"><small><?= $conjunta['dependencia'] ?></small></p>
                <p class="lead m-b-0"><small><?= $norma['estado'] ?></small></p>
              <?php endforeach ?>
            </div>
            <hr>
        </div>

        <div class="col-md-8">
            <article>

                <h1 class="h3"><?= $norma['tituloSumario'] ?></h1>
                <h2 class="h5"><?= $norma['tituloResumido'] ?></h2>

                <div>
                    Fecha de sanción <time class="text-muted"><strong><?= date('d-m-Y', strtotime($norma['sancion'])) ?></strong></time>
                </div>

              <?php if (isset($norma['publicacion'])): ?>
                  <div>Publicada en el Boletín <?= ucfirst($norma['jurisdiccion']) ?> del
                        <?= format_date(strtotime($norma['publicacion']), 'custom', 'd-M-Y', "America/Argentina/Buenos_Aires", NULL) ?>
                  </div>
              <?php endif ?>

                <div class="m-y-4">

                  <?php if(isset($norma['textoResumido']) && !empty($norma['textoResumido'])): ?>
                      <h5>Resumen:</h5>
                      <p><?= $norma['textoResumido'] ?></p>
                  <?php endif; ?>

                  <?php if(isset($norma['observaciones']) && !empty($norma['observaciones'])): ?>
                      <h5>Observaciones:</h5>
                      <p><?= $norma['observaciones'] ?></p>
                  <?php endif; ?>
                </div>

              <?php if (isset($norma['textoNorma'])): ?>
                  <div class="m-b-1">
                      <a href="<?= $url = (bool) strpos($norma['url'], 'S/N') ? str_replace('S/N', 'S-N', $norma['url'] . '/texto') :  $norma['url']  . '/texto' ?>"class="btn btn-link">Texto completo de la norma</a>
                  </div>
              <?php endif ?>

              <?php if (isset($norma['textoNormaAct'])): ?>
                  <div class="m-b-1">
                      <a href="<?= $norma['url'] . '/actualizacion' ?>" class="btn btn-success">Texto actualizado de la norma</a>
                  </div>
              <?php endif ?>
            </article>
        </div>

      <?php if ($cantidadNormasComplementa > 0 || $cantidadNormasQueLaComplementan > 0): ?>
          <div class="col-md-4">
          <h3 class="h5">Normas complementarias</h3>
          <ul class="list-inline">

        <?php if ($cantidadNormasComplementa > 0): ?>
              <li>
                  <div class="media">
                      <div class="media-left">
            <span class="fa-stack">
              <i class="fa fa-square-o fa-stack-2x text-muted"></i>
              <i class="fa fa-long-arrow-right fa-stack-1x text-muted"></i>
            </span>
                      </div>
                      <div class="media-body">
                        <p><a href="<?= $url = (bool) strpos($norma['url'], 'S/N') ? str_replace('S/N', 'S-N', $norma['url']. '/normas-modificadas') :  $norma['url']  . '/normas-modificadas' ?>">Esta norma modifica o complementa a <?= format_plural($cantidadNormasComplementa, '1 norma', '@count normas'); ?> </a></p>
                      </div>
                  </div>
              </li>
        <?php endif ?>

        <?php if ($cantidadNormasQueLaComplementan > 0): ?>
              <li>
                  <div class="media">
                      <div class="media-left">
            <span class="fa-stack">
              <i class="fa fa-square-o fa-stack-2x text-muted"></i>
              <i class="fa fa-long-arrow-left fa-stack-1x text-muted"></i>
            </span>
                      </div>
                      <div class="media-body">
                          <p><a href="<?= $url = (bool) strpos($norma['url'], 'S/N') ? str_replace('S/N', 'S-N', $norma['url']. '/normas-modifican') :  $norma['url']  . '/normas-modifican' ?>">Esta norma es complementada o modificada por <?= format_plural($cantidadNormasQueLaComplementan, '1 norma', '@count normas'); ?> </a></p>

                      </div>
                  </div>
              </li>
        <?php endif ?>

      <?php else: ?>
          <div class="col-md-4">
              <h3 class="h5">Normas complementarias</h3>
              <p>Esta norma no complementa ni es complementada por otras normas.</p>
          </div>

          </ul>
          </div>
      <?php endif; ?>
    </div>
</section>
