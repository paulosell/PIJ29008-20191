#include "Arduino.h"

#ifndef Pluviometer_h
#define Pluviometer_h


class Pluviometer
{
  public:
    Pluviometer(int pin);
    static int debounce();
    static void pluviometerHandler();
    int getMillimeters();
    void setCounter(int counter);
    
  private:
     int _pin;
     static int _debounceLimit;
     static int _mmCounter;
     static unsigned long _now;
     static unsigned long _before;
};
#endif
