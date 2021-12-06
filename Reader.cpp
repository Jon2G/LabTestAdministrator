#include "Reader.h"
Reader::Reader(std::string line)
{
	Values = new std::vector<std::string>();
	std::vector<int> index = GetSeparatorIndexes(line, '|');
	for (int i = 0; i < index.size() - 1; i++)
	{
		int start = index.at(i) + 1;
		int end = index.at(i + 1);
		if (start == end) {
			Values->push_back("");
			continue;
		}
		std::string value = line.substr(start, end-start);
		Values->push_back(value);
	}
}
char Reader::GetChar(int index) {
	return GetString(index)[0];
}
int Reader::GetInt(int index) {
	std::string value = GetString(index);
	return std::stoi(value);
}
float Reader::GetFloat(int index) {
	std::string value = GetString(index);
	return std::stoi(value);
}
std::string	Reader::GetString(int index)
{
	return Values->at(index);
}
std::vector<int> Reader::GetSeparatorIndexes(std::string s, char c) {
	std::vector<int> vecky;
	for (int i = 0; i != s.length(); i++)
	{
		if (s[i] == c)
		{
			vecky.push_back(i);
		}
	}
	return vecky;
}
Reader::~Reader()
{
}
