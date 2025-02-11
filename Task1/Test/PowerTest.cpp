#include "PowerTest.h"

void PowerTest::Run() {
    if (!_isPreparedForRunning) {
        exit(-1);
    }

    double deltTime = _time / _timeLayersAmount;
    _eng->PrepareForTesting(_outsideTemperature);

    do {
        _eng->UpdateStage(deltTime, _outsideTemperature);
        if (_power < _eng->GetPower()){
            _power = _eng->GetPower();
            _rotationSpeed = _eng->GetRotateSpeed();
        }
    } while (_eng->GetTimeStage() < _time and _eng->isSpinning());
}

void PowerTest::WriteResult() {
    std::cout << "\x1B[32mPower test result:\033[0m\t\t" << std::endl;
    std::cout << "The maximum power " << _power << " (kW) was reached at a speed of " << _rotationSpeed << " (rad / sec)." << std::endl;
}
