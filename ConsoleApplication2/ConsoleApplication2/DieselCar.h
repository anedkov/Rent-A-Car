#pragma once
#include "Car.h"
class DieselCar :
	public Car
{
public:
	DieselCar(int yr, string mod, double pr, string rn, bool tk);
	~DieselCar();

	string get_fuel();


};

