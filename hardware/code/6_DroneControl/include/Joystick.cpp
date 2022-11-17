#include "Joystick.hpp"

Joystick::Joystick(){
    I2CDac3.begin(17, 16, 100000);				// Comunicação I2C nos pinos escolhidos
	I2CDac4.begin(21, 22, 100000);				// Comunicação I2C nos pinos padrão

    // Inicializa o objeto DAC com os pinos escolhidos 
	bool status3 = Dac3.begin(0x60, &I2CDac3);
	bool status4 = Dac4.begin(0x60, &I2CDac4);

    // Checa erros
	if (!status3) { 
    	Serial.println("Could not find a valid BME280 sensor, check wiring!");
    	while (1);
  	}

	if (!status4) {
    	Serial.println("Could not find a valid BME280 sensor, check wiring!");
    	while (1);
  	}

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
	Dac3.setVoltage(nivel, false);

}
void Joystick::setJoystickUp4(int nivel){
	Dac4.setVoltage(nivel, false);
}