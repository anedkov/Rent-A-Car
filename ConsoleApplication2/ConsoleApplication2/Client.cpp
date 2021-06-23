#include "stdafx.h"
#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(string ime, string rn, string dt, string dr, string tel)
{
	name = ime;
	reg_nomer = rn;
	date_taken = dt;
	date_returned = dr;
	tel_nomer = tel;
}

void Client::set_name(string ime)
{
	name = ime;
}

string Client::get_name()
{
	return name;
}

void Client::set_reg_nomer(string rn)
{
	reg_nomer = rn;
}

string Client::get_reg_nomer()
{
	return reg_nomer;
}

void Client::set_date_taken(string dt)
{
	date_taken = dt;
}

string Client::get_date_taken()
{
	return date_taken;
}

void Client::set_date_returned(string dr)
{
	date_returned = dr;
}

string Client::get_date_returned()
{
	return date_returned;
}

void Client::set_tel_nomer(string tel)
{
	tel_nomer = tel;
}

string Client::get_tel_nomer()
{
	return tel_nomer;
}
void Client::show()
{
	cout << "==================\n";
	cout << "Name: " << name << "\n";
	cout << "Phone: " << tel_nomer << "\n";
	cout << "Reg number of the car: " << reg_nomer << "\n";
	cout << "Pickup Date: " << date_taken << "\n";
	cout << "Return Date: " << date_returned << "\n";
	cout << "==================\n";
}
