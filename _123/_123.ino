int button = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT );
  Serial.begin(9600);
}
int previous=HIGH;
unsigned long int press_time, release_time;
void loop() {
  // put your main code here, to run repeatedly:
  int current;
  current=digitalRead(button);
  if(current==LOW && previous==HIGH){
    press_time=millis();
    Serial.print(press_time);
    Serial.print(" ");
  else if(current==HIGH && previous==LOW){
    release_time=millis();
    Serial.print("The time difference is ");
    Serial.println(release_time - press_time);
  }
  
  previous=current;
  }

