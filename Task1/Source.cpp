#include "MainHeader.h"

int main() {
    auto values = FileStreamer::Read(configurationFile);
    GeneralEngine* eng = new InternalCombustionEngine(values);
    
    std::cout << "Enter outside temperature value: ";
    std::cin >> T_outside;

    std::cout << "Enter time interval: ";
    std::cin >> T_0 >> T_n;

    std::cout << "Enter time interval splits amount: ";
    std::cin >> T_amount;

    GeneralTest* test1 = new OverheatTest(eng, T_outside, T_0, T_n, T_amount);
    test1->Run();



    delete eng;
    delete test1;
    return 0;
}