#pragma once

#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

class FileStreamer {
public:
    FileStreamer() = delete;
    static std::vector<std::string> Read(std::string pathToFile);
    static void Write(std::string pathToFile);
};

