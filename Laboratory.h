#pragma once
#include<iostream>
#include <string>
class Laboratory
{
public:
	int Index;
	std::string Id;
	std::string Name;
	int Visible;
	Laboratory();
	Laboratory(int Index,std::string Id, std::string Name,int Visible);
	void Print();
};

