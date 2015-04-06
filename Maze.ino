/* Leap Motion Maze
  by Bensu Sicim
  This code controls a simple maze game using Leap Motion and servos
  The goal of the game is to put the ball in the pit
*/ 

#include <Servo.h> 
Servo serX,serY;  // create servo objects
int turnX,turnY,pos,x,y;
int beforeX=0; //set initial positions to 0
int beforeY=0;
void setup() { 
  Serial.begin(9600);
  serX.attach(9);  // attach the serX on pin 9
  serY.attach(8); // attach the serY on pin 10
} 
void loop() {
  char buffer[] = {' ',' ',' ',' ',' ',' '}; // receive up to 6 bytes
  if(Serial.available()){
     Serial.readBytesUntil('n', buffer, 6); //read data
     x = (((int)buffer[0]-48)*100+((int)buffer[1]-48)*10+((int)buffer[2]-48))-100; //get the first 3 digits of buffer and convert them into int
     y = (((int)buffer[3]-48)*100+((int)buffer[4]-48)*10+((int)buffer[2]-48))-100; //get the second 3 digits " " " " " " " " 
     turn();
  }
} 
void turn(){
  if (x<=0){ //give value to turn between [0,180]
    turnX=0;
  }
  else if(x>=180){
    turnX=180;
  }
  else{
    turnX=x;
  }
  if (y<=0){ //give value to turn between [0,180]
    turnY=0;
  }
  else if(y>=180){
    turnY=180;
  }
  else{
    turnY=y;
  }
  if(turnX>beforeX && turnY>beforeY){ //increase the angle if turn is greater than the previous angle, do the opposite if not
    for(pos=beforeX;pos<=turnX;pos+=1){
      serX.write(pos);
      delay(1);
    }
    for(pos=beforeY;pos<=turnY;pos+=1){
      serY.write(pos);
      delay(1);
    }
  }
  else if(turnX<beforeX && turnY<beforeY){
    for(pos=beforeX;pos>=turnX;pos-=1){
      serX.write(pos);
      delay(1);
    }
    for(pos=beforeY;pos>=turnY;pos-=1){
      serY.write(pos);
      delay(1);
    }
  }
  else if(turnX>beforeX && turnY<beforeY){ //increase the angle if turn is greater than the previous angle
    for(pos=beforeX;pos<=turnX;pos+=1){
      serX.write(pos);
      delay(1);
    }
    for(pos=beforeY;pos>=turnY;pos-=1){
      serY.write(pos);
      delay(1);
    }
  }
  else if(turnX<beforeX && turnY>beforeY){
    for(pos=beforeX;pos>=turnX;pos-=1){
      serX.write(pos);
      delay(1);
    }
    for(pos=beforeY;pos<=turnY;pos+=1){
      serY.write(pos);
      delay(1);
    }
  }
  beforeY=turnY; //change previous angle
  beforeX=turnX; //change previous angle
}
