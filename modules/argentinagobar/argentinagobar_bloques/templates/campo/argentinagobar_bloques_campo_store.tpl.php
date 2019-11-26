<?php
	$grilla= sizeof($campo) == 1 ? "col-md-12" : (sizeof($campo) == 2 ? "col-md-6" : (sizeof($campo) == 3 ? "col-md-4" : "col-md-3"));
?>

<div class="row numbers text-center">
<?php
	//caso Android:
	if (isset($campo['android'][0]["value"]) && ($campo['android'][0]["value"] <> null)) {
	?>
		<div class="col-xs-12 col-sm-6 <?php print $grilla;?>">
		<h1 class="text-secondary">
    	<i class="fa fa-android"></i>
       	</h1>
       	<div class="text-muted">Android</div><br>
       	<p>

		<?php print l(
		'Ver en Google Play' ,
		$campo['android'][0]['value'],
		array(
		'attributes' => array(
		'class' => "btn btn-primary"
		),
	)
);
?>

       	</p>
      	</div>
	<?php
		}
	//caso iPhone:
	if (isset($campo['iphone'][0]["value"]) && ($campo['iphone'][0]["value"] <> null)) {
	?>
		<div class="col-xs-12 col-sm-6 <?php print $grilla; ?> ">
		<h1 class="text-secondary">
    	<i class="fa fa-apple"></i>
       	</h1>
       	<div class="text-muted">Apple</div><br>
       	<p>

       	<?php print l(
			'Ver en APP Store' ,
			$campo['iphone'][0]['value'],
			array(
			'attributes' => array(
			'class' => "btn btn-primary"
		),
	)
);
?>

       	</p>
      	</div>
	<?php
		}

	//caso Windows:
	if  (isset($campo['windows'][0]["value"]) && ($campo['windows'][0]["value"] <> null)) {
	?>
		<div class="col-xs-12 col-sm-6 <?php print $grilla; ?> ">
		<h1 class="text-secondary">
    	<i class="fa fa-windows"></i>
       	</h1>
       	<div class="text-muted">Windows Phone</div><br>
       	<p>
<?php print l(
	'Ver en la tienda' ,
	$campo['windows'][0]['value'],
	array(
		'attributes' => array(
			'class' => "btn btn-primary"
		),
	)
);
?>
       	</p>
      	</div>
<?php
	}
//caso BlackBerry:
	if (isset($campo['blackberry'][0]["value"]) && ($campo['blackberry'][0]["value"] <> null)) {
	?>
		<div class="col-xs-12 col-sm-6 <?php print $grilla; ?> ">
		<h1 class="text-secondary">
    	<i class="fa fa-mobile"></i>
       	</h1>
       	<div class="text-muted">BlackBerry</div><br>
       	<p>
<?php print l(
	'Ver en la tienda' ,
	$campo['blackberry'][0]['value'],
	array(
		'attributes' => array(
			'class' => "btn btn-primary"
		),
	)
);
?>
       	</p>
      	</div>


	<?php
		}

	?>

</div>
