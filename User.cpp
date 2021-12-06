#include "User.h"
User::User() {}

User::User(std::string id,
	std::string name, int Visible) {
	this->Id = id;
	this->Name = name;
	this->Visible = Visible;
}

User::~User()
{
}

