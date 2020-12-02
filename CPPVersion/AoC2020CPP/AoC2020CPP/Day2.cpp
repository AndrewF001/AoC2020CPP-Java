#include "Day2.h"
#include "UsefulMethods.h"

Day2::Day2() :DefaultClass(2, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	values.resize(inp.size());
	std::string temp;
	for (int i = 0; i < inp.size(); i++)
	{
		std::string hold = inp[i];
		for (int x = 0; x < hold.size(); x++)
		{
			if (hold[x] == '-')
			{
				values[i].Min = std::stoi(temp);
				temp = std::string();
			}
			else if (hold[x] == ':')
			{
				values[i].Max = std::stoi(temp.substr(0, temp.size() - 2));
				values[i].C = temp[temp.size() - 1];
				values[i].password = hold.substr(x + 2, hold.size() - 1);
				temp = std::string();
				break;
			}
			else
			{
				temp.append(std::string(1,hold[x]));
			}
		}
	}
	
	int sum=0;
	for (int i = 0; i < inp.size(); i++)
	{
		if (Part1(i))
			sum++;
	}
	std::cout << "Part1: " << sum << "\n";
	sum = 0;
	for (int i = 0; i < inp.size(); i++)
	{
		if (Part2(i))
			sum++;
	}
	std::cout << "Part2: " << sum<< "\n";
	TimeClock();
}

bool Day2::Part1(int n)
{
	int sum=0;
	std::string temp = values[n].password;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == values[n].C)
			sum++;
	}
	return(sum > values[n].Min - 1 && sum < values[n].Max + 1);
}

bool Day2::Part2(int i)
{
	return ((values[i].password[values[i].Min - 1] == values[i].C) ^ (values[i].password[values[i].Max - 1] == values[i].C));
}