#include "vdovkin_LR5_6_CropCultivation.hpp"
#include "vdovkin_LR5_6_AgriculturalProcess.hpp"

CropCultivation::CropCultivation() : cropType("unknown"), yield(0.0) {}
CropCultivation::CropCultivation(const CropCultivation &other)
    : AgriculturalProcess(other), cropType(other.cropType), yield(other.yield) {
}
CropCultivation::CropCultivation(const string &id, const string &type)
    : AgriculturalProcess(id), cropType(type), yield(0.0) {}
CropCultivation::~CropCultivation() {}

istream &CropCultivation::input(istream &is) {
  AgriculturalProcess::input(is);
  Enter(is, cropType, "Enter crop type (ex. wheat): ")();
  Enter(is, yield, "Enter expected yield (tons): ")();
  return is;
}

ostream &CropCultivation::print(ostream &os) const {
  AgriculturalProcess::print(os);
  os << ", Crop Type: " << cropType << ", Yield: " << yield << " tons";
  return os;
}

void CropCultivation::startProcess() {
  cout << "Starting crop cultivation for " << cropType << endl;
}

double CropCultivation::calculateCost() const {
  return area * 100.0 + yield * 50.0;
}

bool CropCultivation::validate() const {
  if (!AgriculturalProcess::validate())
    return false;
  if (cropType == "wheat" && yield <= 10)
    return false;
  return true;
}

void CropCultivation::optimizeIrrigation() {
  cout << "Optimizing irrigation for " << cropType << endl;
}

CropCultivation &CropCultivation::operator+=(double additionalArea) {
  area += additionalArea;
  return *this;
}
