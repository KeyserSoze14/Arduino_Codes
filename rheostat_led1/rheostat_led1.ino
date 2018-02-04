const int led_pin = 10;
const int rheostat = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (led_pin, OUTPUT);
pinMode (rheostat, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int rheostat_value = analogRead (rheostat);
rheostat_value = map (rheostat_value, 0, 1023, 0, 255);
analogWrite (led_pin, rheostat_value);
}
