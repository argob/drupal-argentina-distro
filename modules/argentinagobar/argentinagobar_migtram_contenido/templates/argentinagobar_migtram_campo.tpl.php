<?php echo ($campo['titulo']=='' ? '' : '<p><h3>'.$campo['titulo'].'</h3></p>');?>
<div class=<?php echo ($campo['titulo']==''?'text-center':'');?>><p><?php print $campo['contenido']; ?></p></div>