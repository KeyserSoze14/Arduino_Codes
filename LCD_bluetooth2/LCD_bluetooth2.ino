#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int LCD_led = 9;
const int bluetoothRx = 1;
const int bluetoothTx = 0;
const int button_pin = 10;
const int buzzer = 11;

SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int btn_state = 0;
int phone_btn; 

void setup() {
  // put your setup code here, to run once:
pinMode(LCD_led, OUTPUT);
pinMode(button_pin, INPUT);
pinMode(buzzer, OUTPUT);
bluetooth.begin(9600);
Serial.begin(9600);
digitalWrite(LCD_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0){
  phone_btn = Serial.read();
}

if (phone_btn == '2' && digitalRead(button_pin) == HIGH){
  lcd.begin(16,1);
  lcd.clear();
  lcd.noBlink();
  lcd.display();
  digitalWrite(LCD_led,HIGH);
  tone(buzzer,1750);
  delay(1000);
  noTone(buzzer);
  lcd.print("Just a moment");
  delay(2750);
  digitalWrite(LCD_led,LOW);
  lcd.clear();
  lcd.noDisplay();
}

else if (phone_btn == '3' && digitalRead(button_pin) == HIGH){
  noTone(buzzer);
  lcd.begin(16,1);
  lcd.clear();
  lcd.noBlink();
  lcd.display();
  digitalWrite(LCD_led,HIGH);
  lcd.print("Not in room");
  delay(2750);
  digitalWrite(LCD_led,LOW);
  lcd.clear();
  lcd.noDisplay();
}

else{
  lcd.clear();
  lcd.noDisplay();
  digitalWrite(LCD_led,LOW);
}
 /*
  lcd.begin(16,1);
  lcd.clear();
  lcd.noBlink();
  lcd.display();
  digitalWrite(LCD_led,HIGH);
  lcd.print("Just a moment");
  delay(2750);
  digitalWrite(LCD_led,LOW);
  lcd.clear();
  lcd.noDisplay();
  break;

  case '3':
  lcd.begin(16,1);
  lcd.clear();
  lcd.noBlink();
  lcd.display();
  digitalWrite(LCD_led,HIGH);
  lcd.print("Not in room");
  delay(2750);
  digitalWrite(LCD_led,LOW);
  lcd.clear();
  lcd.noDisplay();
  break;
*/
delay(500);
}
