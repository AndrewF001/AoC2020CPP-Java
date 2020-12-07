#include "Day7.h"

Day7::Day7() :DefaultClass(7, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	for (int i = 0; i < inp.size(); i++)
	{
		CipherLine(inp[i]);
	}

	ResetClock();
	Part1();
	TimeResetClock();
	Part2();
	TimeClock();
}

void Day7::CipherLine(std::string Line)
{
	std::vector<std::string> Split = FR.SplitString(Line, ' ');
	OuterBag.push_back(BagLookUp(Split[0] + Split[1]));
	NumBagsContains.push_back(std::vector<int>());
	ContainBags.push_back(std::vector<int>());
	Visited.push_back(false);
	if (Split[4] == "no")
		return;
	for (int i = 4; i < Split.size(); i += 4)
	{
		NumBagsContains.at(NumBagsContains.size() - 1).push_back(std::stoi(Split[i]));
		ContainBags.at(ContainBags.size() - 1).push_back(BagLookUp(Split[i + 1] + Split[i + 2]));
	}
}

int Day7::BagLookUp(std::string colour)
{
	for (int i = 0; i < LookUp.size(); i++)
	{
		if (colour == LookUp[i])
			return i;
	}
	LookUp.push_back(colour);
	return LookUp.size() - 1;
}
void Day7::Part1()
{
	std::vector<int> Lookfor;
	std::vector<int> NextLookfor;
	Lookfor.push_back(BagLookUp("shinygold"));
	int sum = 0;
	while (!Lookfor.empty())
	{
		for (int i = 0; i < ContainBags.size(); i++)
		{
			if (!Visited.at(i))
			{
				if (IsContained(&ContainBags.at(i), &Lookfor))
				{
					NextLookfor.push_back(OuterBag.at(i));
					Visited.at(i) = true;
					sum++;
				}
			}
		}
		Lookfor = NextLookfor;
		NextLookfor.clear();
	}
	std::cout << "Part1: " << sum<<"\n";
}

bool Day7::IsContained(std::vector<int>* Contained, std::vector<int>* Lookfor)
{
	for (int i = 0;  i < Contained->size();  i++)
	{
		for (int j = 0; j < Lookfor->size(); j++)
		{
			if (Contained->at(i) == Lookfor->at(j))
				return true;
		}
	}
	return false;
}

void Day7::Part2()
{
	int x = BagLookUp("shinygold");
	std::cout << "Part2: " << NumBags(x)<<"\n";
}

int Day7::NumBags(int pos)
{
	int sum = 0;
	for (int i = 0; i < OuterBag.size(); i++)
	{
		if (OuterBag.at(i) == pos)
		{
			if (ContainBags.at(i).empty())
				return 0;
			else
			{
				for (int j = 0; j < ContainBags.at(i).size(); j++)
				{
					sum += (NumBagsContains.at(i).at(j) * (NumBags(ContainBags.at(i).at(j)) + 1));
				}
			}
		}
	}
	return sum;
}
