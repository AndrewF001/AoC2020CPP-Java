#pragma once
#include "DefaultClass.h"
class Day6 :
    public DefaultClass
{
private:
    std::vector<std::vector<std::string*>> Groups;
    void Part1();
    void Part2();
    int NumofYes(std::vector<std::string*>*);
    int SumofYes(std::vector<std::string*>*);

public:
    Day6();

};

