#pragma once

#include <stdexcept>

#include "IOStreamer/FileStreamer.h"
#include "Engine/InternalCombustionEngine.h"
#include "Test/OverheatTest.h"
#include "Test/PowerTest.h"

// Input data.
namespace globalsInput {
    extern double g_outsideTemperature;
    extern double g_experimentTime;
    extern size_t g_timeLayersAmount;
}