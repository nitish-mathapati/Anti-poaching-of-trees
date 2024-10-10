# Anti-poaching-of-trees

  Now-a-days, there are many incidents happening about smuggling of trees like Sandalwood which are very expensive and rare in nature. Smuggling of sandalwood has created many law and order problems in India. Also, India’s economy has been greatly effected through these incidents. The main objective of our project is to deploy a system which can be used to restrict these kind of incidents like smuggling of sandalwood trees. This project design uses three different sensors namely, Flame sensor (to detect forest fires), Accelerometer (ADXL335) (to detect the inclination of tree which is being cut), DF Robot Gravity Analog Sound Level Meter (for effective detection of illegal logging of trees i.e. the sounds generated while axing the tree is sensed). Data generated from these three sensors is continuously monitored by the forest officials with the help of  BLYNK server of  IoT (Blynk is an IoT platform that allows you to build your own apps to control certain devices over the internet). With respect to the sensors, their output devices are activated through relay switch. For all these sensors, a buzzer is activated when their conditions are violated.

We use BLYNK IoT cloud application to receive the message and alert notification will be popped-up on the mobile. Since the BLYNK app is linked to your Email-ID, the notification is sent to mail as well.

FUTURE SCOPE of this project:
This project can be built with some more sensors like, Camera sensor – which records the photage of the trees and the person who came to cut the tree, Humidity sensor – which measures the humidity and temperature around the tree in forest, GSM module – which helps to receive the SMS to the forest agents and will be stored in the cloud, GPS location module – which stores the location of the tree where the poaching process is been going on and many other sensors.
We made the above project with the help of both Arduino UNO and ESP8266 Wi-Fi module, but can also be done only through ESP8266 Wi-Fi module, which will be easier.
The upgraded version of BLYNK IoT cloud can be purchased for extra benefits. The benefits are, you can create many no. of devices in the single account, you can access organization and location features in the BLYNK IoT app and many more. 

    
In this we use:
1. Arduino UNO Microcontroller
2. ESP8266 Wi-Fi Module
3. Accelerometer sensor
4. Flame sensor
5. DFRobot Gravity Analog Sound Level Meter
6. Relay module

The images of the following components are given in files. The separate and integrated code is also given.
