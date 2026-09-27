const int trig = 6;
const int echo = 5;
const int green = 8;
const int red = 12;
int distance;
long duration;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(green , OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration=pulseIn(echo,HIGH);
  distance = duration*0.034/2;
  if( distance > 10 ){
       digitalWrite(green , HIGH);
       digitalWrite(red , LOW);
  }
  else{
    digitalWrite(green , LOW);
       digitalWrite(red , HIGH);
    
  }
      
  Serial.print("distance: ");  
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}                 
  
                   