/*
 * Forbiddenbit.com
 */

 #define IN_1 7
 #define IN_2 8
 #define IN_3 4
 #define IN_4 2 
 #define ENA_m1 3
 #define ENB_m1 5

 int valueENA_m1=135; // speed motor 1 
 int valueENB_m1=135; // speed motor 2
 
void setup() {
 Serial.begin (9600);
    pinMode(ENA_m1, OUTPUT);
    pinMode(ENB_m1, OUTPUT);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);



}

void loop() {

int LEFT_SENSOR = analogRead(A0);
int RIGHT_SENSOR = analogRead(A3);
Serial.print(LEFT_SENSOR);
  Serial.print(" R = ");
  Serial.println(RIGHT_SENSOR);
delay(100);

if(RIGHT_SENSOR<200 && LEFT_SENSOR<200) //FORWARD
{
      digitalWrite(IN_1, LOW); 
   digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH); 
   digitalWrite(IN_4, LOW);
    analogWrite(ENA_m1, valueENA_m1);
     analogWrite(ENB_m1, valueENB_m1);
}

else if(RIGHT_SENSOR>200 && LEFT_SENSOR<200) //LEFT
 {
    digitalWrite(IN_1, HIGH); 
     digitalWrite(IN_2, LOW);
     digitalWrite(IN_3, HIGH); 
    digitalWrite(IN_4, LOW);
      analogWrite(ENA_m1, valueENA_m1);
      analogWrite(ENB_m1, valueENB_m1);
}

else if(RIGHT_SENSOR<200 && LEFT_SENSOR>200) //RIGHT
 {
      digitalWrite(IN_1, LOW); 
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW); 
      digitalWrite(IN_4, HIGH);
      analogWrite(ENA_m1, valueENA_m1);
      analogWrite(ENB_m1, valueENB_m1);
}

else if(RIGHT_SENSOR>200 && LEFT_SENSOR>200) //BACK
{

    digitalWrite(IN_1, LOW); 
    digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW); 
     digitalWrite(IN_4, LOW);
      analogWrite(ENA_m1, valueENA_m1);
      analogWrite(ENB_m1, valueENB_m1);
     delay(10000);
}
 
}
