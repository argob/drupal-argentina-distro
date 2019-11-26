<div class="dropdown">
    <a href="#" class="dropdown-toggle btn btn-success" data-toggle="dropdown" aria-expanded="false"><?php print $user['given_name']; ?> <b class="caret"></b></a>
    <ul class="dropdown-menu submenu" role="menu">
        <?php foreach ($links as $link) { ?>
        	<li><?php print $link; ?></li>
        <?php } ?>
    </li>
    </ul>
</div>
