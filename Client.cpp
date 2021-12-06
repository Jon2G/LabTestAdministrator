#include "Client.h"

Client::Client(int index,std::string curp,
	std::string name,
	std::string birthday,
	char gender,
	Doctor doctor, int Visible) :User(curp, name, Visible)
{
	this->Index = index;
	this->CURP = curp;
	this->Name = name;
	this->Birthday = birthday;
	this->Gender = gender;
	this->doctor = doctor;
}
Client::Client() { this->Index = -1; }
Client::~Client() {}
void Client::Print() {
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t#" << this->Index+1 << std::endl;
	std::cout << "\tCURP: " << this->CURP << std::endl;
	std::cout << "\tNOMBRE: " << this->Name << std::endl;
	std::cout << "\tFECHA NACIMIENTO: " << this->Birthday << std::endl;
	std::cout << "\tSEXO: " << this->Gender << std::endl;
	std::cout << "\tDOCTOR: " << this->doctor.Name << std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}
