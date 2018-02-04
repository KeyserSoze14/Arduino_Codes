#include <uarm_library.h>

void setup() {
  // put your setup code here, to run once:
   Wire.begin();  // join i2c bus (address optional for master)
   attach_all_servos();
   pinMode(VALVE_EN, OUTPUT);
   uarm.pump_on();
   
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(VALVE_EN, LOW); //valve is active low. So, low means it works.
delay(1000);
digitalWrite(VALVE_EN, HIGH);
delay(1000);
uarm.move_to(0.56 , -10.77 , 19.70);//initially (13,-13,3)
delay(5000);
uarm.move_to(-13,-13,3);
delay(5000);
}

void detach_all_servos()
{
        uarm.set_servo_status(false, SERVO_ROT_NUM);
        uarm.set_servo_status(false, SERVO_LEFT_NUM);
        uarm.set_servo_status(false, SERVO_RIGHT_NUM);
        uarm.set_servo_status(false, SERVO_HAND_ROT_NUM);
}

void attach_all_servos()
{
        uarm.set_servo_status(true, SERVO_ROT_NUM);
        uarm.set_servo_status(true, SERVO_LEFT_NUM);
        uarm.set_servo_status(true, SERVO_RIGHT_NUM);
        uarm.set_servo_status(true, SERVO_HAND_ROT_NUM);
}
