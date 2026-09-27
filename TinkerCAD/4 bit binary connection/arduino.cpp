int led1 = 4;
int led2 = 7;
int led3 = 8;
int led4 = 12;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("enter decimal no. 0-15");
  
}

void loop()
{
  if (Serial.available() > 0){
   int num = Serial.parseInt();
    
    if(num >=0 && num <= 15){
      
      int bit1 = num/8;
      num = num % 8;
      
      int bit2 = num/4;
      num= num %4;
      
      int bit3 = num/2;
      num = num %2;
      
      int bit4 = num;
      
      digitalWrite(led1, bit1);
      digitalWrite(led2, bit2);
      digitalWrite(led3, bit3);
      digitalWrite(led4 , bit4);
      
      Serial.print("binary: ");
      Serial.print(bit1);
      Serial.print(bit2);
      Serial.print(bit3);
      Serial.print(bit4);
      Serial.println();
      
      
    }
    else{
      Serial.println("invalid , enter no. b/w 0-15");
      
    }
    Serial.println("enter another number:");
  }
}