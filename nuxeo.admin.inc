<?php 

function nuxeo_admin_form() {
	$form = array(
		'nuxeo_db_driver' => array(
			'#type' => 'textfield',
			'#title' => 'Database Driver',
			'#description' => 'Can be one of mysql, pgsql, sqlite, etc',
			'#default_value' => variable_get('nuxeo_db_driver', ''),
		),
		'nuxeo_db_host' => array(
			'#type' => 'textfield',
			'#title' => 'Database Host',
			'#description' => 'Where the Nuxeo database is hosted. localhost, 10.2.1.2, etc',
			'#default_value' => variable_get('nuxeo_db_host', ''),
		),
		'nuxeo_db_name' => array(
			'#type' => 'textfield',
			'#title' => 'Database Name',
			'#description' => 'The name of the Nuxeo database',
			'#default_value' => variable_get('nuxeo_db_name', ''),
		),
		'nuxeo_db_user' => array(
			'#type' => 'textfield',
			'#title' => 'Database Username',
			'#description' => 'The user that connected to the Nuxeo database',
			'#default_value' => variable_get('nuxeo_db_user', ''),
		),
		'nuxeo_db_pass' => array(
			'#type' => 'textfield',
			'#title' => 'Database Password',
			'#description' => 'The password used to connect to the Nuxeo database',
			'#default_value' => variable_get('nuxeo_db_pass', ''),
		),
		'nuxeo_email_as_username' => array(
			'#type' => 'checkbox',
			'#title' => 'Force Email as Username',
			'#description' => 'This setting forces newly created users to have their email address double as their username',
			'#default_value' => variable_get('nuxeo_email_as_username', false)
		),
		'utilities' => array(
			'#type' => 'fieldset',
			'#title' => 'Utilities',
			
			'import' => array(
				'#type' => 'submit',
				'#value' => 'Import Nuxeo Users',
				'#submit' => array('_nuxeo_import_users')
			)
		)
	);

	return system_settings_form($form);
}