<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php if ($content): ?>
  <ul class="nav navbar-nav navbar-right hidden-xs">
    <a onclick="jQuery('.navbar.navbar-top').removeClass('state-search');" href="#" class="btn btn-link visible-xs"> <i class="fa fa-times"></i> </a>
    <?php print $content; ?>
    <!-- Pablo -->
    <!-- <a href="https://mi.argentina.gob.ar" class="btn btn-link hidden-xs" aria-label="Ingresar a Mi Argentina">
           <i class="icono-arg-mi-argentina"></i>Mi Argentina</a> -->
  </ul>
<?php endif; ?>
