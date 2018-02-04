const int ldr = 0;    //A0 assigned as LDR pin.
int value = 0;        //Store values from LDR.

void setup()
{
  Serial.begin(9600);   //Fix serial baud rate at 9600bps
}

void loop()
{
  value = analogRead(ldr);    //Read the analog values from LDR.
  Serial.println(value);      //Print to serial monitor.
  delay(250);                 //Delay of 250 milliseconds (1/4th of a second).
}
