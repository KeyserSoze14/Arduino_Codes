#include <LiquidCrystal.h>
const int rs=12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int button_pin = 8;
int button_state;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
/*
void LCD_Display(){
  lcd.clear();
  lcd.print("Hello World!");
}
*/
void setup() {
  // put your setup code here, to run once:
pinMode(button_pin, INPUT);
lcd.begin(16,1);
lcd.setCursor(0,1);
lcd.clear();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.noBlink();
button_state = digitalRead(button_pin);
if(button_state != 0){
  Serial.println("Button Pressed");
  Serial.println(button_state);
  //LCD_Display();
  lcd.clear();
  lcd.display();
  lcd.print("Hello World!");
  delay(10);
  lcd.clear();
  delay(10);
  button_state = !button_state;
}
else{
  Serial.println("Unpressed");
  lcd.noDisplay();
}
delay(5);
}
