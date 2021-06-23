#include "stdafx.h"
#include "GasolineCar.h"


GasolineCar::GasolineCar(int yr, string mod, double pr, bool LPG, string rn, bool tk):Car(yr, mod, pr,rn,tk)
{
	withLPG = LPG;
}


GasolineCar::~GasolineCar()
{
}

bool GasolineCar::hasLPG()
{
	return false;
}
string GasolineCar::get_fuel()
{
	if (withLPG)
		return "lpg";
	else
		return "gasoline";
};