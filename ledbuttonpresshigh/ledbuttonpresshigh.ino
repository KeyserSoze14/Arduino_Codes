const int buttonPin=2;
const int ledPin = 13;
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}
void loop() {
  int buttonState=digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonState==HIGH)
  {digitalWrite(ledPin, HIGH);}
  else
  {digitalWrite(ledPin, LOW);}
}
  // put your main code here, to run repeatedly:

