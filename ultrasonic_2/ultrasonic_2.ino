#include <SoftwareSerial.h>
#define ledpin 3
#define echo 11
#define trigger 8

const int bluetoothRx = 1;
const int bluetoothTx = 0;
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);
int state = 0;

long distance,duration;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
pinMode(trigger,OUTPUT);
pinMode(echo, INPUT);
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
  //Serial.println("LED Activated");
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  duration = pulseIn(echo,HIGH);
  distance = (duration / 58.138);

  Serial.print(distance);
  Serial.print("cm\n");
}
else{
  digitalWrite(ledpin,LOW);
  Serial.println("LED & Sensor OFF");
  digitalWrite(trigger,LOW);
}
delay(500);
}
