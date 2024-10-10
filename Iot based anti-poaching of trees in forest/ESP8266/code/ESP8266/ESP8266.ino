//Include the library files
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
//#define BLYNK_AUTH_TOKEN "eXMruWnyXnnZXbW0sb-p55E77s0L42sk"

#define BLYNK_AUTH_TOKEN "" //Enter your blynk auth token
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}