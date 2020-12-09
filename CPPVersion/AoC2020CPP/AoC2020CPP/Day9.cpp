#include "Day9.h"

Day9::Day9() : DefaultClass(9, true)
{
	inp = FR.ReadLong();
	long long* arr = new long long[25];
	for (int i = 0; i < 25; i++)
	{
		arr[i] = inp[i];
	}
	ResetClock();
	Part1(&arr[0]);
	TimeResetClock();
	Part2();
	TimeClock();
}

void Day9::Part1(long long* arr)
{
	int Itterator = 0;
	bool valid = false;
	for (int i = 25; i < inp.size(); i++)
	{
		valid = false;
		for (int j = 0; j < 25; j++)
		{
			if (*(arr+j) < inp[i])
			{
				for (int c = 0; c < 25; c++)
				{
					if (c != j)
					{
						if (*(arr+c) + *(arr+j) == inp[i])
						{
							c = 25;
							j = 25;
							valid = true;
						}					
					}
				}
			}
		}
		if (!valid)
		{
			Weakness = inp[i];
			std::cout << "Part1: " << inp[i] << "\n";
			return;
		}
		*(arr+Itterator) = inp[i];
		Itterator = (Itterator + 1) % 25;
	}
}

void Day9::Part2()
{
	long long sum=0;
	long long smallest = 0, largest = 0;
	for (int i = 0; i < inp.size(); i++)
	{
		sum = inp[i];
		for (int j = i+1; j < inp.size(); j++)
		{
			sum += inp[j];
			if (sum == Weakness)
			{
				smallest = inp[i];
				largest = inp[i];
				for (int c = i+1; c < j+1; c++)
				{
					if (inp[c] < smallest)
						smallest = inp[c];
					else if (inp[c] > largest)
						largest = inp[c];
				}
				std::cout << "Part2: " << largest + smallest << "\n";
				return;
			}
			else if (sum > Weakness)
			{
				j = inp.size();
			}
		}
	}
}