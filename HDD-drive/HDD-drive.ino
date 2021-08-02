const int phase1pin = 0;
const int phase2pin = 1;
const int phase3pin = 2;
const int delayTime = 6000;

void setup() {
  Serial.begin(9600);
  pinMode(phase1pin, OUTPUT);
  pinMode(phase2pin, OUTPUT);
  pinMode(phase3pin, OUTPUT);
}

void loop() {
  switchStep(1);
  switchStep(2);
  switchStep(3);
}

void switchStep(int stage){
  switch(stage){
    case 1:
    digitalWrite(phase1pin, HIGH);
    digitalWrite(phase2pin, LOW);
    digitalWrite(phase3pin, LOW);
    delayMicroseconds(delayTime);
    break;

    case 2:
    digitalWrite(phase1pin, LOW);
    digitalWrite(phase2pin, HIGH);
    digitalWrite(phase3pin, LOW);
    delayMicroseconds(delayTime);
    break;
    
    case 3:
    digitalWrite(phase1pin, LOW);
    digitalWrite(phase2pin, LOW);
    digitalWrite(phase3pin, HIGH);
    delayMicroseconds(delayTime);
    break;    
  }
}
