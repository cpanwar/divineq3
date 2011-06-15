
$(document).ready(function() {
    $('#ajax-display').html('test');
  })

Drupal.behaviors.publicbookings = function (context) {
  $('#edit-resource-id',context).change( function() {
    $('#ajax-display').html("Changing");
    var fromDrupal = function(data) {
      //var result = Drupal.parseJson(data);
      var text = '<ul>';
      for ( myKey in data ) {
        text += "<li>data["+myKey+"] = " + data[myKey] + "</li>";
      }
      $('#ajax-display').html(text+"</li>");
    }
    select = document.getElementById('edit-resource-id');
    val    = select.value;
    fields = Drupal.settings.basePath + '?q=publicbookings/ajax/resource/list/' + val;
    $('#ajax-display').html("Value: " + fields);
      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + '?q=publicbookings/ajax/resource/list/' + val,
        success: fromDrupal,
        dataType: 'json',
        data: 'resourceID=' + val
      });
    });
}

