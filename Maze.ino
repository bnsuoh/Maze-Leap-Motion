/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
Servo serX;  // create serX object to control a serX 
char numStr[4];
int turn,pos;
int turnbefore=0;
int serTurn=90;
boolean turnR=false;
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attaches the serX on pin 9 to the serX object
} 
 
void loop() {
  char buffer[] = {' ',' ',' '}; // Receive up to 7 bytes
  if(Serial.available()){
     Serial.readBytesUntil('n', buffer, 3);
     int x = atoi(buffer)-100;
     if (x<=0){
       turn=0;
     }
     else if(x>=180){
       turn=180;
     }
     else{
       turn=x;
     }
     if(turn>turnbefore){
       for(pos=turnbefore;pos<=turn;pos+=1){
         serX.write(pos);
         delay(5);
       }
       turnbefore=turn;
     }
     else if(turn<turnbefore){
       for(pos=turnbefore;pos>=turn;pos-=1){
         serX.write(pos);
         delay(5);
       }
       turnbefore=turn;
     }
  }
} 
