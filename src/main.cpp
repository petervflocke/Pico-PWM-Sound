#include <Arduino.h>
#include "pitches.h"

#define BuzzerPin 16
#define GPIO_AUDIO_OUT_LEFT  6
#define pinBut 14

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/irq.h"
#include "WavPwmAudio.h"
#include "WAVData.h"

void setup() {
  Serial.begin(115200);
  pinMode(pinBut, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  tone(BuzzerPin,NOTE_B5,500);
  delay(1000);

  WavPwmInit(GPIO_AUDIO_OUT_LEFT);

}

void loop() {

 delay(100);
 if (!gpio_get(pinBut)) {
  gpio_put(LED_BUILTIN, 1);
  delay(250);
  gpio_put(LED_BUILTIN, 0);
  Serial.println("OK");
  WavPwmPlayAudio(DING_WAV);
 }

}