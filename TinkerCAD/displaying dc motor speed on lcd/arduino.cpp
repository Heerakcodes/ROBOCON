// C++ code
//
int en1 =3;
int in1 = 12;
int in2 = 8;
int pot = A1;
#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27 , 16, 2);




void setup()
{
  pinMode(en1, OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(pot , INPUT);
  
   lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  
  
  

  
}

void loop()
{
  
  int v = analogRead(pot);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2, LOW);
  int s = map(v , 0 , 1023 , 0, 255);
  
  analogWrite(en1 ,s);
  lcd.print(v);
  lcd.setCursor(0,1);
  lcd.print(s);
  delay(500);
  lcd.clear();
  
  
  
  
}