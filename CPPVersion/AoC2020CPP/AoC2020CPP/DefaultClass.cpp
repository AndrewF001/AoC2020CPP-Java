#include "DefaultClass.h"

DefaultClass::DefaultClass(int d, bool ContainFile)
{
	day = d;
	if (ContainFile)
	{
		FileNameCalc(day);
		FR = FileReader(FileName);
	}
	Start = std::chrono::high_resolution_clock::now();
	ConstructorStart = Start;
	std::cout << "\nDay " << day << " Class running" << "\n";
}

DefaultClass::~DefaultClass()
{
	std::cout << "Day " << day << " took: ";
	std::chrono::high_resolution_clock::duration dur = std::chrono::high_resolution_clock::now() - ConstructorStart;
	std::cout << dur.count() << " nanoseconds    :    " << (double)dur.count() / 1000000 << " milliseconds\n\n";
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
