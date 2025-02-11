#pragma once

#include "GeneralTest.h"

class PowerTest : public GeneralTest {
public:
    PowerTest() : _power(0.0), _rotationSpeed(0.0), GeneralTest() {};
    PowerTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature) :
    _power(0.0), _rotationSpeed(0.0), GeneralTest(eng, time, timeLayersAmount, outsideTemperature) {};
    ~PowerTest() {};

    void Run() override;
    void GetResults() override;
private:
    double _power;
    double _rotationSpeed;
};

