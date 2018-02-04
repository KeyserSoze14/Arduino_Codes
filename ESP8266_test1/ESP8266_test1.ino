#include <SoftwareSerial.h>
SoftwareSerial ESPserial(2,3);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ESPserial.begin(115200);
Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
if (ESPserial.available()){
  Serial.write(ESPserial.read());
}

if (Serial.available()){
  ESPserial.write(Serial.read());
}
}
