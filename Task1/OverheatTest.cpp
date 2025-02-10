#include "OverheatTest.h"

void OverheatTest::Run() {
    if (!isPreparedForRunning) {
        exit(-1);
    }
    double deltTime = (tn - t0) / ta;
    eng->SetBeginningParameters(t0, outdoorTemperature, 0.0);
    while (eng->GetCurrentTime() < tn and !eng->isOverheated()) {
        eng->UpdateStage(deltTime, outdoorTemperature);
    }
    std::cout << eng->GetTemperature() << " " << eng->GetCurrentTime() << std::endl;
}
