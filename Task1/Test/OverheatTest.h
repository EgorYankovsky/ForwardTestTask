#pragma once

#include "GeneralTest.h"

class OverheatTest : public GeneralTest {
public:
    OverheatTest() : _temperature(0.0), _timeElapsed(0.0), GeneralTest() {};
    OverheatTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature) :
        _temperature(0.0), _timeElapsed(0.0), GeneralTest(eng, time, timeLayersAmount, outsideTemperature) {};
    ~OverheatTest() {};

    void Run() override;
    void GetResults() override;
private:
    double _temperature;
    double _timeElapsed;
};