#include <LCD5110_Graph.h>

LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t adam[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
int x;
int y;
int X = 0;
int Y = 23;
void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  myGLCD.InitLCD();
  myGLCD.setContrast(70);
  Serial.begin(9600);
  myGLCD.setFont(SmallFont);

}

void loop() {
  x = digitalRead(2);
  y = digitalRead(3);  
  if( x == 1)
  {
    X++;
    X++;
    X++;
    X++;
    X++;
    X++;
    X++;
    delay(250);
  }
  if( y == 1)
  {
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    Y--;
    delay(250);
  }
  if( X >= 83)
  {
    X = 0;
  }
  if( Y < 23 )
  {
    Y++;
    Y++;
  }
  Serial.print("X = ");
  Serial.println(X);
  Serial.print("Y = ");
  Serial.println(Y);
  Serial.println("-------------------------");
  myGLCD.print("(_)" , X , Y );
  myGLCD.print("______________",2,30);
  delay(250);
  myGLCD.update();
  myGLCD.clrScr();

}
