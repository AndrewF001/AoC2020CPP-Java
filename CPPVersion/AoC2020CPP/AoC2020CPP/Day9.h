#pragma once
#include "DefaultClass.h"
class Day9 :
    public DefaultClass
{
public:
    Day9();
    
private:
    void Part1(long long*);
    void Part2();
    std::vector<long long> inp;
    long long Weakness;


};

