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
array_push($a_json_results,array('control_id' => '3', 'control_value' => rand(0,100)));
array_push($a_json_results,array('control_id' => '5', 'control_value' => rand(0,100)));
array_push($a_json_results,array('control_id' => '6', 'control_value' => rand(0,100)));

$msg_out_json = "";
$msg_out_json = json_encode(array("data" => $a_json_results),JSON_PRETTY_PRINT);
echo $msg_out_json;

?>