int green = 9;
int yellow = 10;
int red = 11;
int pot = A2;
int trig = 6;
int echo = 5;
int distance ;
long duration;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pot , INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  int v =analogRead(pot);
  int warningdistance=map(v,0,1023,10,50);
  digitalWrite(trig ,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig , LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  Serial.print("warning distance: ");
  Serial.print(warningdistance);
  Serial.print("cm");
  Serial.println();
  
  
  if(distance>warningdistance){
    digitalWrite(green , HIGH);
    digitalWrite(yellow , LOW);
    digitalWrite(red, LOW);
    Serial.println("SAFE");
    
  }
  else if( distance > warningdistance/2){
    digitalWrite(green , LOW);
    digitalWrite(yellow , HIGH);
    digitalWrite(red, LOW);
    Serial.println("GETTING CLOSE");
  }
  else{
    digitalWrite(green , LOW);
    digitalWrite(yellow , LOW);
    digitalWrite(red, HIGH);
    Serial.println("TOO CLOSE");
  }
  delay(500);

    
    
  
  
}