<?php

function argentinagobar_search_apachesolr_query_alter($query){

	$search = variable_get('search_regex');

	if(!empty($search)){

		foreach($search as $key => $value){
			$patron[] = '/(^.*'.$value['regex'.$key].'.*$)/i';
			$sust[] = '$1 '.$value['regex_replace'.$key];
		}

		$query->replaceParam('q', preg_replace($patron, $sust, $query->getParam('q')));

	}

}