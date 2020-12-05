#pragma once
#include "DefaultClass.h"
class Day4 :
    public DefaultClass
{
	struct PassPort
	{
		std::string byr="", iyr="", eyr="", hgt="", hcl="", ecl="", pid="", cid="";
	};
private:
	std::vector<PassPort> Data;
	void InputString(std::string*);
	bool IsValid(PassPort*);
	void Part1();
	void Part2();

public:
    Day4();


};

