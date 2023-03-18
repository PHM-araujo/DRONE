#include "Joystick.h"

Joystick controle = Joystick();

void setup(){
  Serial.begin(115200);
  controle.init();
}

void loop() {

	if (Serial.available() > 0){
		String msg = Serial.readStringUntil(';');
		Serial.println(msg);

		// Se não for um rotina atua nos DACs 
		if(controle.processMSG(msg)){
			controle.dacActutor();

			// Tempo que o micro atua nos DACs 
			delay(100);

		}

		controle.returnRest();
		
	}
}