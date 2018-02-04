int buzzer_pin = 10;
int rheostat_pin = A0;
int rheostat_reading = 0;
int led_pin = 9;
int led_reading = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (buzzer_pin, OUTPUT);
pinMode (rheostat_pin, INPUT);
pinMode (led_pin, OUTPUT);
Serial.begin (4800);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(200);
rheostat_reading = analogRead (rheostat_pin);
led_reading = analogRead (rheostat_pin);
rheostat_reading = map (rheostat_reading, 0, 1023, 500, 5000);
led_reading = map (rheostat_reading, 0, 1023, 0, 255);
led_reading = constrain (led_reading, 0, 255);
Serial.print ("Rheostat & LED reading = ");
Serial.print (rheostat_reading);
Serial.print ("\t");
Serial.print (led_reading);
Serial.print("\n");
tone (buzzer_pin, rheostat_reading);
analogWrite (led_pin, led_reading);
}
