#define led_red 10
#define led_green 3 
#define trigpin 8
#define echopin 10
#define buzzerpin 9

long duration, distance;
void pulse_buzzer(){
  tone(buzzerpin, 500);
  delay(50);
  noTone(buzzerpin);
}
void high_buzzer(){
  tone(buzzerpin, 750);
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green,LOW);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led_red, OUTPUT);
pinMode(led_green, OUTPUT);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(buzzerpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigpin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin, HIGH);
 
 delayMicroseconds(5);
 digitalWrite(trigpin, LOW);
 duration = pulseIn(echopin,HIGH);
 distance = (duration/58.138);

 if(distance < 8 && distance > 5){
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  pulse_buzzer();
 }
 else if(distance <= 5){
  high_buzzer();
 }
 else{
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,HIGH);
  noTone(buzzerpin);
 }
if(distance >= 200 || distance <= 0){
  Serial.println("Out of range\n");
}
else{
  Serial.print(distance);
  Serial.print("cm\n");
}
delay(500); 
}
