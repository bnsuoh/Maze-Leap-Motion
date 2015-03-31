/* Leap Motion Maze
  by Bensu Sicim
  This code controls a simple maze game using Leap Motion and servos
  The goal of the game is to put the ball in the pit
*/ 

#include <Servo.h> 
Servo serX,serY;  // create servo objects
int turnX,turnY,pos;
int turnXbefore=0; //set initial positions to 0
int turnYbefore=0;
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attach the serX on pin 9
  serY.attach(10); // attach the serY on pin 10
} 
 
void loop() {
  char buffer[] = {' ',' ',' ',' ',' ',' '}; // receive up to 6 bytes
  if(Serial.available()){
     Serial.readBytesUntil('n', buffer, 6); //read data
     int x = (((int)buffer[0]-48)*100+((int)buffer[1]-48)*10+((int)buffer[2]-48))-100; //get the first 3 digits of buffer and convert them into int
     int y = (((int)buffer[3]-48)*100+((int)buffer[4]-48)*10+((int)buffer[2]-48))-100; //get the second 3 digits " " " " " " " " 
     turn(x,serX,turnX,turnXbefore); //control serX
     turn(y,serY,turnY,turnYbefore); //control serY
  }
} 
void turn(int a, Servo ser, int turn, int before){
  if (a<=0){ //give value to turn between [0,180]
    turn=0;
  }
  else if(a>=180){
    turn=180;
  }
  else{
    turn=a;
  }
  if(turn>before){ //increase the angle if turn is greater than the previous angle
    for(pos=before;pos<=turn;pos+=1){
      ser.write(pos);
      delay(5);
    }
    before=turn;
  }
  else if(turn<before){ //decrease the angle if turn is less than the previous angle
    for(pos=before;pos>=turn;pos-=1){
      ser.write(pos);
      delay(5);
    }
    before=turn; //change previous angle
  }
}
