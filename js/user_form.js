jQuery(document).ready(function($) {
	// if email address is present, replace username with it
	if ($('#edit-mail').val() != '') {
		$('#edit-name').val($('#edit-mail').val());
	}
	// bind events to keep mail and name in sync
	$('#edit-mail').keyup(function(event) {
		$('#edit-name').val(event.target.value);
	});
	$('#edit-mail').focusout(function(event) {
		$('#edit-name').val(event.target.value);
	});
	$('#edit-name').keyup(function(event) {
		$('#edit-mail').val(event.target.value);
	});
	$('#edit-name').focusout(function(event) {
		$('#edit-mail').val(event.target.value);
	});
});