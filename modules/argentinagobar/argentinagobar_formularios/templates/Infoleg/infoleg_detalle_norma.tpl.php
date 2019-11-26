<?= $breadcrumb; ?>

<section>
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
          <?php foreach ($norma['idNormas'] as $conjunta) : ?>
            <h1 class="h5 m-t-2 m-b-0"><?= isset($conjunta['titulo']) ? $conjunta['titulo'] : '' . ' ' . isset($conjunta['ramaDigesto']) ? $conjunta['ramaDigesto'] : '' ?></h1>
            <p class="lead m-b-0"><small><?= isset($conjunta['dependencia']) ? $conjunta['dependencia'] : '' ?></small></p>
            <p class="lead m-b-0"><small><?= isset($norma['estado']) ? $norma['estado'] : '' ?></small></p>
          <?php endforeach ?>

          <time class="text-muted"><strong><?= isset($norma['publicacion']) ? $norma['publicacion'] : '' ?></strong></time>

          <hr>

          <article>
            <?= $texto ?>
          </article>

          <div class="m-t-4">
            <a href="<?= $url = (bool) strpos($norma['url'], 'S/N') ? str_replace('S/N', 'S-N', $norma['url']) :  $norma['url'] ?>" class="btn btn-default">Volver</a>
          </div>
        </div>
    </div>
</section>
