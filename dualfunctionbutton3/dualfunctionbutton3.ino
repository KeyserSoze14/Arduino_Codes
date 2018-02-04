int buttonPin = 2;
int led1_pin = 7;
int led2_pin = 8;

float pressButton_length = 0;
int option1_ms = 100;
int option2_ms = 1000;

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
while (digitalRead (buttonPin) == LOW){
  delay (500);
  pressButton_length += 100;
  Serial.print ("ms = ");
  Serial.println (pressButton_length);
}

if (pressButton_length >= option2_ms){
  digitalWrite (led2_pin, HIGH);
  Serial.print ("Please wait a second");
  delay (1500);
  digitalWrite (led2_pin, LOW);
}
else if (pressButton_length >= option1_ms){
  digitalWrite (led1_pin, HIGH);
  Serial.print("Hold on a second");
  delay (1500);
  digitalWrite (led1_pin, LOW);
}
else{
  Serial.print ("Press The Button!\n");
}

pressButton_length = 0;
}
