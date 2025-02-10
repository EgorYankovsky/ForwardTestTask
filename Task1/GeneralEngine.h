#pragma once

#include <vector>
#include <algorithm>

class GeneralEngine {
protected:
    bool isCommited = false;
    double I = 0.0;
    double T_overheat = 0.0;
    double H_m = 0.0;
    double H_v = 0.0;
    double C = 0.0;
    double timeStage = 0.0;
    double currentTemperature = 0.0;
    std::vector<std::pair<double, double>> values{};
public:
    GeneralEngine() {};
    ~GeneralEngine() {};
    inline double GetTemperature() const { return currentTemperature; }
    inline double GetCurrentTime() const { return timeStage; }
    inline double isOverheated() const { return currentTemperature >= T_overheat; }
    void SetBeginningParameters(double time0, double temperature0) { timeStage = time0; currentTemperature = temperature0; }
    virtual void UpdateStage(double dT) = 0;
};

