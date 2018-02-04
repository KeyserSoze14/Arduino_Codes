int buttonPin = 2;
int led1_pin = 7;
int led2_pin = 8;
unsigned long pressButton_previous = 0;
int option1_ms = 2500;
int option2_ms = 5000;

void setup() {
  // put your setup code here, to run once:
pinMode (led1_pin, OUTPUT);
pinMode (led2_pin, OUTPUT);
pinMode (buttonPin, INPUT_PULLUP);

Serial.begin (9600);
Serial.print ("Press the button");
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead (buttonPin) == LOW){
  delay (500);
  unsigned long pressButton_current = millis();;
  Serial.print ("ms = ");
  Serial.println (pressButton_current);
  if ((pressButton_current - pressButton_previous) >= option2_ms){
    pressButton_previous = pressButton_current;
    digitalWrite (led2_pin, HIGH);
    Serial.print ("Please wait a second\n");
    delay (1000);
    digitalWrite (led2_pin, LOW);
    
  }
  else if (((pressButton_current - pressButton_previous) >= option1_ms) && (pressButton_current - pressButton_previous) < option2_ms){
  pressButton_previous = pressButton_current;
  digitalWrite (led1_pin, HIGH);
  Serial.print("Hold on a second \n");
  delay (1000);
  digitalWrite (led1_pin, LOW);
}
else{
  digitalWrite (led1_pin, HIGH);
  delay(200);
  digitalWrite (led1_pin, LOW);
  digitalWrite (led2_pin, HIGH);
  delay (200);
  digitalWrite (led2_pin, LOW);
  digitalWrite (led1_pin, HIGH);
  delay(200);
  digitalWrite (led1_pin, LOW);
  digitalWrite (led2_pin, HIGH);
  delay(200);
  digitalWrite (led2_pin, LOW);
  Serial.print ("ERROR!! : Repress\n\n");
}

}
}
