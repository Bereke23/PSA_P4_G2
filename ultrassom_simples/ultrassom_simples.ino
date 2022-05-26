#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 8;
const int RightMotorForward = 4;
const int RightMotorBackward = 2;

#define ENA_m1  3      
#define ENB_m1  5

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){
  
  pinMode(ENA_m1, OUTPUT);
  pinMode(ENB_m1, OUTPUT);


  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  analogWrite(ENA_m1, 120);
  analogWrite(ENB_m1, 120);
  
  
  servo_motor.attach(6); //our servo pin

  servo_motor.write(100);
  
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
}

void loop(){
  int distanceTemp = 0;

  servo_motor.write(100);
  distance = readPing();
  makeChange();
  
  delay(100);

}


void makeChange(){
  
  int distanceRight = 0;
  int distanceLeft = 0;
  
  if (distance <= 35){
    moveStop();
    delay(100);
    moveBackward();
    delay(100);
    moveStop();
    delay(100);

    servo_motor.write(50);
    distanceRight = readPing();
    delay(200);

    servo_motor.write(150);
    distanceLeft = readPing();
    delay(200);

    if (distanceRight >= distanceLeft){
      turnRight();
      delay(500);
      moveStop();
   //   moveForward();
    }
    else{
      turnLeft();
      delay(500);
      moveStop();
   //   moveForward();
    }
  }
  else{
    moveForward(); 
  }

}


int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){
    goesForward=true;

    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, LOW); 
    
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  
}

void turnRight(){

  int counter=0;

  analogWrite(ENA_m1, 180);
  analogWrite(ENB_m1, 180);

  while(counter < 2){
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
  
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, LOW);
  
    delay(250);
    counter++;
  }
  
  analogWrite(ENA_m1, 120);
  analogWrite(ENB_m1, 120);
}

void turnLeft(){

  int counter=0;

  analogWrite(ENA_m1, 180);
  analogWrite(ENB_m1, 180);

  while(counter < 2){
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);

    delay(250);
    counter++;
  }
  
  analogWrite(ENA_m1, 120);
  analogWrite(ENB_m1, 120);
}


int lookRight(int delayTime){  
  servo_motor.write(30);
  delay(delayTime);
  int distance = readPing();
  delay(delayTime);
  servo_motor.write(65);
  delay(delayTime);
  if(readPing() < distance) distance = readPing();
  delay(delayTime);
  servo_motor.write(100);
  return distance;
}

int lookLeft(int delayTime){
  servo_motor.write(170);
  delay(delayTime);
  int distance = readPing();
  delay(delayTime);
  servo_motor.write(135);
  delay(delayTime);
  if(readPing() < distance) distance = readPing();
  delay(delayTime);
  servo_motor.write(100);
  return distance;
}
