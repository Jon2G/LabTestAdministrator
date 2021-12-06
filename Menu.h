#pragma once
#include "Database.h"
#include "Admin.h"
#include "Client.h"
#include "Laboratory.h"
#include "Study.h"
#include <ctime>

class Menu
{
public:
	Menu();
	~Menu();
	void Cover();
	void Login();
private:
	void Logo();
	void Pause();
	void Show(Admin* admin);
	void Show(Client* client);
	void Clear();
	void Error(std::string error);
	//L A B O R A T O R I O S
	Laboratory NewLaboratory();
	void EditLaboratory();
	void HideLaboratory();
	void ShowLabs();
	//P A C I E N T E S
	Client NewClient();
	void HideClient();
	void EditClient();
	void ShowClients();
	//E S T U D I O S
	void NewStudy();
	void GlobalStudiesReport();
};



