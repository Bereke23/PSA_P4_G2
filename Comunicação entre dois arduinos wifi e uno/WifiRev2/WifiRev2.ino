
  void setup() {

    // Begin the Serial at 9600 Baud

    Serial.begin(9600);
    Serial1.begin(9600);

  }




  void loop() {
String readString;
String Q;


    while (Serial1.available()){
      delay(1);
      if(Serial1.available()>0){
        char c = Serial1.read();
        Serial.print(c);
        if(isControl(c)){
          break;
        }
      }
    }
    while(Serial.available()){
      delay(1);
      if(Serial.available()>0){
        char c = Serial.read();
        if(isControl(c)){
          break;
        }
        readString +=c;
        
      }
      
    }
Q = readString;
if(Q == "on"){
  Serial1.print("1");
  Serial.println("Sent:on");
  
}
if(Q == "off"){
  Serial1.print("2");
  Serial.print("Sent:Off");
  
}



    
  }
  
