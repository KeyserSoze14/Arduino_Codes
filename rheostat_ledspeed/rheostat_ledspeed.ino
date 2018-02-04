int rheostat_pin = A0;
int led_pin = 7;
int value = 0;
int value_one = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (led_pin, OUTPUT);
pinMode (rheostat_pin, INPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println ("\nValue now is : \n");
value = analogRead (rheostat_pin);    //Here the int value stores the analog_reading of the rheostat.
Serial.print (value);     //prints out the anologue value of the rheostat.
value_one = map (value, 0,1023, 200,2000);    //adjusts the delay so that min value = 200 & max value = 2000
digitalWrite (led_pin, HIGH);
delay (value_one);
digitalWrite (led_pin, LOW);
delay (value_one);
}
