#include <SoftwareSerial.h>

int bluetoothTx = 0; // bluetooth tx to 0 pin
int bluetoothRx = 1; // bluetooth rx to 1 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

#define ledpin 13
int state = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
digitalWrite(ledpin,LOW);
bluetooth.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() > 0){
  state = Serial.read();
}
switch (state){
  case '1':
  digitalWrite(ledpin,HIGH);
  Serial.println("LED: ON");
  break;

  case '0':
  digitalWrite(ledpin,LOW);
  Serial.println("LED: OFF");
  break;
}
}
  

