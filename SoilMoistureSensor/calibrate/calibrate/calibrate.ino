// Выводы, подключенные к датчику
#define sensorPower 7
#define sensorPin A1

void setup() 
{
  pinMode(sensorPower, OUTPUT);

  // Изначально оставляем датчику выключенным
  digitalWrite(sensorPower, LOW);

  Serial.begin(9600);
}

void loop() 
{
  // получить показание из функции ниже и напечатать его
  Serial.print("Analog output: ");
  Serial.println(readSensor());

  delay(1000);
}

// Данная функция возвращает аналоговый результат измерений датчика влажности почвы
int readSensor() 
{
  digitalWrite(sensorPower, HIGH);  // Включить датчик
  delay(10);                        // Дать время питанию установиться
  int val = analogRead(sensorPin);  // Прочитать аналоговое значение от датчика
  digitalWrite(sensorPower, LOW);   // Выключить датчик
  return val;                       // Вернуть аналоговое значение влажности
}
