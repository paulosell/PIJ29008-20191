#include "Arduino.h"

#ifndef Pluviometer_h
#define Pluviometer_h


class Pluviometer
{
  public:
    Pluviometer(int pin, float * externalMM);
    static int debounce();
    static void pluviometerHandler();
    float getMillimeters();
    
  private:
     int _pin;
     static int _debounceLimit;
     static int _mmCounter;
     static unsigned long _now;
     static unsigned long _before;
};
#endif
