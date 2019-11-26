<section>
  <article class="container content_format">
  <?php if(!empty($content['header_full'])){ ?>
    <?php print $content['header_full']; ?>
  <?php } ?>
    <?php if(!empty($content['content'])){ ?>
    <div class="col-md-8 col-md-offset-2">
      <?php print $content['content']; ?>
    </div>
    <?php } ?>
  </article>
</section>
<?php if(!empty($content['content_bottom'])){ ?>
<section>
  <div class="container">
    <?php print $content['content_bottom']; ?>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['footer'])){ ?>
<section class="bg-gray">
  <div class="container">
    <?php print $content['footer']; ?>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['footer_2'])){ ?>
<section>
  <div class="container">
    <?php print $content['footer_2']; ?>
  </div>
</section>
<?php } ?>
