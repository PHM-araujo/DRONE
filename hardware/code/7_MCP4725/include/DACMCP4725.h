#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>

// TODO Ajustar o código para dois potenciômetros 

float voltageMax = 3.56;

Adafruit_MCP4725 dac;

void setVoltage_8bit(int counter8){

	int counter12;

	counter12 = (4095.0*counter8)/255;

	dac.setVoltage(counter12, false);

}

void printVoltage(int counter){
	float voltage;

	voltage = counter * voltageMax / 4095;

	Serial.print("Tensão no DAC = ");
	Serial.println(voltage) ;
}