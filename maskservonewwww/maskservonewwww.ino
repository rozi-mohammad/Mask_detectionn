#define ledhijau 12
#define ledmerah 11
#define ledbiru 13
#define buzzer 10
#include <Servo.h>
Servo myservo;
int pos = 0;

char result;
void setup() {
  Serial.begin(9600);
  pinMode(ledhijau,OUTPUT);
  pinMode(ledmerah,OUTPUT);
  pinMode(buzzer,OUTPUT);
  myservo.attach(8);
}

void loop() {
  while (Serial.available() >0) {
    result = Serial.read();
    switch (result){
      case'2':
        digitalWrite (ledhijau,LOW);
        digitalWrite (ledbiru,LOW);
        digitalWrite (ledmerah,HIGH);
        digitalWrite (buzzer,HIGH);
        for (pos =0; pos < 160; pos += 1){
        myservo.write(pos);
        delay (15);
        }
        for (pos = 160; pos >= 1; pos -= 1){
        myservo.write(pos);
        delay (15);
      }
      break;
      
      case'1':
        digitalWrite (ledhijau,HIGH);
        digitalWrite (ledbiru,LOW);
        digitalWrite (ledmerah,LOW);
        digitalWrite (buzzer,LOW);
        break;
    }
  }
    
}
