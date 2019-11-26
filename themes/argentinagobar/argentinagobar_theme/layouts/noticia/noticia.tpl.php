<article>
  <?php
  if(!empty($content['header_full']) || !empty($content['header_left']) || !empty($content['header_right'])){ ?>
  <header>
    <?php if(!empty($content['header_full'])){ ?>
      <?php print $content['header_full']; ?>
    <?php } ?>
    <div class="container">
      <div class="row">
        <div class="col-sm-6">
          <?php if(!empty($content['header_left'])){ ?>
            <?php print $content['header_left']; ?>
          <?php } ?>
        </div>
        <div class="col-sm-6">
          <?php if(!empty($content['header_right'])){ ?>
            <?php print $content['header_right']; ?>
          <?php } ?>
        </div>
      </div>
    </div>
  </header>
<?php } ?>
<?php if(!empty($content['content'])){ ?>
  <section class="content_format">
    <div class="container">
      <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <?php print $content['content']; ?>
        </div>
      </div>
    </div>
  </section>
<?php } ?>
</article>
<?php if(!empty($content['footer'])){ ?>
<section class="container">
  <div class="row">
    <div class="col-md-12">
        <?php print $content['footer']; ?>
    </div>
  </div>
</section>
<?php } ?>