#include <SoftwareSerial.h>
#define trigger 3
#define echo 2
#define ledpin A5

const int bluetoothRx = 1;
const int bluetoothTx = 0;
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

int state = 0;
long distance,duration;

void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(ledpin,OUTPUT);
bluetooth.begin(9600);
Serial.begin(9600);

digitalWrite(trigger,LOW);
digitalWrite(ledpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()){
  state = Serial.read();
}
if (state == '1'){
  digitalWrite(ledpin,HIGH);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);

  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  duration = pulseIn(echo,HIGH);
  distance = (duration / 58.138);

  Serial.print(distance);
  Serial.print("cm\n");
}
else{
  digitalWrite(trigger,LOW);
  digitalWrite(ledpin,LOW);
  Serial.print("0");
}
delay(100);
}
