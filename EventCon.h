class EventCon{

typedef void (*eventFunc);

  public:
  uint8_t  pinName;
  bool eventType;

  bool state        = true;
  bool lastState    = true;

  bool target       = false;
  bool done         = false;
  
  unsigned long lastChange   = 0;
  unsigned long debounceDelay = 50;
  
  void (*functionName)();
  
  EventCon(){};
  EventCon(uint8_t  argPinName, bool argEventType, bool argTarget, eventFunc argEventFunc){
 
  pinName      = argPinName;
  eventType    = argEventType;
  functionName = argEventFunc;
  target       = argTarget;
    
  }
  void call(){
    functionName();
  }
};
