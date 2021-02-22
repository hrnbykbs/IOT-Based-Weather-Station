#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

DHT dht(2, DHT11); //D4
Adafruit_BMP085 bmp;
WiFiClient client;

const char*  wifiName = "Wifi_Name";
const char*  wifiPassword = "Wifi_Password";

const char* thingSpeakHost = "api.thingspeak.com";
String  APIKey = "API_KEY"; //data send key for the channel in the cloud

void wifiConnection(){
 delay(10);
 Serial.println(); 
 Serial.print(wifiName);
 Serial.print(" Connecting...");
 WiFi.begin(wifiName, wifiPassword); //wifi connection starting
 
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(); 
  Serial.print(wifiName);
  Serial.println(" Connected"); 
  Serial.println(WiFi.localIP());
}

void setup() {
  dht.begin();
  bmp.begin();
  Serial.begin(115200); //serial port baudrate value
  wifiConnection();          
}

void loop() {

  float temperature = dht.readTemperature(); //temperature measurement
  float moisture = dht.readHumidity(); //moisture measurement
  //float bmpTemperature = bmp.readTemperature();
  float pressure = bmp.readPressure(); //pressure measurement
  
if (client.connect (thingSpeakHost, 80)){ //cloud connection operations
     String getCode = APIKey;
     getCode +="&field1=";
     getCode += String(temperature);
     getCode +="&field2=";
     getCode += String(moisture);
     getCode +="&field3=";
     getCode += String(pressure);
     getCode += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+APIKey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(getCode.length());
     client.print("\n\n");
     client.print(getCode);

  Serial.println("-----------------------------------------------\n");
  Serial.println("Temperature: ");
  Serial.println(temperature);
  Serial.println("Moisture: ");
  Serial.println(moisture);
  //Serial.println("BmpTemperature: ");
  //Serial.println(bmpTemperature);
  Serial.println("Pressure: ");
  Serial.println(pressure);
  Serial.println ("Data sent to ThingSpeak\n");  
  Serial.println("-----------------------------------------------");
}
client.stop();
delay (15000); //Data transmission every 15 seconds
}
