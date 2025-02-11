#include "PowerTest.h"

void PowerTest::Run() {
    if (!_isPreparedForRunning) {
        exit(-1);
    }

    double deltTime = _time / _timeLayersAmount;
    _eng->PrepareForTesting(_outsideTemperature);

    do {
        _eng->UpdateStage(deltTime, _outsideTemperature);
    } while (_eng->GetTimeStage() < _time and _eng->isSpinning());
    
    _power = _eng->GetPower();
    _rotationSpeed = _eng->GetRotateSpeed();

    std::cout << _eng->GetPower() << " " << _eng->GetRotateSpeed() << std::endl;
}

void PowerTest::GetResults() {
    _power = _eng->GetPower();
    _rotationSpeed = _eng->GetRotateSpeed();
}
