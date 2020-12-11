#include "Day11.h"

Day11::Day11() :DefaultClass(11, true)
{
	Layout = FR.ReadCharGrid();
	for (int i = 0; i < Layout.size(); i++)
	{
		for (int c = 0; c < Layout[0].size(); c++)
		{
			if (Layout[i][c] == 'L')
				Layout[i][c] = '#';
		}
	}
	TimeResetClock();
	Part1();
	TimeResetClock();
	Part2();
	TimeClock();
}

void Day11::Part1()
{
	Grid = Layout;
	while (SimulatePart1());
	std::cout << "Part1: " << NumOccupiedSeats() << "\n";
}

void Day11::Part2()
{
	Grid = Layout;
	while (SimulatePart2());
	std::cout << "Part2: " << NumOccupiedSeats() << "\n";
}

int Day11::NumOccupiedSeats()
{
	int sum = 0;
	for (int i = 0; i < Grid.size(); i++)
	{
		for (int c = 0; c < Grid[0].size(); c++)
		{
			if (Grid[i][c] == '#')
				sum++;
		}
	}
	return sum;
}

bool Day11::SimulatePart1()
{
	std::vector<std::vector<char>> Grid2 = std::vector<std::vector<char>>();
	bool change = false;
	for (int i = 0; i < Grid.size(); i++)
	{
		Grid2.push_back(std::vector<char>());
		for (int c = 0; c < Grid[0].size(); c++)
		{
			if (Grid[i][c] == 'L')
			{
				if (ChangeLPart1(c, i))
				{
					Grid2[i].push_back('#');
					change = true;
				}
				else
					Grid2[i].push_back('L');
			}
			else if (Grid[i][c] == '#')
			{
				if (ChangeHashPart1(c, i))
				{
					Grid2[i].push_back('L');
					change = true;
				}
				else
					Grid2[i].push_back('#');
			}
			else
				Grid2[i].push_back('.');
		}
	}
	Grid = Grid2;
	return change;
}

bool Day11::ChangeLPart1(int x, int y)
{
	for (int i = -1; i < 2; i++)
	{
		for (int c = -1; c < 2; c++)
		{
			if (x + c > -1 && x + c<Grid[0].size() && y + i>-1 && y + i < Grid.size())
			{
				if (Grid[y + i][x + c] == '#')
					return false;
			}
		}
	}
	return true;
}

bool Day11::ChangeHashPart1(int x, int y)
{
	int sum=0;
	for (int i = -1; i < 2; i++)
	{
		for (int c = -1; c < 2; c++)
		{
			if (x + c > -1 && x + c<Grid[0].size() && y + i>-1 && y + i < Grid.size())
			{
				if (Grid[y + i][x + c] == '#')
					sum++;
			}
		}
	}
	return sum > 4;
}

bool Day11::SimulatePart2()
{
	std::vector<std::vector<char>> Grid2 = std::vector<std::vector<char>>();
	bool change = false;
	for (int i = 0; i < Grid.size(); i++)
	{
		Grid2.push_back(std::vector<char>());
		for (int c = 0; c < Grid[0].size(); c++)
		{
			if (Grid[i][c] == 'L')
			{
				if (ChangeLPart2(c, i))
				{
					Grid2[i].push_back('#');
					change = true;
				}
				else
					Grid2[i].push_back('L');
			}
			else if (Grid[i][c] == '#')
			{
				if (ChangeHashPart2(c, i))
				{
					Grid2[i].push_back('L');
					change = true;
				}
				else
					Grid2[i].push_back('#');
			}
			else
				Grid2[i].push_back('.');
		}
	}
	Grid = Grid2;
	return change;
}

bool Day11::ChangeLPart2(int x, int y)
{
	int sum = CheckAxis(x, y);
	sum += CheckDiagonal(x, y);
	return sum == 0;
}

bool Day11::ChangeHashPart2(int x, int y)
{
	int sum = CheckAxis(x, y);
	sum += CheckDiagonal(x, y);
	return sum > 4;
}

int Day11::CheckAxis(int x, int y)
{
	int sum = 0;
	int x1=x, y1=y;
	if (x != 0)
	{
		x1 = x - 1;
		while (x1 > 0 && Grid[y][x1] == '.')
			x1--;
		if (Grid[y][x1] == '#')
			sum++;
	}
	if (x != Grid[0].size() - 1)
	{
		x1 = x + 1;
		while (x1 < Grid[0].size() -1 && Grid[y][x1] == '.')
			x1++;
		if (Grid[y][x1] == '#')
			sum++;
	}
	if (y != 0)
	{
		x1 = x;
		y1 = y - 1;
		while (y1 > 0 && Grid[y1][x] == '.')
			y1--;
		if (Grid[y1][x] == '#')
			sum++;
	}
	if (y != Grid.size() - 1)
	{
		x1 = x;
		y1 = y + 1;
		while (y1 < Grid.size() -1 && Grid[y1][x] == '.')
			y1++;
		if (Grid[y1][x] == '#')
			sum++;
	}
	return sum;
}

int Day11::CheckDiagonal(int x, int y)
{
	int sum = 0;
	int x1 = x, y1 = y;
	if (x != 0 && y != 0)
	{
		x1 = x - 1;
		y1 = y - 1;
		while (x1 > 0 && y1 > 0 && Grid[y1][x1] == '.')
		{
			x1--;
			y1--;
		}
		if (Grid[y1][x1] == '#')
			sum++;
	}
	if (x != Grid[0].size() - 1 && y != 0)
	{
		x1 = x + 1;
		y1 = y - 1;
		while (x1 < Grid[0].size()-1 && y1 > 0 && Grid[y1][x1] == '.')
		{
			x1++;
			y1--;
		}
		if (Grid[y1][x1] == '#')
			sum++;
	}
	if (x != Grid[0].size() - 1 && y != Grid.size() - 1)
	{
		x1 = x + 1;
		y1 = y + 1;
		while (x1 < Grid[0].size()-1 && y1 < Grid.size()-1 && Grid[y1][x1] == '.')
		{
			x1++;
			y1++;
		}
		if (Grid[y1][x1] == '#')
			sum++;
	}
	if (x != 0 && y != Grid.size() - 1)
	{
		x1 = x - 1;
		y1 = y + 1;
		while (x1 > 0 && y1 < Grid.size()-1 && Grid[y1][x1] == '.')
		{
			x1--;
			y1++;
		}
		if (Grid[y1][x1] == '#')
			sum++;
	}
	return sum;
}