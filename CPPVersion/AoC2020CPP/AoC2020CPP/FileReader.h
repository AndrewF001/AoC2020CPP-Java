#pragma once

#include <fstream>
#include <iostream>
#include <vector>


class FileReader
{
public:
	FileReader();
	FileReader(std::string);
	std::string ReadStraight();
	std::vector<std::string> ReadLine();
	std::vector<int> ReadInts();
	std::vector<int> ReadInts(std::vector<std::string>);
	std::vector<std::string> SplitString(char);
	std::vector<std::string> SplitString(std::string, char);
	void PrintFiles();
	std::string ReplaceChar(std::string str, char Look, char Replace);

private:
	bool OpenFile();
	void CloseFile();
	std::ifstream Reader;
	std::string FileName;
	

};

