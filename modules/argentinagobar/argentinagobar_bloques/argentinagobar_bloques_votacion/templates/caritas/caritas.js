(function ($) {
	Drupal.behaviors.rate_caritas = {
		attach: function(context) {
			$('.rate-widget-caritas:not(.rate-caritas-processed)', context).addClass('rate-caritas-processed').each(function () {
				var widget = $(this);
        // as we use drupal_html_id() to generate unique ids
        // we have to truncate the '--<id>'
        var ids = widget.attr('id').split('--');
        ids = ids[0].match(/^rate\-([a-z]+)\-([0-9]+)\-([0-9]+)\-([0-9])$/);
        var data = {
          content_type: ids[1],
          content_id: ids[2],
          widget_id: ids[3],
          widget_mode: ids[4]
        };
        $(document).bind('eventAfterRate', function(event, data){
				  $('#rating-message').removeClass('hidden');
				});

				widget.find('a').click(function(){
					$(this).addClass('state-loading disabled');
					var token = this.getAttribute('href').match(/rate\=([a-zA-Z0-9\-_]{32,64})/)[1];
          return Drupal.caritasRateVote(widget, data, token);
				});
			})
		}
	};

  Drupal.caritasRateVote = function(widget, data, token) {
  // Invoke JavaScript hook.
  widget.trigger('eventBeforeRate', [data]);

  //$(".rate-info", widget).text(Drupal.t('Saving vote...'));

  // Random number to prevent caching, see http://drupal.org/node/1042216#comment-4046618
  var random = Math.floor(Math.random() * 99999);

  var q = (Drupal.settings.rate.basePath.match(/\?/) ? '&' : '?') + 'widget_id=' + data.widget_id + '&content_type=' + data.content_type + '&content_id=' + data.content_id + '&widget_mode=' + data.widget_mode + '&token=' + token + '&destination=' + encodeURIComponent(Drupal.settings.rate.destination) + '&r=' + random;
  if (data.value) {
    q = q + '&value=' + data.value;
  }

  $.get(Drupal.settings.rate.basePath + q, function(response) {
    if (response.match(/^https?\:\/\/[^\/]+\/(.*)$/)) {
      // We got a redirect.
      document.location = response;
    }
    else {
      // get parent object
      var p = widget.parent();

      // Invoke JavaScript hook.
      widget.trigger('eventAfterRate', [data]);
      widget.before(response);
      //remove widget
      widget.remove();
      widget = undefined;

      Drupal.attachBehaviors(p);
    }
  });

  return false;
}

})(jQuery);
