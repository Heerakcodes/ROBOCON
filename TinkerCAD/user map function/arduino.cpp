int led = 11;
int pot = A4;

float mymap(float value , float inmin , float inmax , float outmin, float outmax)
{
  return (value-inmin)*(outmax-outmin) /(inmax-inmin) + outmin ;
}
        
  

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  
}

void loop()
{
  int v = analogRead(pot);
  
  float brightness =mymap(v , 0,1023,0,255);
  analogWrite(led , brightness);
}