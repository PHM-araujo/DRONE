#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>

float voltageMax = 3.56;

Adafruit_MCP4725 Dac1;
Adafruit_MCP4725 Dac2;

void setVoltage_8bit(int counter8){

	int counter12;

	counter12 = (4095.0*counter8)/255;

	Dac2.setVoltage(counter12, false);
	Dac1.setVoltage(counter12, false);

}

void printVoltage(int counter){
	float voltage;

	voltage = counter * voltageMax / 4095;

	Serial.print("Tensão no DAC = ");
	Serial.println(voltage) ;
}