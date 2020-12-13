#include "Day13.h"

Day13::Day13() : DefaultClass(13, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	BusInp = FR.SplitString(inp[1], ',');
	for (int i = 0; i < BusInp.size(); i++)
	{
		if (BusInp[i] != "x")
			BusID.push_back(std::stoi(BusInp[i]));
	}
	ResetClock();
	Part1(std::stoi(inp[0]));
	TimeResetClock();
	Part2();
	TimeClock();

}

void Day13::Part1(int Arrival)
{
	int ID = 0, Wait = INT16_MAX;
	for (int i = 0; i < BusID.size(); i++)
	{
		int temp = BusID[i] * (Arrival / BusID[i] + 1) - Arrival;
		if (temp < Wait)
		{
			Wait = temp;
			ID = BusID[i];
		}
	}
	std::cout << "Part1: " << Wait * ID<<"\n";
}

void Day13::Part2()
{
	int minute = 0;
	std::vector<int> CRH = std::vector<int>();
	int x = 0;
	for (int i = 0; i < BusInp.size(); i++)
	{
		if (BusInp[i] != "x")
		{
			CRH.push_back(BusID[x] - (minute % BusID[x]));
			x++;
		}
		minute++;
	}
	long long timestamp = 0;
	long long multiplier = BusID[0];
	for (int i = 1; i < BusID.size(); i++)
	{	
		while ((timestamp % BusID[i]) != CRH[i])
			timestamp += multiplier;
		multiplier *= BusID[i];
	}
	std::cout << "Part2: " << timestamp << "\n";
}