#include "Day8.h"

Day8::Day8() : DefaultClass(8,true)
{
	std::vector<std::string> Lines = FR.ReadLine();
	for (int i = 0; i < Lines.size(); i++)
	{
		std::vector<std::string> Split = FR.SplitString(Lines.at(i), ' ');
		if (Split[0] == "jmp")
			Instruct.push_back(0);
		else if (Split[0] == "acc")
			Instruct.push_back(1);
		else
			Instruct.push_back(2);
		Opper.push_back(std::stoi(Split[1]));
	}
	ResetClock();
	Part1();
	TimeResetClock();
	Part2();
	TimeClock();	
}

bool Day8::DidTerminate()
{
	acc = 0;
	int header = 0;
	bool* visited = new bool[Instruct.size()]{};
	while (!visited[header] && header < Instruct.size() - 1)
	{
		visited[header] = true;
		if (Instruct[header] == 0)
		{
			header += Opper[header];
		}
		else if (Instruct[header] == 1)
		{
			acc += Opper[header];
			header++;
		}
		else
		{
			header++;
		}
	}
	return header > Instruct.size() - 2;
}

void Day8::Part1()
{
	DidTerminate();
	std::cout << "Part1: " << acc << "\n";
}

void Day8::Part2()
{
	for (int i = 0; i < Opper.size(); i++)
	{
		if (NotInstruct(i))
		{
			if (DidTerminate())
			{
				std::cout << "Part2: " << acc << "\n";
				return;
			}
			NotInstruct(i);
		}
	}
}

bool Day8::NotInstruct(int i)
{
	if (Instruct[i] == 0)
	{
		Instruct[i] = 2;
		return true;
	}
	else if (Instruct[i] == 2)
	{
		Instruct[i] = 0;
		return true;
	}
	return false;

}