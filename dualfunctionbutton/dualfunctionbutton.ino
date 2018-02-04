int button_pin = 9;
int led1_pin = 7;
int led2_pin = 8;

boolean led1_State = false;
boolean led2_State = false;

boolean buttonActive = false;
boolean longPress_Active = false;

int buttonTimer = 0;
int longTimer = 250;

void setup() {
  // put your setup code here, to run once:
pinMode (button_pin, INPUT);
pinMode (led1_pin, OUTPUT);
pinMode (led2_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead (button_pin == HIGH)){
  if (buttonActive == false ){
    buttonActive = true;
    buttonTimer = millis();
  }
  
  if ((millis () - buttonTimer > longTimer ) && ( longPress_Active == false)){
    led1_State = !led1_State;
    digitalWrite (led1_pin, led1_State);
    longPress_Active = true;
  }
}
  else {
    if (buttonActive == true){
      if (longPress_Active == true){
        longPress_Active = false;
      }
      else {
        led2_State = !led2_State;
        digitalWrite (led2_pin, led2_State);
      }
      buttonActive = false;
      }
  }

}
