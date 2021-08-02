/* Измените эти значения, основываясь на своих значениях калибровки */
#define soilWet 260   // Определяет максимальное значение, при котором, мы решили, что почва 'влажная'
#define soilDry 300  // Определяет минимальное значение, при котором, мы решили, что почва 'сухая'

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
  int moisture = readSensor();
  Serial.print("Analog Output: ");
  Serial.println(moisture);

  // определить состояние нашей почвы
  if (moisture < soilWet) 
  { // слишком влажная
    Serial.println("Status: Soil is too wet");
  }
  else if (moisture >= soilWet && moisture < soilDry) 
  { // идеальное состояние
    Serial.println("Status: Soil moisture is perfect");
  }
  else 
  { // слишком сухая - пора поливать
    Serial.println("Status: Soil is too dry - time to water!");
  }

  delay(1000); // Для проверки берем показания раз в секунду
               // Обычно вам необходимо проверять показания, возможно, раз или два в день
  Serial.println();
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
