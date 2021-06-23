#pragma once
#include "Manager.h"
class Menu
{
public:
	Menu();
	~Menu();

	void showMain();

private:
	Manager manager;

	void showClients();
	void showCars(bool onlyAvailable);
	void showAddOrder();
	void showAddCar();
};

