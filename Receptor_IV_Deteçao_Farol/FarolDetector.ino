/*
 * SimpleReceiver.cpp
 *
 * Demonstrates receiving NEC IR codes with IRrecv
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
*/

#define DECODE_NEC          
#include <Arduino.h>

#include "PinDefinitionsAndMore.h" //Define macros for input and output pin etc.
#include <IRremote.hpp>

// ligar a saída do detetor ao pino 2 do arduino UNO
void setup() {
    Serial.begin(19200);
    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  //  Serial.print(F("Ready to receive IR signals of protocols: "));
  //  printActiveIRProtocols(&Serial);
 //   Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));
}

void loop() {
  
    if (IrReceiver.decode()) {  // se foi recebida alguma informação (vinda do farol)
//       // Print a short summary of received data
//        IrReceiver.printIRResultShort(&Serial);
//        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
//            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
//            // We have an unknown protocol here, print more info
//            IrReceiver.printIRResultRawFormatted(&Serial, true);
//        }
//        Serial.println();

        IrReceiver.resume(); // Enable receiving of the next value
        /*
         * Finally, check the received data and perform actions according to the received command
         */
         uint8_t Comm = IrReceiver.decodedIRData.command;
         uint8_t Add = IrReceiver.decodedIRData.address;
        if (Comm== 0x01) {
            // Código para quando o farol é detetado a menos de 20 cm
            Serial.print("Address = "); Serial.print(Add, HEX); Serial.print(" Detect = "); Serial.println(Comm, HEX);
        } else if (Comm == 0x02) {
            // Código para quando o farol é detetado a mais de 20 cm
            Serial.print("Address 2 = "); Serial.print(Add, HEX); Serial.print(" Detect 2 = "); Serial.println(Comm, HEX);
        }
    }
  
}
