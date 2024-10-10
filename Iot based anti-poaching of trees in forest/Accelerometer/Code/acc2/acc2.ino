#define xPin A0
#define yPin A1
#define zPin A2
//--------------------------------------------------------------
//calibrated minimum and maximum Raw Ranges for each axis
//use calibration.ino file to get these values
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
int xMin = 266;
int xMax = 400;
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
int yMin = 273;
int yMax = 408;
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
int zMin = 269;
int zMax = 402;
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//--------------------------------------------------------------
// Take multiple samples to reduce noise
const int samples = 10;
//--------------------------------------------------------------
int LED = 13;


void setup() 
{
  //analogReference(EXTERNAL);
  Serial.begin(9600);
}


void loop() 
{
  //--------------------------------------------------------------
  //Read raw values
  int xRaw=0,yRaw=0,zRaw=0;
  for(int i=0;i<samples;i++)
  {
    xRaw+=analogRead(xPin);
    yRaw+=analogRead(yPin);
    zRaw+=analogRead(zPin);
  }
  xRaw/=samples;
  yRaw/=samples;
  zRaw/=samples;
  //--------------------------------------------------------------
  //Convert raw values to 'milli-Gs"
  //Convert value of RawMin to -1000
  //Convert value of RawMax to 1000
  long xMilliG = map(xRaw, xMin, xMax, -1000, 1000);
  long yMilliG = map(yRaw, yMin, yMax, -1000, 1000);
  long zMilliG = map(zRaw, zMin, zMax, -1000, 1000);
  //--------------------------------------------------------------
  // re-scale to fractional Gs
  //float x_g_value = xMilliG / 1000.0;
  //float y_g_value = yMilliG / 1000.0;
  //float z_g_value = zMilliG / 1000.0;
  //--------------------------------------------------------------
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
  Serial.print(xRaw);
  //Serial.print(x_g_value,2);
  Serial.print("G");
  Serial.print("\t");
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
  Serial.print(yRaw);
  //Serial.print(y_g_value,2);
  Serial.print("G");
  Serial.print("\t");
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
  Serial.print(zRaw);
  //Serial.print(z_g_value,2);
  Serial.print("G");
  Serial.println();
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
  //--------------------------------------------------------------
  delay(1000);

  if(!(330 <= xRaw <= 350) || (385 <= yRaw <= 400) || (370 <= zRaw <= 385))
  {
    digitalWrite(LED, HIGH);
    Serial.println("Motion detected.......!!!!");
    delay(200);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("Normal condition.....!!");
    delay(1000);
  }

}