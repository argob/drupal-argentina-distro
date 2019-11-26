
<?php

foreach ($campos as $key => $value) {
  if(is_array($value)){
    foreach ($value as $key => $item) {
      print "<strong>".ucfirst(str_replace("_"," ",$key))."</strong>" .": ". '<br>';
      foreach ($item as $key => $valor) {
        if(!is_array($valor)){
          print "<strong>".ucfirst(str_replace("_"," ",$key)).": "."</strong>".ucfirst($valor)."<br>";
        }
      }
    }
  } else {
    if (isset($value)){
    print "<strong>".ucfirst(str_replace("_"," ",$key)).": "."</strong>".ucfirst($value)."<br>";
    }
  }
}
