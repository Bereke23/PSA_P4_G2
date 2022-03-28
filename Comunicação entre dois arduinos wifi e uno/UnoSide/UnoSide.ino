
 //Initialized variable to store recieved data
  
  void setup() {
    // Begin the Serial at 9600 Baud
    pinMode(13,OUTPUT);
    Serial.begin(9600);
  }
  
  void loop() {
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
    if(Q=="1"){
      digitalWrite(13,HIGH);
    }
    if(Q=="2"){
      digitalWrite(13,LOW);
    }
  }
