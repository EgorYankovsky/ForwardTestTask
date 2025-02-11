#pragma once

#include <iostream>
#include "../Engine/GeneralEngine.h"

class GeneralTest {
public:
    GeneralTest() : _eng(nullptr), _time(0.0), _timeLayersAmount(0), _isPreparedForRunning(false), _outsideTemperature(20.0) {};
    GeneralTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature) :
        _eng(eng), _time(time), _timeLayersAmount(timeLayersAmount), _outsideTemperature(outsideTemperature),
        _isPreparedForRunning(true) {};
    ~GeneralTest() {};
    
    virtual void Run() = 0;
    virtual void GetResults() = 0;
protected:
    bool _isPreparedForRunning;
    double _time;
    size_t _timeLayersAmount;
    GeneralEngine* _eng;
    double _outsideTemperature;
};