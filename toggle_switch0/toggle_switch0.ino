const int led = 9;
const int button_pin = 8;
long debounce = 200;
long time_now = 0;
int reading;
int previous = LOW;
int output_state = HIGH;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(button_pin, INPUT);
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
reading = digitalRead(button_pin);
//Serial.println(reading);
if(reading == 1 && previous == 0){
  if(output_state == HIGH){
    digitalWrite(led,LOW);
    output_state = LOW;
  }
  else{
    digitalWrite(led,HIGH);
    output_state = HIGH;
  }
}
previous = reading;
}

