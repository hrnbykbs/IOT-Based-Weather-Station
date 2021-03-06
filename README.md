# IOT Weather Station
This project was made for the realization of an IOT based weather station. Values such as temperature, humidity and air pressure are measured and values are determined. If the situation is far below or far above the average limit; Information about this situation is made to people by e-mail.

# Application Setup
A. Required Components: Hardware <br>
1- NodeMCU Lolin Esp8266 Wifi Module <br>
2- Temperature and Humidity Sensor (DHT11) <br>
3- Air Pressure Sensor (BMP180) <br>
4- Breadboard <br>
5- Jumper Cables <br>

B. Required Components: Software <br>
1- Arduino IDE <br>
2- Accessible Wifi <br>
3- ThingSpeak (Cloud Environment) <br>
4- IFTTT (Trigger Service) <br>

# Circuit Setup
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/circuitSetupWeatherStation.png?raw=true)

# Results
# A. Sensors Data Read and Data Sent to ThingSpeak
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/sensorDataReadAndDataSentToCloud.png?raw=true)

# B. Display of Data Sent to ThingSpeak
# 1- Temperature Chart and Gauge
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/temperatureData.png?raw=true)

# 2- Humidity Chart and Gauge
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/humidityData.png?raw=true)

# 3- Air Pressure Chart and Numeric Display
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/airPressureData.png?raw=true)

# C. IFTTT Applets
# 1- High Temperature Applet
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/highTemperatureApplet.png?raw=true)

# 2- Low Temperature Applet
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/lowTemperatureApplet.png?raw=true)

# D. ThingSpeak ThingHTTP Protocols
# 1- High Temperature ThingHTTP Protocol
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/highTemperatureThingHTTPProtocol.png?raw=true)

# 2- Low Temperature ThingHTTP Protocol
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/lowTemperatureThingHTTPProtocol.png?raw=true)

# E. ThingSpeak React Protocols
# 1- High Temperature React
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/highTemperatureReact.png?raw=true)

# 2- Low Temperature React
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/lowTemperatureReact.png?raw=true)

# F. Sending Mail
# 1- High Temperature Mail
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/highTemperatureMail.png?raw=true)

# 2- Low Temperature Mail
![alt text](https://github.com/hrnbykbs/AllPictures/blob/main/IOTBasedWeatherStation/lowTemperatureMail.png?raw=true)
