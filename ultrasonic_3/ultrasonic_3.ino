#define ledpin A5
#define trigger 3
#define echo 2
#define buzzer A3
long distance, duration;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
digitalWrite(trigger,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger,LOW);
delayMicroseconds(2);

digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);

duration = pulseIn(echo,HIGH, 4400);
distance = (duration/58.138);

if (distance > 0){
  digitalWrite(ledpin, HIGH);
  Serial.print(distance);
  Serial.print("cm\n");
  tone(buzzer,750,15);
}
else{
  noTone(buzzer);
  digitalWrite(ledpin,LOW);
  Serial.print("Undefined\n");
}
delay(100);
}
