#pragma once

#include "FileStreamer/FileStreamer.h"

const std::string configurationFile = "config.txt";

// Input data.
extern double I = 0.0;
extern double T_overheat = 0.0;
extern double C = 0.0;
extern double H_m = 0.0;
extern double H_v = 0.0;

extern std::vector<double> M{};
extern std::vector<double> V{};


void commitData(std::vector<std::string> *_values);