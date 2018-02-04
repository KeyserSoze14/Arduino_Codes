int button = 8;
int led = 12;
int reading;
int previous = LOW;
int output_state = HIGH;

void setup() {
  // put your setup code here, to run once:
pinMode(button, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
reading = digitalRead(button);
if(reading == HIGH && previous == LOW){
  if(output_state == HIGH){
    output_state = LOW;
  }
  else{
    output_state = HIGH;
  }
}
  digitalWrite(led, output_state);
  previous = reading;
}
