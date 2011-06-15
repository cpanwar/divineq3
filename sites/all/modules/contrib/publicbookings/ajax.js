
var block_flag;

$(document).ready(function() {
  $('#ajax-availability').html('<div id="ajax-display"></div><input type="button" value="Check availability" id="check-availability" disabled="disabled" />');
  $('#ajax-availability').css('padding-top', '1em');
  $('#ajax-display').hide();
  $('#ajax-display').css('padding', '0 1em 1em 1em');
  base_path = $('#edit-base-path').val();
  
  button_lock_check(); // initial check
  $('#edit-resource-id, #edit-start-wrapper [name], #edit-end-wrapper [name]').change( button_lock_check ); // and for subsequent changes
  
  $('#check-availability').click( check_availability );
  
  // date select automation
  // changes to the start time's select fields will also update corresponding field for the end time with the same value.
  $('#edit-start-month').change(function(obj) {
    $('#edit-end-month').val(this.value);
  });
  $('#edit-start-day').change(function(obj) {
    $('#edit-end-day').val(this.value);
  });
  $('#edit-start-year').change(function(obj) {
    $('#edit-end-year').val(this.value);
  });
  $('#edit-start-hour').change(function(obj) {
    $('#edit-end-hour').val(this.value);
  });
  $('#edit-start-minute').change(function(obj) {
    $('#edit-end-minute').val(this.value);
  });
  
  // date repeat automation
  // if INTERVAL is set, fill in the UNTIL field with the start date.
  $('#edit-INTERVAL').change(function(obj) {
    if (this.value != 0) {
      if($('#edit-UNTIL-datetime-year').val() == '') $('#edit-UNTIL-datetime-year').val($('#edit-start-year').val());
      if($('#edit-UNTIL-datetime-month').val() == '') $('#edit-UNTIL-datetime-month').val($('#edit-start-month').val());
      if($('#edit-UNTIL-datetime-day').val() == '') $('#edit-UNTIL-datetime-day').val($('#edit-start-day').val());
    } else {
     // if INTERVAL is cleared, clear the UNTIL fields also.
      $('#edit-UNTIL-datetime-year').val('');
      $('#edit-UNTIL-datetime-month').val('');
      $('#edit-UNTIL-datetime-day').val('');
    }
  });
});
 
function check_availability() {
  $('#ajax-display').hide('fast', function() {
    $('#ajax-display').html('Processing...');
  });
  $('#ajax-display').slideDown('fast');
  
  // get the resource ID, and all date-related form elements
  fields = $('#edit-resource-id, #edit-record-id, #edit-start-wrapper [name], #edit-end-wrapper [name], .date-clear [name]').serializeArray();
  // RRULE fields should ideally be in their own multidimensional array, but it is difficult to do that here
  // so, wait until Date module changes the RRULE field names to make this easier.
  /*rrule = new Object();
  rrule.name = 'rrule';
  rrule.value = $('.date-repeat [value]').serializeArray();
  fields[fields.length] = rrule;
  console.log(fields[0]);
  console.log(fields[fields.length -1]);*/
  
  // dispatch request by POST
  $.post( Drupal.settings.basePath + 'publicbookings/ajax/availability', fields, post_callback, 'json');
}

function post_callback( data ) {
  $('#ajax-display').hide('fast', function() {
    if ( typeof(data) != "object" ) {
      $('#ajax-display').html(data);
    } else {
      $('#ajax-display').html(data.html_all_conflicts);
    }
  });
  $('#ajax-display').show('fast');
}

// enable the 'Check availability' button only when resource and start/end times are set properly
function button_lock_check() {
  block_flag = false;
  if ($('#edit-resource-id').val() < 1) block_flag = true;
  $('#edit-start-wrapper [name], #edit-end-wrapper [name]').each(function() {
    if(this.value == '') block_flag = true;
  });
  if (block_flag) {
    $('#check-availability').attr('disabled','disabled');
  } else {
    $('#check-availability').attr('disabled','');
  }
}

function dump(arr,level) {
	var dumped_text = "";
	if(!level) level = 0;
	
	//The padding given at the beginning of the line.
	var level_padding = "";
	for(var j=0;j<level+1;j++) level_padding += "    ";
	
	if(typeof(arr) == 'object') { //Array/Hashes/Objects 
		for(var item in arr) {
			var value = arr[item];
			
			if(typeof(value) == 'object') { //If it is an array,
				dumped_text += level_padding + "'" + item + "' ...\n";
				dumped_text += dump(value,level+1);
			} else {
				dumped_text += level_padding + "'" + item + "' => \"" + value + "\"\n";
			}
		}
	} else { //Stings/Chars/Numbers etc.
		dumped_text = "===>"+arr+"<===("+typeof(arr)+")";
	}
	return dumped_text;
}

