#define MQ_PIN A1
#define LED       7
float mqValue;
float mqPercents;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  mqValue = analogRead(MQ_PIN);
  mqPercents = mqValue/1024*100;
  Serial.print("GAS: ");
  Serial.print(mqPercents);
  Serial.println("%");

  if (mqPercents > 50) { digitalWrite(LED, HIGH); }
  else { digitalWrite(LED, LOW); }
  
  delay(1000);
  // put your main code here, to run repeatedly:

}
