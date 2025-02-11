#include "InternalCombustionEngine.h"

#include <iostream>

double InternalCombustionEngine::getTorqueAt(double rotateSpeed) {
    for (size_t i(0); i < _values.size() - 1; ++i) {
        if (rotateSpeed < _values.front().second) return _values.front().first;
        if (_values.back().second < rotateSpeed) return _values.back().first;

        if (_values[i].second <= rotateSpeed and rotateSpeed <= _values[i + 1].second)
            return (_values[i + 1].first - _values[i].first) / (_values[i + 1].second - _values[i].second) * (rotateSpeed - _values[i].second) + _values[i].first;
    }
    return 0.0;
}

InternalCombustionEngine::InternalCombustionEngine(std::vector<std::string> &values, double rotationAccuracy) : GeneralEngine(rotationAccuracy) {
    _I = std::stod(*values.begin());
    _overheatTemperature = std::stod(*(values.begin() + 1));
    _C = std::stod(*(values.begin() + 2));
    int arrLength = std::stoi(*(values.begin() + 3));
    std::vector<double> M(arrLength);
    std::vector<double> V(arrLength);
    auto iter = values.begin() + 4;
    for (size_t i(0); i < arrLength; ++i) {
        this->_values.emplace_back(std::stod(*iter), std::stod(*(iter + arrLength)));
        ++iter;
    }
    _H_m = std::stod(*(values.rbegin() + 1));
    _H_v = std::stod(*(values.rbegin()));
    _isCommited = true;
    a = 0.0;
}

void InternalCombustionEngine::UpdateStage(double dT, double outsideTemperature) {
    _currentTimeStage += dT;

    a = getTorqueAt(_currentRotateSpeed) / _I;

    if (a >= 1e-7) _isSpinning = true;
    else _isSpinning = false;

    _currentRotateSpeed += a * dT;

    double engineHeatSpeed = getTorqueAt(_currentRotateSpeed) * _H_m + _currentRotateSpeed * _currentRotateSpeed * _H_v;
    double engineCoolSpeed = _C * (GetTemperature() - outsideTemperature);

    _currentTemperature += (engineHeatSpeed - engineCoolSpeed) * dT;

    _currentPower = getTorqueAt(_currentRotateSpeed) * _currentRotateSpeed / 1'000.0;
}