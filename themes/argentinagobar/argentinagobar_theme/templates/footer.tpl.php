<footer class="main-footer">
  <div class="container">
    <section>
    <div class="row">
      <div class="col-sm-6 col-sm-12">
        <section class="block block-block clearfix">
          <?php if ($logo) : ?>
            <img class="image-responsive" src="<?=$logo?>" alt="<?=t('Argentina.gob.ar - Presidencia de la Nación')?>" />
          <?php endif; ?>
          <p class="text-muted small m-b-2">
            <?= l("Los contenidos de Argentina.gob.ar están licenciados bajo Creative Commons Atribución 4.0 Internacional","https://creativecommons.org/licenses/by/4.0/deed.es", array('attributes' => array('target'=>'_blank'))); ?>
          </p>
        </section>
        <?php if (!empty($page['footer1'])): ?>
          <?=render($page['footer1']) ?>
        <?php endif; ?>
      </div>
      <div class="col-md-3 col-sm-6">
          <?php if (!empty($page['footer2'])): ?>
            <?=render($page['footer2'])?>
          <?php endif; ?>
      </div>
      <div class="col-md-3 col-sm-6">
          <?php if (!empty($page['footer3'])): ?>
            <?php print render($page['footer3']); ?>
          <?php endif; ?>
      </div>
    </div>
  </section>
  </div>
</footer>
