# Arduino-Event-Manager

Sürekli tekrar eden pin eventlerini debouncing kontrolüde yaparak kullanabilmek için hazırladım.

EventManager.addEventListener(pinNumber, eventType, eventTarget, targetFunction);

pinNumar (int)            : Arduino üzerindeki dinlenmek istenen pin numarası.
eventType (bool)          : Hedef Pinin tetiklenmesi durumunda hedef fonksiyonun false durumunda 1 kez, true durumunde sürekli çalışmasını sağlar.
eventTarget (bool)        : Hedef pinin hangi durumda tetiklenmesi koşuludu belirtir. HIGH/LOW,
targetFunction (function) : Hedef pin tetiklendiğinde çalışacak olan fonksiyonu belirtir.

Örnek Kullanım :
#include "EventManager.h"

EventManager evMan;

void setup(){
  evMan.addEventListener(5,false,0, tFunc);
}

void loop(){
  evMan.loop();
}

void tFunc(){
  Serial.println ("tusa basıldı");
}
