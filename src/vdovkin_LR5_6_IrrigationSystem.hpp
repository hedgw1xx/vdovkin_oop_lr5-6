#ifndef VDOVKIN_LR5_6_IRRIGATIONSYSTEM_H
#define VDOVKIN_LR5_6_IRRIGATIONSYSTEM_H

#include "vdovkin_LR5_6_AgriculturalProcess.hpp"
#include "vdovkin_LR5_6_WeatherMonitor.hpp"

class IrrigationSystem : public AgriculturalProcess, public WeatherMonitor {
protected:
  double waterConsumption;
  bool isAutomatic;

  ostream &print(ostream &os) const override;
  istream &input(istream &is) override;

public:
  IrrigationSystem();
  IrrigationSystem(const IrrigationSystem &other);
  IrrigationSystem(const string &id);
  ~IrrigationSystem() override;

  void startProcess() override;
  double calculateCost() const override;
  bool validate() const override;

  void emergencyShutdown();
};

#endif // VDOVKIN_LR5_6_IRRIGATIONSYSTEM_H
