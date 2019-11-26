<?php

/**
 * @file
 * Rate widget theme
 */
?>
<?php
  $options = array(
    'html' => TRUE
  );
  $sugerenciasLink = l("Dejanos tus sugerencias", 'node/1534', $options);
  $sugerenciasText = theme(
    'html_tag',
    array(
      'element' => array(
        '#tag' => 'p',
        '#attributes' => array(
          'class' => 'text-center padding-20'
        ),
        '#value' => '¿Querés ayudarnos a mejorar el sitio?<br>' . $sugerenciasLink,
      ),
    )
  );
?>
	<div class="service-rating text-center">
	<?php if (!isset($info['user_vote'])) { ?>
    <div id="rating-buttons">
      <h4 class="margin-0"><?php print $info['title']; ?></h4>
      <p class="text-muted margin-20">
      	<?php
      	if ($display_options['description']) {
				  print $display_options['description'];
				}
				?>
			</p>
		<?php
		print
		theme_item_list(
			array(
			  'items' => $caritas,
			  'type' => 'ul',
		    'title' => '',
		    'attributes' => array(
		      'class' => array(
		      	'list-inline'
		     	)
		  	)
			)
		);
		 ?>
    </div>
  <?php } else { ?>
    <div id="rating-message">
      <h4 class="margin-20">Muchas gracias por darnos tu opinión.</h4>
      <p class="text-muted margin-0">Tu calificación fue:</p>
      <div class="text-muted">
        <i class="" aria-hidden="true"></i> &nbsp; <span class="h2 media-middle"><?php (isset($info['user_vote'])) ? print $info['user_vote'] . "/5" : print ''; ?></span>
      </div>
      <?php //print $sugerenciasText; ?>
    </div>
	<?php } ?>
  </div>
