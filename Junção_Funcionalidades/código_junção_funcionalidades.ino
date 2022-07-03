#include <Servo.h>          //Servo motor library. This is standard library
 #include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

 #define LeftMotorForward 7
 #define LeftMotorBackward 8
 #define RightMotorForward 4
 #define RightMotorBackward 2 

 #define ENA_m1 3
 #define ENB_m1 5

 //sensor pins
 #define trig_pin A1 //analog input 1
 #define echo_pin A2 //analog input 2
 
 #define IR_LEFT A0
 #define IR_RIGHT A3
 #define maximum_distance 200

 int valueENA_m1=120; // speed motor 1 
 int valueENB_m1=120; // speed motor 2

 int valueWhite = 150; //valor do sensor IR para a cor branca

 boolean goesForward = false;
 int distance = 100;

 int angulo_servo = 0;  

 NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
 Servo servo_motor; //our servo name

 boolean detetarObstaculo;
 boolean jaPassouPerpendicular;

//CONTROLO MANUAL
int command;  //Int to store app command state.
int speedCar = 0; // 50 - 255


boolean controloManual;

 
void setup() {
  Serial.begin (9600);

  pinMode(ENA_m1, OUTPUT);
  pinMode(ENB_m1, OUTPUT);

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  servo_motor.attach(6); //our servo pin
  servo_motor.write(0);

  detetarObstaculo = true;
  controloManual = false;
  jaPassouPerpendicular = false;
}

void loop() {
  char command;

  if(Serial.available() > 0){
    command = Serial.read();
    if(command == 'M') controloManual = true;
  }

  if(controloManual) manual();
  else automatico();

}


void manual(){
  char command;

  Serial.print("-->");
  Serial.println(speedCar);
  
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {      
      case 'F': goAhead(); break;
      case 'B': goBack(); break;
      case 'L': goLeft(); break;
      case 'R': goRight(); break;
      case 'I': goAheadRight(); break;
      case 'G': goAheadLeft(); break;
      case 'J': goBackRight(); break;
      case 'H': goBackLeft(); break;
      case '0':
        speedCar = map(102, 0, 1023, 0 , 255);
        Serial.println("102");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '1':
        speedCar = map(204, 0, 1023, 0 , 255);
        Serial.println("204");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '2':
        speedCar = map(306, 0, 1023, 0 , 255);
        Serial.println("306");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '3':
        speedCar = map(408, 0, 1023, 0 , 255);
        Serial.println("408");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '4':
        speedCar = map(510, 0, 1023, 0 , 255);
        Serial.println("510");
      Serial.println(speedCar);
        Serial.println("");
        break;
      case '5':
        speedCar = map(612, 0, 1023, 0 , 255);
        Serial.println("612");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '6':
        speedCar = map(714, 0, 1023, 0 , 255);
       Serial.println("714");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '7':
        speedCar = map(816, 0, 1023, 0 , 255);
        Serial.println("816");
        Serial.println(speedCar);
       Serial.println("");
        break;
      case '8':
        speedCar = map(918, 0, 1023, 0 , 255);
        Serial.println("918");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case '9':
        speedCar = map(1023, 0, 1023, 0 , 255);
        Serial.println("1023");
        Serial.println(speedCar);
        Serial.println("");
        break;
      case 'S': moveStop(); break;
      case 'N':
        moveStop();
        delay(200);
        detetarObstaculo = true;
        controloManual = false;
        jaPassouPerpendicular = false;
        break;
    }

  }


}


void automatico(){
  int distanceTemp = 0;

  servo_motor.write(angulo_servo);
  distance = readPing();
  if(detetarObstaculo) makeChange();

  int LEFT_SENSOR = analogRead(IR_LEFT);
  int RIGHT_SENSOR = analogRead(IR_RIGHT);

  if(RIGHT_SENSOR < valueWhite && LEFT_SENSOR < valueWhite){ //FORWARD
    analogWrite(ENA_m1, valueENA_m1);
    analogWrite(ENB_m1, valueENB_m1);
    
    digitalWrite(LeftMotorForward, LOW); 
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, HIGH); 
    digitalWrite(RightMotorBackward, LOW);

    if(jaPassouPerpendicular){
      jaPassouPerpendicular = controlarCarro();
      detetarObstaculo = true;
    }
    
  }

  else if(RIGHT_SENSOR > valueWhite && LEFT_SENSOR < (valueWhite*2)){ //LEFT
    analogWrite(ENA_m1, valueENA_m1);
    analogWrite(ENB_m1, valueENB_m1);

    digitalWrite(LeftMotorForward, HIGH); 
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, HIGH); 
    digitalWrite(RightMotorBackward, LOW);
  }

  else if(RIGHT_SENSOR < (valueWhite*2) && LEFT_SENSOR > valueWhite){ //RIGHT
    analogWrite(ENA_m1, valueENA_m1);
    analogWrite(ENB_m1, valueENB_m1);

    digitalWrite(LeftMotorForward, LOW); 
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, LOW); 
    digitalWrite(RightMotorBackward, HIGH);
  }

  else if(RIGHT_SENSOR > valueWhite && LEFT_SENSOR > valueWhite){ //BLACK
    moveStop();
    if(!detetarObstaculo){
      perpendicular(LEFT_SENSOR, RIGHT_SENSOR);
    }
  }


}


void perpendicular(int LEFT_SENSOR, int RIGHT_SENSOR){

  moveBackwardUntilWhite(LEFT_SENSOR, RIGHT_SENSOR);
  moveStop();

  moveForward();
  delay(250);
  
  turnRightUntilWhite(LEFT_SENSOR, RIGHT_SENSOR);
    
  jaPassouPerpendicular = true;
  valueENA_m1 = 120;
  valueENB_m1 = 120;
}


boolean controlarCarro(){
  int counter = 0;

  do{
    int LEFT_SENSOR = analogRead(IR_LEFT);
    int RIGHT_SENSOR = analogRead(IR_RIGHT);

    if(RIGHT_SENSOR < valueWhite && LEFT_SENSOR < valueWhite){ //FORWARD
      analogWrite(ENA_m1, 120);
      analogWrite(ENB_m1, 120);
    
      moveForward();
      delay(200);
    }
    else if(RIGHT_SENSOR > valueWhite && LEFT_SENSOR < (valueWhite*2)){ //LEFT
      analogWrite(ENA_m1, 120);
      analogWrite(ENB_m1, 120);

      digitalWrite(LeftMotorForward, HIGH); 
      digitalWrite(LeftMotorBackward, LOW);
      digitalWrite(RightMotorForward, HIGH); 
      digitalWrite(RightMotorBackward, LOW);
      delay(200);
    }
    else if(RIGHT_SENSOR < (valueWhite*2) && LEFT_SENSOR > valueWhite){ //RIGHT
      analogWrite(ENA_m1, 120);
      analogWrite(ENB_m1, 120);

      digitalWrite(LeftMotorForward, LOW); 
      digitalWrite(LeftMotorBackward, HIGH);
      digitalWrite(RightMotorForward, LOW); 
      digitalWrite(RightMotorBackward, HIGH);
      delay(200);
    }

    counter ++;
  }while(counter < 3);

  while(true){
    moveStop();
    delay(100);

    if(Serial.available() > 0){
      char command = Serial.read();
      if(command == 'M'){
        controloManual = true;
        break;
      }
    }
  }

  return false;
}


void makeChange(){
  
  int distanceRight = 0;
  int distanceLeft = 0;
  int LEFT_SENSOR = 0;
  int RIGHT_SENSOR = 0;
  
  if (distance <= 25){
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(100);


    turnRight();
    moveStop();
    delay(300);
    
    analogWrite(ENA_m1, valueENA_m1);
    analogWrite(ENB_m1, valueENB_m1);
    moveForward();
    delay(850);
    moveStop();
    delay(300);

    turnLeft(650);
    moveStop();
    delay(300);

    moveForward();
    delay(250);
    moveStop();
    delay(200);

    servo_motor.write(120);
    

    moveStop();
    delay(500);
    distance = readPing();
    while(distance <= 30){
      moveForward();
      delay(150);

      moveStop();
      delay(200);

      distance = readPing();
    }

    moveStop();
    delay(300);

    moveForward();
    delay(500);
    moveStop();
    delay(300);

    servo_motor.write(angulo_servo);
    
    turnLeft(700);
    moveStop();
    delay(300);

    valueENA_m1 = 110;
    valueENB_m1 = 110;

    do{
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(RightMotorForward, HIGH);
      digitalWrite(LeftMotorBackward, HIGH);
      digitalWrite(RightMotorBackward, LOW); 

      delay(100); //diminuir se for necessario
      moveStop();
      delay(200);
      LEFT_SENSOR = analogRead(IR_LEFT);
      RIGHT_SENSOR = analogRead(IR_RIGHT);
    } while( RIGHT_SENSOR > valueWhite || LEFT_SENSOR > valueWhite );

    moveStop();
    delay(350);

    detetarObstaculo = false;
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



void turnRight(){

  analogWrite(ENA_m1, 220);
  analogWrite(ENB_m1, 220);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  delay(700);
  
  analogWrite(ENA_m1, valueENA_m1);
  analogWrite(ENB_m1, valueENB_m1);
}


void turnLeft(int time){

  analogWrite(ENA_m1, 200);
  analogWrite(ENB_m1, 200);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  delay(time);
  
  analogWrite(ENA_m1, valueENA_m1);
  analogWrite(ENB_m1, valueENB_m1);
}


void turnRightUntilWhite(int LEFT_SENSOR, int RIGHT_SENSOR){

  analogWrite(ENA_m1, 200); //diminuir a velocidade se for necessario
  analogWrite(ENB_m1, 200); //diminuir a velocidade se for necessario

  do{
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
  
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, LOW);

    delay(250); //diminuir se for necessario
    moveStop();
    delay(50);
  
    LEFT_SENSOR = analogRead(IR_LEFT);
    RIGHT_SENSOR = analogRead(IR_RIGHT);
  }while( RIGHT_SENSOR > valueWhite || LEFT_SENSOR > valueWhite );

  moveStop();
  
  analogWrite(ENA_m1, valueENA_m1);
  analogWrite(ENB_m1, valueENB_m1);
}

void moveStop(){
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}


void moveBackward(){
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  
}

void moveForward(){
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, LOW); 
}


void moveBackwardUntilWhite(int LEFT_SENSOR, int RIGHT_SENSOR){
  analogWrite(ENA_m1, 125); //velocidade para vir back (80?) mudar se for necessário
  analogWrite(ENB_m1, 125); //velocidade para vir back (80?) mudar se for necessário

  do{
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, LOW);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
    delay(100);
    moveStop();
    delay(200);

    LEFT_SENSOR = analogRead(IR_LEFT);
    RIGHT_SENSOR = analogRead(IR_RIGHT);
  } while( RIGHT_SENSOR > valueWhite || LEFT_SENSOR > valueWhite );

  moveStop();
  moveForward();
  moveStop();
  delay(100);

  analogWrite(ENA_m1, valueENA_m1);
  analogWrite(ENB_m1, valueENB_m1);
}



//CONTROLO MANUAL DO CARRO

void goAhead(){     
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(RightMotorBackward, LOW);
  analogWrite(ENB_m1, speedCar);
}

void goBack(){ 
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, LOW); 
  digitalWrite(RightMotorBackward, HIGH);
  analogWrite(ENB_m1, speedCar);
}

void goRight(){ 
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, LOW); 
  digitalWrite(RightMotorBackward, HIGH);
  analogWrite(ENB_m1, speedCar);
}

void goLeft(){
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(RightMotorBackward, LOW);
  analogWrite(ENB_m1, speedCar);     
}
  
void goAheadRight(){
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(RightMotorBackward, LOW);
  analogWrite(ENB_m1, 127);   
}

void goAheadLeft(){
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  analogWrite(ENA_m1, 127);

  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(RightMotorBackward, LOW);
  analogWrite(ENB_m1, speedCar);
}

void goBackRight(){ 
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  analogWrite(ENA_m1, speedCar);

  digitalWrite(RightMotorForward, LOW); 
  digitalWrite(RightMotorBackward, HIGH);
  analogWrite(ENB_m1, 127);
}

void goBackLeft(){ 
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  analogWrite(ENA_m1, 127);

  digitalWrite(RightMotorForward, LOW); 
  digitalWrite(RightMotorBackward, HIGH);
  analogWrite(ENB_m1, speedCar);
}
