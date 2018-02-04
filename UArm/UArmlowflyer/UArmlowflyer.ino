#include <uarm_library.h>

void setup() {
  // put your setup code here, to run once:
Wire.begin();      // join i2c bus (address optional for master)
Serial.begin(9600); // start serial port at 9600 bps
attach_all_servos();
uarm.init();
delay(1500);
pinMode(VALVE_EN, OUTPUT);
//uarm.pump_on();
}

void loop() {
  // put your main code here, to run repeatedly:  
digitalWrite(VALVE_EN, LOW); //valve is active low. So, low means it works.
delay(1000);

uarm.pump_on();       //for (x,y,z); +x=toward right of box.
                                    //+y=toward front
                                    //+z=up
uarm.move_to(-16.37,-4.49,8.04);//initially (13,-13,3)
delay(500);

uarm.move_to(2.26,-19.06,22.11);//Initially [5,0,0,RELATIVE,2]
delay(500);

uarm.move_to(18.98,-2.23,22.12);//initially (13,-13,3)
delay(500);

uarm.move_to(13.79,-1.62,13.66);//Initially [-4,3,-2,RELATIVE,5]
delay(500);

uarm.pump_off();

uarm.move_to(0.56 , -10.77 , 19.70);//initially (13,-13,3)
delay(500);
}

void attach_all_servos()
{
        uarm.set_servo_status(true, SERVO_ROT_NUM);
        uarm.set_servo_status(true, SERVO_LEFT_NUM);
        uarm.set_servo_status(true, SERVO_RIGHT_NUM);
        uarm.set_servo_status(true, SERVO_HAND_ROT_NUM);
}
