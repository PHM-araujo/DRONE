#ifndef _JOYSTICK_
#define _JOYSTICK_

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP4725.h"

class Joystick{
private:
    enum Estado {BAIXO = 0, REPOUSO = 127, ALTO = 255};

    uint16_t timerBTN = 300;

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

    //----------------------AUX----------------------//
    // Configura o Joystick relacionado ao DAC do Esp32 - 1
    void setJoystickSD(int nivel);
    // Configura o Joystick relacionado ao DAC do Esp32 - 2
    void setJoystickHA(int nivel);
    // Configura o Joystick relacionado ao DAC externo - 3
    void setJoystickFT(int nivel);
    // Configura o Joystick relacionado ao DAC externo - 4
    void setJoystickED(int nivel);

    // COnverte o comando em 8 bits para 12 bits
    int Convert8to12bits(int counter8);

    // Pegar as tensões que serão usadas nos DACs 
    void getVoltages(String msg);

public:
    bool rest = false;


    Joystick();

    void init();

    // Processa a msg passada pela serial 
    int processMSG(String msg);

    // Atua nos DACs 
    void dacActutor();

    //----------------------Rotinas----------------------//
    // Rotina para iniciar o drone 
    void initDrone();
    // Rotina para voltar o drone para o repouso 
    void returnRest();
    //  Rotina para desligar o drone
    void DisconnectDrone();
    // Rotina para conectar o drone
    void connectDrone(); 
    // Rotina para calibrar o drone com o chão  
    void calibChao();

    // Rotinas para acionar os botões 
    void btnCalibSDAdd();
    void btnCalibFTAdd();
    void btnCalibEDAdd();

    void btnCalibSDMinnus();
    void btnCalibFTMinnus();
    void btnCalibEDMinnus();
  
};


#endif
