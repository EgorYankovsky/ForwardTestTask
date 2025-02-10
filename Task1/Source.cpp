#include "MainHeader.h"

int main() {
    auto values = FileStreamer::Read(configurationFile);
    commitData(&values);
    return 0;
}

void commitData(std::vector<std::string> *_values) {
    I = std::stod(*_values->begin());
    T_overheat = std::stod(*(_values->begin() + 1));
    C = std::stod(*(_values->begin() + 2));
    int arrLength = std::stoi(*(_values->begin() + 3));
    M.resize(arrLength);
    V.resize(arrLength);
    auto iter = _values->begin() + 4;
    for (size_t i(0); i < arrLength; ++i) {
        M[i] = std::stod(*iter);
        V[i] = std::stod(*(iter + arrLength));
        ++iter;
    }
    H_m = std::stod(*(_values->rbegin() + 1));
    H_v = std::stod(*(_values->rbegin()));
}