void setup() {
 
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

}

  uint32_t tmr;
  int val = 0;
  bool dir = true;
void loop() {
  if (millis() - tmr >= 10.) {
    tmr = millis();
    if (dir) val++; // увеличиваем яркость
    else val--;     // уменьшаем
    if (val >= 255 || val <= 0) dir = !dir; // разворачиваем
    
    analogWrite(3, val);
    analogWrite(5, val);
    analogWrite(6, val);
    analogWrite(9, val);
    
  }

  
}
