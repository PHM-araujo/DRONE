#include "Joystick.h"
#define Atime 1000

int aux = -1;

Joystick controle = Joystick();

void setup(){
  Serial.begin(115200);
  controle.init();
  // Configura o timeout da Serial (Milliseconds)
  Serial.setTimeout(1); 
}

void loop() {
	if (Serial.available() > 0){
		String msg = Serial.readStringUntil(';');
		Serial.println(msg);

		// aux = controle.processMSG(msg);


		// // Se não for um rotina atua nos DACs 
		// if(aux){
		// 	controle.dacActutor();
		// }
		
		// if (controle.rest){
		// 	controle.returnRest();
		// 	controle.rest = false;
		// }
		
	}
}