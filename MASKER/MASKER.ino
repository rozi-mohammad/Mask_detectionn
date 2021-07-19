#define buzzer 10

char result;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  while (Serial.available() >0) {
    result = Serial.read();
    switch (result){
      case'1':
      digitalWrite(buzzer,LOW);
      break;
      case'2':
      digitalWrite(buzzer,HIGH);
      break;
    }
  }
  delay(100);
  
  

}
