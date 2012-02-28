<?php 
define('DRUPAL_ROOT', getcwd().'/../../../../..');
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

if (!isset($argv[1]) || !isset($argv[2])) {
	print "Imports users from csv into Drupal and associates them with a role\n";
	print "Usage: user_import_csv <file.csv> <role_name>\n";
	print "CSV Format: FirstName, LastName, Email, Password\n";
	exit();
}

// ensure the role exists and load it
$role = user_role_load_by_name($argv[2]);
if (!$role) {
	print "The role you specified couldn't be found.  Did you spell it right?\n";
	exit();
}

// open the csv file and read lines
$csv = fopen($argv[1], 'r');
if (!$csv) {
	print "The CSV file couldn't be opened\n";
	exit();
}
while ($line = fgetcsv($csv)) {
	// print_r($line);
	// ensure this user isn't already in the system
	$exists = db_query('SELECT mail FROM {users} u WHERE u.mail = :mail',
		array(':mail' => $line[2]))
		->rowCount();
	if ($exists > 0) {
		print "Not re-adding existing user: {$line[0]} {$line[1]} - {$line[2]}\n";
		continue;
	}
	// assemble new user object
	$account = new stdClass();
	$account->is_new = TRUE;
	$account->status = 1;
	$account->name = $line[2];
	$account->mail = $line[2];
	$account->field_nuxeo_pass['und'][0]['value'] = _nuxeo_encode_pass($line[3]);
	$account->roles[$role->rid] = $role->name;
	user_save($account, array('pass' => $line[3]));
}

