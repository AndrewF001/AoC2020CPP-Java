#include "Day5.h"

Day5::Day5() : DefaultClass(5, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	for (int i = 0; i < inp.size(); i++)
	{
		Insert(&inp[i]);
	}
	ResetClock();
	Part1();
	TimeClock();
	ResetClock();
	Part2();
	TimeClock();
}

void Day5::Insert(std::string* str)
{
	FR.ReplaceChar(str, 'R', 'B');
	FR.ReplaceChar(str, 'L', 'F');
	Plane[BinarySearch(&str->at(0), 0, 127)][BinarySearch(&str->at(7), 0, 7)]=true;
}

int Day5::BinarySearch(char* C, int min, int max)
{
	if (min == max)
		return max;
	else
	{
		if (*C == 'F')
		{
			return BinarySearch(C + 1, min, max - ((max - min) / 2 + 1));
		}
		else if (*C == 'B')
		{
			return BinarySearch(C + 1, min + ((max - min) / 2 + 1), max);
		}			
	}
}

void Day5::Part1()
{
	for (int i = 127; i > -1; i--)
	{
		for (int j = 7; j > -1; j--)
		{
			if(Plane[i][j])
			{
				std::cout<< "Part1: " << (i * 8 + j)<<"\n";
				return;
			}
		}
	}
}

void Day5::Part2()
{
	bool check = false;
	for (int i = 0; i < 127; i++)
	{
		for (int j= 0; j < 8; j++)
		{
			if (!Plane[i][j] && check)
			{
				std::cout << "Part1: " << (i * 8 + j) << "\n";
				return;
			}
			else if (Plane[i][j])
				check = true;
		}
	}
}