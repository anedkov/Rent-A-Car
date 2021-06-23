#pragma once 

#include <string>
#include "Printing.h"

using namespace std;

class Car : public Printing
{
public:
	Car(int year, string Model, double Price, string reg_nomer, bool taken);

	void set_Price(double pr);
	double get_Price();
	void set_Model(string mod);
	string get_Model();
	void set_Year(int yr);
	int get_Year();
    virtual string get_fuel()=0;
	void set_reg_nomer(string rn);
	string get_reg_nomer();
	void set_taken(bool tk);
	bool get_taken();
	void show();
private:
	string Model;
	int Year;
	double Price;
	string reg_nomer;
	bool taken;
};
