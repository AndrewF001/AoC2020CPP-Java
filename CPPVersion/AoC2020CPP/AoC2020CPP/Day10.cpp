#include "Day10.h"

Day10::Day10() :DefaultClass(10, true)
{
	std::vector<int> Adpaters =  FR.ReadInts();
	for (int i = 0; i < Adpaters.size(); i++)
	{
		bool changes = false;
		for (int c = 0; c < Adpaters.size()-i-1; c++)
		{
			if (Adpaters[c] > Adpaters[c + 1])
			{
				int temp = Adpaters[c];
				Adpaters[c] = Adpaters[c + 1];
				Adpaters[c + 1] = temp;
				changes = true;
			}
		}
		if (!changes)
			i = Adpaters.size();
	}
	Adpaters.push_back(Adpaters[Adpaters.size() - 1] + 3);
	TimeResetClock();
	int three = 0, one = 1;
	for (int i = 1; i < Adpaters.size(); i++)
	{
		if (Adpaters[i] - Adpaters[i - 1] == 3)
			three++;
		else
			one++;
	}
	std::cout << "Part1: " << (one * three) << "\n";
	TimeResetClock();
	long long ways = 1;
	int concurrent = 1;
	for (int i = 1; i < Adpaters.size(); i++)
	{
		if (Adpaters[i] - Adpaters[i - 1] == 1)
			concurrent++;
		else if (Adpaters[i] - Adpaters[i - 1] == 3)
		{
			concurrent--;
			if (concurrent > 0)
			{
				long long x = std::pow(2, concurrent);
				if (concurrent > 2)
					x -= concurrent - 2;
				ways *= x;
			}
			concurrent = 0;
		}
	}
	concurrent--;
	if (concurrent > 0)
	{
		long long x = std::pow(2, concurrent);
		if (concurrent > 2)
			x -= concurrent - 2;
		ways *= x;
	}
	std::cout << "Part2: " << ways << "\n";
	TimeClock();
}