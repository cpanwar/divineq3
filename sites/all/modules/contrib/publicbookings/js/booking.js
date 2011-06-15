
var block_flag;

$(document).ready(function() {
  $('#ajax-availability').html('<input type="button" value="Check availability" id="check-availability" disabled="disabled" />');
  $('#check-availability').click( check_availability );
  $('#ajax-availability').css('padding-top', '1em');
  $('#ajax-display').hide();
  $('#ajax-display').css('padding', '0 1em 1em 1em');
  base_path = $('#edit-base-path').val();
 })


Drupal.behaviors.publicbookings = function (context) {
  $('#edit-start-month',context).change(function(obj) {
    $('#edit-end-month').val(this.value);
  });
  $('#edit-start-day',context).change(function(obj) {
    $('#edit-end-day').val(this.value);
  });
  $('#edit-start-year',context).change(function(obj) {
    $('#edit-end-year').val(this.value);
  });
  $('#edit-start-hour',context).change(function(obj) {
    $('#edit-end-hour').val(this.value);
  });
  $('#edit-start-minute',context).change(function(obj) {
    $('#edit-end-minute').val(this.value);
  });
  
  // date repeat automation
  // if INTERVAL is set, fill in the UNTIL field with the start date.
  $('#edit-INTERVAL',context).change(function(obj) {
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

  button_lock_check(); // initial check
  $('#edit-resource-id, #edit-start-wrapper [name], #edit-end-wrapper [name]',context).change( button_lock_check ); // and for subsequent changes
 }

function check_availability() {
  $('#ajax-display').show();
  $('#ajax-display').html("Processing");

  fields = $('#edit-resource-id, #edit-record-id, #edit-start-wrapper [name], #edit-end-wrapper [name], .date-clear [name]').serializeArray();
  $.ajax({
    type: 'POST',
    url: Drupal.settings.basePath + '?q=publicbookings/ajax/availability',
    success: print_availability,
    dataType: 'json',
    data: fields
  });
}

function print_availability(data) {
  $('#ajax-display').html(data);
}

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
