#include "OverheatTest.h"

void OverheatTest::Run() {
    if (!isPreparedForRunning) {
        exit(-1);
    }
    eng->SetBeginningParameters(t0, outdoorTemperature);
    while (eng->GetCurrentTime() < tn and !eng->isOverheated()) {

    }

}
