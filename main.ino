#define PIN_MQ2  A1    // имя пина для подключения MQ2
#define LED       13   // имя пина для подключения светодиода
#include "TM1637Display.h"
TM1637Display display(3, 2); // CLC, DIO
int value;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(PIN_MQ2, INPUT);
  display.setBrightness(7); // яркость от 0 до 7, true/false
  display.clear();
}

void loop() {
   // записываем полученные данные с датчика
   value = analogRead(PIN_MQ2);

   // выводим информацию на монитор порта
   Serial.println("VALUE - " + String(value));
   Serial.println(" ");
   display.showNumberDec(value, false, 3, 0);
   display.setSegments(value, 1, 3);
   delay(500);

   // включаем светодиод при превышении определенного значения
   if (value > 200) { digitalWrite(LED, HIGH); }
   else { digitalWrite(LED, LOW); }

   delay(200);
}