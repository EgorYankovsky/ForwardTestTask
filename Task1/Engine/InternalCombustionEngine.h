#pragma once

#include "GeneralEngine.h"
#include <string>

/**
 * @brief Class that simulates the operation of an Internal Combustion Engine (ICE).
*/
class InternalCombustionEngine : public GeneralEngine {
public:
    InternalCombustionEngine() : _I(0.0), _H_m(0.0), _H_v(0.0), _C(0.0), _values({}), a(0.0), GeneralEngine(0.0) {};
    
    /**
    * @breif Main constructor.
    * @param values - vector of integer or float values presented as string.
    * @param rotationAccuracy - double value for counting angular acceleration.
    */
    InternalCombustionEngine(std::vector<std::string> &values, double rotationAccuracy);
    ~InternalCombustionEngine() {};

    void UpdateStage(double dT, double outsideTemp) override;

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