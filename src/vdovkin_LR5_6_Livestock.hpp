#ifndef VDOVKIN_LR5_6_LIVESTOCK_H
#define VDOVKIN_LR5_6_LIVESTOCK_H

#include "vdovkin_LR5_6_AgriculturalProcess.hpp"

class Livestock final : public AgriculturalProcess {
protected:
  string animalType;
  int headCount;

  ostream &print(ostream &os) const override;
  istream &input(istream &is) override;

public:
  Livestock();
  Livestock(const Livestock &other);
  Livestock(const string &id, const string &type);
  ~Livestock() override;

  void startProcess() override;
  double calculateCost() const override;
  bool validate() const override;

  void scheduleVaccination();
  Livestock operator+(const Livestock &other) const;
};

#endif // VDOVKIN_LR5_6_LIVESTOCK_H
