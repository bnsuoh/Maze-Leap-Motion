/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
Servo serX;  // create serX object to control a serX 
 
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attaches the serX on pin 9 to the serX object 
  serX.write(0);
  delay(500);
} 
 
void loop() {
  while(Serial.available() && Serial.read()>0){
    int x=int(Serial.read());
    turn(x);
    delay(5);
  }
} 
void turn(int x){
  int a=90;
  if (x<=0){
    a=0;
  }
  else if(x>180){
    a=180;
  }
  else{
    a=x;
  }
  serX.write(a);
}
