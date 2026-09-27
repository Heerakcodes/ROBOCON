int led =2;
int pmeter = 6;

void setup(){
  pinMode(led , OUTPUT);
  pinMode(pmeter,INPUT);
}
void loop(){
  int p = digitalRead(pmeter);
  digitalWrite(led , p);
}