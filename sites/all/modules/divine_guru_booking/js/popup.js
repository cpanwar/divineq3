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
function loadPopup(val,week,timezone){
	//loads popup only if it is disabled
	if(popupStatus==0){
		loadData(val,week,timezone);
		$("#backgroundPopup").css({
			"opacity": "0.7"
		});
		$("#backgroundPopup").fadeIn("slow");
		$("#popupContact").fadeIn("slow");
		popupStatus = 1;
	}
}

//loading popup with jQuery magic!
function loadPopupSimple(){
	//loads popup only if it is disabled
	if(popupStatus==0){
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

function loadData(val,week,timezone){
	$("#contactArea").html("<b>Loading Data.Please wait.................</b>");
	$.ajax({
         type: "POST",
		 url: jsURL+"fetch-guru-timeslots",
		 data: "gid="+val+"&week="+week+"&timezone="+timezone,
         success: function(responseText){
            $("#contactArea").html(responseText);
        }
    });
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

function openGuruTimeSlots(val,week,timezone){
  $("#popupContact").css({
	  "height": "480",
      "width": "850", 
  });
  $("#contactArea").css({
	  "height": "470",
      "width": "840", 
  });
  centerPopup();
  loadPopup(val,week,timezone);
}

function openGuruTimeSlotsWithTimezone(val,week){
  var timezone = $('#timezone').val();
  openGuruTimeSlots(val,week,timezone);	 
}

function loadGuruProfile(val){
	$("#contactArea").html("<b>Loading Data.Please wait.................</b>");
	$.ajax({
         type: "POST",
		 url: jsURL+"fetch-guru-profile",
		 data: "gid="+val,
         success: function(responseText){
            $("#contactArea").html(responseText);
        }
    });
}

function openGuruDetails(val){
  $("#popupContact").css({
	  "height": "350",
      "width": "600", 
  });
  $("#contactArea").css({
	  "height": "350",
      "width": "600", 
  });
  centerPopup();
  loadGuruProfile(val);
  loadPopupSimple();
}