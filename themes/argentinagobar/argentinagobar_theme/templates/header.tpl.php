<header>
  <nav class="navbar navbar-top navbar-default" role="navigation">
    <div class="container">
      <div>
        <div class="navbar-header">
          <a class="navbar-brand" href="/"  aria-label="Argentina.gob.ar Presidencia de la Nación">
            <?php if ($logo) : ?>
              <img src="<?=$logo?>" alt="<?=t('Argentina.gob.ar')?>" height="50" />
            <?php endif; ?>
            <?php if (!empty($site_name)): ?>
              <h1 class="sr-only"><?=$site_name?> <small>Presidencia de la Nación</small></h1>
            <?php endif; ?>
          </a>
            <?php if(!drupal_is_front_page()): ?>
              <a onclick="jQuery('.navbar.navbar-top').addClass('state-search');" class="btn btn-primary btn-login visible-xs" href="#" aria-labelledby="edit-keys"><span class="fa fa-search fa-fw"></span></a>
            <?php endif; ?>
            <!-- Pablo -->
            <a class="btn btn-link btn-login visible-xs" href="https://mi.argentina.gob.ar" aria-label="Ingresar a Mi Argentina"><i class="icono-arg-mi-argentina fa-fw"></i></a>
        </div>
        <?php if (!empty($page['header_right'])): ?>
          <?=render($page['header_right']); ?>
        <?php endif; ?>
      </div>
    </div>
  </nav>
</header>
