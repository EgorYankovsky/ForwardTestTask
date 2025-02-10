#include "FileStreamer/FileStreamer.h"

std::vector<std::string> FileStreamer::Read(std::string pathToFile) {
    std::ifstream file(pathToFile, std::ios::in | std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cout << "File to read isn't opened." << std::endl;
        exit(-1);
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    
    if (!file.read(buffer.data(), size)) {
        std::cout << "Error during file fetching" << std::endl;
        exit(-1);
    }
    file.close();

    std::vector<std::string> values;
    /*
    * -1 -> no reading
    *  0 -> delayed reading
    *  1 -> read word
    *  2 -> read number
    */
    int readMode = -1;
    std::string word;
    std::string mes;
    for (auto character : buffer) {
        switch (character) {
        case 10: // \n
            if (readMode == 2 && !word.empty()) {
                values.push_back(word);
                word = std::string();
            }
            break;
        case 13: // \r
            break;
        case 91: // [
            readMode = 1;
            if (!word.empty()) {
                values.push_back(word);
                word = std::string();
            }
            break;
        case 93: // ]
            readMode = 2;
            mes = word + " already read!";
            word = std::string();
            break;
        case 32: // (space)
            if (readMode == 1) word += character;
            if (readMode == 2 && !word.empty()) {
                values.push_back(word);
                word = std::string();
            }
            break;
        default:
            if (readMode == -1) {
                std::cout << "Failure during reading" << std::endl;
                exit(-1);
            }
            if (readMode == 0) {
                mes = "Unexpected character: " + character;
                std::cout << mes << std::endl;
            }
            if (readMode == 1 || readMode == 2) word += character;
        }
    }
    values.push_back(word);
    return values;
}
