#include "DefaultClass.h"
#include "DayClasses.h"

int main()
{
    std::cout << "Andrew F Advent of Code C++ Program\n\n";
    std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();


    DefaultClass* program = new Day1();
    delete program;
    program = new Day2();
    delete program;
    program = new Day3();
    delete program;
    program = new Day4();
    delete program;
    program = new Day5();
    delete program;
    program = new Day6();
    delete program;
    program = new Day7();
    delete program;
    program = new Day8();
    delete program;
    program = new Day9();
    delete program;

    std::cout << "\nThe entire program took: ";
    std::chrono::high_resolution_clock::duration dur = std::chrono::high_resolution_clock::now() - Start;
    std::cout << dur.count() << " nanoseconds    :    " << (double)dur.count() / 1000000 << " milliseconds\n";

    char x;
    std::cin>>x;
}


