// C++ code
//
#include<Servo.h>
Servo s1;
Servo s2;
int sPin = 3;
int sPin2 = 5;
int pot = A0;
void setup()
{
  pinMode(pot, INPUT);
  s1.attach(sPin);
  s2.attach(sPin2);
  
}

void loop()
{
  int v =analogRead(pot);
  
  
  s1.write(map(v , 0, 1023 , 0 , 180));
  s2.write(map(v , 0 , 1023 , 180 , 0));
}