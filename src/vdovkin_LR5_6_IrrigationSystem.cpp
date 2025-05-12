#include "vdovkin_LR5_6_IrrigationSystem.hpp"

IrrigationSystem::IrrigationSystem()
    : waterConsumption(0.0), isAutomatic(false) {}
IrrigationSystem::IrrigationSystem(const IrrigationSystem &other)
    : AgriculturalProcess(other), waterConsumption(other.waterConsumption),
      isAutomatic(other.isAutomatic) {}
IrrigationSystem::IrrigationSystem(const string &id)
    : AgriculturalProcess(id), waterConsumption(0.0), isAutomatic(false) {}
IrrigationSystem::~IrrigationSystem() {}

istream &IrrigationSystem::input(istream &is) {
  AgriculturalProcess::input(is);
  EnterDouble(is, waterConsumption,
              "Enter water consumption (liters/hour): ")();
  EnterBool(is, isAutomatic, "Is automatic (0/1): ")();
  return is;
}

ostream &IrrigationSystem::print(ostream &os) const {
  os << "IrrigationSystem [ID: " << processID << ", Area: " << area
     << " ha, Active: " << (isActive ? "Yes" : "No")
     << ", Water Consumption: " << waterConsumption
     << " L/h, Automatic: " << (isAutomatic ? "Yes" : "No") << "]";
  return os;
}

void IrrigationSystem::startProcess() {
  string weather = getWeather();
  if (weather == "dry") {
    cout << "Starting irrigation due to dry weather." << endl;
  } else {
    cout << "No need for irrigation." << endl;
  }
}

double IrrigationSystem::calculateCost() const {
  return waterConsumption * 0.1;
}

bool IrrigationSystem::validate() const {
  if (!AgriculturalProcess::validate())
    return false;
  if (waterConsumption > 5000)
    return false;
  return true;
}

string IrrigationSystem::getWeather() const {
  return "dry"; // вообще любое
}

void IrrigationSystem::emergencyShutdown() {
  cout << "Emergency shutdown of irrigation system." << endl;
}
