#include <NewPing.h>
NewPing Sonar(12,13,200); //echo,trigger,maximum value.
int led;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int distance = Sonar.ping()/US_ROUNDTRIP_CM;
  Serial.println(distance);
  if(distance < 10){
    digitalWrite(led,HIGH);
  }
  delay (100);
  
}
