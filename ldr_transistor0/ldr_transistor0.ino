int ldr_pin = A0;
int transbase_pin = 2;
long int ldr_reading, mapped_reading;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr_pin, INPUT);
pinMode(transbase_pin, OUTPUT); 
Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
ldr_reading = analogRead(ldr_pin);
Serial.print("LDR Reading is : \n");
Serial.println(ldr_reading);
mapped_reading = map(ldr_reading, 0, 1023, 0, 255);
Serial.println(mapped_reading);
if (mapped_reading > 50){
  digitalWrite(transbase_pin, LOW);
  delay(100);
}
else{
  digitalWrite(transbase_pin, HIGH);
  delay(100);
}

}
