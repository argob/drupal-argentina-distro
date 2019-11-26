<div class="container">
<?php print $content['header_full']; ?>

  <section>
    <div class="row">
      <div class="col-md-12 m-b-2">
      <?php print $content['header_contained']; ?>
      </div>
    </div>

    <div class="row">
      <div class="col-md-8">
        <article>
          <div class="row">
            <div class="col-md-12">

             <?php print $content['content']; ?>

            </div>
          </div>
        </article>

        <div class="row m-y-3">
      <?php print $content['section_1']; ?>
        </div>

        <div class="row visible-xs">
        <?php print $content['section_2']; ?>
        </div>

        <hr>

        <div class="row">
          <div class="section-actions col-md-12 social-share">
             <?php print $content['section_3']; ?>
          </div>
        </div>
      </div>

        <div class="col-md-4">
            <div class="row">
                <div class="col-xs-12 col-md-11 col-md-offset-1">
                    <div class="row hidden-xs hidden-sm">
                        <div class="col-md-12">
                            <?php print $content['aside_hidden_xs']; ?>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-md-12">
                            <?php print $content['aside']; ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>

    </div>
  </section>
</div>
