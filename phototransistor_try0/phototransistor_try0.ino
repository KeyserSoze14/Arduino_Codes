int phototran_pin = A0;
long int photo_reading;
void setup() {
  // put your setup code here, to run once:
  pinMode (phototran_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  photo_reading = analogRead(phototran_pin);
  Serial.println(photo_reading);
}
