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
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attaches the serX on pin 9 to the serX object 
  serX.write(0);
  delay(500);
} 
 
void loop() {
  char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes
  while(Serial.available() && Serial.read()>0){
     Serial.readBytesUntil('n', buffer, 7);
     int x = atoi(buffer);
     if (x<=0){
       turn=0;
     }
     else if(x>180){
       turn=180;
     }
     else{
       turn=x;
     }
     if(turn>turnbefore){
       for(pos=0;pos<=turn;pos+=1){
         serX.write(pos);
         delay(5);
       }
     }
     else if(turn<turnbefore){
       for(pos=turn;pos>=0;pos-=1){
         serX.write(pos);
         delay(5);
       }
     }
     turnbefore=turn;
  }
} 
