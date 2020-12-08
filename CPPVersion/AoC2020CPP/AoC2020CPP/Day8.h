#pragma once
#include "DefaultClass.h"
class Day8 :
    public DefaultClass
{
public:
    Day8();

private:
    void Part1();
    void Part2();
    bool DidTerminate();
    bool NotInstruct(int);
    std::vector<int> Opper;
    std::vector<int> Instruct;
    int acc = 0;

};

