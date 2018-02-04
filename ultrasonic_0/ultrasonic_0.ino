#include <SoftwareSerial.h>
#define trigger 8
#define echo 9
const int bluetoothTx = 0;  //pin0
const int bluetoothRx = 1; //pin1
SoftwareSerial bluetooth (bluetoothTx, bluetoothRx);
 
int state;
long duration, distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() > 0){
  state = Serial.read();
}
if(state == '1'){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 58.138);
  Serial.print(distance);
  Serial.print("cm\n");
  delay(100);
}
else{
  Serial.println("No Activity");
}
 delay(500);
}
