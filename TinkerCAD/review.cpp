// C++ code
//
#include <Servo.h>
Servo s;
int pot = A0;
int in1 = 2;
int in2 = 4;
int en = 3;
int servo = 9;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(en , OUTPUT);
  pinMode(servo , INPUT);
  
  
}


void loop()
{
  
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  
  s.attach(servo);
  int v = analogRead(pot);
  int speed = map(v , 0, 1023 , 0, 255);
  
  if( speed > 0 & speed < 127){
  analogWrite(en , speed);
  }
  else{
    s.write(speed);
}
}