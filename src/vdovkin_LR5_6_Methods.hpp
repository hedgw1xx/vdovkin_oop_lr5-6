#ifndef VDOVKIN_LR5_6_METHODS_H
#define VDOVKIN_LR5_6_METHODS_H

#include "vdovkin_LR5_6_CropCultivation.hpp"
#include "vdovkin_LR5_6_IrrigationSystem.hpp"
#include "vdovkin_LR5_6_Livestock.hpp"

using ProcessMap = map<string, unique_ptr<AgriculturalProcess>>;

void createCropCultivation(ProcessMap &processes);
void createLivestock(ProcessMap &processes);
void createIrrigationSystem(ProcessMap &processes);
void displayProcesses(const ProcessMap &processes);
void startAllProcesses(const ProcessMap &processes);

#endif // VDOVKIN_LR5_6_METHODS_H
