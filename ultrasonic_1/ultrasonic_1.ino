#define trigger 8
#define echo 9
long distance, duration;

void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);

delayMicroseconds(10);
digitalWrite(trigger,LOW);
duration = pulseIn(echo,HIGH);
distance = (duration/58.138);

Serial.print(distance);
Serial.print("cm\n");
delay(500);
}
