<div class="input-group">
  <?php if(isset($element['#attributes']['data-input-group-addon-left-text'])) { ?>
  <span class="input-group-addon" id="addon-<?php print $element['#id']; ?>"><?php print $element['#attributes']['data-input-group-addon-left-text'] ?></span>
  <?php } ?>
  <?php print theme($element['#type'], array('element' => $element)); ?>
  <?php if(isset($element['#attributes']['data-input-group-addon-right-text'])) { ?>
  <span class="input-group-addon" id="addon-<?php print $element['#id']; ?>"><?php print $element['#attributes']['data-input-group-addon-right-text'] ?></span>
  <?php } ?>
</div>
