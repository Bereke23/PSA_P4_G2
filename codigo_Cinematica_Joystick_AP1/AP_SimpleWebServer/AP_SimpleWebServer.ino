/*
  WiFi Web Server LED Blink

  A simple web server that lets you blink an LED via the web.
  This sketch will create a new access point (with no password).
  It will then launch a new server and print out the IP address
  to the Serial Monitor. From there, you can open that address in a web browser
  to turn on and off the LED on pin 13.

  If the IP address of your board is yourAddress:
    http://yourAddress/H turns the LED on
    http://yourAddress/L turns it off

  created 25 Nov 2012
  by Tom Igoe
  adapted to WiFi AP by Adafruit
 */

// PARTE INICIAL

#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                // your network key index number (needed only for WEP)


int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  // Estabelecimento das comunicações

   Serial1.begin(9600);
   
  Serial.begin(9600);

  
   
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Access Point Web Server");

        // set the LED pin mode

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
  // by default the local IP address will be 192.168.4.1
  // you can override it with the following:
  // WiFi.config(IPAddress(10, 0, 0, 1));
  // print the network name (SSID);
  Serial.print("Creating access point named: ");
  Serial.println(ssid);
  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid, pass);
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    // don't continue
    while (true);
  }

  // wait 10 seconds for connection:
  delay(10000);

  // start the web server on port 80
  server.begin();


  // you're connected now, so print out the status
printWiFiStatus();
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







  
  // Estabelecimento das comunicações
  // compare the previous status to the current status
  if (status != WiFi.status()) {
    // it has changed update the variable
    status = WiFi.status();

    if (status == WL_AP_CONNECTED) {
      // a device has connected to the AP
      Serial.println("Device connected to AP");
    } else {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }

  
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      delayMicroseconds(10);                // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            // the content of the HTTP response follows the header:
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }





// ANALISE DA MENSAGEM E RESPOSTA 
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /F")) {
         Serial1.print("F");            // Para andar para para frente
        }
        if (currentLine.endsWith("GET /P")) {
         Serial1.print("P"); // Para andar para para frente
        }
         if (currentLine.endsWith("GET /B")) {
         Serial1.print("B");            // Para andar para para Trás
        }
         if (currentLine.endsWith("GET /L")) {
         Serial1.print("L");            // Para andar para para Lado esquerdo
        }
         if (currentLine.endsWith("GET /R")) {
         Serial1.print("R");            // Para andar para para Lado direito
        }
         if (currentLine.endsWith("GET /I")) {
         Serial1.print("I");            // Para andar para para frente direita
        }
         if (currentLine.endsWith("GET /G")) {
         Serial1.print("G");            // Para andar para para frente esquerda
        }
         if (currentLine.endsWith("GET /J")) {
         Serial1.print("J");            // Para andar para para Tras direita
        }
         if (currentLine.endsWith("GET /H")) {
         Serial1.print("H");            // Para andar para para Tras esquerda
        }
        // Velocidade 
          if (currentLine.endsWith("GET /0")) {
         Serial1.print("0");            // Velocidade 100
        }
         if (currentLine.endsWith("GET /1")) {
         Serial1.print("1");            // Velocidade 120
        }
         if (currentLine.endsWith("GET /2")) {
         Serial1.print("2");            // Velocidade 135
        }
         if (currentLine.endsWith("GET /3")) {
         Serial1.print("3");            // Velocidade 155
        }
         if (currentLine.endsWith("GET /4")) {
         Serial1.print("4");            // Velocidade 170
        }
         if (currentLine.endsWith("GET /5")) {
         Serial1.print("5");            // Velocidade 185
        }
         if (currentLine.endsWith("GET /6")) {
         Serial1.print("6");            // Velocidade 195
        }
         if (currentLine.endsWith("GET /7")) {
         Serial1.print("7");           // Velocidade 215
        }
         if (currentLine.endsWith("GET /8")) {
         Serial1.print("8");            // Velocidade 235
        }
         if (currentLine.endsWith("GET /9")) {
         Serial1.print("9");            // Velocidade 255
        }

         if (currentLine.endsWith("GET /S")) {
         Serial1.print("S");            // Parar O carro
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }

}
void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
