$(document).ready(function() {
  var i = 1;
  $('#views_slideshow_singleframe_pager_yoga_banner-block_5 .pager-item').each(function() {
    var replacement_string = $('#views_slideshow_singleframe_teaser_section_yoga_banner-block_5 .views-row-'+i+' h2').text();
    if(replacement_string.length>26)
    replacement_string= replacement_string.substr(0,26).concat(' ...');
    $(this).children('a').html(replacement_string);
    i = i + 1;
    //console.debug($(this).children('a'));
  });
});

