#include "DroneControl.h"

void setup() {
  Serial.begin(115200);

  initDigPot();

  Serial.println("Digite o comando para o drone:");
}

void loop() {


  if (Serial.available() > 0){
    String Leitura = Serial.readString();

    if (Leitura == "inicia"){
      inicia();
    } 
    if (Leitura == "sobe"){
      sobe();
    } 
    if (Leitura == "desce"){
      desce();
    } 
    if (Leitura == "esquerda"){
      esquerda();
    } 
    if (Leitura == "direita"){
      direita();
    } 
    if (Leitura == "frete"){
      frente();
    } 
    if (Leitura == "tras"){
      tras();
    } 
    if (Leitura == "horario"){
      horario();
    } 
    if (Leitura == "antihor"){
      antihorario();
    } 
  }
  
}