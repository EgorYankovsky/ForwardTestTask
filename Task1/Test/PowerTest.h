#pragma once

#include "GeneralTest.h"

/**
* Class of finding maximum value of engine power.
*/
class PowerTest : public GeneralTest {
public:
    PowerTest() : _power(0.0), _rotationSpeed(0.0), GeneralTest() {};

    /**
    * @brief Main constructor.
    * @param eng - engine to test,
    * @param time - test time duration,
    * @param timeLayersAmount - amount of values for time mesh,
    * @param outsideTemperature - temperature of outside air,
    * @param testAccuracy - accuracy of test (default value - 0.0).
    */
    PowerTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature, double testAccuracy = 0.0) :
    _power(0.0), _rotationSpeed(0.0), GeneralTest(eng, time, timeLayersAmount, outsideTemperature, testAccuracy) {};
    ~PowerTest() {};

    void Run() override;
    void WriteResult() override;
private:
    double _power;
    double _rotationSpeed;
};

