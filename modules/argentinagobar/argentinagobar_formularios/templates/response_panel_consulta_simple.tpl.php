

      <h2><?php print $titulo; ?></h2>


      <?php foreach ($paneles as $panel){ ?>
         <?php    print $panel ?>
      <?php } ?>



      <?php
        print '<h3>'.$footer['titulo'].'</h3>';
          if(isset($footer)) {
            foreach ($footer['data'] as $foot){
              print  '<label class="control-label">'.$foot['label'].'</label>';
              print  '<p>'.$foot['value'].'</p>';
            }
          }
      ?>
