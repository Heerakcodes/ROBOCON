int led = 9;
int trig = 6;
int echo = 3;
int duration;
float distance;
int inmin = 20;
int inmax = 200;
int outmin = 0;
int outmax = 255;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo,HIGH);
  
  distance = (0.034/2)*duration;
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("");
  
  
  
  if( distance < 20 || distance >200 ){
    digitalWrite(led , LOW);
  }
  else{
    
    
    float a = distance/(inmin+inmax)* 100 ;
    
    float v = ((outmax + outmin)*a)/100 ; 
    Serial.print("mapped value at(0-255): ");
    Serial.print(v);
    analogWrite(led,v);
    
      
    
    
    
    
  }
  
}