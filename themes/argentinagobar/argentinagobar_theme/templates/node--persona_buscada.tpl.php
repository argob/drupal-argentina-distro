<?php
  
  /**
  * Persona buscada. template, by @mcord
  */

  $esFemenino       = substr($field_situacion[0]['value'], -1) == 'a';
  $esExtraviado     = substr($field_situacion[0]['value'], 0,1) == 'E';
  $esAutores        = $field_situacion[0]['value'] == 'Autores';
  $tieneRecompensa  = !empty($field_recompensa[0]['value']);
  $nombreCompleto   = $field_nombre[0]['value'] . ' ' . $title;
  $estaEncontrado   = $field_fue_encontrado[0]['value'] == '1';
  $esNN             = $field_es_nn[0]['value'] == '1';

  if($tieneRecompensa)
  {
    $recompensa = number_format($field_recompensa[0]['value'],0, ',', '.');
  }
  if($esAutores)
  {
    if($tieneRecompensa)
    {
      $textoAccionMinisterio = 'El Ministerio de Seguridad está ofreciendo una recompensa de $'. $recompensa . ' por información que conduzca directamente a encontrar a los autores del crimen de ' . $nombreCompleto . '.' ;
    } 
    else 
    {
      $textoAccionMinisterio = 'El Ministerio de Seguridad solicita información que conduzca directamente a encontrar a los autores del crimen de ' . $nombreCompleto . '.';
    }
  }
  else 
  {
    if($esExtraviado)
    {
      if($tieneRecompensa)
      {
        if($esNN)
        {
          $textoAccionMinisterio = 'El Ministerio de Seguridad está ofreciendo una recompensa de $'. $recompensa . ' por información acerca de la identidad de esta persona NN.' ;
        }
        else 
        {
          $textoAccionMinisterio = 'El Ministerio de Seguridad está ofreciendo una recompensa de $'. $recompensa . ' por información que conduzca directamente a encontrar a ' . $nombreCompleto . '.' ;
        }
      } 
      else
      {
        if($esNN){
          $textoAccionMinisterio = 'El Ministerio de Seguridad solicita información acerca de la identidad de esta persona NN.' ;
        }
        else{
          $textoAccionMinisterio = 'El Ministerio de Seguridad solicita información que conduzca directamente a encontrar a ' . $nombreCompleto . '.';
        }
      }
    }
    else
    {
      if($tieneRecompensa)
      {
        $textoAccionMinisterio = 'El Ministerio de Seguridad está ofreciendo una recompensa de $'. $recompensa . ' por información que conduzca directamente al arresto de ' . $nombreCompleto . '.' ;
      }
      else
      {
        $textoAccionMinisterio = 'El Ministerio de Seguridad solicita información que conduzca directamente al arresto de ' . $nombreCompleto . '.';
      }
    }
  }

  $esBusqueda = false;
  $esBuscar = false;
  $esCufre = false;

  foreach($field_programa as $k => $arr)
  {
    foreach($arr as $key => $value)
    {
      if($value == 'Búsqueda')
      {
        $esBusqueda = true;
      }
      if($value == 'Buscar')
      {
        $esBuscar = true;
      }
      if($value == 'Cufre')
      {
        $esCufre = true;
      }
    }
  }
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header>
    <h1 class="node-header bold"><?php print $field_situacion[0]['value']; ?></a></h1>
  </header>
  <div id="persona-buscada-panel" class="my-1 row">
    <div class="col-md-4 padding-0">
      <?php if(!empty($field_image[0]['filename'])): ?>
        <img id="img-persona-buscada" class="fit-width" src="<?php echo base_path();?>sites/default/files/<?=$field_image[0]['filename']?>" />
      <?php elseif ($esFemenino): ?>
        <img id="img-persona-buscada" class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/silueta-mujer.png" />
      <?php else: ?>
        <img id="img-persona-buscada" class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/silueta-hombre.png" />
      <?php endif; ?>
    </div>
    <div class="col-md-8 rtejustify">
      <div class="mx-3">
        <h2 class="bold text-center py-1"><?php print $nombreCompleto; ?></h2>
      
        <?php if($estaEncontrado): ?>
          <p style="text-align: center;">El Ministerio de Seguridad informa el hallazgo de <?php print $nombreCompleto; ?></p>
          <p style="text-align: center;">Muchas gracias.</p>
        <?php else: ?>
          <p><?php print $body[0]['value']; ?></p>
      
          <?php if ($tieneRecompensa): ?>
            <h3 class="bold">Recompensa: $<?php print $recompensa; ?></h3>
          <?php endif; ?>
      
          <p><?php echo $textoAccionMinisterio; ?></p>
        <?php endif; ?>
      
          <div class="row pt-2">
      
            <?php if(!$estaEncontrado): ?>
              <div class="col-xs-12 text-center">
                <a target="_blank" href="mailto:juntoavos@minseg.gob.ar"><div class="btn btn-lg btn-danger">ENVIAR INFORMACIÓN</div></a>
              </div>
            <?php endif; ?>
      
            <div class="col-xs-12 mt-2 text-center">
              <div id="redes-sociales" class="btn btn-lg btn-outline-primary">
                <a style="color:white;" target="_blank" href="https://www.facebook.com/sharer/sharer.php?u= <?php print urlencode($_SERVER['HTTP_HOST'] . request_uri());?>&amp;src=sdkpreparse">
                  <i class="fa fa-facebook-official fa-2x" ></i>
                </a>&nbsp;&nbsp;&nbsp;
                <a style="color:white;" target="_blank" href="https://twitter.com/intent/tweet?text=<?php print urlencode('Ayudanos a compartir esta búsqueda para que juntos podamos encontrar a '. $nombreCompleto . '. http://' . $_SERVER['HTTP_HOST'] . request_uri());?>&amp;src=sdkpreparse">
                  <i class="fa fa-twitter fa-2x"></i>
                </a>
              </div>
            </div>
          </div>
        </div>
    </div>
  </div>
  <br />
  <div class="row">
    <div class="col-xs-12 padding-0">
      <div class="col-xs-12 col-md-4 padding-0">
        
        <?php if ($esBusqueda): ?>
          <div class="col-xs-6">
            <img class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/100-logo-busqueda.png" />
          </div>
        <?php endif; ?>
        
        <?php if ($esBuscar): ?>
          <div class="col-xs-6">
            <img class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/100-logo_buscar.png" />
          </div>
        <?php endif; ?>

      </div>
      <div class="col-xs-12 col-md-8  padding-0">
        <div class="hidden-xs hidden-sm col-md-4">
          <img class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/100-denuncias-anonimas.png" />
        </div>
        <div class="col-xs-12 col-md-8">
          <img class="fit-width" src="<?php echo base_path();?>sites/default/files/recursos/img/persona-buscada/100-0800.png" />
        </div>
      </div>
    </div>
  </div>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>
</article>
