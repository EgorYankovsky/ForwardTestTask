#pragma once

#include <iostream>
#include "../Engine/GeneralEngine.h"

/**
* @brief Abstract class of test.
* Parent class for every test.
*/
class GeneralTest {
public:
    GeneralTest() : _eng(nullptr), _time(0.0), _timeLayersAmount(0), _isPreparedForRunning(false), _outsideTemperature(20.0), 
                    _testAccuracy(0.0) {};
    GeneralTest(GeneralEngine* eng, double time, size_t timeLayersAmount, double outsideTemperature, double testAccuracy) :
        _eng(eng), _time(time), _timeLayersAmount(timeLayersAmount), _outsideTemperature(outsideTemperature),
        _isPreparedForRunning(true), _testAccuracy(testAccuracy) {};
    ~GeneralTest() {};
    
    /**
     * @brief Method that start test.
    */
    virtual void Run() = 0;

    /**
     * @brief Method that makes console output of test result.
    */
    virtual void WriteResult() = 0;
protected:
    bool _isPreparedForRunning;
    double _time;
    size_t _timeLayersAmount;
    GeneralEngine* _eng;
    double _outsideTemperature;
    double _testAccuracy;
};