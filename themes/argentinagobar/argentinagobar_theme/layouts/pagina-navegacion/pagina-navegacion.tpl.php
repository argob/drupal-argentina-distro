<?php if(!empty($content['header_full'])){ ?>
  <?php print $content['header_full']; ?>
<?php } ?>
<?php if(!empty($content['header_left']) || !empty($content['header_right']) || !empty($content['header_contained'])){ ?>
  <div class="container">
    <?php print $content['header_contained']; ?>
    <div class="row">
      <div class="col-sm-6">
      <?php print $content['header_left']; ?>
      </div>
      <div class="col-sm-6">
        <?php print $content['header_right']; ?>
      </div>
    </div>
  </div>
<?php } ?>
<?php if(!empty($content['content'])|| !empty($content['aside'])){ ?>
<section>
  <div class="container">
    <article class="content_format col-md-8 col-md-push-4">
      <?php print $content['content']; ?>
    </article>
    <aside class="col-md-4 col-md-pull-8">
    <?php print $content['aside']; ?>
    </aside>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['content_bottom'])){ ?>
<section>
  <div class="container">
    <?php print $content['content_bottom']; ?>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['section_1'])){ ?>
<section>
  <div class="container">
    <?php print $content['section_1']; ?>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['section_2'])){ ?>
<section>
  <div class="container">
    <?php print $content['section_2']; ?>
  </div>
</section>
<?php } ?>
<?php if(!empty($content['section_3'])){ ?>
<section>
  <div class="container">
    <?php print $content['section_3']; ?>
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
<?php if(!empty($content['footer_2']) || !empty($content['footer_2a']) || !empty($content['footer_2b'])){ ?>
<section>
  <div class="container">
    <?php print $content['footer_2']; ?>
    <div class="col-sm-6">
      <?php print $content['footer_2a']; ?>
    </div>
    <div class="col-sm-6">
      <?php print $content['footer_2b']; ?>
    </div>
  </div>
</section>
<?php } ?>
