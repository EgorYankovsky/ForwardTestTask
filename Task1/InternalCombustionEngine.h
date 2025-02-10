#pragma once

#include "GeneralEngine.h"
#include <string>

class InternalCombustionEngine : public GeneralEngine {
private:
    double getTorqueAt(double rotateSpeed);
public:
    InternalCombustionEngine() {};
    InternalCombustionEngine(double I, double T_overheat, double H_m, double H_v, double C,
                             std::vector<double> M, std::vector<double> V);
    InternalCombustionEngine(std::vector<std::string> &values);
    ~InternalCombustionEngine() {};

    void UpdateStage(double dT) override;
};