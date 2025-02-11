#include "MainHeader.h"
using namespace globalsInput;

constexpr const char* CONFIGURATION_FILE = "config.txt";

double globalsInput::g_outsideTemperature = 0.0;
double globalsInput::g_experimentTime = 0.0;
size_t globalsInput::g_timeLayersAmount = 0;

int main() {
    try {
        auto values = FileStreamer::Read(CONFIGURATION_FILE);
        GeneralEngine* engine = new InternalCombustionEngine(values);

        std::cout << "Enter outside temperature value (Celsius, float): ";
        std::cin >> g_outsideTemperature;

        std::cout << "Enter time for experiment (sec, float): ";
        std::cin >> g_experimentTime;

        std::cout << "Enter time interval splits amount (integer): ";
        std::cin >> g_timeLayersAmount;

        GeneralTest* test1 = new OverheatTest(engine, g_experimentTime, g_timeLayersAmount, g_outsideTemperature);
        test1->Run();

        //GeneralTest* test2 = new PowerTest(engine, g_experimentTime, g_timeLayersAmount, g_outsideTemperature);
        //test2->Run();

        delete engine;
        delete test1;
        //delete test2;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}