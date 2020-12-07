#pragma once
#include "DefaultClass.h"
class Day2 :
    public DefaultClass
{
private:
    class Data {
    public:
        int Min;
        int Max;
        char C;
        std::string password;
    };
    std::vector<Data> values;
    bool Part1(int);
    bool Part2(int);


public:
    Day2();
};

