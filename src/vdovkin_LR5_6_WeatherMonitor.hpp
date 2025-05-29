#ifndef VDOVKIN_LR5_6_WEATHERMONITOR_H
#define VDOVKIN_LR5_6_WEATHERMONITOR_H

#include "vdovkin_def.hpp"

class WeatherMonitor {
protected:
  string weather;

public:
  WeatherMonitor() : weather("unknown") {}
  WeatherMonitor(const WeatherMonitor &other) : weather(other.weather) {}
  WeatherMonitor(const string &newWeather) : weather(newWeather) {}

  virtual string getWeather() const { return weather; }
  virtual void setWeather(const string &newWeather) { weather = newWeather; }
  virtual ~WeatherMonitor() {}
};

#endif // VDOVKIN_LR5_6_WEATHERMONITOR_H
