#include "Joystick.h"

Joystick::Joystick(){}

void Joystick::init(){

    I2CDac3.begin(17, 16, 100000);				// Comunicação I2C nos pinos escolhidos
	I2CDac4.begin(22, 21, 100000);				// Comunicação I2C nos pinos padrão

    // Inicializa o objeto DAC com os pinos escolhidos 
	bool status3 = Dac3.begin(0x60, &I2CDac3);
	bool status4 = Dac4.begin(0x60, &I2CDac4);

	
    // Checa erros
	if (!status3) { 
    	Serial.println("Could not find a valid DAC3, check wiring!");
    	while (1);
  	}

	if (!status4) {
    	Serial.println("Could not find a valid DAC4, check wiring!");
    	while (1);
  	}

	Serial.println("Controle iniciando");
	setJoystickUp1(127);
  	setJoystickUp2(127);
  	setJoystickUp3(127);
  	setJoystickUp4(127);
	delay(5000);
	Serial.println("Controle iniciado");
}

int Joystick::Convert8to12bits(int counter8){

	int counter12;

	counter12 = (4095.0*counter8)/255;

    return counter12;

}

void Joystick::setJoystickUp1(int nivel){
	dacWrite(Dac1Adress, nivel);
}
void Joystick::setJoystickUp2(int nivel){
	dacWrite(Dac2Adress, nivel);

}
void Joystick::setJoystickUp3(int nivel){
	Dac3.setVoltage(Convert8to12bits(nivel), false);

}
void Joystick::setJoystickUp4(int nivel){
	Dac4.setVoltage(Convert8to12bits(nivel), false);
}

void Joystick::teste1(String Leitura){
    if (Leitura == "s"){
      setJoystickUp1(255);
      delay(5000);
      setJoystickUp1(127);
      delay(5000);
      Serial.println("Subiu");
    } 
    if (Leitura == "des"){
      setJoystickUp1(0);
      delay(5000);
      setJoystickUp1(127);
      delay(5000);
      Serial.println("Desceu");
    } 
    if (Leitura == "esq"){
      setJoystickUp4(255);
      delay(5000);
      setJoystickUp4(127);
      delay(5000);
      Serial.println("Foi pra esquerda");
    } 
    if (Leitura == "dir"){
      setJoystickUp4(0);
      delay(5000);
      setJoystickUp4(127);
      delay(5000);
      Serial.println("Foi pra direita");
    } 
    if (Leitura == "fr"){
      setJoystickUp3(255);
      delay(5000);
      setJoystickUp3(127);
      delay(5000);
      Serial.println("Foi pra frente");
    } 
    if (Leitura == "tr"){
      setJoystickUp3(0);
      delay(5000);
      setJoystickUp3(127);
      delay(5000);
      Serial.println("Foi pra tras");
    } 
    if (Leitura == "h"){
      setJoystickUp2(255);
      delay(5000);
		setJoystickUp2(127);
      delay(5000);
      Serial.println("Rodou horario");
    } 
    if (Leitura == "ant"){
      setJoystickUp2(0);
      delay(5000);
      setJoystickUp2(127);
      delay(5000);
      Serial.println("Rodou antihorario");
    }
}

bool Joystick::processMSG(String msg){
	switch (msg[0])
	{
	case 'C':
		connectDrone();
		break;
	
	default:
		getVoltages(msg);
		break;
	}
}

void Joystick::connectDrone(){
	setJoystickUp1(ALTO);
	delay(1000);
	setJoystickUp1(BAIXO);
	delay(1000);
	setJoystickUp1(REPOUSO);
	delay(1000);
	Serial.println("Iniciou");
}

void Joystick::getVoltages(String msg){
	String SD_str = "", HA_str = "", FT_str = "", ED_str = "";
}