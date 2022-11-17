#include <Arduino.h>
#include "DACMCP4725.h"

void setup() {
	Serial.begin(115200);

	Serial.println("Inicializando módulo DAC");
	dac.begin(0x60);
}

void loop() {

	setVoltage_8bit(255);

	/*
	for (uint32_t counter = 0; counter < 4095; counter++){
		printVoltage(counter);
		dac.setVoltage(counter, false);
		delay(500);
	}
	*/
}