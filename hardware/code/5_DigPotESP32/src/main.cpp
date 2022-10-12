#include <Arduino.h>
#include "DigitalPot.h"


void setup() {

  Serial.begin(115200);

  // Iniciliza o potenciômetro digital 
  initDigPot();


}

void loop() {
  
  
  // move pot0 wiper from min to max in increments of 1 position
  Serial.println("Pot 0 Control");
  for (int i = 0; i < 255; i++) {
    Serial.print("Posição do seletor: ");
    Serial.println(i);


    setPotWiper(pot0, i);

    measuredVoltage(i);

    delay(500);
  }  
  
  
  

}