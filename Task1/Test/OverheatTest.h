#pragma once

#include "GeneralTest.h"

class OverheatTest : public GeneralTest {
public:
    OverheatTest() : _temperature(0.0), _timeElapsed(0.0), _wasEngineOverheated(false), GeneralTest() {};
    OverheatTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature, double testAccuracy) :
        _temperature(0.0), _timeElapsed(0.0), _wasEngineOverheated(false), 
        GeneralTest(eng, time, timeLayersAmount, outsideTemperature, testAccuracy) {};
    ~OverheatTest() {};

    bool IsOverheated();

    void Run() override;
    void WriteResult() override;
private:
    double _temperature;
    double _timeElapsed;
    bool _wasEngineOverheated;
};