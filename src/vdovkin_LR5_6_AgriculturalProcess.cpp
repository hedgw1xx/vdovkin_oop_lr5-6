#include "vdovkin_LR5_6_AgriculturalProcess.hpp"
#include <ostream>

AgriculturalProcess::AgriculturalProcess()
    : processID("unknown"), area(0.0), isActive(false) {}
AgriculturalProcess::AgriculturalProcess(const AgriculturalProcess &other)
    : processID(other.processID), area(other.area), isActive(other.isActive) {}
AgriculturalProcess::AgriculturalProcess(const string &id)
    : processID(id), area(0.0), isActive(false) {}
AgriculturalProcess::~AgriculturalProcess() {}

istream &AgriculturalProcess::input(istream &is) {
  Enter(is, processID, "Enter process ID: ")();
  Enter(is, area, "Enter area (hectares): ")();
  Enter(is, isActive, "Is active (0/1): ")();
  return is;
}

ostream &AgriculturalProcess::print(ostream &os) const {
  os << "ID: " << processID << ", Area: " << area
     << " ha, Active: " << (isActive ? "Yes" : "No");
  return os;
}

bool AgriculturalProcess::validate() const { return area > 0; }

bool AgriculturalProcess::operator==(const AgriculturalProcess &other) const {
  return processID == other.processID;
}

ostream &operator<<(ostream &os, const AgriculturalProcess &process) {
  return process.print(os);
}

istream &operator>>(istream &is, AgriculturalProcess &process) {
  return process.input(is);
}
