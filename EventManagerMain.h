#include "EventCon.h"
class EventManagerMain{
typedef void (*eventFunc);

public: 
  
  EventCon events[40];
  uint8_t currentCount = 0;
  unsigned long debounceDelay = 50;
  
  EventManagerMain(){};
  
  void addEventListener(uint8_t argPinName, bool argEventType, bool argEventTarget, eventFunc argEventFunc){
    events[currentCount] = EventCon(argPinName, argEventType, argEventTarget, argEventFunc);
    pinMode(argPinName, INPUT_PULLUP);
    currentCount++;  
  }
  
  void loop(){
    for(uint8_t i=0;i<currentCount;i++){
      
	bool tmpRead = digitalRead(events[i].pName);

    if(tmpRead != events[i].lState){
        events[i].lState  = tmpRead;
        events[i].lChange = millis();
     }

     if(millis() > events[i].lChange + debounceDelay){
        events[i].lChange = millis();
        events[i].state = tmpRead;
     }

     if(events[i].state == events[i].target ){

          if(events[i].eType){
            events[i].call();
          }else{
            if(!events[i].done){
              events[i].done = true;
              events[i].call();
              
            }
          }
     }else{
       events[i].done = false;
     }
      
    }
  }

};
