#include "stdafx.h"
#include "Manager.h"
#include "DieselCar.h"
#include "GasolineCar.h"

#include <iostream>
#include <windows.h>

Manager::Manager()
{
	loadallcars();
	loadclients();
}


Manager::~Manager()
{
}

void Manager::add_Car(Car * car)
{
	Cars.push_back(car);
}


void Manager::loadallcars()
{
	string line = "";
	ifstream infile(getPath() + "\\..\\resources\\cars.txt");
	while (getline(infile, line))
	{
		try
		{
			string razdelitel = ",";
			int index = line.find(razdelitel);
			string reg_nomer = line.substr(0, index);

			int index1 = line.find(razdelitel, index + 1);
			string model = line.substr(index + 1, index1 - index - 1);
			index = line.find(razdelitel, index1 + 1);

			int year = stoi(line.substr(index1 + 1, index - index1 - 1));
			index1 = line.find(razdelitel, index + 1);

			double price = stod(line.substr(index + 1, index1 - index - 1));
			index = line.find(razdelitel, index1 + 1);

			string strtaken = line.substr(index1 + 1, index - index1 - 1);
			bool taken = strtaken == "yes";


			index1 = line.find(razdelitel, index + 1);
			string fuel = line.substr(index + 1, index1);

			if (fuel == "diesel")
			{
				add_Car(new DieselCar(year, model, price, reg_nomer, taken));
			}
			else if (fuel == "gasoline")
			{
				add_Car(new GasolineCar(year, model, price, false, reg_nomer, taken));
			}
			else if (fuel == "lpg")
			{
				add_Car(new GasolineCar(year, model, price, true, reg_nomer, taken));
			}
		}
		catch (...)
		{
		}
	}
	infile.close();
}

void Manager::loadclients()
{
	string line = "";
	ifstream infile(getPath() + "\\..\\resources\\clients.txt");
	while (getline(infile, line))
	{
		try
		{
			string razdelitel = ",";
			int index = line.find(razdelitel);
			string name = line.substr(0, index);

			int index1 = line.find(razdelitel, index + 1);
			string reg_nomer = line.substr(index + 1, index1 - index - 1);
			index = line.find(razdelitel, index1 + 1);

			string date_taken = line.substr(index1 + 1, index - index1 - 1);
			index1 = line.find(razdelitel, index + 1);

			string date_returned = line.substr(index + 1, index1 - index - 1);
			index = line.find(razdelitel, index1 + 1);

			string tel_nomer = line.substr(index1 + 1, index - index1 - 1);
			index1 = line.find(razdelitel, index + 1);

			add_Client(new Client(name, reg_nomer, date_taken, date_returned, tel_nomer));
		}
		catch (...)
		{
		}
	}
	infile.close();
}

void Manager::add_Client(Client * client)
{
	Clients.push_back(client);
}

vector<Car*> Manager::get_Cars()
{
	return Cars;
}

vector<Client*> Manager::get_Clients()
{
	return Clients;
}

int Manager::createClientOrder(string name, string phone, Car* selectedCar, string pickupdate, string returndate)
{
	Clients.push_back(new Client(name, selectedCar->get_reg_nomer(), pickupdate, returndate, phone));
	selectedCar->set_taken(true);
	saveCars();

	return saveClients();
}

string Manager::getPath()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}


int Manager::saveClients()
{
	try
	{
		ofstream save(getPath() + "\\..\\resources\\clients.txt");
		for (Client* client : Clients)
		{
			string line = client->get_name() + "," + client->get_reg_nomer() + "," + client->get_date_taken() + "," + client->get_date_returned() + "," + client->get_tel_nomer() + "\n";

			save << line;
		}

		save.close();
	}
	catch (...)
	{
		return -1;
	}

	return 0;
}


int Manager::addNewCar(string reg_nom, string model, int year, double price, string fuel)
{
	if (fuel == "diesel")
	{
		add_Car(new DieselCar(year, model, price, reg_nom, false));
	}
	else if (fuel == "gasoline")
	{
		add_Car(new GasolineCar(year, model, price, false, reg_nom, false));
	}
	else if (fuel == "lpg")
	{
		add_Car(new GasolineCar(year, model, price, true, reg_nom, false));
	}
	
	return saveCars();
}

int Manager::saveCars()
{
	try
	{
		ofstream save(getPath() + "\\..\\resources\\cars.txt");
		for (Car* car : Cars)
		{
			string taken = car->get_taken() ? "yes" : "no";
			string line = car->get_reg_nomer() + "," + car->get_Model() + "," + to_string(car->get_Year()) + "," + to_string(car->get_Price()) + "," + taken + "," + car->get_fuel() + "\n";

			save << line;
		}

		save.close();
	}
	catch (...)
	{
		return -1;
	}

	return 0;
}
