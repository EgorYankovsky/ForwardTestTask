#pragma once

#include "FileStreamer.h"
#include "InternalCombustionEngine.h"
#include "OverheatTest.h"
#include "PowerTest.h"

// Input data.
namespace globalsInput {
    extern double g_outsideTemperature;
    extern double g_experimentTime;
    extern size_t g_timeLayersAmount;
}