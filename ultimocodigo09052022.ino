#define ENA_m1  3       // Enable/speed motor Motores das rodas da 
#define ENB_m1  5       // Enable/speed motor Motores das rodas da 
// #define ENA_m2 4      // Enable/speed motor Front Left velocidade frente esquerda
// #define ENB_m2 5       // Enable/speed motor Back Left velocidade tras esquerda

#define IN_1  7        // L298N #1 in 1 motor Front Left IN1 DA FRENTE 
#define IN_2  8       // L298N #1 in 2 motor Front left IN2 DA FRENTE
#define IN_3  4        // L298N #2 in 3 motor Back Right IN1 DO TRAS
#define IN_4  2        // L298N #2 in 4 motor Back Right IN2 DE TRAS


/*
#define IN_FL1  6        // L298N #1 in 1 motor Front Left IN1 DA FRENTE 
#define IN_FL2  7        // L298N #1 in 2 motor Front left IN2 DA FRENTE
#define IN_BR1  8        // L298N #2 in 3 motor Back Right IN1 DO TRAS
#define IN_BR2  9        // L298N #2 in 4 motor Back Right IN2 DE TRAS

#define IN_FR3  10       // L298N #1 in 1 motor Front  Right IN3 DA FRENTE
#define IN_FR4  11       // L298N #1 in 2 motor Front Right IN4 DA FRENTE
#define IN_BL3  12     // L298N #2 in 3 motor Back Left IN3 DA TRAS
#define IN_BL4  13       // L298N #2 in 4 motor Back Left IN4 DA TRAS
*/

int command; 			      //Int to store app command state.
int speedCar = 0; 		// 50 - 255.
// int speed_Coeff = 2;


void setup() {  
    Serial.begin(9600);
	 
    
	  pinMode(ENA_m1, OUTPUT);
  	pinMode(ENB_m1, OUTPUT);
	
  
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
    
   
 

  } 

void goAhead(){
      
      
      
      digitalWrite(IN_1, LOW); // Esta bem
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, HIGH); 
      digitalWrite(IN_4, LOW);
      analogWrite(ENB_m1, speedCar);



  
/*
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
   */
  }

void goBack(){ 


  
      digitalWrite(IN_1, HIGH); // Esta bem
      digitalWrite(IN_2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB_m1, speedCar);

 /*
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
     */ 

  }

void goRight(){ 
      
      
      
      digitalWrite(IN_1, LOW); // Esta bem
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB_m1, speedCar);



 /*
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
*/
  }

void goLeft(){
      digitalWrite(IN_1, HIGH); // Esta bem
      digitalWrite(IN_2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, HIGH); 
      digitalWrite(IN_4, LOW);
      analogWrite(ENB_m1, speedCar);



  
/*
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
*/
        
  }
  
void goAheadRight(){

  
      digitalWrite(IN_1, LOW); // Esta bem
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, HIGH); 
      digitalWrite(IN_4, LOW);
      analogWrite(ENB_m1, 127);





/*
      digitalWrite(IN_FL1, HIGH); 
      digitalWrite(IN_FL2, LOW);
      analogWrite(ENA_m1,127);


      digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, HIGH);
      analogWrite(ENB_m1,127);


      digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2, HIGH);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, HIGH); 
      digitalWrite(IN_BL4, LOW);
      analogWrite(ENB_m2, speedCar);
 */     
  }

void goAheadLeft(){

      digitalWrite(IN_1, LOW); // Esta bem
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA_m1, 127);

      digitalWrite(IN_3, HIGH); 
      digitalWrite(IN_4, LOW);
      analogWrite(ENB_m1, speedCar);

  
    /*  
      digitalWrite(IN_FL1, HIGH); 
      digitalWrite(IN_FL2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_FR3, LOW); 
      digitalWrite(IN_FR4, HIGH);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_BR1, LOW);
      digitalWrite(IN_BR2,HIGH);
      analogWrite(ENA_m2, 127);


      digitalWrite(IN_BL3, HIGH); 
      digitalWrite(IN_BL4, LOW);
      analogWrite(ENB_m2, 127);
 */
  }

void goBackRight(){ 


  
      digitalWrite(IN_1, HIGH); // Esta bem
      digitalWrite(IN_2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB_m1, 127);


  
/*
      digitalWrite(IN_FL1, LOW); 
      digitalWrite(IN_FL2, HIGH);
      analogWrite(ENA_m1, 127);

      digitalWrite(IN_FR3, HIGH); 
      digitalWrite(IN_FR4, LOW);
      analogWrite(ENB_m1, 127);
      
      digitalWrite(IN_BR1, HIGH);
      digitalWrite(IN_BR2, LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_BL3, LOW); 
      digitalWrite(IN_BL4, HIGH);
      analogWrite(ENB_m2, speedCar);
*/
  }

void goBackLeft(){ 
       

      digitalWrite(IN_1, HIGH); // Esta bem
      digitalWrite(IN_2, LOW);
      analogWrite(ENA_m1, 127);

      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB_m1, speedCar);


  
/*
      digitalWrite(IN_FL1, LOW); 
      digitalWrite(IN_FL2, HIGH);
     analogWrite(ENA_m1, speedCar);

     digitalWrite(IN_FR3, HIGH); 
      digitalWrite(IN_FR4, LOW);
      analogWrite(ENB_m1, speedCar);


    digitalWrite(IN_BR1, HIGH);
      digitalWrite(IN_BR2,LOW);
      analogWrite(ENA_m2,127);


     digitalWrite(IN_BL3, LOW); 
      digitalWrite(IN_BL4, HIGH);
      analogWrite(ENB_m2,127);
*/
  }
void stopRobot(){  

  
digitalWrite(IN_1, LOW); 
      digitalWrite(IN_2, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, LOW);
      analogWrite(ENB_m1, speedCar);
     
  }



void loop(){
 char command;

  Serial.print("-->");
  Serial.println(speedCar);
  if (Serial.available() > 0) {
    command = Serial.read(); 
   
    switch (command) {
      case 'F':goAhead();break;
      case 'B':goBack();break;
      case 'L':goLeft();break;
      case 'R':goRight();break;
      case 'I':goAheadRight();break;
      case 'G':goAheadLeft();break;
      case 'J':goBackRight();break;
      case 'H':goBackLeft();break;
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
      case 'S':stopRobot();break;
    }

 
  } 


}
