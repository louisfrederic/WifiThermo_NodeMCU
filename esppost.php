<?php
//create a variable that will recieve the temperature
$Temp = $_POST["temperatur"];
$Write="<p>Temperatur : " . $Temp . " °C </p>";
file_put_contents('index.html',$Write);
?>
