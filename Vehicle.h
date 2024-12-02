#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Customer.h"
class Customer;
class Vehicle
{
protected:
	string reg_no;
	string brand;
	bool is_rented;
	double rent_price;
	Customer* renter;
public:
	Vehicle(string _r, string _b, double _rp);
	string get_reg_no();
	bool is_already_rented();
	string get_brand();
	double get_rent_price();
	Customer* get_renter();
	virtual void display_info() = 0;
	virtual bool is_it_premium_car();
	void rent_this_vehicle(Customer* c);
	void free_this_vehicle();
	virtual int get_carriage_capacity();
};

