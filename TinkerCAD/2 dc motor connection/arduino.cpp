int en1 = 5;
int en2 = 3;
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;

void setup()
{
  pinMode(en1, OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1, 100);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(en2,100);
  
}