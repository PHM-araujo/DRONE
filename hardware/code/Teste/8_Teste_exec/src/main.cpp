#include <Arduino.h>


void setup() {
  Serial.begin(115200);
}

void loop() {
  iif(Serial.available()>0){
    input=Serial.read();
    print(input);
  }
}
