#include "Arduino.h"
#include "pluviometer.h"


int Pluviometer::_debounceLimit;
int Pluviometer::_mmCounter;
unsigned long Pluviometer::_now;
unsigned long Pluviometer::_before;



Pluviometer::Pluviometer(int pin) {
  _pin = pin;
  _mmCounter = 0;
  _debounceLimit = 200;
  _before = millis();
  pinMode(_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(_pin), pluviometerHandler,  HIGH);
}

int Pluviometer::debounce() {
  _now = millis();
  if ((_now - _before) > _debounceLimit) {
    _before = _now;
    return 1;
  }
  else {
    return 0;
  }
}

static void Pluviometer::pluviometerHandler(){
  if (debounce()){
    _mmCounter = _mmCounter + 1;
    Serial.print("Medida de chuva: ");
    Serial.print(_mmCounter * 0.25);
    Serial.println("mm");
    Serial.print("Contagem: ");
    Serial.println(_mmCounter);
   

  }
 
}


void Pluviometer::setCounter(int counter){
  _mmCounter = counter;
}
int Pluviometer::getMillimeters(){
	return _mmCounter;
}
