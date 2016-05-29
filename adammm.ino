#include <LCD5110_Graph.h>

LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t adam[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
int xa;
int y;
int xb;
int s;
int d;
int X = 0;
int Y = 0;
int A = 25;
int a;
int ss;
int ft;
void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  myGLCD.InitLCD();
  myGLCD.setContrast(70);
  Serial.begin(9600);
  myGLCD.setFont(SmallFont);

}

void loop() {
  xa = digitalRead(2);
  y = digitalRead(3);  
  xb = digitalRead(4);
  s = digitalRead(5);
  ss = digitalRead(6);
  d = 20;
  a = A-7;
   if(s == 1)
   {
    d = 5;
   }
   else
   {
    d = 20;
   }
   if( xb == 1)
  {
    X--;
    delay(d);
    X--;
    delay(d);
    X--;
    delay(d);
    X--;
    delay(d);
    X--;
    delay(d);
    X--;
    delay(d);
    X--;
  }
  if( xa == 1)
  {
    X++;
    delay(d);
    X++;
    delay(d);
    X++;
    delay(d);
    X++;
    delay(d);
    X++;
    delay(d);
    X++;
    delay(d);
    X++;
  }
  if( y == 1 && ft == 0)
  {
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    ft = 1;
    delay(250);
  }
  if( X >= 83)
  {
    A  = 24;
    X = 0;
  }
  if( Y == a)
  {
    ft = 0;
  }
  if( Y < a )
  {
    Y++;
  }
  Serial.print("X = ");
  Serial.println(X);
  Serial.print("Y = ");
  Serial.println(Y);
  Serial.print("Spint = ");
  Serial.println(s);
  Serial.print("y button = ");
  Serial.println(y);
  Serial.print("x+ button = ");
  Serial.println(xa);
  Serial.print("x- button = ");
  Serial.println(xb);
  Serial.println(a);
  Serial.println(A);
  Serial.println("-------------------------");
  myGLCD.print("(_)" , X , Y );
  myGLCD.print("______________",2,A);
  delay(250);
  myGLCD.update();
  myGLCD.clrScr();

}
