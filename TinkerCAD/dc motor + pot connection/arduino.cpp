// C++ code
//
int en1 = 3;
int in1 = 2;
int in2 = 4;
int pot = A0;
void setup()
{
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pot,INPUT);
}

void loop()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  int v = analogRead(pot);
  analogWrite(en1,map(v,0,1023,0,255));
  
}