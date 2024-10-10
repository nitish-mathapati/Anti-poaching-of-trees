#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "";  // type your wifi name
char pass[] = "";  // type your wifi password
 

BlynkTimer timer;
int flag=0; 
void sendSensor(){ 
   int isButtonPressed = digitalRead(D1);
    
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the Forest");  
    //Blynk.email("ntshmathapati2003@gmail.com", "Alert", "Fire Detected!");
    Blynk.logEvent("Alerts","Fire Detected in the Forest");
    
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
    
  }

}
void sendSensor2(){ 
   int micValue = analogRead(A0);
  int x = micValue*50;
 
  

  if (x>20000)
  {
     Serial.println(x);
   Serial.println("Sound in the Forest");  
    //Blynk.email("ntshmathapati2003@gmail.com", "Alert", "Fire Detected!");
    Blynk.logEvent("fire_alert","Sound Detected in the Forest");
  }
  else
  {
     Serial.println("NORMALForest");  
  }

 
}
void setup(){
  pinMode(D1, INPUT);
   //pinMode(A0, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, sendSensor);
  //timer.setInterval(5000L, sendSensor2);
}

void loop(){
  Blynk.run();
  timer.run();
}