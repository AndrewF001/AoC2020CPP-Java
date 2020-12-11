#pragma once
#include "DefaultClass.h"
class Day11 :
    public DefaultClass
{
public:
    Day11();

private:
    std::vector<std::vector<char>> Layout;
    std::vector<std::vector<char>> Grid;
    void Part1();
    bool SimulatePart1();
    void Part2();
    bool SimulatePart2();
    int NumOccupiedSeats();
    bool ChangeLPart1(int,int);
    bool ChangeHashPart1(int,int);
    bool ChangeLPart2(int, int);
    bool ChangeHashPart2(int, int);
    int CheckDiagonal(int, int);
    int CheckAxis(int, int);
};

