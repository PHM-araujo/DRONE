
#include "Joystick.hpp"

Joystick controle = Joystick();

void setup() {
  
  Serial.begin(115200);

  Serial.println("Digite o comando para o drone:");
}

void loop() {
  

  if (Serial.available() > 0){
    String Leitura = Serial.readString();

    if (Leitura == "inicia"){
      controle.setJoystickUp1(255);
      delay(1000);
      controle.setJoystickUp1(0);
      delay(1000);
      controle.setJoystickUp1(127);
      delay(1000);

    Serial.println("Iniciou");
    } 
    if (Leitura == "sobe"){
      //sobe();
    } 
    if (Leitura == "desce"){
      //desce();
    } 
    if (Leitura == "esquerda"){
      //esquerda();
    } 
    if (Leitura == "direita"){
      //direita();
    } 
    if (Leitura == "frete"){
      //frente();
    } 
    if (Leitura == "tras"){
      //tras();
    } 
    if (Leitura == "horario"){
      //horario();
    } 
    if (Leitura == "antihor"){
      //antihorario();
    } 
  }
  
  
}