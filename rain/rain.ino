#define PIN_ANALOG_RAIN_SENSOR A5  // Аналоговый вход для сигнала датчика протечки и дождя
#define PIN_DIGITAL_RAIN_SENSOR 7  // Цифровой вход для сигнала датчика протечки и дождя
 
void setup(){
   Serial.begin(9600);
}
void loop(){
   int sensorValue = analogRead(PIN_ANALOG_RAIN_SENSOR); // Считываем данные с аналогового порта
   Serial.print("Analog value: "); 
   Serial.println(sensorValue); // Выводим аналоговое значение в монитр порта

   sensorValue = digitalRead(PIN_DIGITAL_RAIN_SENSOR); // Считываем данные с цифрового порта
   Serial.print("Digital value: "); 
   Serial.println(sensorValue); // Выводим цифровое значение в монитр порта

   delay(1000); // Задержка между измерениями
}
