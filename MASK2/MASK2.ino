#define ledhijau 12
#define ledmerah 11
#define ledbiru 13
#define buzzer 10

char result;
void setup() {
  Serial.begin(9600);
  pinMode(ledhijau,OUTPUT);
  pinMode(ledmerah,OUTPUT);
  pinMode(buzzer,OUTPUT);

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
