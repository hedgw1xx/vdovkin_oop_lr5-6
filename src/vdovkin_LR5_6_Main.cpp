#include "vdovkin_LR5_6_Methods.hpp"
#include "vdovkin_def.hpp"

int main() {
  ProcessMap processes;

  map<int, pair<string, function<void()>>> menu = {
      {1,
       {"Create CropCultivation",
        [&processes]() { createCropCultivation(processes); }}},
      {2, {"Create Livestock", [&processes]() { createLivestock(processes); }}},
      {3,
       {"Create IrrigationSystem",
        [&processes]() { createIrrigationSystem(processes); }}},
      {4,
       {"Display all processes",
        [&processes]() { displayProcesses(processes); }}},
      {5,
       {"Calculate cost for a process",
        [&processes]() { calculateCostForProcess(processes); }}},
      {6,
       {"Start all processes",
        [&processes]() { startAllProcesses(processes); }}},
  };

  int choice = 0;
  while (true) {
    cout << "Menu:\n";
    for (const auto &item : menu) {
      cout << item.first << ". " << item.second.first << "\n";
    }
    cout << "• 0. Exit" << endl;

    EnterInt(cin, choice, "Enter your choice: ")();

    if (choice == 0) {
      cout << "© 2025 Eugene Vdovkin" << endl;
      break;
    }

    if (menu.find(choice) != menu.end()) {
      menu[choice].second();
    } else {
      cout << "Invalid choice\n";
    }
  }
  return 0;
}
