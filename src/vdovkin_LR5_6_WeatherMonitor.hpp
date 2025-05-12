#ifndef VDOVKIN_LR5_6_WEATHERMONITOR_H
#define VDOVKIN_LR5_6_WEATHERMONITOR_H

#include "vdovkin_def.hpp"

class WeatherMonitor {
public:
  virtual string getWeather() const = 0;
  virtual ~WeatherMonitor() {}
};

#endif // VDOVKIN_LR5_6_WEATHERMONITOR_H
