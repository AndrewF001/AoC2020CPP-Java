#pragma once
#include "DefaultClass.h"
class Day5 :
    public DefaultClass
{
private:
    bool Plane[128][8] = {};
    void Part1();
    void Part2();
    void Insert(std::string*);
    int BinarySearch(char*,int,int);
public:
    Day5();
};

