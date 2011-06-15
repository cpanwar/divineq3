(function ($) {
  $(document).ready(function() {
   $('#edit-mail').keyup(function(){
   	$('#edit-name').attr('value',$('#edit-mail').attr('value'));
   });
   $('ul.nice-menu-down > li > a').attr('href','Javascript:void(0);');
   $('#block-menu-menu-headermenu2 > div.content > ul.menu li.leaf.first > a').attr('href','Javascript:void(0);');
   $('#block-menu-menu-customerservice > div.content > ul.menu > li.leaf.last > a').attr('href','Javascript:void(0);');	
   
   $('#view-id-yoga_mudra-page_1 table tbody tr td div.views-field-nodequeue-links ul li a').click(function(e) {

      if($(this).text()=="add to yoga sequence") {
         var move_to_block = $(this).parent('li').parent('ul').parent('span').parent('div').parent('td').children().clone();
         if (($('#block-views-yoga_mudra-block_1 .view-yoga-mudra .view-empty').text().trim())=="Build your Sequence") {
            $('#block-views-yoga_mudra-block_1 .view-yoga-mudra .view-empty').remove();
            $('#block-views-yoga_mudra-block_1 .views-admin-links').after("<div class='view-content'><table class='views-view-grid'><tbody><tr class='row-1 row-first row-last'><td class='col-1'></td></tr></tbody></table></div>");
            $('#block-views-yoga_mudra-block_1 .view-content table tbody tr .col-1').append(move_to_block);                   
            $('#block-views-yoga_mudra-block_1 .view-content table tbody tr:last td div.views-field-nodequeue-links ').remove(); 
         }
         else {
             $('#block-views-yoga_mudra-block_1 .view-content table tbody tr:last').after("<tr class='row-last'><td class='col-1'></td></tr>");
             $('#block-views-yoga_mudra-block_1 .view-content table tbody tr:last .col-1').append(move_to_block);       
             $('#block-views-yoga_mudra-block_1 .view-content table tbody tr:last td div.views-field-nodequeue-links ').remove(); 
         } 
      } 
      else {
         var remove_from_block = $(this).parent('li').parent('ul').parent('span').parent('div').parent('td').children().find('a').text().replace('remove from yoga sequence','');
         $('#block-views-yoga_mudra-block_1 table tbody tr').children().each(function() {
              check_title=$(this).find('a').text();
              check_td=$(this);   
              if(check_title==remove_from_block) {
                $(this).css('display','none');
              }
         });
      } 
  });
	
  });
})(jQuery);	
