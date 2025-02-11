#pragma once

#include <vector>
#include <algorithm>

/**
* @brief Abstract class of engine.
* Parent class for every engine.
*/
class GeneralEngine {
public:
    GeneralEngine(double rotationAccuracy) : _rotationAccuracy(rotationAccuracy), _isCommited(false), 
        _currentTimeStage(0.0), _currentPower(0.0), _currentTemperature(0.0), _overheatTemperature(0.0), 
        _isSpinning(false), _currentRotateSpeed(0.0) {};
    ~GeneralEngine() {};
    
    inline double GetTemperature() const { return _currentTemperature; }
    inline double GetTimeStage() const { return _currentTimeStage; }
    inline double GetPower() const { return _currentPower; }
    inline double GetRotateSpeed() const { return _currentRotateSpeed; }
    inline double GetOverheatTemperature() const { return _overheatTemperature; }
    
    inline virtual bool isSpinning() const { return _isSpinning; }
    inline bool isCommitedForTesting() const { return _isCommited; }

    inline virtual void PrepareForTesting(double outsideTemperature) { _currentTemperature = outsideTemperature; _currentRotateSpeed = 0.0; }
    virtual void UpdateStage(double dT, double outsideTemp) = 0;
protected:
    bool _isCommited;
    bool _isSpinning;
    double _currentTimeStage;
    double _currentPower;
    double _currentTemperature;
    double _overheatTemperature;
    double _currentRotateSpeed;
    double _rotationAccuracy;
};

