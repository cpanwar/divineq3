function fetchTeachers(){
 var packageid = $('#packageid').val();
 if(packageid==''){
	 alert('Select a package');
     $('#packageid').focus();
	 return false;
 }
 blockPage(1);
 $('#teacherDisplayDiv').html("");
	$.ajax({
         type: "POST",
		 url: jsURL+"fetch-special-package-mapping",
		 data: "p="+packageid,
         success: function(responseText){
            blockPage(0);
            $('#teacherDisplayDiv').html(responseText);
        }
  });
}

function saveSpecialMapping(){
   var ele=document.mappingForm.elements;
   var eleLength=ele.length;

	var flag=0;
	for(var i=0; i<eleLength; i++){
      try{
	   if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]" &&  ele[i].checked==true){
		flag=1;
	   }
	  }
	  catch(e){}
   }
  
   if(!flag){
	  if(!confirm("You are de-assigning all teachers from this package.\nAre you sure?")){
		return false;
	  }
   }
  
  blockPage(1);
  $.ajax({
         type: "POST",
		 url: jsURL+"add-mapping",
		 data: $('#mappingForm').serialize(),
         success: function(responseText){
            blockPage(0);
            alert(responseText);
            if(responseText=='Data saved'){
			  cleanUpData();	 
			}
        }
    });
}

function cleanUpData(){
	$('#teacherDisplayDiv').html("");
}

function blockPage(mode){
if(mode==1){
  var windowHeight = document.documentElement.clientHeight;
  var windowWidth = document.documentElement.clientWidth;
  $("#blockPopup").css({
		"height": windowHeight,
        "opacity": "0.7",
        "z-index": 500
  });
  $("#blockPopup").show();
 }
 else{
	$("#blockPopup").hide();
 }
}


function checkAll(state){
  var ele=document.mappingForm.elements;
  var eleLength=ele.length;
  for(var i=0; i<eleLength; i++){
	  if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]"){
	ele[i].checked=state;
  }
 }
}