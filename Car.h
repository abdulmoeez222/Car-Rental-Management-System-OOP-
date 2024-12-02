#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
class Car:public Vehicle
{
private:
	/*string reg_no;
	string brand;*/
	/*bool is_rented;*/
	bool is_premium;
	/*double rent_price;*/
	/*Customer* renter;*/
public:
	Car(string _r, string _b, bool _ip, double _rp);
	void display_info();
	bool is_it_premium_car();
};

