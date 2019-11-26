<?php

/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and
 * the child template are dependent to one another sharing the markup for
 * definition lists.
 *
 * Note that modules may implement their own search type and theme function
 * completely bypassing this template.
 *
 * Available variables:
 * - $search_results: All results as it is rendered through
 *   search-result.tpl.php
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 *
 *
 * @see template_preprocess_search_results()
 *
 * @ingroup themeable
 */

?>
<?php if ($search_results): ?>
	<div class="container">

	<div class="search col-xs-12 col-sm-12 col-md-12 col-lg-12">

	<div class="col-md-8 col-md-push-4">
		<?php argentinagobar_search_search_data(arg(1),$response->response->numFound); ?>
		<ul style="padding:0;" class="search-results <?php print $module; ?>-results">
			<?php print $search_results; ?>
		</ul>
		<?php print $pager; ?>
	</div>

	<aside class="col-md-4 col-md-pull-8">
		<div class="panel-body">
			<div class="pane-content">
				<nav>
					<h2 class="h3 section-title">Navegación</h2>

						<?php
						//TODOS LOS FACETS
						foreach(variable_get('facetas') as $key => $value ){
							if(!empty($value)){
								$block = module_invoke('facetapi', 'block_view', $value['id']);
								if(!empty($value['title']) and !empty($block['content'])){
									print '<h3 class="filter">'.$value['title'].'</h3>';
								}
								print render($block['content']);
							}
						}
						?>

				</nav>
			</div>
		</div>
	</aside>

</div>

</div>

<?php else : ?>
	<h2><?php print t('Su búsqueda no arrojó resultados');?></h2>
	<?php print search_help('search#noresults', drupal_help_arg()); ?>
<?php endif; ?>