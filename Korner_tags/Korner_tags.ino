/*  I have made this project using

  ESP8266 module,a 3-axis accelerometer.

  Watch out it's project video od DIY Korner on my YouTube Channel.

  Search for "techiesms" on YouTube.

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define sensitivity 20 // 10 - highest sensitivity 100 - lowest sensitivity
#define sens A0  //Z-axis of accelerometer is attached to A0 pin.

// Details of router created by our Korner stick
const char* ssid = "ESPap";
const char* password = "thereisnospoon";

int num = 0;
long int total;
int avg;
bool triggered = 1;

void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  
  WiFi.mode(WIFI_STA);// turning the mode to station mode.
  
  WiFi.disconnect(true);// disconnect if already connected
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    pinMode(sens, INPUT);
    delay(15000);
  }
 
 //------------ Getting the local IP address
  String ip = WiFi.localIP().toString();
  Serial.println(ip);
  Serial.println("Connected");
//------------- Filtering the 4th part of our IP address // 192.168.4.1
  int count = 0;
  while (ip.charAt(count) != '.')
    count++;
  count++;
  while (ip.charAt(count) != '.')
    count++;
  count++;
  while (ip.charAt(count) != '.')
    count++;
  count++;
//-------------- Converting the 4th part of IP address to Int  
  String number = ip.substring(count);
  num = number.toInt();
  Serial.println(number);
}


void loop() {
  // wait for WiFi connection
  if ((WiFi.status() == WL_CONNECTED)) {

    HTTPClient http;
//---------------- Calbrating the surface to 0.    
if(triggered)
{
   for(int i =0 ; i<100; i++)
   {
    int temp = analogRead(sens);
    total = total + temp;
    delay(20);
   }

   avg = total / 100;
   triggered = 0;
   total = 0;
   Serial.print("AVERAGE ");Serial.println(avg);
}  

Serial.print("ANALOG - AVG = ");Serial.println(analogRead(sens) - avg);
Serial.print("AVG - ANALOG = ");Serial.println(avg - analogRead(sens));
    if (analogRead(sens) - avg > sensitivity || avg - analogRead(sens) > sensitivity)// if the module is deviated from its calibrated value than it will request a link based on its IP address
    {

      if (num == 1)
      {
        Serial.print("[HTTP] begin...1\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens1"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 2)
      {
        Serial.print("[HTTP] begin...2\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens2"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 3)
      {
        Serial.print("[HTTP] begin...3\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens3"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 4)
      {
        Serial.print("[HTTP] begin...4\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens4"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 5)
      {
        Serial.print("[HTTP] begin...5\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens5"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 6)
      {
        Serial.print("[HTTP] begin...6\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens6"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 7)
      {
        Serial.print("[HTTP] begin...7\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens7"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 8)
      {
        Serial.print("[HTTP] begin...8\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens8"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 9)
      {
        Serial.print("[HTTP] begin...9\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens9"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }

      else if (num == 10)
      {
        Serial.print("[HTTP] begin...10\n");
        // requesting required link
        http.begin("http://192.168.4.1/sens10"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        triggered = 1;
      }
      else
      {
        Serial.println("NOTHING TO DO");
      }
      
    }

  }
}




