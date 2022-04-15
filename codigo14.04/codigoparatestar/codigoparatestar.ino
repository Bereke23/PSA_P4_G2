#define ENB_m1 2        // Enable/speed motor Front Right velocidade da frente direita
#define ENA_m1 3        // Enable/speed motor Back Right velocidade de tras direita
#define ENA_m2 4      // Enable/speed motor Front Left VELOCIDADE DE FRENTE ESQUERDA
#define ENB_m2 5       // Enable/speed motor Back Left

#define IN_FL1  6        // L298N #1 in 1 motor Front Left IN3 DA FRENTE 
#define IN_FL2  7        // L298N #1 in 2 motor Front left IN4 DA FRENTE
#define IN_BR1  8        // L298N #1 in 3 motor Back Right IN1 DO TRAS
#define IN_BR2  9        // L298N #1 in 4 motor Back Right IN2 DE TRAS

#define IN_FR3  10       // L298N #2 in 1 motor Front  Right IN1 DA FRENTE
#define IN_FR4  11       // L298N #2 in 2 motor Front Right IN2 DA FRENTE
#define IN_BL3  12     // L298N #2 in 3 motor Back Left IN3 DA TRAS
#define IN_BL4  13       // L298N #2 in 4 motor Back Left IN4 DA TRAS


int command; 			      //Int to store app command state.
int speedCar = 0; 		// 50 - 255.
// int speed_Coeff = 2;


void setup() {  
    Serial.begin(9600);
	 
    
	  pinMode(ENA_m1, OUTPUT);
  	pinMode(ENB_m1, OUTPUT);
	  pinMode(ENA_m2, OUTPUT);
	  pinMode(ENB_m2, OUTPUT);
  
    pinMode(IN_FL1, OUTPUT);
    pinMode(IN_FL2, OUTPUT);
    pinMode(IN_BR1, OUTPUT);
    pinMode(IN_BR2, OUTPUT);
    
    pinMode(IN_FR3, OUTPUT);
    pinMode(IN_FR4, OUTPUT);
    pinMode(IN_BL3, OUTPUT);
    pinMode(IN_BL4, OUTPUT);

 

  } 

void goAhead(){

      digitalWrite(IN_FL1, HIGH); // Esta bem
      digitalWrite(IN_FL2, LOW);
	    analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, HIGH);
	    analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2, HIGH);
	    analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, HIGH); 
      digitalWrite(IN_BL4, LOW);
	    analogWrite(ENB_m2, speedCar);
      
  }

void goBack(){ 

 
      digitalWrite(IN_FL1, LOW); 
      digitalWrite(IN_FL2, HIGH);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_FR3, HIGH); 
      digitalWrite(IN_FR4, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_BR1, HIGH);
      digitalWrite(IN_BR2,LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, LOW); 
      digitalWrite(IN_BL4, HIGH);
      analogWrite(ENB_m2, speedCar);
      

  }

void goRight(){ 

 
      digitalWrite(IN_FL1, HIGH); 
      digitalWrite(IN_FL2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_FR3, HIGH); 
      digitalWrite(IN_FR4, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_BR1, HIGH);
      digitalWrite(IN_BR2,LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, HIGH); 
      digitalWrite(IN_BL4, LOW);
      analogWrite(ENB_m2, speedCar);

  }

void goLeft(){

      digitalWrite(IN_FL1, LOW); 
      digitalWrite(IN_FL2, HIGH);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, HIGH);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2,HIGH);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, LOW); 
      digitalWrite(IN_BL4, HIGH);
      analogWrite(ENB_m2, speedCar);

        
  }
/*
void goAheadRight(){
      
      digitalWrite(IN_FL1, HIGH); 
      digitalWrite(IN_FL2, LOW);
      analogWrite(ENA_m1, speedCar);

     digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, HIGH);
      analogWrite(ENB_m1, speedCar/2);


    digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2, HIGH);
      analogWrite(ENA_m2, speedCar/2);


     digitalWrite(IN_BL3, HIGH); 
      digitalWrite(IN_BL4, LOW);
      analogWrite(ENB_m2, speedCar);
      
  }
/*
void goAheadLeft(){
      
      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
      analogWrite(ENA_m2, speedCar - (speedCar/4));


      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar - (speedCar/4));
 
  }

void goBackRight(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar - (speedCar/4));


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar- (speedCar/4));


      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar);

  }

void goBackLeft(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar  - (speedCar/4));


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar - (speedCar/4));

  }
*/
void stopRobot(){  

     digitalWrite(IN_FL1, LOW); 
      digitalWrite(IN_FL2, LOW);
     analogWrite(ENA_m1, speedCar);

     digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, LOW);
      analogWrite(ENB_m1, speedCar);


    digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2,LOW);
      analogWrite(ENA_m2, speedCar);


     digitalWrite(IN_BL3, LOW); 
      digitalWrite(IN_BL4, LOW);
      analogWrite(ENB_m2, speedCar);
  
  }


void loop(){
 char command;
 // String commandAux;


  if (Serial.available() > 0) {
  command = Serial.read();
    //commandAux = Serial.read();
    //command = commandAux.charAt(0);

   
    switch (command) {
      case 'F':goAhead();break;
      case 'B':goBack();break;
      case 'L':goLeft();break;
      case 'R':goRight();break;
 /*   case 'I':goAheadRight();break;
 /*   case 'G':goAheadLeft();break;
      case 'J':goBackRight();break;
      case 'H':goBackLeft();break;
  */  case '0':speedCar = 100;break;
      case '1':speedCar = 120;break;
      case '2':speedCar = 135;break;
      case '3':speedCar = 155;break;
      case '4':speedCar = 170;break;
      case '5':speedCar = 185;break;
      case '6':speedCar = 195;break;
      case '7':speedCar = 215;break;
      case '8':speedCar = 235;break;
      case '9':speedCar = 255;break;
      case 'S':stopRobot();break;


    }
/*
    switch (command) {
      case 70:goAhead();break;
      case 66:goBack();break;
      case 76:goLeft();break;
      case 82:goRight();break;
/*    case 73:goAheadRight();break;
      case 71:goAheadLeft();break;
      case 74:goBackRight();break;
      case 72:goBackLeft();break;
      case 48:speedCar = 100;break;
      case 49:speedCar = 120;break;
      case 50:speedCar = 135;break;
      case 51:speedCar = 155;break;
      case 52:speedCar = 170;break;
      case 53:speedCar = 185;break;
      case 54:speedCar = 195;break;
      case 55:speedCar = 215;break;
      case 56:speedCar = 235;break;
      case 57:speedCar = 255;break;
      case 83:stopRobot();break;
    }

    
}




  /*
  String readString;
    String Q;
    while (Serial.available()){
      delay(1);
      if(Serial.available()>0){
        char c = Serial.read();
        if(isControl(c)){
          break;
        }
        readString += c;
      }
    }
 
   Q = readString;


  
   if (Q=="S"){
stopRobot();
   
 }
   if (Q=="F"){
goAhead();
   
 }
    if (Q=="B"){
   goBack();
   
 }
     if (Q=="L"){
   goLeft();
   
 }
      if (Q=="R"){
 goRight();
   
 }
 if (Q=="I"){
goAheadRight();
   
 }
  if (Q=="G"){
goAheadLeft();
   
 }
   if (Q=="J"){
goBackRight();
   
 }
    if (Q=="H"){
goBackLeft();
   
 }
 
     if (Q=="0"){
speedCar = 100;
   
 }
      if (Q=="1"){
speedCar = 120;
   
 }
      if (Q=="2"){
speedCar = 135;
   
 }
      if (Q=="3"){
speedCar = 155;
   
 }
      if (Q=="4"){
speedCar = 170;
   
 }
      if (Q=="5"){
speedCar = 185;
   
 }
       if (Q=="6"){
speedCar = 195;
   
 }
       if (Q=="7"){
speedCar = 215;
   
 }
       if (Q=="8"){
speedCar = 235;
   
 }
        if (Q=="9"){
speedCar = 255;
   
 }
*/
 
  } 

}
