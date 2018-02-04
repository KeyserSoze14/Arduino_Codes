#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int LCD_led = 9;
const int bluetoothRx = 1;
const int bluetoothTx = 0;
const int button_pin = 10;

SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int btn_state = 0;
int phone_btn; 

void setup() {
  // put your setup code here, to run once:
pinMode(LCD_led, OUTPUT);
pinMode(button_pin, INPUT);
bluetooth.begin(9600);
Serial.begin(9600);
digitalWrite(LCD_led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0){
  phone_btn = Serial.read();
}
if (phone_btn == '1'){
  lcd.begin(16,1);
  lcd.clear();
  lcd.noBlink();
  btn_state = digitalRead(button_pin);
  if (btn_state == HIGH){
    lcd.display();
    digitalWrite(LCD_led,HIGH);
    lcd.print("Just a moment");
    delay(2000);
    digitalWrite(LCD_led,LOW);
    lcd.clear();
    lcd.noDisplay();
  }
  else{
    lcd.noDisplay();
    digitalWrite(LCD_led,LOW);
  }
}
else{
  lcd.clear();
  lcd.noDisplay();
}
delay(500);
}
