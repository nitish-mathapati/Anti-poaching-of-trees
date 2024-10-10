#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

int FLAME = 3;
int LED = 13;
int isFlame = HIGH;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(FLAME, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();

  isFlame = digitalRead(FLAME);
  if (isFlame == LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("FLAME is detected......!!!!!");
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("NORMAL condition....");
    delay(2000);
  }
  

}
