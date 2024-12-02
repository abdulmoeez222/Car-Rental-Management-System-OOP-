#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Customer.h"
class IndividualCustomer :public Customer
{
private:
    Vehicle* rented_car;
public:
    IndividualCustomer(string _n);
    void rent_a_car(Vehicle* c) override;
    void return_a_car(Vehicle* c) override;
    void print_bill()override;
    void display_info()override;
};

