#pragma once

#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

/**
* @brief Static class for file I/O.
*/
class FileStreamer {
public:
    FileStreamer() = delete;
    /**
    * @brief Read data from file.
    * @param pathToFile - relative path to file directory. 
    * @return std::vector<std::string> - vector of integers or floats.
    */
    static std::vector<std::string> Read(std::string pathToFile);
    static void Write(std::string pathToFile);
};

