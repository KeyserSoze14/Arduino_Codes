int a=1;
int b=2;
int c=5;
int d=6;
int e=7;
int f=3;
int g=4;
void digitalnumber (int y){
if ( y != 1 && y != 4)
digitalWrite ( a, HIGH);
if (y != 5 && y != 6)
digitalWrite ( b, HIGH);
if (y != 2)
digitalWrite ( c, HIGH);  
if ( y != 1 && y != 7 && y != 4)
  digitalWrite (d, HIGH);
if ( y !=1 && y != 3 && y != 4 && y != 5 && y != 7)
  digitalWrite (e, HIGH);
if ( y != 1 && y != 3 && y != 7  && y != 2)
  digitalWrite (f, HIGH);
if ( y != 0 && y != 1 && y != 7)
  digitalWrite (g, HIGH);
  return;
}
void digitalreset (void){
 digitalWrite ( a, LOW);
 digitalWrite ( b, LOW);
digitalWrite ( c, LOW);
digitalWrite ( d, LOW);
digitalWrite ( e, LOW);
digitalWrite ( f, LOW);
digitalWrite ( g, LOW);
}
void setup(){
pinMode ( a, OUTPUT);
pinMode (b, OUTPUT);
pinMode (c, OUTPUT);
pinMode (d, OUTPUT);
pinMode (e, OUTPUT);
pinMode (f, OUTPUT);
pinMode (g, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  int x;
  for (x=0;x<10; x++){
    digitalnumber(x);
    delay (500);
    digitalreset();
  }
}
  
