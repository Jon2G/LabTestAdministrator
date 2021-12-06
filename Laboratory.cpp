#include "Laboratory.h"

Laboratory::Laboratory(){}
Laboratory::Laboratory(int Index,std::string Id, std::string Name, int Visible) {
	this->Index = Index;
	this->Id = Id;
	this->Name = Name;
	this->Visible = Visible;
}
void Laboratory::Print() {
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\tCLAVE: " << this->Id << std::endl;
	std::cout << "\tNOMBRE: " << this->Name << std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}