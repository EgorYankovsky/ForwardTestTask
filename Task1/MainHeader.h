#pragma once

#include "FileStreamer.h"
#include "InternalCombustionEngine.h"
#include "OverheatTest.h"

const std::string configurationFile = "config.txt";

// Input data.
extern double T_outside = NAN;
extern double T_0 = NAN;
extern double T_n = NAN;
extern size_t T_amount = NAN;