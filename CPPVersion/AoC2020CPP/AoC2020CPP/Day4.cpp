#include "Day4.h"

Day4::Day4() : DefaultClass(4, true)
{
	std::vector<std::string> inp = FR.ReadLine();
	std::string temp;
	std::vector<std::string> passports;
	for (int i = 0; i < inp.size(); i++)
	{
		if (inp[i] == "")
		{
			temp.resize(temp.size() - 1);
			passports.push_back(temp);
			temp = "";
		}
		else
			temp.append(inp[i]+" ");
	}
	passports.push_back(temp);
	for (int i = 0; i < passports.size(); i++)
	{
		InputString(&passports[i]);
	}
	std::cout << "File read and extract to data type: ";
	TimeClock();
	ResetClock();
	Part1();
	TimeClock();
	ResetClock();
	Part2();
	TimeClock();
}
	
void Day4::InputString(std::string* str)
{
	 FR.ReplaceChar(str, ' ', ':');
	std::vector<std::string> arr = FR.SplitString(*str,':');
	Data.push_back(PassPort());
	for (int i = 0; i < arr.size(); i+=2)
	{
		if (arr[i] == "byr")
			Data.back().byr = arr[i + 1];
		else if (arr[i] == "iyr")
			Data.back().iyr = arr[i + 1];
		else if (arr[i] == "eyr")
			Data.back().eyr = arr[i + 1];
		else if (arr[i] == "hgt")
			Data.back().hgt = arr[i + 1];
		else if (arr[i] == "hcl")
			Data.back().hcl = arr[i + 1];
		else if (arr[i] == "ecl")
			Data.back().ecl = arr[i + 1];
		else if (arr[i] == "pid")
			Data.back().pid = arr[i + 1];
	}
}

bool Day4::IsValid(PassPort* P)
{
	int byr, iyr, eyr, hi;
	std::string hgt = P->hgt, hcl = P->hcl, ecl = P->ecl, pid = P->pid;
	if (P->byr != "")
		byr = std::stoi(P->byr);
	else
		return false;
	if (P->iyr != "")
		iyr = std::stoi(P->iyr);
	else
		return false;
	if (P->eyr != "")
		eyr = std::stoi(P->eyr);
	else
		return false;
	if (P->hgt != ""&&P->hgt.size()>3)
		hi = std::stoi(hgt.substr(0, hgt.size() - 2));
	else
		return false;

	if (byr < 1920 || byr>2002)
		return false;
	if (iyr < 2010 || iyr>2020)
		return false;
	if (eyr < 2020 || eyr >2030)
		return false;
	if (hgt[hgt.size() - 2] == 'c')
	{
		if (hi < 150 || hi>193)
			return false;
	}
	else if (hgt[hgt.size() - 2] == 'i')
	{
		if (hi < 59 || hi>76)
			return false;
	}
	if (hcl[0] != '#')
		return false;
	else
	{
		for (int i = 1; i < hcl.size(); i++)
		{
			if (!(((int)hcl[i] > 47 && (int)hcl[i] < 58) || ((int)hcl[i] > 96 && (int)hcl[i] < 103)))
				return false;
		}
	}

	if (!(ecl == "amb" || ecl == "blu" || ecl == "brn" || ecl == "gry" || ecl == "grn" || ecl == "hzl" || ecl == "oth"))
		return false;

	if (pid.size() != 9)
		return false;	
	for (int i = 0; i < pid.size(); i++)
	{
		if (!std::isdigit(pid[i]))
			return false;
	}

	return true;
}
void Day4::Part1()
{
	int sum = 0;
	for (int i = 0; i <Data.size(); i++)
	{
		PassPort* p = &Data.at(i);
		if (p->byr != "" && p->iyr != "" && p->eyr != "" && p->hgt != "" && p->hcl != "" && p->ecl != "" && p->pid != "")
			sum++;
	}
	std::cout << "Part1: " << sum<< "\n";
}
void Day4::Part2()
{
	int sum = 0;
	for (int i = 0; i < Data.size(); i++)
	{
		if (IsValid(&Data.at(i)))
			sum++;
	}
	std::cout << "Part2: " << sum << "\n";
}
