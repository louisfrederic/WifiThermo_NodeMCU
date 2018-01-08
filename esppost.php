<?php
//create a variable that will recieve the temperature
$Temp = $_POST["temperatur"];
$date = $date->format("d-M-Y  h:i:s  ");


$Write="<p>Temperatur : " . $Temp . " °C </p>";
file_put_contents('sensor.html',$Write);
?>