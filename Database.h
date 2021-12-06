#pragma once
#include <filesystem>
#include <fstream>
#include "User.h"
#include "Menu.h"
#include "Client.h"
#include "Admin.h"
#include "Reader.h"
#include "Laboratory.h"
#include "Study.h"
class Database
{
public:
	Database();
	~Database();
	User* Login(std::string user, std::string password);
	void Save(Laboratory laboratory);
	void Save(Doctor doctor);
	void Save(Client client);
	void Save(Study study);
	std::vector<Laboratory> GetLabs();
	std::vector<Client> GetClients();
	std::vector<Study> GetStudies();
	Laboratory* GetLab(std::string id);
	Client GetClient(std::string id);
	void DeleteRecord(int index, std::string path);
	Doctor GetOrSaveDoctor(std::string name);
private:
	std::fstream FOpen(std::string path);
	std::ifstream FRead(std::string path);
	const std::string Users = "Db\\users.txt";
	const std::string Laboratories = "Db\\labs.txt";
	const std::string Doctors = "Db\\doctors.txt";
	const std::string Clients = "Db\\clients.txt";
	const std::string Studies ="Db\\studies.txt";
	const std::string Temporal ="Db\\temp.txt";
};
