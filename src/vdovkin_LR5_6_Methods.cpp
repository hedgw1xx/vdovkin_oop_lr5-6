#include "vdovkin_LR5_6_Methods.hpp"
#include "vdovkin_LR5_6_AgriculturalProcess.hpp"
#include "vdovkin_LR5_6_CropCultivation.hpp"
#include "vdovkin_LR5_6_Livestock.hpp"
#include "vdovkin_def.hpp"

void createCropCultivation(ProcessMap &processes) {
  auto process = make_unique<CropCultivation>();
  cin >> *process;
  cout << *process << endl;
  if (processes.find(process->getProcessID()) != processes.end()) {
    cout << "Process with ID " << process->getProcessID()
         << " already exists.\n";
    return;
  }
  processes[process->getProcessID()] = std::move(process);
}

void createLivestock(ProcessMap &processes) {
  auto process = make_unique<Livestock>();
  cin >> *process;
  cout << *process << endl;
  if (processes.find(process->getProcessID()) != processes.end()) {
    cout << "Process with ID " << process->getProcessID()
         << " already exists.\n";
    return;
  }
  processes[process->getProcessID()] = std::move(process);
}

void createIrrigationSystem(ProcessMap &processes) {
  auto process = make_unique<IrrigationSystem>();
  cin >> *process;
  cout << *process << endl;
  if (processes.find(process->getProcessID()) != processes.end()) {
    cout << "Process with ID " << process->getProcessID()
         << " already exists.\n";
    return;
  }
  processes[process->getProcessID()] = std::move(process);
}

void displayProcesses(const ProcessMap &processes) {
  for (const auto &pair : processes) {
    cout << *pair.second << endl;
  }
}

void startAllProcesses(const ProcessMap &processes) {
  for (const auto &pair : processes) {
    cout << "Process ID: " << pair.first << endl;

    // Вызов validate()
    bool isValid = pair.second->validate();
    cout << "Validation: " << (isValid ? "passed" : "failed") << endl;

    if (isValid) {
      pair.second->startProcess();
    }

    if (pair.second == pair.second) {
      cout << "Process's ID are identical" << endl;
    } else {
      cout << "Process's ID are different" << endl;
    }

    if (auto cropPtr = dynamic_cast<CropCultivation *>(pair.second.get())) {
      *(dynamic_cast<CropCultivation *>(pair.second.get())) += 100.0;
      cout << *(dynamic_cast<CropCultivation *>(pair.second.get())) << endl;

      cropPtr->optimizeIrrigation();
    }

    if (auto irrigationPtr =
            dynamic_cast<IrrigationSystem *>(pair.second.get())) {
      cout << "Погода: " << irrigationPtr->getWeather() << endl;
      irrigationPtr->emergencyShutdown();
    }

    if (auto livestockPtr = dynamic_cast<Livestock *>(pair.second.get())) {
      cout << "Before animal addition: \n";
      cout << *(dynamic_cast<Livestock *>(pair.second.get())) << endl;
      cout << "After animal addition: \n";
      cout << *(dynamic_cast<Livestock *>(pair.second.get())) +
                  *(dynamic_cast<Livestock *>(pair.second.get()))
           << endl;
      livestockPtr->scheduleVaccination();
    }

    double cost = pair.second->calculateCost();
    cout << "Cost: " << cost << " у.е." << endl;

    cout << "\n-----------------------------" << endl;
  }
}
