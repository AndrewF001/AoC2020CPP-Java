#pragma once
#include <string.h>
#include <string>
#include <chrono>
#include <vector>
#include <iostream>

#include "FileReader.h"

class DefaultClass
{
public:
	DefaultClass(int, bool);

protected:
	std::string FileName;
	FileReader FR;
	void TimeClock();
	void ResetClock();
	void TimeResetClock();

private:
	std::chrono::high_resolution_clock::time_point Start;
	void FileNameCalc(int);


};

