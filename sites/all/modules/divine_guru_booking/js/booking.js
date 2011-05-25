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

  $.ajax({
         type: "POST",
		 url: jsURL+"fetch-guru-list",
		 data: "packageid="+packageid,
         success: function(responseText){
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
  $.ajax({
         type: "POST",
		 url: jsURL+"fetch-guru-details",
		 data: "guru="+uid,
         success: function(responseText){
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
	if(cnt>classes_left){
		alert("You have used all classes for this package.");
		return false;
	}
    
	var returnvalue=0;
	$.ajax({
         type: "POST",
		 url: jsURL+"check-guru-availability",
         async: false,
		 data: "key="+key+"&arr="+dataArray+"&pid="+$('#packageid').val(),
         success: function(responseText){
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

	$('#confirmTRId1').show();
    $('#confirmTRId2').show();

	var jQtable=$('#scheduleTable');
	
	var guruname=$('#guruname').val();
	var class_date=$('#class_date').val();
	var class_time=$('#class_time').val();
	var timezone=$('#timezone option:selected').text();

	var class_details='Guru :'+guruname + '<br/>On <b>' + class_date + '</b> at <b>' + class_time + '</b> in <b>' + timezone + '</b>';

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
		tds +='<td align="center"><a href="javascript:void(0)" onclick="editSchedule(this,'+classCounter+')">Edit</a></td>';
		tds +='<td align="center"><a href="javascript:void(0)" onclick="deleteSchedule(this,'+classCounter+')">Delete</a></td>';
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
	var returnvalue=0;
	$.ajax({
         type: "POST",
		 url: jsURL+"confirm-classes",
         async: false,
		 data: "arr="+dataArray+"&pid="+$('#packageid').val()+"&ebid="+ebid,
         success: function(responseText){
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

function editSchedule(val,classCounter){
  var arr=dataArray[classCounter].split('-');
  $('#timezone').val(arr[1]);
  $('#class_time').val(arr[2]);
  $('#class_date').val(arr[3]);
  deleteSchedule(val,classCounter);
}

function deleteSchedule(val,classCounter){
	$(val).parent().parent().remove();
    dataArray.splice(classCounter,1);
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

function editClassSchedule(val){
	window.location=jsURL+"package?bid="+val+"&mode=1";
}

function deleteClassSchedule(val){

	if(!confirm("Do you want to delte this record?")){
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