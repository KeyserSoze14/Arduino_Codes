int red_pin = 11;
int green_pin = 10;
int blue_pin = 9;

void setColour (int red, int green, int blue);
void setup() {
  // put your setup code here, to run once:

pinMode (red_pin, OUTPUT);
pinMode (green_pin, OUTPUT);
pinMode (blue_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
setColour (100, 255, 255);    //red
delay (300);

setColour (255, 100, 255);    //green
delay (300);

setColour(255, 255, 100);     //blue
delay (300);

setColour (80, 50, 255);  //yellow
delay (300);

setColour (100, 255, 100);  //purple
delay (300);

setColour (255, 80, 80);  //aqua
delay (300);

}

//Common Anode Configuration
void setColour (int red, int green, int blue){
  analogWrite (red_pin, red);
  analogWrite (green_pin, green);
  analogWrite (blue_pin, blue);
}


