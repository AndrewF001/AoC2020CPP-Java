#include "Day6.h"

Day6::Day6() : DefaultClass(6, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	int count = 0;
	Groups.push_back(std::vector<std::string*>());
	for (int i = 0; i < inp.size(); i++)
	{
		if (inp[i] == "")
		{
			count++;
			Groups.push_back(std::vector<std::string*>());
		}
		else
			Groups[count].push_back(&inp[i]);
	}
	std::cout << "File Reader and format";
	TimeResetClock();
	Part1();
	TimeResetClock();
	Part2();
	TimeClock();
}

void Day6::Part1()
{
	int sum = 0;
	for (int i = 0; i < Groups.size(); i++)
	{
		sum += NumofYes(&Groups[i]);
	}
	std::cout << "Part1: " << sum<<"\n";
}

void Day6::Part2()
{
	int sum = 0;
	for (int i = 0; i < Groups.size(); i++)
	{
		sum += SumofYes(&Groups[i]);
	}
	std::cout << "Part2: " << sum << "\n";

}

int Day6::NumofYes(std::vector<std::string*>* group)
{
	bool Letters[27] = {};
	for (int i = 0; i < group->size(); i++)
	{
		for (int j = 0; j < group->at(i)->size(); j++)
		{
			Letters[(int)group->at(i)->at(j) - 97] = true;
		}
	}
	int sum = 0;
	for (int i = 0; i < 27; i++)
	{
		if(Letters[i])
			sum++;
	}
	return sum;
}

int Day6::SumofYes(std::vector<std::string*>* group)
{
	int Letters[27] = {};
	for (int i = 0; i < group->size(); i++)
	{
		for (int j = 0; j < group->at(i)->size(); j++)
		{
			Letters[(int)group->at(i)->at(j) - 97]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < 27; i++)
	{
		if (Letters[i]==group->size())
			sum++;
	}
	return sum;
}