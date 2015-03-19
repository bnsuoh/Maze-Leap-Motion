/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
Servo serX;  // create serX object to control a serX 
int pos = 0;    // variable to store the serX position 
String inputString = "";
 
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attaches the serX on pin 9 to the serX object 
  serX.write(0);
} 
 
void loop() {
  while(Serial.available()>0){
    int x=Serial.parseInt();
    turn(x);
  }
} 
void turn(int x){
  if (x<=0){
    serX.write(0);
  }
  else if(x>=180){
    serX.write(180);
  }
  else{
    serX.write(x);
  }
}
