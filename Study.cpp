#include "Study.h"

Study::Study() {

}
Study::Study(int index, std::string ClientId, std::string LaboratoryId, std::string sampleDate,
	std::string deliverDate, float result) {
	this->Index = index;
	this->SampleDate = sampleDate;
	this->ClientId = ClientId;
	this->LaboratoryId = LaboratoryId;
	this->DeliverDate = deliverDate;
	this->Result = result;
}

int Study::IsPositive() {
	return this->Result >= 2.4 ? 1 : 0;
}