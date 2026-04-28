
/*
--------------------------------
            LIBRARIES
--------------------------------
*/
#include <CAN.h>
#include <ESP32Servo.h>
#include <analogWrite.h>
#include <tone.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

/*
--------------------------------
            PINS
--------------------------------
*/
const int  rpmsensor = 6;
const int servoTX1= 18;
const int servoTX2= 19;
const int enable =10;
/*
--------------------------------
            VARIABLES
--------------------------------
*/
volatile int pulseCount = 0;
unsigned long lastTime = 0;
const float teeth_per_rev = 60.0; 
float activaterpm=9000;
bool status=0;
/*
--------------------------------
            FUNCTIONS
--------------------------------
*/
//FUNCTION DECLARATION
float actvrpm();
void IRAM_ATTR countPulse();
void activateServ();
void disableServ();
void rpmcase();
void setup() {  
 //Communication using usb
  Serial.begin(115200);
  //Input 
  pinMode(rpmsensor, INPUT_PULLUP);
  pinMode(enable,INPUT);
  //Output
  pinMode(servoTX1,OUTPUT);
  pinMode(servoTX2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(rpmsensor), countPulse, RISING); 

}

void loop() {
  if(digitalRead(enable)==1){
    status=1;
  }
  else{
    status=0;
  }
  rpmcase();
}
//FUNCTION REALIZATION
float actvrpm(){
  if (millis() - lastTime >= 1000) { // Every 1 second
    noInterrupts(); // Pause interrupts to read value
    int currentPulses = pulseCount;
    pulseCount = 0;
    interrupts();
    lastTime = millis();
    // Formula: (pulses / teeth_per_rev) * 60 seconds
    float rpm = (currentPulses / teeth_per_rev) * 60.0; // Example for 60-tooth wheel
   }
  return rpm;
}

void IRAM_ATTR countPulse() {
  pulseCount++;
}

void activateServ(){

}

void disableserv(){

}

void rpmcase(){
  if(status==1){
    if(actvrpm()>=rpm){
      activateServ();
    }
    else{
      disableServ();
    }
  }
  else{
    disableServ();

  }  
}