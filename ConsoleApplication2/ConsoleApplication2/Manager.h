#pragma once
#include <vector>
#include "Car.h"
#include <iostream>
#include <utility> 
#include <fstream>
#include "DieselCar.h"
#include "GasolineCar.h"
#include "Client.h"
#include <string>
using namespace std;

class Manager

{
public:
	Manager();
	~Manager();
	void add_Car(Car* car);
	void add_Client(Client* client);
	vector<Car*> get_Cars();
	vector<Client*> get_Clients();

	int createClientOrder(string name, string phone, Car * selectedCar, string pickupdate, string returndate);
	int addNewCar(string reg_nom, string model, int godina, double price, string fuel);

	
private:
	vector <Car*> Cars;
	vector <Client*>Clients;
	void loadallcars();
	void loadclients();

	int saveCars();

	int saveClients();

	string getPath();
};

