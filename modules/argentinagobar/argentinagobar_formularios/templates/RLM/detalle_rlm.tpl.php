<section p-y-1="">
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <ol class="breadcrumb pull-left">
                    <?php foreach($breadcrumb as $crumb): ?>
                        <?= !is_array($crumb) ? '<li>'.$crumb.'</li>' : '' ?>
                    <?php endforeach; ?>
                    <li class="active"><span><?= isset($items['name']) ? $items['name'] : ''?></span></li>
                </ol>
            </div>
        </div>
    </div>
</section>

<div class="text-center m-t-4" id="captcha_completo">
    <body onload="createCaptcha()">
      <form onsubmit="validateCaptcha()">
        <div id="captcha">
        </div>
        <input type="text" placeholder="Escriba el texto de arriba" id="cpatchaTextBox"/>
        <button class="btn-primary" type="submit">Enviar</button>
        <div style="margin-top: 15px;" id="menssage_captcha">
        </div>
      </form>
    </body>
</div>

<style type="text/css">
    input[type=text] {
        padding: 12px 20px;
        display: inline-block;
        border: 1px solid #ccc;
        border-radius: 4px;
        box-sizing: border-box;
    }
    button{
      background-color: #4CAF50;
        border: none;
        color: white;
        padding: 12px 30px;
        text-decoration: none;
        margin: 4px 2px;
        cursor: pointer;
    }
    canvas{
      /*prevent interaction with the canvas*/
      pointer-events:none;
    }
</style>


<script type="text/javascript">

  var code;

  function createCaptcha() {

    //clear the contents of captcha div first
    document.getElementById('captcha').innerHTML = "";
    var charsArray =
    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var lengthOtp = 6;
    var captcha = [];
    for (var i = 0; i < lengthOtp; i++) {
    //below code will not allow Repetition of Characters
    var index = Math.floor(Math.random() * charsArray.length + 1); //get the next character from the array
    if (captcha.indexOf(charsArray[index]) == -1)
      captcha.push(charsArray[index]);
    else i--;
    }
    var canv = document.createElement("canvas");
    canv.id = "captcha";
    canv.width = 150;
    canv.height = 50;
    var ctx = canv.getContext("2d");
    ctx.font = "25px Georgia";
    ctx.strokeText(captcha.join(""), 0, 30);
    //storing captcha so that can validate you can save it somewhere else according to your specific requirements
    code = captcha.join("");
    document.getElementById("captcha").appendChild(canv); // adds the canvas to the body element
  }


  function validateCaptcha() {
    event.preventDefault();
    if (document.getElementById("cpatchaTextBox").value == code) {
      document.getElementById("detalle_rlm_completo").style.display = "block";
      document.getElementById("captcha_completo").style.display = "none";
    }else{
      document.getElementById('menssage_captcha').innerHTML = 'Por favor intrese el texto que aparece arriba'
      document.getElementById('menssage_captcha').style.color = 'red';
      createCaptcha();
    }
  }

</script>



<div id="detalle_rlm_completo" style="display: none">
    <div class="text-center m-t-4" id="rlm_nuevabusqueda">
      <a href="<?php print url($base_url . '/aaip/datospersonales/reclama'); ?>" class="btn btn-primary">Nueva búsqueda</a>
    </div>
    <div class="container">
      <section class="row">
        <?php if (isset($items['name'])): ?>
          <div class="col-xs-12">
            <h2><?= $items['name']?></h2>
            <div class="">
              <div class=" col-xs-12 col-md-4 pull-right m-y-1">
                <img src="<?= $items['link']?>/sites/default/files/usuario.png" alt="" class="img-tamanio">
                <h3>Información</h3>
                <div class="m-b-1">
                  <strong>Tipo de persona</strong>
                  <p><?= $items['tipoPersona']?></p>
                </div>
                <div class="m-b-1">
                  <strong>Código de responsable</strong>
                  <p><?= $items['ref_number']?></p>
                </div>
                <div class="m-b-1">
                  <strong>CUIL / CUIT </strong>
                  <p><?= $items['cuit']?></p>
                </div>
                <?php if (isset($bases[0])): ?>
                  <?php if ($bases[0]['valoresFC']['txt_nombre_fantasia']):?>
                <div class="m-b-1">
                  <strong>Nombre de Fantasía </strong>
                  <p><?= $bases[0]['valoresFC']['txt_nombre_fantasia']?></p>
                </div>
                <?php endif ?>
                <?php endif ?>
              </div>
              <div class="col-md-8">
                <hr>
              </div>
            </div>
            <div>
            <div class="col-md-8 pull-left m-b-1">
              <?php foreach ($bases as $base): ?>


                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left p-r-1">
                      <i class="fa fa-database fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <h5 class="col-xs-12">Base de datos</h5>
                      <p class="col-sm-10">
                        <?=$base['valoresFC']['nombre_base_datos']?>
                      </p>
                    </div>
                  </div>
                </div>

                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left">
                      <i class="fa fa-warning fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <h5 class="col-xs-12">Forma habilitada de reclamar</h5>
                      <ul class="m-t-0">
                        <?= $base['valoresFC']['chk_telefonicamente'] ? '<li>Teléfono</li>' : '' ?>
                        <?= $base['valoresFC']['chk_correo_elect'] ? '<li>Correo Electronico</li>' : '' ?>
                        <?= $base['valoresFC']['chk_personalmente'] ? '<li>Personalmente</li>' : '' ?>
                        <?= $base['valoresFC']['chk_carta_doc'] ? '<li>Carta Documento</li>' : '' ?>
                        <?= $base['valoresFC']['chk_present_escrita'] ? '<li>Presentación Escrita</li>' : '' ?>
                        <?= $base['valoresFC']['chk_otros_5'] ? '<li>'. $base['valoresFC']['txt_descrip_5'].'</li>' : '' ?>
                      </ul>
                    </div>
                  </div>
                </div>

                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left">
                      <i class="fa fa-arrow-circle-right fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <h5 class="mt-0 col-xs-12">Finalidad</h5>
                      <ul class="m-t-0">
                      <?php foreach ($base['valoresFC']['finalidades'] as $finalidad) : ?>
                        <?= '<li>'. $finalidad . '</li>' ?>
                      <?php endforeach;?>
                      </ul>
                    </div>
                  </div>
                </div>

                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left">
                      <i class="fa fa-drivers-license-o fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <?php if ($base['valoresFC']['mail_correo_electronico']) :?>
                      <div class="col-sm-6">
                        <h5 class="mt-0">Correo electrónico</h5>
                        <p><?= $base['valoresFC']['mail_correo_electronico'] ?></p>
                      </div>
                      <?php endif;?>

                      <?php if ($base['valoresFC']['lng_telefono']) :?>
                      <div class="col-sm-6">
                        <h5 class="mt-0">Teléfono</h5>
                        <p><?= $base['valoresFC']['lng_telefono']  ?></p>
                      </div>
                      <?php endif;?>
                    </div>
                  </div>
                </div>

                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left p-r-2">
                      <i class="fa fa-map-marker  fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <h5 class="col-xs-12">Domicilio</h5>
                      <p class="col-sm-10"><?= $base['valoresFC']['domicilio']?></p>
                    </div>
                  </div>
                </div>

                <div class="col-md-8 m-b-1">
                  <div class="media">
                    <div class="media-left p-r-1">
                      <i class="fa fa-list-ul fa-2x text-primary m-t-1"></i>
                    </div>
                    <div class="media-body">
                      <h5 class="col-xs-12">Requisito para solicitar acceso y procedimiento</h5>
                      <p class="col-sm-10">
                        <?=$base['valoresFC']['requisitos']?>
                      </p>
                    </div>
                  </div>
                </div>

                <div class="col-md-8">
                  <hr>
                </div>

              <?php endforeach; ?>
</div>
            </div>
          </div>
        <?php endif ?>
      </section>
    </div>
</div>
