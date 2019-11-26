<?php
  class FieldEmail extends FieldTextfield
  {

    function get_rules(){
      return array(
          'email',
      );
    }
  }
