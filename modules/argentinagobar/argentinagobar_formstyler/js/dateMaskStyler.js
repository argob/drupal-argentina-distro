function dateMaskStyle(){
	jQuery('.dateMaskStyler').mask('00/00/0000');
}

jQuery(document).ready(function () {
	dateMaskStyle();
});

jQuery(document).ajaxComplete(function() {
	//dateMaskStyle();
});