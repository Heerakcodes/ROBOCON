int green = 3;
int yellow = 6;
int red = 11;
int pot = A4;
void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(pot , INPUT);
  Serial.begin(9600);
}

void loop()
{
  int v = analogRead(pot);
  Serial.println(v);
  
  if(v>=0 && v <341){
    v = map( v , 0 , 340 , 0 , 255);
    analogWrite(green,v);
    digitalWrite(yellow , LOW);
    digitalWrite(red , LOW);
    Serial.println("GREEN");
  }
  else if ( v>340 && v <681){
    v = map(v , 341 , 680 , 0 ,255);
    analogWrite(yellow, v);
    digitalWrite(green, LOW);
    digitalWrite(red,LOW);
    Serial.println("YELLOW");
  }
  else{
    v = map(v, 681 , 1023 , 0 ,255);
    analogWrite(red , v);
    digitalWrite(green , LOW);
    digitalWrite(yellow , LOW);
    Serial.println("RED");
  }
}