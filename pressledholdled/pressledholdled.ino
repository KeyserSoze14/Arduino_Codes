int button = 12;
int led=7;
void setup() {
  pinMode(button,INPUT );
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
int previous=HIGH;
/* 'long' here ensures at least a 32bit system is used*/ 
unsigned long int press_time, release_time;   //unsigned here means the same as in digital logic...all 3 bits of data is used. Not one bit is used for storing the 'sign magnitude' of the binary digit.
bool updated=false;
bool ledstate=false;
int current;
void loop() {
  // put your main code here, to run repeatedly:
  current=digitalRead(button);
  if(current==LOW && previous==HIGH){
    press_time=millis();
    updated=false;
    
  }
  else if(current== LOW && previous==LOW){
    if(millis()-press_time >= 2000){
      if(updated==false){
        ledstate=!ledstate;
        updated=true;
        digitalWrite(led,ledstate);
      }
    }
  }
  
  previous=current;
  }

