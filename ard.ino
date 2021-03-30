#include "EventManagerMain.h"

EventManagerMain evMan;
void setup() {
  Serial.begin(9600);
  Serial.println("basladi");

  evMan.addEventListener(5,false,0, calis);
  evMan.addEventListener(7,true,0, calis2);
}

void loop() {
  evMan.loop();
}
 
void calis(){
  Serial.println("1. olan ");
  
}

void calis2(){
  Serial.println("2. olan ");
}
