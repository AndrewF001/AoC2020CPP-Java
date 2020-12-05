#include "DefaultClass.h"

DefaultClass::DefaultClass(int day, bool ContainFile)
{
	if (ContainFile)
	{
		FileNameCalc(day);
		FR = FileReader(FileName);
	}
	Start = std::chrono::high_resolution_clock::now();
	std::cout << "\nDay " + std::to_string(day) + " Class running" << "\n";
}

void DefaultClass::FileNameCalc(int n)
{
	FileName = "Textfiles/input" +  std::to_string(n) + ".txt";
}


void DefaultClass::ResetClock()
{
	Start = std::chrono::high_resolution_clock::now();
}

void DefaultClass::TimeClock()
{
	std::chrono::high_resolution_clock::duration dur = std::chrono::high_resolution_clock::now() - Start;
	std::cout << dur.count()<<" nanoseconds    :    " <<  (double)dur.count()/1000000<< " milliseconds\n";
}

void DefaultClass::TimeResetClock()
{
	TimeClock();
	ResetClock();
}
