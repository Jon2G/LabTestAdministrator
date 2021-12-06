#pragma once
#include <string>
class Study
{
public:
	int Index;
	std::string ClientId;
	std::string LaboratoryId;
	float Result;
	std::string SampleDate;
	std::string DeliverDate;
	int IsPositive();
	Study();
	Study(int Index,std::string ClientId, std::string LaboratoryId, std::string sampleDate, std::string deliverDate,
		float result);
};

