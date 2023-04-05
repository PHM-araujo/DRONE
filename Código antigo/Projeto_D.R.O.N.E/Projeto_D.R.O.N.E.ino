/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.

  Hardware Required:
    LaunchPad with an LED

  This example code is in the public domain.
*/

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "libraries/utils/uartstdio.h"
#include "libraries/utils/ustdlib.h"

#define PWM_FREQUENCY 31250 //31250?

void setPeripherals();
void setPWMs();
void setUART();
void readSerialInput();

/* BOTOES */
const byte A0but = PD_0;
const byte A1but = PD_1;
const byte A2but = PD_2;
const byte A3but = PD_3;

/* Joysticks */
const byte JS1_UD = PB_7;
const byte JS1_LR = PB_6;
const byte JS2_UD = PC_4;
const byte JS2_LR = PC_5;

/* Constantes base para os Joysticks */
const byte ALTO    = 255;
const byte REPOUSO = 127;
const byte BAIXO   = 0;

String Nomes[10] = {"Video", "Foto", "FT", "RT", "LT", "BT", "Loop", "LS", "Speed", "RS"};

volatile uint32_t ui32Period = 0;
volatile uint8_t ui8Resolution = 255;


void setup() {
  SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //40MHz
  SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

  setPeripherals();
  setPWMs();
  setUART();

  pinMode(A0but, OUTPUT);
  pinMode(A1but, OUTPUT);
  pinMode(A2but, OUTPUT);
  pinMode(A3but, OUTPUT);

  digitalWrite(A0but, LOW);
  digitalWrite(A1but, LOW);
  digitalWrite(A2but, LOW);
  digitalWrite(A3but, LOW);
  UARTprintf("Hello\n");
}

void loop() {
  //  Serial.println("A");
      readSerialInput();
}

void setPeripherals() {
  SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
}

void setPWMs() {
  volatile uint32_t ui32PWMClock = 0;
  volatile uint8_t ui8PWMAdjust = 127;

  //Pinos que possuem função PWM
  GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
  GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);

  //Os configura como pino de PWM
  GPIOPinConfigure(GPIO_PC4_M0PWM6);
  GPIOPinConfigure(GPIO_PC5_M0PWM7);
  GPIOPinConfigure(GPIO_PB6_M0PWM0);
  GPIOPinConfigure(GPIO_PB7_M0PWM1);

  //Seta o periodo com base no clock do sistema
  ui32PWMClock = SysCtlClockGet() / 64;
  ui32Period = (ui32PWMClock / PWM_FREQUENCY) - 1;
  PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ui32Period);

  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, ui8PWMAdjust * ui32Period / ui8Resolution);
  PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7, ui8PWMAdjust * ui32Period / ui8Resolution);
  PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true);
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ui8PWMAdjust * ui32Period / ui8Resolution);
  PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, ui8PWMAdjust * ui32Period / ui8Resolution);
  PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
  PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}

void setUART() {
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  UARTStdioConfig(0, 115200, 40000000);
}
void readSerialInput() {
  char Leitura[20]="\0";
//  String Leitura = Serial.readString();
  UARTgets(Leitura, 20);

  if (ustrcmp(Leitura, "Inicia") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, ALTO * ui32Period / ui8Resolution);
    delay(1000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, BAIXO * ui32Period / ui8Resolution);
    delay(1000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Iniciou\n");
  } else if (ustrcmp(Leitura, "Sobe") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, ALTO * ui32Period / ui8Resolution);
    delay(500);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Subiu\n");
  } else if (ustrcmp(Leitura, "Desce") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, BAIXO * ui32Period / ui8Resolution);
    delay(2000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Desceu\n");
  } else if (ustrcmp(Leitura, "Esquerda") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ALTO * ui32Period / ui8Resolution);
    delay(1000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Esquerdou\n");
  } else if (ustrcmp(Leitura, "Direita") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, BAIXO * ui32Period / ui8Resolution);
    delay(2000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Direitou\n");
  } else if (ustrcmp(Leitura, "Drone") == 0) {
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, BAIXO * ui32Period / ui8Resolution);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, BAIXO * ui32Period / ui8Resolution);
    delay(2000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, REPOUSO * ui32Period / ui8Resolution);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, REPOUSO * ui32Period / ui8Resolution);
    delay(1000);
    UARTprintf("Dronou\n");
  }  else {
    int i = atoi(Leitura);
    if (i > 0 && i < 11) {
      digitalWrite(A0but, bitRead(i, 0));
      digitalWrite(A1but, bitRead(i, 1));
      digitalWrite(A2but, bitRead(i, 2));
      digitalWrite(A3but, bitRead(i, 3));

      delay(500);

      digitalWrite(A0but, LOW);
      digitalWrite(A1but, LOW);
      digitalWrite(A2but, LOW);
      digitalWrite(A3but, LOW);
      Serial.print(Nomes[i - 1]);
      Serial.print(' ');
      Serial.println(i);
    }
  }
}
