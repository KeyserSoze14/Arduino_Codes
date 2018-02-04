const int buzzer_pin = 6;
const int LDR_pin = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
double LDR_reading = analogRead (LDR_pin);
int tone_frequency = 200 + round ((LDR_reading) / 3);   //Here, +200 because
tone (buzzer_pin, tone_frequency);
}
