#include "vdovkin_LR5_6_Livestock.hpp"
#include <string>

Livestock::Livestock() : animalType("unknown"), headCount(0) {}
Livestock::Livestock(const Livestock &other)
    : AgriculturalProcess(other), animalType(other.animalType),
      headCount(other.headCount) {}
Livestock::Livestock(const string &id, const string &type)
    : AgriculturalProcess(id), animalType(type) {}
Livestock::~Livestock() {}

istream &Livestock::input(istream &is) {
  AgriculturalProcess::input(is);
  Enter(is, animalType, "Enter animal type: ")();
  Enter(is, headCount, "Enter head count: ")();
  return is;
}

ostream &Livestock::print(ostream &os) const {
  AgriculturalProcess::print(os);
  os << ", Animal Type: " << animalType << ", Head Count: " << headCount;
  return os;
}

void Livestock::startProcess() {
  cout << "Starting livestock management for " << animalType << endl;
}

double Livestock::calculateCost() const { return headCount * 200.0; }

bool Livestock::validate() const {
  if (!AgriculturalProcess::validate())
    return false;
  if (headCount <= 500)
    return false;
  return true;
}

void Livestock::scheduleVaccination() {
  cout << "Scheduling vaccination for " << animalType << endl;
}

Livestock Livestock::operator+(const Livestock &other) const {
  Livestock result(*this);
  result.animalType += " + " + other.animalType;
  result.headCount += other.headCount;
  return result;
}
