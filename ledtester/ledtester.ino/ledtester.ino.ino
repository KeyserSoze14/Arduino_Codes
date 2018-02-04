 int buttonpin = 2;
int ledpin = 13;
int buttonstate = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonpin, INPUT);
pinMode(ledpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledpin,LOW);
/*buttonstate = digitalRead(buttonpin);
if (buttonstate == HIGH){
  digitalWrite(ledpin, HIGH);
}
else if (buttonstate == LOW){
  digitalWrite(ledpin, HIGH);
}
*/
}
