#pragma once

#include "GeneralTest.h"

/**
* Class of engine overheat test.
*/
class OverheatTest : public GeneralTest {
public:
    OverheatTest() : _temperature(0.0), _timeElapsed(0.0), _wasEngineOverheated(false), GeneralTest() {};
    
    /**
    * @brief Main constructor.
    * @param eng - engine to test,
    * @param time - test time duration,
    * @param timeLayersAmount - amount of values for time mesh,
    * @param outsideTemperature - temperature of outside air,
    * @param testAccuracy - accuracy of test (default value - 0.0).
    */
    OverheatTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature, double testAccuracy) :
        _temperature(0.0), _timeElapsed(0.0), _wasEngineOverheated(false), 
        GeneralTest(eng, time, timeLayersAmount, outsideTemperature, testAccuracy) {};
    ~OverheatTest() {};

    inline bool IsOverheated() const { return _eng->GetOverheatTemperature() - _eng->GetTemperature() <= _testAccuracy; }

    void Run() override;
    void WriteResult() override;
private:
    double _temperature;
    double _timeElapsed;
    bool _wasEngineOverheated;
};