#include <Servo.h>
Servo myservo;
int pos = 0;
const int echo = 2;
const int trig = 3;

long duration;
int distance;
int savetyDistance;
 
void setup() {
  pinMode (echo,INPUT);
  pinMode (trig,OUTPUT);
  myservo.attach(8);
  Serial.begin(9600);
}

void loop() {
  //buat penyasuaian sensor;
  digitalWrite (trig,LOW);
  delayMicroseconds (2);
  //buat atur nyala matinya sensor;
  digitalWrite (trig,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig,LOW);
  //NGATUR SI ECHO
  duration = pulseIn (echo,HIGH);
  //PEMBACAAN SENSOR;
  distance = duration *0.34/2;

  savetyDistance = distance;
  if (savetyDistance <=100){
  for (pos =0; pos < 160; pos += 1){
    myservo.write(pos);
    delay (15);
  }
  }else{
  for (pos = 160; pos >= 1; pos -= 1){
    myservo.write(pos);
    delay (15);
  }
  }
   Serial.print("Distance: ");
    Serial.println(distance);
}
