#include "Admin.h"
Admin::Admin(std::string id,
	std::string name) :User(id.c_str(), name.c_str(),1)
{

}
Admin::~Admin() {}