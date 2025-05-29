#include "vdovkin_LR5_6_IrrigationSystem.hpp"
#include "vdovkin_LR5_6_WeatherMonitor.hpp"

IrrigationSystem::IrrigationSystem()
    : WeatherMonitor(), waterConsumption(0.0), isAutomatic(false) {}
IrrigationSystem::IrrigationSystem(const IrrigationSystem &other)
    : AgriculturalProcess(other), WeatherMonitor(other),
      waterConsumption(other.waterConsumption), isAutomatic(other.isAutomatic) {
}
IrrigationSystem::IrrigationSystem(const string &id)
    : AgriculturalProcess(id), WeatherMonitor("dry"), waterConsumption(0.0),
      isAutomatic(false) {}
IrrigationSystem::~IrrigationSystem() {}

istream &IrrigationSystem::input(istream &is) {
  AgriculturalProcess::input(is);
  Enter(is, weather, "Enter weather (rainy/dry): ")();
  Enter(is, waterConsumption, "Enter water consumption (liters/hour): ")();
  Enter(is, isAutomatic, "Is automatic (0/1): ")();
  return is;
}

ostream &IrrigationSystem::print(ostream &os) const {
  AgriculturalProcess::print(os);
  os << ", Weather: " << weather << ", Water Consumption: " << waterConsumption
     << " L/h, Automatic: " << (isAutomatic ? "Yes" : "No");
  return os;
}

void IrrigationSystem::startProcess() {
  if (isActive) {
    string weather = getWeather();
    if (weather == "dry") {
      cout << "Starting irrigation due to dry weather." << endl;
    } else {
      cout << "No need for irrigation." << endl;
      isActive = false;
    }
  }
}

double IrrigationSystem::calculateCost() const {
  return waterConsumption * 0.1;
}

bool IrrigationSystem::validate() const {
  if (!AgriculturalProcess::validate())
    return false;
  if (waterConsumption <= 5000)
    return false;
  return true;
}

void IrrigationSystem::emergencyShutdown() {
  if (isActive) {
    cout << "Emergency shutdown of irrigation system." << endl;
    isActive = false;
  } else {
    cout << "Irrigation system is not running." << endl;
  }
}
