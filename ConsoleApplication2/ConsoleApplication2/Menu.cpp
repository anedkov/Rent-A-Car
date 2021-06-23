#include "stdafx.h"
#include "Menu.h"
#include "iostream"
using namespace std;
#include <string>
#include <utility>
#include "Manager.h"

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::showMain()
{
	do
	{
		cout << "Please make your choice ....  \n";
		cout << "1 - Show all cars\n";
		cout << "2 - Show all available cars\n";
		cout << "3 - Add new car\n";
		cout << "4 - New order\n";
		cout << "5 - Show all orders\n";
		cout << "6 - Exit\n";
		cout << "Selection: ";


		string strSelection = "";
		cin >> strSelection;
		if (cin.fail())
			continue;
		int selection = 0;
		try
		{
			selection = stoi(strSelection);

			switch (selection)
			{
			case 1:
				showCars(false);
				break;
			case 2:
				showCars(true);
				break;
			case 3:
				showAddCar();
				break;
			case 4:
				showAddOrder();
				break;
			case 5:
				showClients();
				break;
			case 6:
				cout << "The program will shut down soon..." << endl;
				return;
			default:
				continue; //show the menu again
			}
		}
		catch (...)
		{

		}
	} while (true);
};

void Menu::showClients()
{
	for (Client* client : manager.get_Clients())
	{
		client->show();
	}
};


void Menu::showCars(bool onlyAvailable)
{
	for (Car* car : manager.get_Cars())
	{
		if (onlyAvailable)
		{
			if (!car->get_taken())
				car->show();
		}
		else
			car->show();
	}
};


void Menu::showAddOrder()
{
	do
	{
		try
		{
			cout << "Choose a car:" << endl;
			vector<pair<int, Car*>> availablecars;
			int i = 0;
			for (Car* car : manager.get_Cars())
			{
				if (car->get_taken())
					continue;

				availablecars.push_back(pair<int, Car*>(i, car));
				cout << i << ": " << car->get_reg_nomer() << ": " << car->get_Model() << ", year:" << car->get_Year() << ", fuel:" << car->get_fuel() << ", price: " << car->get_Price() << "lv per day\n";

				i++;
			}
			
			cout << i << ": Back" << endl;
			cout << "Please select: ";

			string strSelection = "";
			cin >> strSelection;

			int selection = stoi(strSelection);

			Car* selectedCar = NULL;
			for (pair<int, Car*> car : availablecars)
			{
				if (selection == car.first)
				{
					selectedCar = car.second;
					break;
				}
			}

			if (selectedCar == NULL)
			{
				return;
			}

			cout << "Enter client name: ";
			string name = "";
			getline(cin >> ws, name);

			cout << "Enter client phone: ";
			string phone = "";
			getline(cin >> ws, phone);

			cout << "Enter pickup date: ";
			string pickupdate = "";
			getline(cin >> ws, pickupdate);

			cout << "Enter return date: ";
			string returndate = "";
			getline(cin >> ws, returndate);

			int result = manager.createClientOrder(name, phone, selectedCar, pickupdate, returndate);

			if (result == 0)
			{
				cout << "Success!\n";
				break;
			}
			else
			{
				cout << "There was a problem, pry try again.\n";
				break;
			}
		}
		catch (...)
		{
			continue; //repeat on error
		}

	} while (true);
}


void Menu::showAddCar()
{
	do
	{
		try
		{
			cout << "Enter reg number of the car:";
			string regNumber;
			cin >> regNumber;

			cout << "Enter model:";
			string model;
			getline(cin >> ws, model);

			cout << "Enter year:";
			string stryear;
			getline(cin >> ws, stryear);
			int year = stoi(stryear);

			cout << "Enter price:";
			string strprice;
			getline(cin >> ws, strprice);
			int price = stoi(strprice);

			int selection = -1;
			do
			{
				cout << "Select fuel type:" << endl;
				cout << "1: Diesel" << endl;
				cout << "2: Gasoline" << endl;
				cout << "3: LPG" << endl;
				cout << "Select:" << endl;
				string strFuel;
				cin >> strFuel;
				
				selection = stoi(strFuel);

			} while (selection < 1 || selection >3);

			string fuel = "";
			if (selection == 1)
				fuel = "diesel";
			else if (selection == 2)
				fuel = "gasoline";
			else if (selection == 3)
				fuel = "lpg";

			int result = manager.addNewCar(regNumber, model, year, price, fuel);

			if (result == 0)
			{
				cout << "Success!\n";
				break;
			}
			else
			{
				cout << "There was a problem, pry try again.\n";
				break;
			}
		}
		catch (...)
		{
			continue; //repeat on error
		}

	} while (true);
}
