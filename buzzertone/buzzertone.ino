const int buzzer=9; /*this step makes it easy to reassign a value to the variable buzzer so that when different pins are used, the value of this variable can be changed to the value of the new pin*/

void setup() {
  pinMode(buzzer, OUTPUT); 
  /*Above, setting the pin 9 as the output*/
}

void loop() {
  /*Below, using the tone() function. This allows the buzzer to operate*/
  tone(buzzer,500);
  delay(500);
  /*Below, using noTone() function.*/
  noTone(buzzer);
  delay(500);

}
