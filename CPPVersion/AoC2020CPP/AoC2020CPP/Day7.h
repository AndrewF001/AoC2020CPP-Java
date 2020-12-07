#pragma once
#include "DefaultClass.h"
class Day7 :
    public DefaultClass
{
private:
    std::vector<std::string> LookUp;
    std::vector<int> OuterBag;
    std::vector<std::vector<int>> ContainBags;
    std::vector<std::vector<int>> NumBagsContains;
    std::vector<bool> Visited;
    void CipherLine(std::string);
    void Part1();
    void Part2();
    int BagLookUp(std::string);
    bool IsContained(std::vector<int>* Contained, std::vector<int>* Lookfor);
    int NumBags(int);

public:
    Day7();
};

