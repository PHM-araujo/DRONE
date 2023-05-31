#include "Joystick.h"

Joystick::Joystick(){}

void Joystick::init(){

  pinMode(2, OUTPUT);

  // Pinos btn
  pinMode(13, OUTPUT);  
  pinMode(14, OUTPUT);     
  pinMode(27, OUTPUT);  
  pinMode(12, OUTPUT);  

  I2CDac3.begin(17, 16, 100000);				// Comunicação I2C nos pinos escolhidos
	I2CDac4.begin(22, 21, 100000);				// Comunicação I2C nos pinos padrão

  // Inicializa o objeto DAC com os pinos escolhidos 
	bool status3 = Dac3.begin(0x60, &I2CDac3);
	bool status4 = Dac4.begin(0x60, &I2CDac4);

	
  // Checa erros
  if (!status3) { 
    Serial.println("Could not find a valid DAC3, check wiring!");
    while (1);
  }

	if (!status4) {
    Serial.println("Could not find a valid DAC4, check wiring!");
    while (1);
  }

	Serial.println("Controle iniciando...");
	setJoystickSD(REPOUSO);
  setJoystickHA(REPOUSO);
  setJoystickFT(REPOUSO);
  setJoystickED(REPOUSO);
	delay(5000);
	Serial.println("Controle iniciado");
  digitalWrite(2, HIGH);
}

int Joystick::processMSG(String msg){
	
  switch (msg[0])
	{
	case 'P':
		connectDrone();
		break;
  case 'I':
    initDrone();
    break;
  case 'D':
    DisconnectDrone();
    break;
  case 'S':
    getVoltages(msg);
    return 1;
  case 'R':
    rest = true;
    break;
  case 'A':
    getRest(msg);
    break;
  case 'C':
    calibChao();
    break;
  case '1':
    btnCalibSDAdd();
    break;
  case '2':
    btnCalibFTAdd();
    break;
  case '3':
    btnCalibEDAdd();
    break;
  case '4':
    btnCalibSDMinnus();
    break;
  case '5':
    btnCalibFTMinnus();
    break;
  case '6':
    btnCalibEDMinnus();
    break;
	default:
		break;
	}

  return 0;
}

void Joystick::dacActutor(){
  setJoystickSD(SD);
  setJoystickHA(HA);
  setJoystickFT(FT);
  setJoystickED(ED);

  Serial.println("Atuadores atualizados");
}

//----------------------AUX----------------------//

void Joystick::setJoystickSD(int nivel){
	dacWrite(Dac1Adress, nivel);
}
void Joystick::setJoystickHA(int nivel){
	dacWrite(Dac2Adress, nivel);

}
void Joystick::setJoystickFT(int nivel){
	Dac3.setVoltage(Convert8to12bits(nivel), false);

}
void Joystick::setJoystickED(int nivel){
	Dac4.setVoltage(Convert8to12bits(nivel), false);
}

void Joystick::getVoltages(String msg){
	String SD_str = "", HA_str = "", FT_str = "", ED_str = "";

  int pos = msg.indexOf(',', 2);
  for(int i = 4; i < pos; i++) SD_str += msg[i];

  int pos2 = msg.indexOf(',', pos + 1);
  for(int i = pos + 3; i < pos2; i++) HA_str += msg[i];

  int pos3 = msg.indexOf(',', pos2 + 1);
  for(int i = pos2 + 3; i < pos3; i++) FT_str += msg[i];

  int pos4 = msg.indexOf(',', pos3 + 1);
  for(int i = pos3 + 3; i < pos4; i++) ED_str += msg[i];

  char R_str = msg[pos4 + 1];
  Serial.println(R_str);

  // Quando só se pressiona o botão 
  if(R_str == 'R'){
    rest = true;
  }

  SD = SD_str.toInt();
  Serial.print("SD = ");
  Serial.println(SD);
  HA = HA_str.toInt();
  Serial.print("HA = ");
  Serial.println(HA);
  FT = FT_str.toInt();
  Serial.print("FT = ");
  Serial.println(FT);
  ED = ED_str.toInt();
  Serial.print("ED = ");
  Serial.println(ED);
}

int Joystick::Convert8to12bits(int counter8){

	int counter12;

	counter12 = (4095.0*counter8)/255;

    return counter12;

}

//----------------------Rotinas----------------------//

void Joystick::initDrone(){
  Serial.println("Motores Iniciando...");
  setJoystickSD(ALTO);
	delay(1000);
	setJoystickSD(REPOUSO);
	delay(1000);
	Serial.println("Motores Iniciados");
}

void Joystick::DisconnectDrone(){
  Serial.println("Motores Desligando...");
  setJoystickSD(BAIXO);
	delay(3000);
	setJoystickSD(REPOUSO);
	delay(1000);
	Serial.println("Motores Desligados");
}

void Joystick::returnRest(){
  setJoystickSD(REPOUSO);
  setJoystickHA(REPOUSO);
  setJoystickFT(Rest_FT);
  setJoystickED(Rest_LR);
  Serial.println("Atuadores no repouso");

  delay(100);
}

void Joystick::connectDrone(){
	
  Serial.println("Pareando...");
  setJoystickSD(ALTO);
	delay(1000);
	setJoystickSD(BAIXO);
	delay(1000);
	setJoystickSD(REPOUSO);
	delay(1000);
	Serial.println("Pareado");
}

void Joystick::calibChao(){
	
  Serial.println("Calibrando com o chão...");
  setJoystickSD(BAIXO);
  setJoystickHA(BAIXO);
  setJoystickFT(BAIXO);
  setJoystickED(BAIXO);
	delay(3000);
	setJoystickSD(REPOUSO);
  setJoystickHA(REPOUSO);
  setJoystickFT(REPOUSO);
  setJoystickED(REPOUSO);
	delay(1000);
	Serial.println("Calibrado");
}


//----------------------BTNs de ajuste----------------------//

// S8
void Joystick::btnCalibSDAdd(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, HIGH);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}

// S3
void Joystick::btnCalibFTAdd(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, HIGH);
  // B
	digitalWrite(14, HIGH);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}

// S2
void Joystick::btnCalibEDAdd(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, HIGH);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}

//S10
void Joystick::btnCalibSDMinnus(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, HIGH);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, HIGH);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}

// S6
void Joystick::btnCalibFTMinnus(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, HIGH);
  // C
  digitalWrite(12, HIGH);
  // D
	digitalWrite(13, LOW);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}

// S4
void Joystick::btnCalibEDMinnus(){
  Serial.println("Apertei btn");
  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, HIGH);
  // D
	digitalWrite(13, LOW);

  delay(timerBTN);

  // A
  digitalWrite(27, LOW);
  // B
	digitalWrite(14, LOW);
  // C
  digitalWrite(12, LOW);
  // D
	digitalWrite(13, LOW);

  delay(500);

}


void Joystick::getRest(String msg){
  String RFT_str = "", RLR_str = "";
  int pos = msg.indexOf(',', 3);
  for(int i = 5; i < pos; i++) RFT_str += msg[i];

  int pos2 = msg.indexOf(',', pos + 1);
  for(int i = pos + 3; i < pos2; i++) RLR_str += msg[i];

  Rest_LR = RLR_str.toInt();
  Rest_FT = RFT_str.toInt();

  returnRest();

  return;
}