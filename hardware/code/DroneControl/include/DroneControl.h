#include <Arduino.h>
#include "DigitalPot.h"

// Constantes base para os Joysticks 
const byte ALTO = 255;
const byte REPOUSO = 127;
const byte BAIXO = 0;

#define JS1_UD 25          // DAC 0
#define JS1_LR 26          // DAC 1
#define JS2_UD pot0
#define JS2_LR pot1



void measuredVoltage(int i){
    float volt = (3300.0 / 255.0) * (float)i;
    Serial.print("Tensão nos terminais: ");
    Serial.print(volt);
    Serial.println(" mV");
}

// Essa função testa os joyticks variando a tensão de 1 a 256 em todos os terminais 
void testeJoystick(){

    for(int i = 0; i < 256; i ++){

        setPotWiper(JS2_UD, i);
        setPotWiper(JS2_LR, i);
        dacWrite(JS1_UD, i);
        dacWrite(JS1_LR, i);

        Serial.print("Valor de i = ");
        Serial.println(i);

        Serial.print("Tensão nos terminais: ");
        measuredVoltage(i);

        delay(500);
    }
}


void inicia(){
    dacWrite(JS1_UD, ALTO);
    delay(1000);
    dacWrite(JS1_UD, BAIXO);
    delay(1000);
    dacWrite(JS1_UD, REPOUSO);
    delay(1000);

    Serial.println("Iniciou");
}

void sobe(){
    dacWrite(JS1_UD, ALTO);
    delay(1000);
    dacWrite(JS1_UD, REPOUSO);
    delay(1000);

    Serial.println("Subiu");
}

void desce(){
    dacWrite(JS1_UD, BAIXO);
    delay(1000);
    dacWrite(JS1_UD, REPOUSO);
    delay(1000);

    Serial.println("Iniciou");
}

void esquerda(){
    dacWrite(JS1_LR, ALTO);
    delay(1000);
    dacWrite(JS1_LR, REPOUSO);
    delay(1000);

    Serial.println("Esquerdou");
}

void direita(){
    dacWrite(JS1_LR, ALTO);
    delay(1000);
    dacWrite(JS1_LR, REPOUSO);
    delay(1000);

    Serial.println("Direitou");
}

void frente(){
    setPotWiper(JS2_UD, ALTO);
    delay(1000);
    setPotWiper(JS2_UD, REPOUSO);
    delay(1000);

    Serial.println("Direitou");
}


void tras(){
    setPotWiper(JS2_UD, BAIXO);
    delay(1000);
    setPotWiper(JS2_UD, REPOUSO);
    delay(1000);

    Serial.println("Direitou");
}

void horario(){
    setPotWiper(JS2_LR, ALTO);
    delay(1000);
    setPotWiper(JS2_LR, REPOUSO);
    delay(1000);

    Serial.println("Direitou");
}

void antihorario(){
    setPotWiper(JS2_LR, BAIXO);
    delay(1000);
    setPotWiper(JS2_LR, REPOUSO);
    delay(1000);

    Serial.println("Direitou");
}
