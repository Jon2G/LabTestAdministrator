
#include "Doctor.h"

Doctor::Doctor() { this->Index = -1; }
Doctor::Doctor(int index,std::string name) {
	this->Index = index;
	this->Name = name;
}
Doctor::~Doctor() {}