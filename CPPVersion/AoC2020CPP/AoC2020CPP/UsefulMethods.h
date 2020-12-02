#pragma once
#include <vector>
#include <string.h>
#include <string>
static class UsefulMethods
{
public:
	static int ManhattenDistance(int, int, int, int);
	static double ManhattenDistance(double, double, double, double);
	static double Pythagoras(int, int, int, int);
	static double Pythagoras(double, double, double, double);
	static int AreaSqr(int, int, int, int);
	static double AreaSqr(double, double, double, double);
	static std::string RemoveWhiteSpace(std::string);
	static std::string RemoveChars(std::string,char);
	static std::vector<std::string> SplitStringVector(std::string, char);
	static std::string SplitStringString(std::string, char);
};

