
(function($) {

Drupal.RotorBanner = {};

Drupal.RotorBanner.initialize = function() {
    Drupal.RotorBanner.animate();
};

Drupal.RotorBanner.animate = function() {
	// redefine Cycle's updateActivePagerLink function 
	$.fn.cycle.updateActivePagerLink = function(pager, currSlideIndex){
		$(pager).find('.rotor-tab').removeClass('selected')
		.filter('.rotor-tab:eq(' + currSlideIndex + ')').addClass('selected');
	};
	
  for (rotor_item in Drupal.settings.RotorBanner) {
    var settings = Drupal.settings.RotorBanner[rotor_item];
    // cache the jquery context for a performance boost
    var $rotor = $('#rotor-view-id-'+ settings.view_id +'-view-display-id-'+ settings.display_id);
    
    if (settings.effect == 'random') {
      settings.effect = 'blindX, blindY, blindZ, cover, curtainX, curtainY, fade, fadeZoom, growX, growY, scrollUp, scrollDown, scrollLeft, scrollRight, scrollHorz, scrollVert, shuffle, slideX, slideY, toss, turnUp, turnDown, turnLeft, turnRight, uncover, wipe, zoom';
      settings.randomize = 1;
    }

    $items = $rotor.find('div.rotor-items');
  	$items.cycle({
  		timeout: settings.time * 1000,
  		speed: settings.speed,
  		fx: settings.effect,
  		randomizeEffects: settings.randomize,
  		pause: settings.pause,
  		cleartypeNoBg: true,
  		pager: $('div.rotor-tabs', $rotor),
  		pagerAnchorBuilder: function(idx, slide){
  			return $('div.rotor-tabs .rotor-tab:eq(' + idx + ')', $rotor); 
  		}
  	}).css('visibility', 'visible');
  }
};

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    Drupal.RotorBanner.initialize();
  });
}

})(jQuery);
