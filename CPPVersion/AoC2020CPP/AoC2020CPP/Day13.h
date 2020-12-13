#pragma once
#include "DefaultClass.h"
class Day13 :
    public DefaultClass
{
public:
    Day13();

private:
    void Part1(int);
    void Part2();
    std::vector<int> BusID = std::vector<int>();
    std::vector<std::string> BusInp = std::vector<std::string>();
    
};

