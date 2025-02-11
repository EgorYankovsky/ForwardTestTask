#include "OverheatTest.h"

bool OverheatTest::IsOverheated() { 
    //std::cout << abs(_eng->GetOverheatTemperature() - _eng->GetTemperature()) << std::endl;
    return abs(_eng->GetOverheatTemperature() - _eng->GetTemperature()) <= _testAccuracy;
}

void OverheatTest::Run() {
    if (!_isPreparedForRunning or !_eng->isCommitedForTesting()) return;

    double deltTime = _time / _timeLayersAmount;
    _eng->PrepareForTesting(_outsideTemperature);
    do {
        _eng->UpdateStage(deltTime, _outsideTemperature);
    } while (_eng->GetTimeStage() < _time and !IsOverheated());

    _wasEngineOverheated = IsOverheated();
    _temperature = _eng->GetTemperature();
    _timeElapsed = _eng->GetTimeStage();
}

void OverheatTest::WriteResult() {
    std::cout << "\x1B[32mOverheat test result:\033[0m\t\t" << std::endl;
    
    if (!_isPreparedForRunning or !_eng->isCommitedForTesting())
        std::cout << "\x1B[31mData wasn't prepared for testing!\033[0m\t\t" << std::endl;
    
    if (_wasEngineOverheated)
        std::cout << "The engine was overheated at the time " << _timeElapsed << " sec." << std::endl;
    else
        std::cout << "The engine was not overheated during the test." << std::endl;
}
