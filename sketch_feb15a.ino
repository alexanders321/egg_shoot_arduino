#include "Servo.h"
Servo servo;
int angle=80; // переменная для угла поворота микро серво
int angle_attack=120; // переменная для угла поворота микро серво
void setup() {
  servo.attach(7); // пин для подключения микро серво
  Serial.begin(9600);    // установим скорость обмена данными
}

void loop() {
    servo.write(angle); 
  // цикл для поворота от 0 до 90 градусов
   String stringOne = "Info from Arduino ";
   Serial.println(stringOne);  // отправляем строку на порт

  char incomingChar;
  
  if (Serial.available() > 0)
  {    // считываем полученное с порта значение в переменную
    incomingChar = Serial.read();  
   // в зависимости от значения переменной включаем или выключаем LED
    if(incomingChar =='f')shoot();
    
}
}






void shoot(){

    servo.write(angle_attack); // сообщаем микро серво угол поворота
    delay(10000); // ждем 20 мс, пока серво не сделает поворот
    servo.write(angle); 
    delay(10000); // ждем 20 мс, пока серво не сделает повор

}