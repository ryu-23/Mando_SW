#include <MsTimer2.h>
#define encodPinA1      2 
#define encodPinB1      3                       // Quadrature encoder B pin
volatile long encoderPos = 0;
 
void setup(){

    MsTimer2::set(100, interrupt_setup);
    MsTimer2::start();
    Serial.begin(115200);
    delay(100);
}

void interrupt_setup(void)
{
  pinMode(encodPinA1, INPUT_PULLUP); 
  pinMode(encodPinB1, INPUT_PULLUP);  
  attachInterrupt(0, encoderB, RISING);  
}

void encoderB()  
{
  
  delayMicroseconds(3);
  if(digitalRead(encodPinB1)==LOW)    encoderPos++;           
  else                                 encoderPos--; 
}

void loop(){
  interrupt_setup();

  Serial.print("encoderPos = ");
  Serial.println(encoderPos);

  delay(50);
}
 
