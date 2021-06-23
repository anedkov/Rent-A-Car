#pragma once
#include <string>

#include "Printing.h"

using namespace std;

class Client : public Printing
{
public:
	Client(string name, string reg_nomer, string date_taken, string date_returned, string tel_nomer);
	void set_name(string ime );
	string get_name();
	void set_reg_nomer(string rn);
	string get_reg_nomer();
	void set_date_taken(string dt);
	string get_date_taken();
	void set_date_returned(string dr);
	string get_date_returned();
	void set_tel_nomer(string tel);
	string get_tel_nomer();
	void show();
private:
	string name;
	string reg_nomer;
	string date_taken;
	string date_returned;
	string tel_nomer;


};


