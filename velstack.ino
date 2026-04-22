/*
--------------------------------
            LIBRARIES
--------------------------------
*/
#include <CAN.h>
#include <Servo.h>
/*
--------------------------------
            PINS
--------------------------------
*/
int  rpmHI = 6;
int rpmLO =7;
int servoTX1= 18;
int servoTX2= 19;
int enable =10;
/*
--------------------------------
            VARIABLES
--------------------------------
*/

/*
--------------------------------
            FUNCTIONS
--------------------------------
*/
void setup() {
  //Input 
  pinMode(rpmLO, INPUT);
  pinMode(rpmHi,INPUT);
  pinMode(enable,INPUT);
  //Output
  pinMode(servoTX1,OUTPUT);
  pinMode(servoTX2,OUTPUT);
  //Communication using usb
  Serial.begin(115200);
}
//FUNCTION DECLARATION
int actvrpm();
void loop() {

}
//FUNCTION REALIZATION
int actvrpm(){
    
}
