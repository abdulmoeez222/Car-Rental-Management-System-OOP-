#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
class Vehicle;
class Customer
{
protected:
	string name;
	int rented_cars_count;
public:
	Customer(string _n);
	string get_name();
	int get_rented_cars_count();
	virtual void display_info();
	virtual void rent_a_car(Vehicle* c) = 0;
	virtual void return_a_car(Vehicle* c)=0;
	virtual void print_bill()=0;
};

