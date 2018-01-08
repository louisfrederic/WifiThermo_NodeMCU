#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "****";
const char* password = "*********";
const char* host = "192.168.178.34";
Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  //Serial.println();
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
}
  
void loop() {
    //Serial.print("Temperature = ");
    //Serial.print(bmp.readTemperature());
    //Serial.println(" *C");
    
    // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
//temp variable is set with a function to check the temp of an DS18B20 sensor. Let me know if you need it
  String data = "temp1=" + (String)bmp.readTemperature(); 
// "temp1=" is what is going to be sent using GET to the apache server, see code in add.php

  // We now create a URI for the request
  String url = "GET /add.php?" + data + " HTTP/1.1";
  Serial.println(url);
client.println(url);
  client.println("Host: 192.168.178.34");
  //client.println("Connection: close");
  client.println();
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  client.stop(); //Stopping client
//  ESP.deepSleep(60U*60*1000000); //U for unsigned
  delay(1000); //for above sleep
}
