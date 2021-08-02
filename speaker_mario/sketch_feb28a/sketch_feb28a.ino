#include "pitches.h"
int SPEAKER=9;

int notes[] = {
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_A4, NOTE_F4, NOTE_C4, NOTE_C4,
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_AS4,
  NOTE_G4, NOTE_C5, 0, NOTE_C5, NOTE_D4,
  NOTE_D4, NOTE_AS4,NOTE_AS4,NOTE_A4,
  NOTE_G4, NOTE_F4, NOTE_C4, NOTE_A4,
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4
};

int times[] = {
  400,400,400,400,
  400,400,400,400,
  400,400,400,400,
  400,600,20,400,400,
  400,400,400,400,
  400,400,400,400,
  400,400,400,600
};

void setup(){
 for (int i = 0; i < 29; i++){
  tone(SPEAKER, notes[i],times[i]);
  delay(times[i]);
  noTone(SPEAKER);
 }
}
void loop(){} 
