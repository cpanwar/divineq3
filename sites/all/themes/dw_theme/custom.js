$(document).ready(function(){

  // Rounded corners for IE

  if($.browser.msie) {  
    
    // bottom left bottom right 10px
    $('#footer-inner').corner("br bl 10px");
    
    // top left, top right 5px
    $('body.not-logged-in #header-top-inner #block-menu-menu-account ul li.first, #header-top-inner #block-menu-secondary-links ul li, #header-group').corner("tr tl 5px");
    
    // top left, top right 0px
    // $('#header-top-inner #block-menu-secondary-links ul li').corner("tr tl 0px");
    $('#header-top-inner #block-menu-secondary-links ul li ul li').corner("1px");
    // bottom right, top right 5px
    $('#uc-cart-block-header .view-cart ').corner("br tr 5px");
    
    // bottom right, top right 4px 
    // this is giving error in IE - have to check why
    // $('#block-search-0 form input[type=submit], #sidebar-first-inner .block-simplenews input[type=submit]').corner("br tr 4px");
    
    // bottom right, bottom left 5px
    $('#sidebar-first-inner .block-simplenews .inner, #content-bottom #block-views-products_blocks-block_1 .inner, .page-main-title, #catalog-filters').corner("br bl 5px");
    
    // All rounded 5px
    $('#postscript-bottom #block-views-catalog_grid-block_1 .view-catalog-grid .item-list ul li.read-more a, .uc-cart-page input[type=submit], #continue-shopping-link, div.content-messages-inner div.status, #uc-cart-checkout-form input[type=button], #uc-cart-checkout-form input[type=submit]').corner("5px");  
  }

});
