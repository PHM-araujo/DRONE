#include <Arduino.h>
#include "PCF8591.h"
#define PCF8591_I2C_ADDRESS 0x48
#include <Wire.h>

// #define SDA_2 33
// #define SCL_2 32

// float tensao_unid = 3.3 / 255;

// Define a frequência da comunição 
uint32_t frequencia = 100000;

// Cria os objetos para interfaciar com o modulo DAC e os incializa com o correto endereço e barramento I2C 
// PCF8591 pcf8591_1(&Wire1, PCF8591_I2C_ADDRESS);
PCF8591 pcf8591_2(PCF8591_I2C_ADDRESS);

/* Constantes base para os Joysticks */
const byte ALTO    = 255;
const byte REPOUSO = 127;
const byte BAIXO   = 0;

/* Definição do canal DAC0 (GPIO 25) */
// #define CANAL_DAC0 25  

/* Definição do canal DAC1 (GPIO 26) */
// #define CANAL_DAC1 26

void setup() {
  Serial.begin(115200);

  Wire.begin();
  // Wire1.begin(SDA_2, SCL_2);

  // pcf8591_1.begin();
  pcf8591_2.begin();

}

void loop() {
  String Leitura = Serial.readString();

  if (Leitura == "Inicia" || Leitura == "Inicia\n") {

    dacWrite(CANAL_DAC0, ALTO);
    delay(1000);
    dacWrite(CANAL_DAC0, BAIXO);
    delay(1000);
    dacWrite(CANAL_DAC0, REPOUSO);
    delay(1000);

    // analogWrite(JS1_UD, ALTO);
    // delay(1000);
    // analogWrite(JS1_UD, BAIXO);
    // delay(1000);
    // analogWrite(JS1_UD, REPOUSO);
    // delay(1000);
    Serial.println("Iniciou");
  } else if (Leitura == "Sobe" || Leitura == "Sobe\n") {

    for(int i = 0; i <= 255; i++){
      dacWrite(CANAL_DAC0, i);
      dacWrite(CANAL_DAC1, i);

      float tensao_total = tensao_unid * i;

      pcf8591_1.voltageWrite(tensao_total); // 3.0 Volts output

      pcf8591_2.voltageWrite(tensao_total);

      Serial.print("Valor de tensão: ");
      Serial.println(tensao_total);
      Serial.print("Valor de i: ");
      Serial.println(i);
      Serial.println("--------------------");

      delay(500);

    } 

    for(int i = 255; i > 0; i--){
      dacWrite(CANAL_DAC0, i);
      dacWrite(CANAL_DAC1, i);

      float tensao_total = tensao_unid * i;

      pcf8591_1.voltageWrite(tensao_total); // 3.0 Volts output

      pcf8591_2.voltageWrite(tensao_total);

      Serial.print("Valor de tensão: ");
      Serial.println(tensao_total);
      Serial.print("Valor de i: ");
      Serial.println(i);
      Serial.println("--------------------");


      delay(500);
      
    } 

    // dacWrite(CANAL_DAC0, ALTO);
    // delay(1000);
    // dacWrite(CANAL_DAC0, REPOUSO);
    // delay(1000);
    
    // analogWrite(JS1_UD, ALTO);
    // delay(2000);
    // analogWrite(JS1_UD, REPOUSO);
    // delay(1000);
    Serial.println("Subiu");
  } else if (Leitura == "Desce" || Leitura == "Desce\n") {

    dacWrite(CANAL_DAC0, ALTO);
    delay(1000);
    dacWrite(CANAL_DAC0, REPOUSO);
    delay(1000);

    // analogWrite(JS1_UD, BAIXO);
    // delay(2000);
    // analogWrite(JS1_UD, REPOUSO);
    // delay(1000);
    // Serial.println("Desceu");
  } else if (Leitura == "Esquerda" || Leitura == "Esquerda\n") {
    // analogWrite(JS1_LR, ALTO);
    // delay(2000);
    // analogWrite(JS1_UD, REPOUSO);
    // delay(1000);
    // Serial.println("Esquerdou");
  } else if (Leitura == "Direita" || Leitura == "Direita\n") {
    // analogWrite(JS1_LR, BAIXO);
    // delay(2000);
    // analogWrite(JS1_UD, REPOUSO);
    // delay(1000);
    // Serial.println("Direitou");
  } else {
    int i = atoi(Leitura.c_str());
    if (i > 0 && i < 11) {
      // digitalWrite(A0, bitRead(i, 0));
      // digitalWrite(A1, bitRead(i, 1));
      // digitalWrite(A2, bitRead(i, 2));
      // digitalWrite(A3, bitRead(i, 3));

      delay(500);

      // digitalWrite(A0, LOW);
      // digitalWrite(A1, LOW);
      // digitalWrite(A2, LOW);
      // digitalWrite(A3, LOW);
      // Serial.print(Nomes[i - 1]);
      // Serial.print(' ');
      // Serial.println(i);
    }
  }
}

