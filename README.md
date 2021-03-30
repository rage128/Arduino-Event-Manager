# Arduino-Event-Manager

Sürekli tekrar eden pin eventlerini debouncing kontrolüde yaparak kullanabilmek için hazırladım.

EventManagerMain.addEventListener(pinNumber, eventType, eventTarget, targetFunction);

pinNumar (int)            : Arduino üzerindeki dinlenmek istenen pin numarası.<br>
eventType (bool)          : Hedef Pinin tetiklenmesi durumunda hedef fonksiyonun false durumunda 1 kez, true durumunde sürekli çalışmasını sağlar.<br>
eventTarget (bool)        : Hedef pinin hangi durumda tetiklenmesi koşuludu belirtir. HIGH/LOW,<br>
targetFunction (function) : Hedef pin tetiklendiğinde çalışacak olan fonksiyonu belirtir.<br>

<b>Örnek Kullanım :</b><br>
#include "EventManager.h"

EventManagerMain evMan;

void setup(){
  evMan.addEventListener(5,false,0, tFunc);
}

void loop(){
  evMan.loop();
}

void tFunc(){
  Serial.println ("tusa basıldı");
}
 
