<?php
  class FieldNumeric extends FieldTextfield
  {

    function get_rules(){
      return array(
          'numeric',
      );
    }
  }
