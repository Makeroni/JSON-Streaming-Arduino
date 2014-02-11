<?php
//Return JSON data
//ini_set( 'default_charset', 'UTF-8' );
//header( 'Content-Type: text/html; charset=utf-8' );
// Prevent caching.
header('Cache-Control: no-cache, must-revalidate');
header('Expires: Mon, 01 Jan 1996 00:00:00 GMT');

// The JSON standard MIME header.
header('Content-type: application/json');

$a_json_results = array();

for($x=0; $x<=13; $x++)
{
	array_push($a_json_results, array('control_id' => $x, 'control_value' => rand(0,100)));
}
$msg_out_json = "";
//$msg_out_json = json_encode($a_json_results);
$msg_out_json = json_encode(array("data" => $a_json_results));

echo $msg_out_json;

?>
