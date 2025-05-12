#ifndef VDOVKIN_LR5_6_AGRICULTURALPROCESS_H
#define VDOVKIN_LR5_6_AGRICULTURALPROCESS_H

#include "vdovkin_def.hpp"

class AgriculturalProcess {
protected:
  string processID;
  double area;
  bool isActive;

  virtual ostream &print(ostream &os) const = 0;
  virtual istream &input(istream &is);

public:
  AgriculturalProcess();
  AgriculturalProcess(const AgriculturalProcess &other);
  AgriculturalProcess(const string &id);
  virtual ~AgriculturalProcess();

  string getProcessID() const { return processID; }

  // Public setter for processID
  void setProcessID(const string &id) { processID = id; }

  virtual void startProcess() = 0;
  virtual double calculateCost() const = 0;
  virtual bool validate() const;

  bool operator==(const AgriculturalProcess &other) const;

  friend ostream &operator<<(ostream &os, const AgriculturalProcess &process);
  friend istream &operator>>(istream &is, AgriculturalProcess &process);
};

#endif // VDOVKIN_LR5_6_AGRICULTURALPROCESS_H
