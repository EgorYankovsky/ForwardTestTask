#include "InternalCombustionEngine.h"

double InternalCombustionEngine::getTorqueAt(double rotateSpeed) {
    for (size_t i(0); i < values.size() - 1; ++i) {
        if (rotateSpeed < values.front().second) return values.front().first;
        if (values.back().second < rotateSpeed) return values.back().first;

        if (values[i].second <= rotateSpeed and rotateSpeed <= values[i + 1].second)
            return (values[i + 1].first - values[i].first) / (values[i + 1].second - values[i].second) * (rotateSpeed - values[i].second) + values[i].first;
    }
    return 0.0;
}


InternalCombustionEngine::InternalCombustionEngine(double I, double T_overheat, double H_m, double H_v, double C,
                                                   std::vector<double> M, std::vector<double> V) {
    this->I = I;
    this->T_overheat = T_overheat;
    this->H_m = H_m;
    this->H_v = H_v;
    this->C = C;
    this->values.resize(M.size());
    for (size_t i(0); i < M.size(); ++i)
        values.emplace_back(M[i], V[i]);
}

InternalCombustionEngine::InternalCombustionEngine(std::vector<std::string> &values) {
    this->I = std::stod(*values.begin());
    this->T_overheat = std::stod(*(values.begin() + 1));
    this->C = std::stod(*(values.begin() + 2));
    int arrLength = std::stoi(*(values.begin() + 3));
    std::vector<double> M(arrLength);
    std::vector<double> V(arrLength);
    auto iter = values.begin() + 4;
    for (size_t i(0); i < arrLength; ++i) {
        //M[i] = std::stod(*iter);
        //V[i] = std::stod(*(iter + arrLength));
        this->values.emplace_back(std::stod(*iter), std::stod(*(iter + arrLength)));
        ++iter;
    }
    H_m = std::stod(*(values.rbegin() + 1));
    H_v = std::stod(*(values.rbegin()));
}

void InternalCombustionEngine::UpdateStage(double dT, double outsideTemp) {
    timeStage += dT;

    double a = getTorqueAt(currentRotateSpeed) / I;

    currentRotateSpeed += a * dT;

    double engineHeatSpeed = getTorqueAt(currentRotateSpeed) * H_m + currentRotateSpeed * currentRotateSpeed * H_v;
    double engineCoolSpeed = C * (GetTemperature() - outsideTemp);

    currentTemperature += (engineHeatSpeed - engineCoolSpeed) * dT;
}
