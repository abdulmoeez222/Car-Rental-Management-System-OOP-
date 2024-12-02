#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "Customer.h"
using namespace std;
class Car;
class VIPCustomer : public Customer
{
private:
	Vehicle** rented_cars;
public:
	VIPCustomer(string _n);
	void rent_a_car(Vehicle* c)override;
	void return_a_car(Vehicle* c)override;
	void print_bill()override;
};

