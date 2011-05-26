/***************************/
//@Author: Adrian "yEnS" Mato Gondelle
//@website: www.yensdesign.com
//@email: yensamg@gmail.com
//@license: Feel free to use it, but keep this credits please!					
/***************************/

//SETTING UP OUR POPUP
//0 means disabled; 1 means enabled;
var popupStatus = 0;

//loading popup with jQuery magic!
function loadPopup(timestamp){
	//loads popup only if it is disabled
	if(popupStatus==0){
		$("#sel_date").val(timestamp); 
		loadData(timestamp);
		$("#backgroundPopup").css({
			"opacity": "0.7"
		});
		$("#backgroundPopup").fadeIn("slow");
		$("#popupContact").fadeIn("slow");
		popupStatus = 1;
	}
}

//disabling popup with jQuery magic!
function disablePopup(){
	//disables popup only if it is enabled
	if(popupStatus==1){
		$("#sel_date").val("");
		$("#backgroundPopup").fadeOut("slow");
		$("#popupContact").fadeOut("slow");
		popupStatus = 0;
	}
}

//centering popup
function centerPopup(){
	//request data for centering
	var windowWidth = document.documentElement.clientWidth;
	var windowHeight = document.documentElement.clientHeight;
	var popupHeight = $("#popupContact").height();
	var popupWidth = $("#popupContact").width();

	//centering
	$("#popupContact").css({
		//"position": "absolute",
		"position": "fixed",
		"top": windowHeight/2-popupHeight/2,
		"left": windowWidth/2-popupWidth/2
	});
	//only need force for IE6
	
	$("#backgroundPopup").css({
		"height": windowHeight
	});
	
}

function loadData(timestamp){
	$("#contactArea").html("");
	$.ajax({
         type: "POST",
		 url: jsURL+"fetch-availability",
		 data: "ts="+timestamp,
         success: function(responseText){
            $("#contactArea").html(responseText);
        }
    });
}

function saveData(){
  var ele=document.time_slot_form.elements;
  var eleLength=ele.length;
  var flag=0;
  for(var i=0; i<eleLength; i++){
   if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="avail_chk[]" &&  ele[i].checked==true){
	flag=1;
   }
  }
  if(!flag){
   if(!confirm("You are making yourself unavailable for the entire day.\nAre you sure?")){
 	 return false;
	}
  }
  blockPage(1);
  $.ajax({
         type: "POST",
		 url: jsURL+"add_availability",
		 data: $('#time_slot_form').serialize(),
         success: function(responseText){
            blockPage(0);
            alert(responseText);
            if(responseText=='Time slot information saved'){
			  disablePopup();	 
			}
        }
    });
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


//CONTROLLING EVENTS IN jQuery
$(document).ready(function(){

	//LOADING POPUP
	//Click the button event!
	$("#button").click(function(){
		//centering with css
		centerPopup();
		//load popup
		loadPopup();
	});
				
	//CLOSING POPUP
	//Click the x event!
	$("#popupContactClose").click(function(){
		disablePopup();
	});
	//Click out event!
	$("#backgroundPopup").click(function(){
		disablePopup();
	});
	//Press Escape event!
	$(document).keypress(function(e){
		if(e.keyCode==27 && popupStatus==1){
			disablePopup();
		}
	});

});