int seg_a = 4;
int seg_b = 5;
int seg_c = 8;
int seg_d = 7;
int seg_e = 6;
int seg_f = 3;
int seg_g = 2;
int DP = 9;


void setup() {
  // put your setup code here, to run once:
pinMode (seg_a, OUTPUT);
pinMode (seg_b, OUTPUT);
pinMode (seg_c, OUTPUT);
pinMode (seg_d, OUTPUT);
pinMode (seg_e, OUTPUT);
pinMode (seg_f, OUTPUT);
pinMode (seg_g, OUTPUT);
pinMode (DP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (7, HIGH);
/*
digitalWrite (seg_g, LOW);
digitalWrite (DP, LOW);
digitalWrite (seg_a, HIGH);
digitalWrite (seg_b, HIGH);
digitalWrite (seg_c, HIGH);
digitalWrite (seg_d, HIGH);
digitalWrite (seg_e, HIGH);
digitalWrite (seg_f, HIGH);
*/
}
