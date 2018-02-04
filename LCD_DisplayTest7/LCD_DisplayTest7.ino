#include <LiquidCrystal.h>
#define button_pin 10
int btn_state = 0;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //the LCD pins
const int LCD_led = 9;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
pinMode(button_pin,INPUT);
pinMode(LCD_led, OUTPUT);
lcd.begin(16,1);
digitalWrite(LCD_led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.noBlink(); 
btn_state = digitalRead(button_pin);

  if (btn_state == HIGH){
  lcd.display();
  digitalWrite(LCD_led,HIGH);
  lcd.print("Just a moment");
  delay(2000);
  lcd.clear();
  digitalWrite(LCD_led,LOW);
}
else{
  lcd.noDisplay();
  digitalWrite(LCD_led,LOW);
}
delay(500);
}


