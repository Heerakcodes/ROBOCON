int sw1= 12;
int sw2=8;
int led1 = 2;
int led2= 4;
int led3=7;
void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  bool s1 = digitalRead(sw1);
  bool s2 = digitalRead(sw2);
  if(s1 == 1 && s2 ==1){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  Serial.println("move forward");
  }
  
  else if(s1==0 && s2 ==1 ){
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);  
  Serial.println("move backward");  
  }
  if(s2==0){
  digitalWrite(led3, HIGH);
  digitalWrite(led2 ,LOW);  
  digitalWrite(led1 , LOW);  
  Serial.println("stop");  
    
  }
}