int ldr_pin = A0;
int transbase_pin = 3;
int array_reading[100];
long int sum_reading=0;
int average_bright_reading(int);
void setup() {
  // put your setup code here, to run once:
pinMode(ldr_pin, INPUT);
pinMode(transbase_pin, OUTPUT);
Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i<50; i++){
  array_reading[i] = analogRead(ldr_pin);
  sum_reading+=array_reading[i];
  }
  average_bright_reading(sum_reading);
}

int average_bright_reading(int sum){
  int average;
  average = sum/50;
  return average;
}

