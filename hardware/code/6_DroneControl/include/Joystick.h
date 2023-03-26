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

    float SD = REPOUSO;
    float HA = REPOUSO;
    float FT = REPOUSO;
    float ED = REPOUSO;



public:
    bool rest = false;

    enum Estado {BAIXO = 0, REPOUSO = 127, ALTO = 255};

    Joystick();

    void init();
    int Convert8to12bits(int counter8);

    // Configura o Joystick relacionado ao DAC do Esp32 - 1
    void setJoystickSD(int nivel);
    // Configura o Joystick relacionado ao DAC do Esp32 - 2
    void setJoystickHA(int nivel);
    // Configura o Joystick relacionado ao DAC externo - 3
    void setJoystickFT(int nivel);
    // Configura o Joystick relacionado ao DAC externo - 4
    void setJoystickED(int nivel);

    // Conecta o drone ao controle 
    void connectDrone(); 

    // Processa a msg passada pela serial 
    int processMSG(String msg);
    // Atua nos DACs 
    void dacActutor();
    // Retorna os DACs para o repouso
    void returnRest();
    // Pegar as tensões que serão usadas nos DACs 
    void getVoltages(String msg);

    void teste1(String Leitura);

    void startDrone();

    void DisconnectDrone();


};


#endif
