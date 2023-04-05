/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-i2c-communication-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <Arduino.h>
#include "PCF8591.h"
#define PCF8591_I2C_ADDRESS 0x48
#include <Wire.h>

// Define as portas usadas no ESP32 para o I2C
// Por padrão as portas são 
// SDA_1 21
// SCL_1 22

// float tensao_unid = 3.3 / 255;


#define SDA_2 33
#define SCL_2 32

// Define a frequência da comunição 
uint32_t frequencia = 100000;

// Cria os objetos para interfaciar com o modulo DAC e os incializa com o correto endereço e barramento I2C 
// PCF8591 pcf8591_1(&Wire1, PCF8591_I2C_ADDRESS);
PCF8591 pcf8591_2(PCF8591_I2C_ADDRESS);

void setup() {
  Serial.begin(115200);
  Serial.println("DAC test");

  Wire.begin();
  // Wire1.begin(SDA_2, SCL_2);

  // pcf8591_1.begin();
  pcf8591_2.begin();
  
  Serial.println();
}

void loop() { 

  // for(int i = 1; i <= 255; i++){
  //   // Coloca uma valor analogico na saida
  //   pcf8591_2.voltageWrite(3.3); // 3.0 Volts output
  //   delay(500);

  //   Serial.println("Valor de tensão: 3.3");
  //   Serial.println("--------------------");
    
  // }

  // // Coloca uma valor analogico na saida
  // pcf8591_1.voltageWrite(3.0); // 3.0 Volts output
	// delay(3000);
  // Serial.println("3.0V em AOUT 1");
  // Serial.println("--------------------");

  // Coloca uma valor analogico de na saida
  uint8_t ana = (255*0.5) / 4.58;
  pcf8591_2.analogWrite(ana); // 5.0 Volts output

	delay(3000);
  Serial.print(" ana = ");
  Serial.println(ana);
  Serial.println("--------------------");
  
  delay(30000);
}