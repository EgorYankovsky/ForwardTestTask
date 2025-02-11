#include "OverheatTest.h"

void OverheatTest::Run() {
    if (!_isPreparedForRunning) {
        exit(-1);
    }
    double deltTime = _time / _timeLayersAmount;
    
    _eng->PrepareForTesting(_outsideTemperature);
    do {
        _eng->UpdateStage(deltTime, _outsideTemperature);
    } while (_eng->GetTimeStage() < _time and !_eng->isOverheated());

    _temperature = _eng->GetTemperature();
    _timeElapsed = _eng->GetTimeStage();

    std::cout << _eng->GetTemperature() << " " << _eng->GetTimeStage() << std::endl;

}

void OverheatTest::GetResults() {
    _temperature = _eng->GetTemperature();
    _timeElapsed = _eng->GetTimeStage();
}
