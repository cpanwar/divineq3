function cleanUpData(mode){
  $('#selectionTrId').hide();
  $('#guruDiv').hide();
  $('#guruDiv').html("");
  $('#packageDetailsDiv').hide();
  $('#packageDetailsDiv').html("");
  
  $('#confirmTRId1').hide();
  $('#confirmTRId2').hide();
  dataArray=new Array();
  classCounter=0;
  $("#scheduleTable").find("tr:gt(1)").remove();
  $('#timezone').val(userTid);
  $('#class_date').val("");
  $('#class_time').val("");
}

function showGuruList(){
  $('#guruDetailsDiv').html("");
  $('#guruDetailsDiv').hide();
  $('#selectionTrId').hide();
  $('#guruDiv').show();

  $('#confirmTRId1').hide();
  $('#confirmTRId2').hide();
  dataArray=new Array();
  classCounter=0;
  $("#scheduleTable").find("tr:gt(1)").remove();
  $('#timezone').val(userTid);
  $('#class_date').val("");
  $('#class_time').val("");
}

function fetchGuruList(mode){
  var packageid=$('#packageid').val();
  if(packageid=='0'){
	  alert('Please select a package');
      $('#packageid').focus();
	  return false;
  }
  
  $('#guruDetailsDiv').html("");
  $('#selectionTrId').hide();
  $('#guruDetailsDiv').hide();

  $('#confirmTRId1').hide();
  $('#confirmTRId2').hide();
  dataArray=new Array();
  classCounter=0;
  $("#scheduleTable").find("tr:gt(1)").remove();
  $('#timezone').val(userTid);
  $('#class_date').val("");
  $('#class_time').val("");
  blockPage(1);
  $.ajax({
         type: "POST",
		 url: jsURL+"fetch-guru-list",
		 data: "packageid="+packageid,
         success: function(responseText){
            blockPage(0);
            if(responseText=='No gurus found for this package'){
			  alert(responseText);
			  cleanUpData(1);
			  return false;
			}
			var ret= responseText.split('!#@!$#!');
			$('#packageDetailsDiv').html(ret[0]);
			$('#packageDetailsDiv').show();
            $('#guruDiv').html(ret[1]);
			if(mode==1){ //when not called during edit operation
			 $('#guruDiv').show();
			}
        }
    });
}

function selectGuru(uid){
  blockPage(1);
  $.ajax({
         type: "POST",
         async: false,
		 url: jsURL+"fetch-guru-details",
		 data: "guru="+uid,
         success: function(responseText){
            blockPage(0);
            if(responseText=='No guru found'){
			  alert(responseText);
			  return false;
			}
            $('#guruDetailsDiv').html(responseText);
			$('#selectionTrId').show();
			$('#guruDetailsDiv').show();
			$('#guruDiv').hide();
        }
    });
}

function getAvailableTimeSlotsForGuru(editMode){

   $("#class_time").html("");
   var optionString = '<option value="">Select Time</option>';
   $(optionString).appendTo("#class_time");

   var timezone = $('#timezone').val();
   var dt = $('#class_date').val();
   var uid = $('#guruid').val();

   if(dt==''){
      return false;
   }

   blockPage(1);
   $.ajax({
         type: "POST",
         async: false,
		 url: jsURL+"fetch-guru-available-timeslots",
		 data: "guru="+uid+"&dt="+dt+"&tid="+timezone+"&em="+editMode,
         success: function(responseText){
            blockPage(0);
            if(responseText==''){
			  return false;
			}
			var obj=JSON.parse(responseText);
			var cnt = obj.length; 
			optionString = '';
			for(var i=0; i<cnt ; i++){
              var opt=new Option(obj[i].name,obj[i].id);
			  document.getElementById('class_time').options.add(opt);
			}
        }
   });
}

var classCounter=0;
var dataArray=new Array();

function addToSchedule(){
    
	if($('#timezone').val()=='0'){
		alert("Please select timezone");
        $('#timezone').focus();
		return false;
	}

	if($('#class_date').val()==''){
		alert("Please select date");
        $('#class_date').focus();
		return false;
	}
	if($('#class_time').val()==''){
		alert("Please select time");
        $('#class_time').focus();
		return false;
	}
	if($('#timezone').val()==''){
		alert("Please select timezone");
        $('#timezone').focus();
		return false;
	}
	
    var guruid=$('#guruid').val();
	var tid=$('#timezone').val();
	var cdate=$('#class_date').val();
	var ctime=$('#class_time').val();

	var key=guruid+'-'+tid+'-'+ctime+'-'+cdate;
	var cnt=dataArray.length;
	for(var i=0; i<cnt; i++){
		if(dataArray[i]==key){
			alert("You have already added this class to your schedule.");
			return false;
		}
	}

	var classes_left = $('#classes_left').val();
	var noRec = 0;
	var jQtable=$('#scheduleTable');
	var rowCounter = 0;
	jQtable.each(function(){
        var $table = $(this);
		rowCounter = $('tr', this).length;
		noRec = ($('tr', this).length-2);
    });

	//alert(noRec);
	//if(cnt>classes_left){
    if(noRec==classes_left){ 
		alert("You have used all classes for this package.");
		return false;
	}
    blockPage(1);
	var returnvalue=0;
	$.ajax({
         type: "POST",
		 url: jsURL+"check-guru-availability",
         async: false,
		 data: "key="+key+"&arr="+dataArray+"&pid="+$('#packageid').val(),
         success: function(responseText){
            blockPage(0);
            if(responseText=='1'){
				returnvalue= 1;
			}
			else if(responseText=='2'){
				returnvalue= 2;
			}
			else if(responseText=='3'){
				returnvalue= 3;
			}
			else if(responseText=='4'){
				returnvalue= 4;
			}
			else{
				returnvalue= responseText;
			}
        }
    });

	if(returnvalue==2){
		alert("This selection is clashing with your previously scheduled classes");
		return false;
	}
	if(returnvalue==3){
		alert("This selection is clashing with your currently selected classes");
		return false;
	}
	if(returnvalue==4){
		alert("This time slot is not available");
		return false;
	}
	if(returnvalue!=1){
		alert(returnvalue);
		return false;
	}

	//return;
    dataArray[classCounter]=key;
	//dataArray[rowCounter]

	$('#confirmTRId1').show();
    $('#confirmTRId2').show();

	var jQtable=$('#scheduleTable');
	
	var guruname=$('#guruname').val();
	var class_date=$('#class_date').val();
	//var class_time=$('#class_time').val();
	var class_time=$('#class_time option:selected').text();
	var timezone=$('#timezone option:selected').text();

	var class_details='Teacher :'+guruname + '<br/>On <b>' + class_date + '</b> at <b>' + class_time + '</b> in <b>' + timezone + '</b>';

    jQtable.each(function(){
        var $table = $(this);
        //alert($('tr', this).length);
		/*var n = $('tr:last td', this).length;
        var tds = '<tr>';
        for(var i = 0; i < n; i++){
            tds += '<td>'+n+'</td>';
        }
		*/
		var tds = '<tr>';
		tds +='<td>Class '+(classCounter+1)+'</td>';
		tds +='<td>'+class_details+'</td>';
		tds +='<td align="center"><a href="javascript:void(0)" onclick=editSchedule(this,"'+key+'")>Edit</a></td>';
		tds +='<td align="center"><a href="javascript:void(0)" onclick=deleteSchedule(this,"'+key+'")>Delete</a></td>';
        tds += '</tr>';
		classCounter++;
        if($('tbody', this).length > 0){
            $('tbody', this).append(tds);
        }else {
            $(this).append(tds);
        }
    });
}

function confirmClasses(mode){
	if(mode==2){
      
	  if($('#class_time').val()==''){
		alert("Please select time");
        $('#class_time').focus();
		return false;
	  }

      var guruid=$('#guruid').val();
	  var tid=$('#timezone').val();
	  var cdate=$('#class_date').val();
	  var ctime=$('#class_time').val();
      
	  var key=guruid+'-'+tid+'-'+ctime+'-'+cdate;
      
	  dataArray=new Array();
      dataArray[0]=key;

	}
    var flag=0;
	var cnt=dataArray.length;
	for(var i=0; i<cnt; i++){
		if(dataArray[i]!=''){
          flag=1;
		  break;
		}
	}
	if(flag==0){
		alert("Please select at least one class details before confirming");
		return false;
	}
	if($('#packageid').val()=='0'){
	  alert('Please select a package');
      $('#packageid').focus();
	  return false;	 
	}
	blockPage(1);
	var returnvalue=0;
	$.ajax({
         type: "POST",
		 url: jsURL+"confirm-classes",
         async: false,
		 data: "arr="+dataArray+"&pid="+$('#packageid').val()+"&ebid="+ebid,
         success: function(responseText){
            blockPage(0);
            var retvalue=responseText.split('!$@$!*!$@$!');
			var cnt=retvalue.length;
			var err=retvalue[0];
			if(err=='err:0'){
               alert("Classes confirmed"); //redirect to list page?
			   if(calledFrom == '1'){
				   window.location = jsURL+"/show-scheduled-classes";
			   }
			   else if(calledFrom == '2' ){
                   window.location = jsURL+"/show-scheduled-classes"; //to users dashboard
			   }
			   cleanUpData(1);
			   return false;
			}
			else if(err=='Please select at least one class details before confirming' || err=='Please select a package'){
				alert(err);
				return false;
			}
			else if(err=='Invalid input specified'){
				alert(err);
				return false;
			}
			else{
				if(retvalue[1]=='err_type:4'){
				   alert("This class could not be confirmed\nReason : Selected time slot is not available");
				}
				if(retvalue[1]=='err_type:2'){
				   alert("This class could not be confirmed\nReason : Present selection is clashing with your previously scheduled classes");
				}
				if(retvalue[1]=='err_type:3'){
				   alert("This class could not be confirmed\nReason : Present selection is clashing with your currently selected classes");
				}
				if(retvalue[1]=='err_type:5'){
				   alert("This class could not be confirmed\nReason : Invalid input data specified");
				}
				if(retvalue[1]=='err_type:6'){
				   alert("This class could not be confirmed\nReason : Data could not be saved");
				}
				if(retvalue[1]=='err_type:7'){
				   alert("This class could not be confirmed\nReason : "+retvalue[2]);
				   return false;
				}
				var row=retvalue[2].split(':');
				if(row.length>1){
				 highlightRow(row[1]);
				}
			}
        }
    });
}

function highlightRow(rowNumber){
  $('#scheduleTable tr').each(function() {
    if($(this).index()==rowNumber){
     $(this).css("color", "red");
	}
  });
}

function editSchedule(val,key){
  //var arr=dataArray[classCounter].split('-');
  var arr=key.split('-');
  $('#timezone').val(arr[1]);
  $('#class_time').val(arr[2]);
  $('#class_date').val(arr[3]);
  deleteSchedule(val,key);
}

function deleteSchedule(val,key){
	$(val).parent().parent().remove();
    //dataArray.splice(classCounter,1);
	deleteDataArray(key);
	var jQtable=$('#scheduleTable');
	jQtable.each(function(){
        var $table = $(this);
		if($('tr', this).length==2){
	     $('#confirmTRId1').hide();
         $('#confirmTRId2').hide();
         dataArray=new Array();
	     classCounter=0;
	    }
    });
}

function deleteDataArray(key){
   var cnt=	dataArray.length;
   for(var i=0;i<cnt;i++){
	   if(dataArray[i]==key){
		   dataArray.splice(i,1);
		   break;
	   }
   }
}

function editClassSchedule(val){
	window.location=jsURL+"package?bid="+val+"&mode=1";
}

function deleteClassSchedule(val){

	if(!confirm("Do you want to delete this record?")){
		return false;
	}
    var returnvalue=0;
	$.ajax({
         type: "POST",
		 url: jsURL+"delete-schedule-class",
         async: false,
		 data: "key="+val,
         success: function(responseText){
            if(responseText=='1'){
				returnvalue= 1;
			}
			else{
				returnvalue= 0;
			}
        }
    });

	if(returnvalue==1){
		alert("This record is deleted");
		window.location.reload();
		//return false;
	}
	else{
		alert(responseText);
		return false;
	}
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


function pupulateFields(uid,date,time){ 
 selectGuru(uid);
 $('#class_date').val(date);
 $('#class_time').val(time);
 disablePopup();
}