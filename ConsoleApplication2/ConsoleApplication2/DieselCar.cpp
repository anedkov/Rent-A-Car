#include "stdafx.h"
#include "DieselCar.h"


DieselCar::DieselCar(int yr, string mod, double pr, string rn, bool tk):Car(yr,mod,pr,rn,tk)
{
}


DieselCar::~DieselCar()
{
}

string DieselCar::get_fuel()
{
	return "diesel";
};

