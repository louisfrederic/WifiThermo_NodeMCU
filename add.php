<?php

$date = new DateTime();
$date = $date->format("d-M-Y  h:i:s  ");


if(!empty($_GET["temp1"]))
{
 $tempesp = "Temperature=";
 $tempesp .= ($_GET["temp1"]);
 file_put_contents("/media/USB/Temp.ESP", $date);
 file_put_contents("/media/USB/Temp.ESP", $tempesp, FILE_APPEND);
}


echo $tempesp;

?>