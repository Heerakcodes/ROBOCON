int led1=7;
int led2=4;
void setup()
{
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int num=Serial.parseInt();
  if(num==1){
  digitalWrite(led1, HIGH);
  delay(1000);
  }
  if(num==2){
  digitalWrite(led1, LOW);
  delay(1000); 
  }
  if(num==3){
  
  digitalWrite(led2, HIGH);
  delay(1000); 
  
  
  digitalWrite(led2, LOW);
  delay(1000);
  }// Wait for 1000 millisecond(s)
}