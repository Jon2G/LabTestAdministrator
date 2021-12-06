#include "Menu.h"
Database* db;
Menu::Menu()
{
	db = new Database();
}
Menu::~Menu() {}
void Menu::Pause() {
	std::string a;
	std::getline(std::cin, a);
}
void Menu::Logo() {
	std::cout << "\t        __  __  __    ___ __  __   __  " << std::endl;
	std::cout << "\t|   /\\ |__)/  \\|__) /\\ | /  \\|__)|/  \\ " << std::endl;
	std::cout << "\t|__/--\\|__)\\__/| \\ /--\\| \\__/| \\ |\\__/ " << std::endl;
}
void Menu::Cover() {
	Clear();
	Logo();
	std::cout << "\tAlumna: Alma Karen Partida Herrera" << std::endl;
	std::cout << "\t\t*PRESIONE UNA TECLA PARA CONTINUAR*" << std::endl;
	Pause();
}
void Menu::Error(std::string error) {
	Clear();
	Logo();
	std::cout << "\t        __ __ ___     " << std::endl;
	std::cout << "\t /\\ |  |_ |__) |  /\\  " << std::endl;
	std::cout << "\t/--\\|__|__| \\  | /--\\ \n\n" << std::endl;
	std::cout << "\t\t" << error << std::endl;
	Pause();
}
void Menu::Login() {
	Clear();
	std::string user;
	std::string password;
	Logo();
	std::cout << "\tINICIO DE SESION" << std::endl;
	std::cout << "\tUsuario:";
	std::getline(std::cin, user);
	std::cout << "\tContrasena:";
	std::getline(std::cin, password);
	User* login = db->Login(user.c_str(), password.c_str());
	Client* client = dynamic_cast<Client*>(login);
	if (client != NULL) {
		Show(client);
		return;
	}

	Admin* admin = dynamic_cast<Admin*>(login);
	if (admin != NULL) {
		Show(admin);
		return;
	}
	Error("Usuario o contrasena incorrectos");
	Login();
}
//L A B O R A T O R I O S
Laboratory Menu::NewLaboratory() {
	Clear();
	std::string id;
	std::string name;
	Logo();
	std::cout << "\tALTA LABORATORIO" << std::endl;
	std::cout << "\tClave:";
	std::getline(std::cin, id);
	std::cout << "\tNombre:";
	std::getline(std::cin, name);
	Laboratory lab = Laboratory(-1, id, name, 1);
	db->Save(lab);
	Error("Agregado correctamente");
	return lab;
}
void Menu::EditLaboratory() {
	Clear();
	Logo();
	std::cout << "\tEDITAR LABORATORIO" << std::endl;
	std::vector<Laboratory> labs = db->GetLabs();
	for (int i = 0; i < labs.size(); i++) {
		labs[i].Print();
	}
	std::string id;
	std::cout << "\tClave del laboratorio:";
	std::getline(std::cin, id);
	Laboratory* laboratory = db->GetLab(id);
	if (laboratory == nullptr) {
		Error("Laboratorio no encontrado");
		return;
	}
	std::cout << "\tNueva clave:";
	std::getline(std::cin, laboratory->Id);
	std::cout << "\tNuevo nombre:";
	std::getline(std::cin, laboratory->Name);
	db->Save(laboratory[0]);
	Error("Laboratorio editado correctamente");
}
void Menu::HideLaboratory()
{
	Clear();
	Logo();
	std::cout << "\BAJA LABORATORIO" << std::endl;
	std::vector<Laboratory> labs = db->GetLabs();
	for (int i = 0; i < labs.size(); i++) {
		labs[i].Print();
	}
	std::string id;
	std::cout << "\tClave del laboratorio:";
	std::getline(std::cin, id);
	Laboratory* laboratory = db->GetLab(id);
	if (laboratory == nullptr) {
		Error("Laboratorio no encontrado");
		return;
	}
	laboratory->Visible = 0;
	db->Save(laboratory[0]);
	Error("Laboratorio dado de baja correctamente");
}
void Menu::ShowLabs() {
	Clear();
	Logo();
	std::cout << "\tL A B O R A T O R I O S" << std::endl;
	std::vector<Laboratory> labs = db->GetLabs();
	for (int i = 0; i < labs.size(); i++) {
		labs[i].Print();
	}
	Pause();
}
//P A C I E N T E S
Client Menu::NewClient() {
	Clear();
	Client client = Client();
	Logo();
	std::cout << "\tALTA PACIENTE" << std::endl;
	std::cout << "\tCurp:";
	std::getline(std::cin, client.CURP);
	std::cout << "\tNombre:";
	std::getline(std::cin, client.Name);
	std::cout << "\tDia de nacimiento (dd-mm-yyyy):";
	std::getline(std::cin, client.Birthday);
	std::cout << "\tSexo (H/M):";
	client.Gender = std::getchar();
	std::cin.ignore();
	std::cout << "\tNombre del doctor:";
	std::getline(std::cin, client.doctor.Name);
	client.doctor = db->GetOrSaveDoctor(client.doctor.Name);
	db->Save(client);
	Error("Agregado correctamente");
	return client;
}
void Menu::EditClient() {
	Clear();
	Logo();
	std::cout << "\tEDITAR PACIENTE" << std::endl;
	std::vector<Client> items = db->GetClients();
	for (int i = 0; i < items.size(); i++) {
		items[i].Print();
	}
	std::string sid;
	std::cout << "\tNumero de cliente:";
	std::getline(std::cin, sid);
	int id = std::stoi(sid)-1;
	if (items.size() > id && id >= 0) {
		Client client = items.at(id);
		std::cout << "\tALTA PACIENTE" << std::endl;
		std::cout << "\tCurp:";
		std::getline(std::cin, client.CURP);
		std::cout << "\tNombre:";
		std::getline(std::cin, client.Name);
		std::cout << "\tDia de nacimiento (dd-mm-yyyy):";
		std::getline(std::cin, client.Birthday);
		std::cout << "\tSexo (H/M)::";
		client.Gender = std::getchar();
		db->Save(client);
		Error("Laboratorio editado correctamente");
	}
	else {
		Error("Cliente no encontrado");
		return;
	}
}
void Menu::HideClient() {
	Clear();
	Logo();
	std::cout << "\BAJA CLIENTE" << std::endl;
	std::vector<Client> items = db->GetClients();
	for (int i = 0; i < items.size(); i++) {
		items[i].Print();
	}
	std::string sid;
	std::cout << "\tNumero de cliente:";
	std::getline(std::cin, sid);
	int id = std::stoi(sid)-1;
	if (items.size() > id && id > 0) {
		Client client = items.at(id);
		client.Visible = 0;
		db->Save(client);
		Error("Cliente dado de baja correctamente");
	}
	else {
		Error("Cliente no encontrado");
		return;
	}
}
void Menu::ShowClients() {
	Clear();
	Logo();
	std::cout << "\tP A C I E N T E S" << std::endl;
	std::vector<Client> items = db->GetClients();
	for (int i = 0; i < items.size(); i++) {
		items[i].Print();
	}
	Pause();
}
//E S T U D I O S
void Menu::NewStudy() 
{
	Clear();
	Logo();
	std::cout << "\ALTA ESTUDIO" << std::endl;
	std::vector<Client> items = db->GetClients();
	for (int i = 0; i < items.size(); i++) {
		items[i].Print();
	}
	std::string sid;
	std::cout << "\tNumero de cliente:";
	std::getline(std::cin, sid);
	int id = std::stoi(sid)-1;
	if (items.size() > id && id >= 0) {
		Client client = items.at(id);
		std::cout << "\tLABORATORIOS" << std::endl;
		std::vector<Laboratory> labs = db->GetLabs();
		for (int i = 0; i < labs.size(); i++) {
			labs[i].Print();
		}
		std::string labId;
		std::cout << "\tClave del laboratorio:";
		std::getline(std::cin, labId);
		Laboratory* laboratory = db->GetLab(labId);
		if (laboratory == nullptr) {
			Error("Laboratorio no encontrado");
			return;
		}
		Study study = Study();
		study.ClientId = client.Id;
		study.LaboratoryId = labId;
		std::cout << "\tFecha prueba (dd-mm-yyyy hh-mm):";
		std::getline(std::cin, study.SampleDate);
		std::cout << "\tFecha entrega (dd-mm-yyyy hh-mm):";
		std::getline(std::cin, study.DeliverDate);
		std::cout << "\tResultado antigenos:";
		std::string sresult;
		std::getline(std::cin, sresult);
		study.Result = std::stoi(sresult);
		db->Save(study);
		Error("Estudio registrado correctamente");
	}
	else {
		Error("Cliente no encontrado");
		return;
	}

}
void Menu::GlobalStudiesReport()
{
	Clear();
	std::vector<Study> items = db->GetStudies();
	for (int i = 0; i < items.size(); i++)
	{
		Study study = items.at(i);
		Client client = db->GetClient(study.ClientId);

		Laboratory lab = Laboratory();
		Laboratory* nlab = db->GetLab(study.LaboratoryId);
		if (nlab != nullptr) {
			lab = nlab[0];
		}

		std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "\t#" << study.Index + 1 << std::endl;
		std::cout << "\tCURP: " << study.ClientId << std::endl;
		std::cout << "\tNOMBRE: " << client.Name << std::endl;
		std::cout << "\tFECHA NACIMIENTO: " << client.Birthday << std::endl;
		std::cout << "\tSEXO: " << client.Gender << std::endl;
		std::cout << "\tLABORATORIO: [" << lab.Id << "] - " << lab.Name << std::endl;
		std::cout << "\tDOCTOR: " << client.doctor.Name << std::endl;
		if (study.IsPositive()==1) {
			std::cout << "\tPOSITIVO"<< std::endl;
		}
		else {
			std::cout << "\tNEGATIVO" << std::endl;
		}
		std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}
	Pause();
}


void Menu::Show(Admin* admin) {
	Clear();
	Logo();
	std::cout << "\n\n\t BIENVENID@:" << admin->Name << std::endl;

	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\tL A B O R A T O R I O S" << std::endl;
	std::cout << "\t a)Alta de laboratorio" << std::endl;
	std::cout << "\t b)Baja de laboratorio" << std::endl;
	std::cout << "\t c)Editar informacion de laboratorio" << std::endl;
	std::cout << "\t d)Listar laboratorios" << std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\tP A C I E N T E S" << std::endl;
	std::cout << "\t e)Alta de paciente" << std::endl;
	std::cout << "\t f)Baja de paciente" << std::endl;
	std::cout << "\t g)Editar información de paciente" << std::endl;
	std::cout << "\t h)Listar pacientes" << std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\tE S T U D I O S" << std::endl;
	std::cout << "\t i)Ingresar resultados estudio" << std::endl;
	std::cout << "\t j)Reporte global de estudios" << std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t k) Cerrar sesion" << std::endl << std::flush;
	int selection = std::getchar();
	std::cin.ignore();
	switch (selection)
	{
	case 97: //a
		NewLaboratory();
		break;
	case 98://b
		HideLaboratory();
		break;
	case 99://c
		EditLaboratory();
		break;
	case 100://d
		ShowLabs();
		break;
	case 101://e
		NewClient();
		break;
	case 102://f
		HideClient();
		break;
	case 103://g
		EditClient();
		break;
	case 104://h
		ShowClients();
		break;
	case 105://i
		NewStudy();
		break;
	case 106://j
		GlobalStudiesReport();
		break;
		break;
	case 107://k
		return;
		break;
	}
	Show(admin);
}
void Menu::Show(Client* client) {

}

void Menu::Clear()
{
	system("cls");
}