const int buzzer_pin = 6;
const int num_tones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};    //frequency of the tones (obtained online)

void setup() { //put code here iff to make the buzzer run through once
  // put your setup code here, to run once:
for (int i = 0; i < 10; i++) {
  tone (buzzer_pin, tones[i]);    //function to operate buzzer..takes two parameters : which pin buzzer connected to & frequency to output 
  delay (200);
}
noTone (buzzer_pin);      //Stops any tune from playing here...terminating
}

void loop() {
  // put your main code here, to run repeatedly:

}
