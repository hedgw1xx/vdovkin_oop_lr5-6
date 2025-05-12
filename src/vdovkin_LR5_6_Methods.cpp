#include "vdovkin_LR5_6_Methods.hpp"

void createCropCultivation(ProcessMap &processes) {
  auto process = make_unique<CropCultivation>();
  cin >> *process;
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

void calculateCostForProcess(const ProcessMap &processes) {
  string id;
  EnterString(cin, id, "Enter process ID: ")();
  auto it = processes.find(id);
  if (it != processes.end()) {
    cout << "Cost: " << it->second->calculateCost() << endl;
  } else {
    cout << "Process not found.\n";
  }
}

void startAllProcesses(const ProcessMap &processes) {
  for (const auto &pair : processes) {
    pair.second->startProcess();
  }
}
