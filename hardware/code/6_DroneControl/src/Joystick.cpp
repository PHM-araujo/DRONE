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
	setJoystickSD(REPOUSO);
  setJoystickHA(REPOUSO);
  setJoystickFT(REPOUSO);
  setJoystickED(REPOUSO);
	delay(5000);
	Serial.println("Controle iniciado");
}

int Joystick::Convert8to12bits(int counter8){

	int counter12;

	counter12 = (4095.0*counter8)/255;

    return counter12;

}

void Joystick::setJoystickSD(int nivel){
	dacWrite(Dac1Adress, nivel);
}
void Joystick::setJoystickHA(int nivel){
	dacWrite(Dac2Adress, nivel);

}
void Joystick::setJoystickFT(int nivel){
	Dac3.setVoltage(Convert8to12bits(nivel), false);

}
void Joystick::setJoystickED(int nivel){
	Dac4.setVoltage(Convert8to12bits(nivel), false);
}

//TODO testar
void Joystick::returnRest(){
  setJoystickSD(REPOUSO);
  setJoystickHA(REPOUSO);
  setJoystickFT(REPOUSO);
  setJoystickED(REPOUSO);

  delay(100);
}

bool Joystick::processMSG(String msg){
	
  switch (msg[0])
	{
	case 'C':
		connectDrone();
		break;

  case 'S':
    getVoltages(msg);
    return true;
		break;

	default:
		break;
	}

  return false;
}

//TODO testar
void Joystick::connectDrone(){
	setJoystickSD(ALTO);
	delay(1000);
	setJoystickSD(BAIXO);
	delay(1000);
	setJoystickSD(REPOUSO);
	delay(1000);
	Serial.println("Iniciou");
}


void Joystick::getVoltages(String msg){
	String SD_str = "", HA_str = "", FT_str = "", ED_str = "";

  int pos = msg.indexOf(',', 2);
  for(int i = 4; i < pos; i++) SD_str += msg[i];

  int pos2 = msg.indexOf(',', pos + 1);
  for(int i = pos + 3; i < pos2; i++) HA_str += msg[i];

  int pos3 = msg.indexOf(',', pos2 + 1);
  for(int i = pos2 + 3; i < pos3; i++) FT_str += msg[i];

  int pos4 = msg.indexOf(',', pos3 + 1);
  for(int i = pos3 + 3; i < pos4; i++) ED_str += msg[i];

  SD = SD_str.toInt();
  Serial.print("SD = ");
  Serial.println(SD);
  HA = HA_str.toInt();
  Serial.print("HA = ");
  Serial.println(HA);
  FT = FT_str.toInt();
  Serial.print("FT = ");
  Serial.println(FT);
  ED = ED_str.toInt();
  Serial.print("ED = ");
  Serial.println(ED);
}

//TODO testar
void Joystick::dacActutor(){
  setJoystickSD(SD);
  setJoystickHA(HA);
  setJoystickFT(FT);
  setJoystickED(ED);

  Serial.println("Atuadores atualizados");
}