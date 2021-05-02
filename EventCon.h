class EventCon{

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
  EventCon(uint8_t  argPinName, bool argEventType, bool argTarget, unsigned int argEventFunc){
 
  Serial.println("test");
  Serial.println(argEventFunc);
  
  
  pName        = argPinName;
  eType        = argEventType;
  fName        = 699; //argEventFunc;
  target       = argTarget;
  
  //fName();
  }
  void call(){
    //fName();
  }
};
