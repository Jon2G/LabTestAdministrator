#pragma once
#include "User.h"
#include "Doctor.h"
class Client :public User
{
public:
	int Index;
	std::string Curp;
	std::string Name;
	std::string CURP;
	std::string Birthday;
	char Gender;
	Doctor doctor;
	Client();
	Client(int Index,std::string curp,
		std::string name,
		std::string birthday,
		char gender,
		Doctor doctor, int Visible);
	~Client();
	void Print();

private:

};

