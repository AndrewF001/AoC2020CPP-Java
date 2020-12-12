#pragma once
#include "DefaultClass.h"
class Day12 :
    public DefaultClass
{
public:
    Day12();

private:
    std::vector<std::string> inp = std::vector<std::string>();
    void Part1();
    void Part2();
    int DegreeToTurn(int);
};

