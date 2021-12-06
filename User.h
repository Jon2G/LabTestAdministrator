#pragma once
#include<iostream>

class User
{
public:
	std::string Id;
	std::string Name;
	int Visible;
	User();
	User(std::string id, std::string name, int Visible);
	virtual ~User();

private:

};
