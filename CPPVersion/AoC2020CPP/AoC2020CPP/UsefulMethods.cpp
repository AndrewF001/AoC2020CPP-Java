#include "UsefulMethods.h"
#include <iostream>
#include <math.h>

int UsefulMethods::ManhattenDistance(int x1, int y1, int x2, int y2)
{
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

double UsefulMethods::ManhattenDistance(double x1, double  y1, double  x2, double  y2)
{
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

double UsefulMethods::Pythagoras(int x1, int y1, int x2, int y2)
{
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

double UsefulMethods::Pythagoras(double x1, double  y1, double  x2, double  y2)
{
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int UsefulMethods::AreaSqr(int x1, int y1, int x2, int y2)
{
	return std::abs(x1 - x2) * std::abs(y1 - y2);
}

double UsefulMethods::AreaSqr(double x1, double  y1, double  x2, double  y2)
{
	return std::abs(x1 - x2) * std::abs(y1 - y2);
}

std::string UsefulMethods::RemoveWhiteSpace(std::string str)
{
	std::string out;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
			out.append(std::string(1, str[i]));
	}
	return out;
}

std::string UsefulMethods::RemoveChars(std::string str, char c)
{
	std::string out;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != c)
			out.append(std::string(1, str[i]));
	}
	return out;
}

std::vector<std::string> UsefulMethods::SplitStringVector(std::string str, char C)
{
	std::vector<std::string> out;
	std::string temp;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == C)
		{
			out.push_back(temp);
			temp = std::string();
		}
		else
			temp.append(std::string(1, str[i]));
	}
	out.push_back(temp);
	return out;
}

std::string UsefulMethods::SplitStringString(std::string str, char C)
{
	std::string temp;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == C)
		{
			return temp;
		}
		else
		{
			temp.append(std::string(1, str[i]));
		}
	}
	return str;
}