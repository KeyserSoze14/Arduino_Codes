// include the library code:

#include<LiquidCrystal.h>

int state=1;//initialize push button state

int pb=8;//initialize push button state

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

pinMode(pb,INPUT);//set pb as input

// set up the LCD's number of columns and rows:

lcd.begin(16, 1);

lcd.setCursor(0,1);

lcd.clear();//clear LCD

}

void loop() {

//LCD library command for no blink

lcd.noBlink();

state=digitalRead(pb);

if(state==0){

//to get a steady input, the LCD has to clear and write the message after the delay //without the .clear() command, the message will run from right to left or verse varsa

//in the LCD, using the clear and a short delay message, the LCD clears and prints the meaage a

//again after the delay time.

lcd.clear();

lcd.print("off");//print message on the LCD

delay(10); //delay message

lcd.clear();//clear LCD

delay(10);//delay message again

}

else

{

lcd.clear();

lcd.print("on");

delay(10);

lcd.clear();

delay(10);

state=1;

}

}
