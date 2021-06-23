#pragma once
#include "Car.h"
class GasolineCar :
	public Car
{
public:
	GasolineCar(int yr, string mod, double pr, bool LPG, string rn, bool tk);
	~GasolineCar();

	bool hasLPG();
	string get_fuel();
private:
	bool withLPG;
};

