#include <Arduino.h>
#define LED_PIN 12

void setup(){

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
} 


void loop(){


  digitalWrite(LED_PIN, HIGH);

}