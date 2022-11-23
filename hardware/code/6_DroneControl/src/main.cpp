#include "Joystick.h"

Joystick controle = Joystick();

void setup(){
  
  Serial.begin(115200);
  controle.init();
  
  Serial.println("Controle iniciando");
  controle.setJoystickUp1(127);
  controle.setJoystickUp2(127);
  controle.setJoystickUp3(127);
  controle.setJoystickUp4(127);
  delay(5000);
  Serial.println("Controle iniciado");

}

void loop() {

  if (Serial.available() > 0){
    String Leitura = Serial.readString();
    Serial.println(Leitura);

    if (Leitura == "in"){
  
      controle.setJoystickUp1(255);
      delay(1000);
      controle.setJoystickUp1(0);
      delay(1000);
      controle.setJoystickUp1(127);
      delay(1000);
      Serial.println("Iniciou");
      
    } 
    if (Leitura == "s"){
      controle.setJoystickUp1(255);
      delay(5000);
      controle.setJoystickUp1(127);
      delay(5000);
      Serial.println("Subiu");
    } 
    if (Leitura == "des"){
      controle.setJoystickUp1(0);
      delay(5000);
      controle.setJoystickUp1(127);
      delay(5000);
      Serial.println("Desceu");
    } 
    if (Leitura == "esq"){
      controle.setJoystickUp4(255);
      delay(5000);
      controle.setJoystickUp4(127);
      delay(5000);
      Serial.println("Foi pra esquerda");
    } 
    if (Leitura == "dir"){
      controle.setJoystickUp4(0);
      delay(5000);
      controle.setJoystickUp4(127);
      delay(5000);
      Serial.println("Foi pra direita");
    } 
    if (Leitura == "fr"){
      controle.setJoystickUp3(255);
      delay(5000);
      controle.setJoystickUp3(127);
      delay(5000);
      Serial.println("Foi pra frente");
    } 
    if (Leitura == "tr"){
      controle.setJoystickUp3(0);
      delay(5000);
      controle.setJoystickUp3(127);
      delay(5000);
      Serial.println("Foi pra tras");
    } 
    if (Leitura == "h"){
      controle.setJoystickUp2(255);
      delay(5000);
     controle.setJoystickUp2(127);
      delay(5000);
      Serial.println("Rodou horario");
    } 
    if (Leitura == "ant"){
      controle.setJoystickUp2(0);
      delay(5000);
      controle.setJoystickUp2(127);
      delay(5000);
      Serial.println("Rodou antihorario");
    } 
  }
  
  
}