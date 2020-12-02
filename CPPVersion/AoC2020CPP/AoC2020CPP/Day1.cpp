#include "Day1.h"

Day1::Day1() : DefaultClass(1, true)
{
    std::vector<int> input = FR.ReadInts();
    ResetClock();
    for (int i = 0; i < input.size(); i++) {
        for (int j = i + 1; j < input.size(); j++) {
            if (input[i] + input[j] == 2020)
            {
                std::cout << (input[i] * input[j]) << "\n";
                break;
            }
        }
    }
    TimeClock();
    ResetClock();
    for (int i = 0; i < input.size() - 2; i++) {
        for (int j = i + 1; j < input.size() - 1; j++) {
            for (int k = j + 1; k < input.size(); k++) {
                if (input[k] + input[j] + input[i] == 2020)
                {
                    std::cout << (input[k] * input[j] * input[i]) << "\n";
                    break;
                }
            }
        }
    }
    TimeClock();
}