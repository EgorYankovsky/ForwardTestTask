#pragma once

#include "GeneralEngine.h"
#include <string>

class InternalCombustionEngine : public GeneralEngine {
public:
    InternalCombustionEngine() : _I(0.0), _H_m(0.0), _H_v(0.0), _C(0.0), _values({}), a(0.0), GeneralEngine(0.0) {};
    InternalCombustionEngine(std::vector<std::string> &values, double rotationAccuracy);
    ~InternalCombustionEngine() {};

    void UpdateStage(double dT, double outsideTemp) override;

    inline void SetAcceleration(double value) { a = value; };
    inline double GetAcceleration() const { return a; }

    inline bool isSpinning() const override { return a >= _rotationAccuracy; }

protected:
    double _I;
    double _H_m;
    double _H_v;
    double _C;
    std::vector<std::pair<double, double>> _values;     // Discrete dependence M(V).
private:
    double getTorqueAt(double rotateSpeed);
    double a;
};