#Self-Sorting-Dustbin
//A self sorting dustbin which can sort wet and dry waste by its own. It's having a humidity sensor which tracks the humidity in it and decides if it's a wet or a dry //waste. 
#include "dht.h"
int pos;
#include<Servo.h>
Servo myservo; 
#define dht_apin A0
 dht DHT;
 const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 3; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 10; 
float duration_us, distance_cm;

int WET= 3; 
int DRY= 2;  
int Sensor= 1; // Soil Sensor input at Analog PIN A1
int value= 0; 
void setup() { 
myservo.attach(5);
 Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode`
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT); }
 void loop() { 
   digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10000);
  digitalWrite(TRIG_PIN, LOW);
   duration_us = pulseIn(ECHO_PIN, HIGH);
   delay(1000);
  // calculate the distance
  distance_cm = 0.017 * duration_us;
 DHT.read11(dht_apin);

 
Serial.print("Sample OK: "); 
Serial.print(DHT.temperature); 
Serial.print(" *C, "); 
Serial.print(DHT.humidity);
 Serial.println(" %"); 
 Serial.print("MOISTURE LEVEL : ");
  value= analogRead(Sensor);
  value= value/10;
  Serial.println(value); 
if ((DHT.humidity <= 64)&&(distance_cm < DISTANCE_THRESHOLD)) 
//change the humidity reading according to the current humidity readings
{
myservo.write(0);
}
 else if((DHT.humidity >= 65)&&(distance_cm < DISTANCE_THRESHOLD)) 
 //change the humidity readings according to the current humidity+2
 {

myservo.write(180);

 }
 else
 {
myservo.write(90); }
delay(1000);
 }
