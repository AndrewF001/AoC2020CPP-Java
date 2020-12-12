#include "Day12.h"
#include "UsefulMethods.h"

Day12::Day12() :DefaultClass(12, true)
{
	inp = FR.ReadLine();
	Part1();
	TimeResetClock();
	Part2();
	TimeClock();
}

int Day12::DegreeToTurn(int degree)
{
	if (degree == 90)
		return 1;
	else if (degree == 180)
		return 2;
	else if (degree == 270)
		return 3;
	return 0;
}

void Day12::Part1()
{
	int x = 0, y = 0;
	int facing = 1;
	int num;
	for (int i = 0; i < inp.size(); i++)
	{
		num = std::stoi(inp[i].substr(1));
		switch (inp[i][0])
		{
		case('F'):
			if (facing == 0)
				y += num;
			else if (facing == 1)
				x += num;
			else if (facing == 2)
				y -= num;
			else if (facing == 3)
				x -= num;
			break;
		case('R'):
			facing += DegreeToTurn(num);
			if (facing > 3)
				facing -= 4;
			break;
		case('L'):
			facing -= DegreeToTurn(num);
			if (facing < 0)
				facing += 4;
			break;
		case('N'):
			y += num;
			break;
		case('S'):
			y -= num;
			break;
		case('E'):
			x += num;
			break;
		case('W'):
			x -= num;
			break;
		}
	}
	std::cout << "Part1: " << UsefulMethods::ManhattenDistance(0, 0, x, y)<<"\n";
}

void Day12::Part2()
{
	int x = 0, y = 0;
	int Wx = 10, Wy = 1;
	int facing = 1;
	int num;
	for (int i = 0; i < inp.size(); i++)
	{
		num = std::stoi(inp[i].substr(1));
		switch (inp[i][0])
		{
		case('F'):
			for (int c = 0; c < num; c++)
			{
				x += Wx;
				y += Wy;
			}
			break;
		case('R'):
			for (int c = 0; c < DegreeToTurn(num); c++)
			{
				int temp = Wx;
				Wx = Wy;
				Wy = -1*temp;
			}
			break;
		case('L'):
			for (int c = 0; c < DegreeToTurn(num); c++)
			{
				int temp = Wx;
				Wx = -1 * Wy;
				Wy = temp;
			}
			break;
		case('N'):
			Wy += num;
			break;
		case('S'):
			Wy -= num;
			break;
		case('E'):
			Wx += num;
			break;
		case('W'):
			Wx -= num;
			break;
		}
	}
	std::cout << "Part1: " << UsefulMethods::ManhattenDistance(0, 0, x, y) << "\n";
}