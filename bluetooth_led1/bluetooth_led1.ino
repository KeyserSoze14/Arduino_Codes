#include <SoftwareSerial.h>
#define ledpin 3
const int bluetoothRx = 1;
const int bluetoothTx = 0;
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

int state = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
Serial.begin(9600);
bluetooth.begin(9600);
digitalWrite(ledpin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0){
  state = Serial.read();
}
if (state == '1'){
  digitalWrite(ledpin,HIGH);
  Serial.println("LED Activated");
}
else{
  digitalWrite(ledpin,LOW);
  Serial.println("LED OFF");
}
delay(50);
}
