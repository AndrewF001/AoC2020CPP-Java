#include "FileReader.h"
#include <string>
#include <sstream>


FileReader::FileReader()
{
	FileName = "input.txt";
}

FileReader::FileReader(std::string FN)
{
	FileName = FN;
	Reader = std::ifstream(FileName);
	if (Reader.fail())
		throw std::invalid_argument("File does not exist in currect file path");
	Reader.close();
}

bool FileReader::OpenFile()
{
	Reader.open(FileName);
	if (!Reader)
	{
		std::cerr << "File does no exist in currect path";
		exit(1);
	}
	return true;
}

void FileReader::CloseFile()
{
	Reader.close();
}

std::string FileReader::ReadStraight()
{
	OpenFile();
	std::stringstream buffer;
	buffer << Reader.rdbuf();
	CloseFile();
	return buffer.str();
}

std::vector<std::string> FileReader::ReadLine()
{
	std::vector<std::string> out;
	std::string temp;
	OpenFile();
	while (std::getline(Reader, temp))
		out.push_back(temp);
	CloseFile();
	return out;
}

std::vector<int> FileReader::ReadInts()
{
	int x;
	std::vector<int> out;
	OpenFile();
	while (Reader >> x)
		out.push_back(x);
	CloseFile();
	return out;
}

std::vector<int> FileReader::ReadInts(std::vector<std::string> inp)
{
	std::vector<int> out;
	for (std::string x : inp)
		out.push_back(std::stoi(x));
	return out;
}

std::vector<std::string> FileReader::SplitString(char delimiter)
{
	char c;
	std::string temp = "";
	std::vector<std::string> out;
	OpenFile();
	while (c = Reader.get())
	{
		if (c == delimiter)
		{
			out.push_back(temp);
			temp.clear();
		}
		else
		{
			temp.append(std::string(1,c));
		}
	}
	out.push_back(temp);
	return out;
}

std::vector<std::string> FileReader::SplitString(std::string str, char delimiter)
{
	std::string temp = "";
	std::vector<std::string> out;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == delimiter)
		{
			out.push_back(temp);
			temp.clear();
		}
		else
		{
			temp.append(std::string(1, str[i]));
		}
	}	
	out.push_back(temp);
	return out;
}

std::string FileReader::ReplaceChar(std::string str, char Look, char Change)
{
	std::string out;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == Look)
			out.append(std::string(1,Change));
		else
			out.append(std::string(1, str[i]));
	}
	return out;
}

void FileReader::PrintFiles()
{

}