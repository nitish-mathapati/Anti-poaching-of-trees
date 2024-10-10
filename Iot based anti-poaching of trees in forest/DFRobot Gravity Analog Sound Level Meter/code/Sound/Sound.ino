int sound = A2; // Digital output pin
int LED = 13; // LED pin or Buzzer
//const int threshold=10;
int micValue;
void setup() {
  pinMode(sound, INPUT);
  //pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  micValue = analogRead(sound);
  int x = micValue*50;
  //delay(2000);
  /*if (micValue >= threshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Sound detected!");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("Quiet environment");
  }
  */
  Serial.println(x);
  delay(2000);
  if (x>17000)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Sound detected....../////");
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

