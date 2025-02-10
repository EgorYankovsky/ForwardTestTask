#pragma once

#include "FileStreamer.h"
#include "InternalCombustionEngine.h"
#include "OverheatTest.h"

const std::string configurationFile = "config.txt";

// Input data.
extern double T_outside;
extern double T_0;
extern double T_n;
extern size_t T_amount;