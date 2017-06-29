/*
   I have made this project using

   ESP8266 module, a piezo buzzer.

   Watch out it's project video of DIY Korner on my YouTube Channel

   Search for "techiesms" on YouTube.
   
   Adafruit MQTT
   WiFi Access Point 
*/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#define buzzer D8 // Buzzer is attached on D8 pin

// Details of your router.
#define WLAN_SSID       "SSID"
#define WLAN_PASS       "PASSWORD"

// Details for making ESP act as a router.
const char *ssid = "ESPap";
const char *password = "thereisnospoon";


#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "USERNAME"
#define AIO_KEY         "AIO_KEY"


ESP8266WebServer server(80);

WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup feeds each for different korner tags.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish sensor_2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens2");
Adafruit_MQTT_Publish sensor_3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens3");
Adafruit_MQTT_Publish sensor_4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens4");
Adafruit_MQTT_Publish sensor_5 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens5");
Adafruit_MQTT_Publish sensor_6 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens6");
Adafruit_MQTT_Publish sensor_7 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens7");
Adafruit_MQTT_Publish sensor_8 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens8");
Adafruit_MQTT_Publish sensor_9 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens9");
Adafruit_MQTT_Publish sensor_10 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sens10");


/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void handleRoot()
{
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

uint32_t x = 0;

void sensor2()
{
  Serial.println("Link Requested from one of the device 2");
  if (!sensor_2.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_2.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}


void sensor3()
{
  Serial.println("Link Requested from one of the device 3");
  if (! sensor_3.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_3.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor4()
{
  Serial.println("Link Requested from one of the device 4");
  if (! sensor_4.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_4.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor5()
{
  Serial.println("Link Requested from one of the device 5");
  if (! sensor_5.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_5.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor6()
{
  Serial.println("Link Requested from one of the device 6");
  if (! sensor_6.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_6.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor7()
{
  Serial.println("Link Requested from one of the device 7");
  if (! sensor_7.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_7.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor8()
{
  Serial.println("Link Requested from one of the device 8");
  if (! sensor_8.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_8.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}

void sensor9()
{
  Serial.println("Link Requested from one of the device 9");
  if (! sensor_9.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_9.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}


void sensor10()
{
  Serial.println("Link Requested from one of the device 10");
  if (! sensor_10.publish(1)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  server.send(200, "text/html", "<h1>Your Request Serviced</h1>");
  if (!sensor_10.publish(0)) {
    Serial.println(F("Published"));
  } else {
    Serial.println(F("OK!"));
  }
}
void setup() 
{
    
  WiFi.mode(WIFI_AP_STA);// Selecting mode 3 
  delay(1000);
  
  Serial.begin(115200);
  
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  pinMode(buzzer, OUTPUT);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot); 
  server.on("/sens2", sensor2); //192.168.4.1/sens2 
  server.on("/sens3", sensor3);
  server.on("/sens4", sensor4);
  server.on("/sens5", sensor5);
  server.on("/sens6", sensor6);
  server.on("/sens7", sensor7);
  server.on("/sens8", sensor8);
  server.on("/sens9", sensor9);
  server.on("/sens10", sensor10);
  server.begin();
  
  Serial.println("HTTP server started");

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.

  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

}

void loop() 
{
  MQTT_connect(); //Establishing MQTT connection
  Adafruit_MQTT_Subscribe *subscription;
  Serial.println("Waiting for the link");
  digitalWrite(buzzer, LOW); // by default the buzzer will be low
  server.handleClient(); // waiting for link to be requested from tags
}


void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}
