#ifndef _JOYSTICK_
#define _JOYSTICK_

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP4725.h"

class Joystick{
private:
    int Dac1Adress = 25;
    int Dac2Adress = 26;

    TwoWire I2CDac3 = TwoWire(0);
	TwoWire I2CDac4 = TwoWire(1);

    Adafruit_MCP4725 Dac3;
    Adafruit_MCP4725 Dac4;
public:
    enum Estado {BAIXO = 0, REPOUSO = 127, ALTO = 255};

    Joystick();

    void init();

    int Convert8to12bits(int counter8);

    void setJoystickUp1(int nivel);
    void setJoystickUp2(int nivel);
    void setJoystickUp3(int nivel);
    void setJoystickUp4(int nivel);

    void inicia();
    void sobe();
    void desce();
    void esquerda();
    void direita();
    void frente();
    void tras();
    void horario();
    void antihorario();

    void printVoltage();


};


#endif
