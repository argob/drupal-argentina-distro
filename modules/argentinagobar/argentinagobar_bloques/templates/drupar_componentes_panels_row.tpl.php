<?php foreach ($rows as $column) { ?>
  <div class="row panels-row">
      <?php foreach ($column as $content) { ?>
        <?php print $content; ?>
      <?php } ?>
  </div>
<?php } ?>
