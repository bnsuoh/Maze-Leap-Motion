/* Leap Motion Maze
  by Bensu Sicim
  This code controls a simple maze game using Leap Motion and servos
  The goal of the game is to put the ball in the pit
*/ 

#include <Servo.h> 
Servo serX,serY;  // create servo objects
int turnX,turnY,pos,xAng,yAng;
int x=90;
int y=90;
String a,b;
int beforeX=0; //set initial positions to 0
int beforeY=0;
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attach the serX on pin 9
  serY.attach(8); // attach the serY on pin 10
  serX.write(90);
  serY.write(90);
  xAng=90;
  yAng=90;

} 
void loop() {
  char buffer[] = {' ',' ',' ',' ',' ',' '}; // receive up to 6 bytes
  if(Serial.available()){
     Serial.readBytesUntil('n', buffer, 6); //read data
     a=String(buffer[0])+String(buffer[1])+String(buffer[2]);
     b=String(buffer[3])+String(buffer[4])+String(buffer[5]);
     x=a.toInt()-100;
     y=b.toInt()-100;
     /*x = (((int)buffer[0])*100+((int)buffer[1])*10+((int)buffer[2]))-100; //get the first 3 digits of buffer and convert them into int
     y = (((int)buffer[3])*100+((int)buffer[4])*10+((int)buffer[2]))-100; //get the second 3 digits " " " " " " " " */
  }
     if(x>90){
       xAng+=5;
     }
     else if(x<90){
       xAng-=5;
     }
     
     if(y>90){
       yAng+=5;
     }
     else if(y<90){
       yAng-=5;
     }
     if(xAng<=0){
       xAng=0;
     }
     else if(xAng>=180){
       xAng=180;
     }
     if(yAng<=0){
       yAng=0;
     }
     else if(yAng>=180){
       yAng=180;
     }
     serX.write(xAng);
     serY.write(yAng);
     delay(40);
}
