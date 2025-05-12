#ifndef VDOVKIN_LR5_6_CROPCULTIVATION_H
#define VDOVKIN_LR5_6_CROPCULTIVATION_H

#include "vdovkin_LR5_6_AgriculturalProcess.hpp"

class CropCultivation : public AgriculturalProcess {
protected:
  string cropType;
  double yield;

  ostream &print(ostream &os) const override;
  istream &input(istream &is) override;

public:
  CropCultivation();
  CropCultivation(const CropCultivation &other);
  CropCultivation(const string &id, const string &type);
  ~CropCultivation() override;

  void startProcess() override;
  double calculateCost() const override;
  bool validate() const override;

  void optimizeIrrigation();
  CropCultivation &operator+=(double additionalArea);
};

#endif // VDOVKIN_LR5_6_CROPCULTIVATION_H
