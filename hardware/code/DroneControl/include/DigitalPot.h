#include <Arduino.h>
#include <SPI.h>

/*
Pinos

21     <-  CS       VDD     ->  3.3V
18     <-  SCK      SO      ->  
23     <-  SI       SHDN    ->  3.3V
GND    <-  VSS      RS      ->  3.3V
GND    <-  PB1      PB0     ->  GND
-      <-  PW1      PW0     ->  -
3.3V   <-  PA1      PA0     ->  3.3V

*/

// Constantes do Potenciômetro digital 
const byte csPin           = 21;      // MCP42100 chip select pin
const byte rWiper          = 125;     // 125 ohms pot wiper resistance (valor esperado)
const byte pot0            = 0x11;    // pot0 addr
const byte pot1            = 0x12;    // pot1 addr
const byte potBoth         = 0x13;    // pot0 and pot1 simultaneous addr
const byte pot0Shutdown    = 0x21;    // pot0 shutdown
const byte pot1Shutdown    = 0x22;    // pot1 shutdown
const byte potBothShutdown = 0x23;    // pot0 and pot1 simultaneous shutdown

void initDigPot(){
    pinMode(csPin, OUTPUT);     // configure chip select as output
    digitalWrite(csPin, HIGH);  // chip select default to de-selected

    SPI.begin();                // Inicializa comunicação SPI                    
}

void setPotWiper(int addr, int pos) {

  digitalWrite(csPin, LOW);                // select chip

  SPI.transfer(addr);                      // Confira com que potenciômetro irá ser alterado 
  SPI.transfer(pos);                       // Escreve o valor de configuração 
  digitalWrite(csPin, HIGH);               // de-select chip

}

