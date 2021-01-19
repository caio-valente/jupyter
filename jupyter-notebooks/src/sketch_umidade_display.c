//Programa: Teste LCD 16x2 com Keypad e Sensor de umidade
//Autor: Caio

/* 
 HTU21D Humidity Sensor Example Code
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 15th, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Uses the HTU21D library to display the current humidity and temperature
 
 Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
  
 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)

 */

  
#include <LiquidCrystal.h>
#include <Wire.h>
#include "SparkFunHTU21D.h"
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
HTU21D myHumidity; 
  
void setup()   
{
 Serial.begin(9600);
 Serial.print("Temp");
 Serial.print("\tHmdt");
 Serial.print("\n");
 myHumidity.begin();
 lcd.begin(16, 2);  
 lcd.setCursor(0,0);  
 lcd.print("Umidade:");  
 lcd.setCursor(0,1);  
 lcd.print("Temp:");  
}  
  
void loop()  
{  
 int botao;
 float humd = myHumidity.readHumidity();
 float temp = myHumidity.readTemperature(); 
 humd += (75 - 71.21);
 botao = analogRead (0);  //Leitura do valor da porta analógica A0
 lcd.setCursor(9,0);  
 lcd.print(humd);
 lcd.print("%");
 lcd.setCursor(6,1);  
 lcd.print(temp);
 lcd.print("C");
 if (botao < 100) {  
  //Direita
 }  
 else if (botao < 200) {  
  //Cima  
 }  
 else if (botao < 400){  
  //Baixo
 }  
 else if (botao < 600){  
  //Esquerda
 }  
 else if (botao < 800){  
  //Select
 }  
  Serial.print(temp, 1);
  Serial.print("\t");
  Serial.print(humd, 1);
  Serial.println();
  delay(1000);
}
