    $(function() {
      $("#inc").click(function(){
        $(":text[name='qty']").val( Number($(":text[name='qty']").val()) + 1 );
        return false;
      });
      $("#dec").click(function(){
        if(Number($(":text[name='qty']").val())> 0){
        $(":text[name='qty']").val( Number($(":text[name='qty']").val()) - 1 );
        return false;
      }else{return false;}
      });
    });
