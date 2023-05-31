#include "DACMCP4725.h"

TwoWire I2CDac1 = TwoWire(1);
TwoWire I2CDac2 = TwoWire(0);
unsigned long delayTime;

void setup() {
	Serial.begin(115200);
	Serial.println("Inicializando módulo DAC");

	I2CDac2.begin(17, 16, 100000);				// Comunicação I2C nos pinos escolhidos
	I2CDac1.begin(21, 22, 100000);				// Comunicação I2C nos pinos padrão 

	// Inicializa o objeto DAC com os pinos escolhidos 
	bool status1 = Dac1.begin(0x60, &I2CDac1);
	bool status2 = Dac2.begin(0x60, &I2CDac2);

	// Checa erros
	if (!status1) {
    	Serial.println("Could not find a valid BME280 sensor, check wiring!");
    	while (1);
  	}

	if (!status2) {
    	Serial.println("Could not find a valid BME280 sensor, check wiring!");
    	while (1);
  	}

	Serial.println();
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