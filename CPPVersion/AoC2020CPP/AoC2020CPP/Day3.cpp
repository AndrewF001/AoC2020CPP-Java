#include "Day3.h"
#include <iostream>

Day3::Day3() :DefaultClass(3, true)
{
	inp = FR.ReadLine();
	ResetClock();
	std::cout << "Part1: " << SlopValue(3, 1) << "\n";
	TimeClock();
	ResetClock();
	long long sum = SlopValue(1, 1);
	sum *= SlopValue(3, 1);
	sum *= SlopValue(5, 1);
	sum *= SlopValue(7, 1);
	sum *= SlopValue(1, 2);
	std::cout << "Part2: " << sum << "\n";
	TimeClock();
}

long Day3::SlopValue(int right, int down)
{
	int sum = 0;
	int x=0;
	for (int i = 0; i < inp.size(); i+=down)
	{
		if (inp[i][x] == '#')
			sum++;
		x = (x+right) % inp[0].length();
	}
	return (long)sum;
}