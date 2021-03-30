class EventCon{

typedef void (*eventFunc);

  public:
  uint8_t  pName;
  bool eType;

  bool state        = true;
  bool lState       = true;

  bool target       = false;
  bool done         = false;
  
  unsigned long lChange   = 0;

  void (*fName)();
  
  EventCon(){};
  EventCon(uint8_t  argPinName, bool argEventType, bool argTarget, eventFunc argEventFunc){
 
  pName        = argPinName;
  eType        = argEventType;
  fName        = argEventFunc;
  target       = argTarget;
    
  }
  void call(){
    fName();
  }
};
