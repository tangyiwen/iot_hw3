#include "pitches.h"

#define MIC_PIN A0
#define BUZ_PIN 2

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MIC_PIN,INPUT);
  pinMode(BUZ_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mic = analogRead(MIC_PIN);
  Serial.println(mic);
  if(mic >= 350){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZ_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZ_PIN);
  }
}}
