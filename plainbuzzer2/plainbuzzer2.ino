int buzzer_pin = 10;

void setup() {
  // put your setup code here, to run once:
pinMode (buzzer_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tone (buzzer_pin, 10000);

}
