#include "MainHeader.h"
using namespace globalsInput;

constexpr const char* CONFIGURATION_FILE = "config.txt";

double globalsInput::g_outsideTemperature = 0.0;
double globalsInput::g_experimentTime = 0.0;
size_t globalsInput::g_timeLayersAmount = 0;

int main() {
    auto values = FileStreamer::Read(CONFIGURATION_FILE);
    GeneralEngine* engine = new InternalCombustionEngine(values, 1e-1);

    std::cout << "Enter outside temperature value (Celsius, float): ";
    std::cin >> g_outsideTemperature;

    std::cout << "Enter experiment time duration (sec, float): ";
    std::cin >> g_experimentTime;

    std::cout << "Enter time interval splits amount (integer): ";
    std::cin >> g_timeLayersAmount;

    GeneralTest* test1 = new OverheatTest(engine, g_experimentTime, g_timeLayersAmount, g_outsideTemperature, 1e0);
    test1->Run();

    GeneralTest* test2 = new PowerTest(engine, g_experimentTime, g_timeLayersAmount, g_outsideTemperature);
    test2->Run();

    test1->WriteResult();
    test2->WriteResult();

    delete engine;
    delete test1;
    delete test2;
    return 0;
}