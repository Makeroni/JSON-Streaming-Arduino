<?
# We start with the standard headers. PHP allows us this much
header("Cache-Control: no-cache");
header("Cache-Control: private");
header("Pragma: no-cache");
header("Content-type: text/plain");

# Set this so PHP doesn't timeout during a long stream
set_time_limit(0);

# Disable Apache and PHP's compression of output to the client
@apache_setenv('no-gzip', 1);
@ini_set('zlib.output_compression', 0);

# Set implicit flush, and flush all current buffers
@ini_set('implicit_flush', 1);
for ($i = 0; $i < ob_get_level(); $i++)
    ob_end_flush();
ob_implicit_flush(1);

# The loop
$i=0;
while (true) {

    # Rainbow gradient
    $red   = sin($i*2*pi()/128 + 0) * 127 + 128;
    $green = sin($i*2*pi()/128 + 2) * 127 + 128;
    $blue  = sin($i*2*pi()/128 + 4) * 127 + 128;

    # JSON data for red color
    $id = 3;
    $value = sprintf("%03d", $red);
    $id = sprintf("%03d", $id);
    $msg = "{ \"id\" : ".$id.", \"value\" : ".$value." },\n";
    $msg = str_replace(': 00', ':   ', $msg);
    $msg = str_replace(': 0', ':  ', $msg);
    echo $msg;

    # JSON data for green color
    $id = 5;
    $value = sprintf("%03d", $green);
    $id = sprintf("%03d", $id);
    $msg = "{ \"id\" : ".$id.", \"value\" : ".$value." },\n";
    $msg = str_replace(': 00', ':   ', $msg);
    $msg = str_replace(': 0', ':  ', $msg);
    echo $msg;

    # JSON data for blue color
    $id = 6;
    $value = sprintf("%03d", $blue);
    $id = sprintf("%03d", $id);
    $msg = "{ \"id\" : ".$id.", \"value\" : ".$value." },\n";
    $msg = str_replace(': 00', ':   ', $msg);
    $msg = str_replace(': 0', ':  ', $msg);
    echo $msg;

    # Advance gradient and loop
    $i=$i+2;
    if($i==128){ $i=0; }
    
    # 100ms sleep (10 messages per second)
    usleep(100000);
}
?>
