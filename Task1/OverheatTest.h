#pragma once

#include "GeneralTest.h"
#include "GeneralEngine.h"

class OverheatTest : public GeneralTest {
private:
    bool isPreparedForRunning = false;
    double outdoorTemperature = 20.0;
    double t0;
    double tn;
    size_t ta;
    GeneralEngine* eng;
public:
    void Run() override;
    OverheatTest() {};
    OverheatTest(GeneralEngine* _eng, double _outdoorTemperature, double T_0, double T_n, size_t T_amount) : 
        eng(_eng), outdoorTemperature(_outdoorTemperature), t0(T_0), tn(T_n), ta(T_amount) {
        isPreparedForRunning = true;
    };
    ~OverheatTest() {};
};