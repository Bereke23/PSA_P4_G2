/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 6
 #define outputB 5

 int Contador = 0; 
 int aestado;
 int aultimoestado;  
 int incomingByte = 0;

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aultimoestado = digitalRead(outputA);   
 } 

 void loop() { 
   aestado = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aultimoestado!= aultimoestado){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aestado) { 
       Contador ++;
       Serial.print("Andar para frente");
      
     } else {
       Contador --;
       Serial.print("Andar para tras");
     }
     float(incomingByte) = Contador * float(23.56194)/float(15);
     Serial.print("Position: ");
     Serial.println(Contador);
     Serial.println(incomingByte);
   } 
   incomingByte = Serial.read();

   aultimoestado = aestado; // Updates the previous state of the outputA with the current state
 }
