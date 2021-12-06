#pragma once
#include "User.h"
class Admin :public User
{
public:
	Admin(std::string id,
		std::string name);
	~Admin();

private:

};