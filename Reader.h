#pragma once
#include <string>
#include<iostream>
#include<vector>

class Reader
{
public:
	Reader(std::string line);
	std::string	GetString(int index);
	char GetChar(int index);
	float GetFloat(int index);
	int GetInt(int index);
	~Reader();

private:
	std::vector<std::string>* Values;
	std::vector<int> GetSeparatorIndexes(std::string s, char c);
};
