#include "Arduino.h"

#ifndef Pluviometer_h
#define Pluviometer_h


class Pluviometer
{
  public:
    Pluviometer(int pin, float * externalMM);
    static int debounce();
    static void pluviometerHandler();
    static float getMillimeters();
    
  private:
     int _pin;
     static float * _externalMM;
     static int _debounceLimit;
     static int _mmCounter;
     static unsigned long _now;
     static unsigned long _before;
};
#endif
