
#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(int yr, string mod, double pr,string rn, bool tk)
{
	Price = pr;
	Model = mod;
	Year = yr;
	reg_nomer = rn;
	taken = tk;
};

void Car::set_Price(double pr)
{
	Price = pr;
};

double Car::get_Price()
{
	return Price;
};

void Car::set_Model(string mod)
{
	Model = mod;
};
string Car::get_Model()
{
	return Model;
};
void Car::set_Year(int yr)
{
	Year = yr;
}
int Car::get_Year()
{
	return Year;
}
void Car::set_reg_nomer(string rn)
{
	reg_nomer = rn;
}
string Car::get_reg_nomer()
{
	return reg_nomer;
}
void Car::set_taken(bool tk)
{
	taken = tk;
}
bool Car::get_taken()
{
	return taken;
}
void Car::show()
{
	string available = taken ? "No" : "Yes";
	cout << "==================\n";
	cout << "----- " << reg_nomer << "-----\n";
	cout << "Model: " << Model << "\n";
	cout << "Year: " << Year << "\n";
	cout << "Fuel: " << get_fuel() << "\n";
	cout << "Price: " << get_Price() << "lv.\n";
	cout << "Available: " << available <<"\n";
	cout << "==================\n";
}

