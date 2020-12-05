#include "DefaultClass.h"
#include "DayClasses.h"

int main()
{
    std::cout << "Andrew F Advent of Code C++ Program\n\n";
    std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();


    DefaultClass program = Day1();
    program = Day2();
    program = Day3();
    program = Day4();
    program = Day5();


    std::cout << "\nThe entier program took: ";
    std::chrono::high_resolution_clock::duration dur = std::chrono::high_resolution_clock::now() - Start;
    std::cout << dur.count() << " nanoseconds    :    " << (double)dur.count() / 1000000 << " milliseconds\n";

    char x;
    std::cin>>x;
}


