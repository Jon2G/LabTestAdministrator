#include "Database.h"


Database::Database() {

}
Database::~Database() {}


std::fstream Database::FOpen(std::string path)
{
	std::fstream wfile(path, std::ios::out | std::ios::app);
	return wfile;
}
std::ifstream Database::FRead(std::string path) {
	std::ifstream file(path);
	return file;
}
void Database::DeleteRecord(int index, std::string path) {
	std::ifstream is(path);
	std::ofstream ofs;
	ofs.open(Temporal, std::ofstream::out);

	char c;
	int line_no = 0;
	while (is.get(c))
	{
		if (c == '\n')
			line_no++;
		if (line_no != index)
			ofs << c;
	}
	ofs.close();
	is.close();
	remove(path.c_str());
	rename(Temporal.c_str(), path.c_str());
}
void Database::Save(Laboratory laboratory)
{
	if (laboratory.Index >= 0)
	{
		DeleteRecord(laboratory.Index, Laboratories);
	}
	std::fstream wfile = FOpen(Laboratories);
	wfile << "|" << laboratory.Id << "|" << laboratory.Name << "|" << laboratory.Visible << "|" << std::endl;
	wfile.close();
}
void Database::Save(Doctor doctor)
{
	if (doctor.Index >= 0)
	{
		DeleteRecord(doctor.Index, Doctors);
	}
	std::fstream wfile = FOpen(Doctors);
	wfile << "|" << doctor.Name << "|" << std::endl;
	wfile.close();
}
void Database::Save(Client client)
{
	if (client.Index >= 0)
	{
		DeleteRecord(client.Index, Clients);
	}
	Save(client.doctor);
	std::fstream wfile = FOpen(Clients);
	wfile << "|" << client.CURP
		<< "|" << client.Name
		<< "|" << client.Birthday
		<< "|" << client.Gender
		<< "|" << client.doctor.Name
		<< "|" << client.Visible << "|"
		<< std::endl;
	wfile.close();
}
void Database::Save(Study study)
{
	if (study.Index >= 0)
	{
		DeleteRecord(study.Index, Studies);
	}
	std::fstream wfile = FOpen(Studies);
	wfile << "|" << study.ClientId
		<< "|" << study.LaboratoryId
		<< "|" << study.Result
		<< "|" << study.SampleDate
		<< "|" << study.DeliverDate << "|"
		<< std::endl;
	wfile.close();
}
std::vector<Laboratory> Database::GetLabs() {
	std::vector<Laboratory> items;
	std::string line;
	std::ifstream rfile = FRead(Laboratories);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		if (reader.GetInt(2) == 1)
			items.push_back(Laboratory(i, reader.GetString(0), reader.GetString(1), reader.GetInt(2)));
		i++;
	}
	rfile.close();
	return items;
}
std::vector<Client> Database::GetClients() {
	std::vector<Client> items;
	std::string line;
	std::ifstream rfile = FRead(Clients);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		if (reader.GetInt(5) == 1)
			items.push_back(Client(i,
				reader.GetString(0),
				reader.GetString(1),
				reader.GetString(2),
				reader.GetChar(3),
				GetOrSaveDoctor(reader.GetString(4)),
				reader.GetInt(5)));
		i++;
	}
	rfile.close();
	return items;
}
std::vector<Study> Database::GetStudies() {
	std::vector<Study> items;
	std::string line;
	std::ifstream rfile = FRead(Studies);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
			items.push_back(Study(i,
				reader.GetString(0),
				reader.GetString(1),
				reader.GetString(3),
				reader.GetString(4),
				reader.GetFloat(2)));
		i++;
	}
	rfile.close();
	return items;
}
Laboratory* Database::GetLab(std::string id) {
	std::string line;
	std::ifstream rfile = FRead(Laboratories);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		if (id == reader.GetString(0)) {
			if (reader.GetInt(2) == 0) {
				rfile.close();
				return nullptr;
			}
			return new Laboratory(i, reader.GetString(0), reader.GetString(1), reader.GetInt(2));
		}
		i++;
	}
	rfile.close();
	return nullptr;
}
Client Database::GetClient(std::string id)
{
	std::string line;
	std::ifstream rfile = FRead(Clients);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		if (id == reader.GetString(0)) {
			if (reader.GetInt(5) == 0) {
				rfile.close();
				return Client();
			}
			return Client(i,
				reader.GetString(0),
				reader.GetString(1),
				reader.GetString(2),
				reader.GetChar(3),
				GetOrSaveDoctor(reader.GetString(4)),
				reader.GetInt(5));
		}
		i++;
	}
	rfile.close();
	return Client();
}
User* Database::Login(std::string user, std::string password) {
	std::string line;
	std::ifstream rfile = FRead(Users);
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		char userType = reader.GetChar(0);
		switch (userType)
		{
		case 'a':
			if (user == reader.GetString(1) && password == reader.GetString(2)) {
				return new Admin(user, password);
			}
		case 'c':
			//return new Client(line);
			break;
		case 'u':
			//return new User(line);
			break;
		}
	}
	rfile.close();
	return NULL;
}
Doctor Database::GetOrSaveDoctor(std::string name)
{
	std::string line;
	std::ifstream rfile = FRead(Doctors);
	int i = 0;
	while (std::getline(rfile, line))
	{
		Reader reader = Reader(line);
		if (name == reader.GetString(0)) {
			return Doctor(i, reader.GetString(0));
		}
		i++;
	}
	rfile.close();
	return Doctor(i, name);
}
