#pragma once

#include "GeneralEngine.h"
#include <string>

class InternalCombustionEngine : public GeneralEngine {
public:
    InternalCombustionEngine() : _I(0.0), _H_m(0.0), _H_v(0.0), _C(0.0), _values({}), GeneralEngine() {};
    InternalCombustionEngine(std::vector<std::string> &values);
    ~InternalCombustionEngine() {};

    void UpdateStage(double dT, double outsideTemp) override;
protected:
    double _I;
    double _H_m;
    double _H_v;
    double _C;
    std::vector<std::pair<double, double>> _values;     // Discrete dependence M(V).
private:
    double getTorqueAt(double rotateSpeed);
};