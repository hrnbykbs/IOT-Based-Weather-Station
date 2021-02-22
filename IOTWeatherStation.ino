#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

DHT dht(2, DHT11); //DHT11 pini ayarlandı
Adafruit_BMP085 bmp;
WiFiClient client;

const char*  wifiAd = "Lazona - 2.4 GHz";  //Bağlanılacak wifi adı
const char*  wifiSifre = "lazina.5353";   //Bağlanılacak wifi şifresi

const char* thingSpeakHost = "api.thingspeak.com"; //buluta veri yollamada kullanılacak kodun bir kısmı
String  APIKey = "7FH9D311JD1JAXJM"; //buluttaki kanala ait veri gönderme anahtarı

void wifiBaglanti(){
 delay(10);
 Serial.println(); 
 Serial.print(wifiAd);
 Serial.print(" Kablosuz Agina Baglaniyor");
 WiFi.begin(wifiAd, wifiSifre); //wifi bağlantısı başlatılıyor
 
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(); Serial.print(wifiAd);
  Serial.println(" Kablosuz Agina Baglandi"); Serial.println(WiFi.localIP());
}

void setup() {
  dht.begin();
  bmp.begin();
  Serial.begin(115200); //seri port baudrate değeri
  wifiBaglanti();          
}

void loop() {

  float sicaklik = dht.readTemperature(); //sıcaklık ölçümü
  float nem = dht.readHumidity(); //nem ölçümü
  float bmpsicaklik = bmp.readTemperature();
  float basinc = bmp.readPressure(); //basınç ölçümü
  
if (client.connect (thingSpeakHost, 80)){ //buluta bağlantı işlemleri
     String getCode = APIKey;
     getCode +="&field1=";
     getCode += String(sicaklik);
     getCode +="&field2=";
     getCode += String(nem);
     getCode +="&field3=";
     getCode += String(basinc);
     getCode += "\r\n\r\n";
    //hangi alanlara hangi değerlerin gideceği belirtiliyor
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+APIKey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(getCode.length());
     client.print("\n\n");
     client.print(getCode);
     //buluta gönderim işlemleri
  Serial.println("-----------------------------------------------\n");
  Serial.println("Sıcaklık: ");
  Serial.println(sicaklik);
  Serial.println("Nem: ");
  Serial.println(nem);
  Serial.println("Bmpsicaklik: ");
  Serial.println(bmpsicaklik);
  Serial.println("Basinc: ");
  Serial.println(basinc);
  Serial.println ("Thingspeak'e veri gönderildi\n");  
  Serial.println("-----------------------------------------------");
  //port ekranına yazılacaklar
}
client.stop();
delay (15000); //15 saniyede bir veri gönderimi
}
