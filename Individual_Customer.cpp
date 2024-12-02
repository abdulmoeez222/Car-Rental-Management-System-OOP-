#include "Individual_Customer.h"
IndividualCustomer::IndividualCustomer(string _n) :Customer(_n), rented_car(nullptr) {}
void IndividualCustomer::rent_a_car(Vehicle* c) {
	if (rented_cars_count == 0 && c->is_it_premium_car() == false && c->is_already_rented() == false) {
		rented_cars_count++;
		rented_car = c;
		c->rent_this_vehicle(this);
	}
	else {
		if (rented_cars_count > 0) {
			cout << "This Customer has already rented a car!!!";
		}
		if (c->is_it_premium_car() == true) {
			cout << "Only VIP Customers can rent this car!!!";
		}
		if (c->is_already_rented() == true) {
			cout << "This Car is already rented!!!";
		}
	}
}
void IndividualCustomer::return_a_car(Vehicle* c) {
	if (rented_car == c) {
		c->free_this_vehicle();
		rented_car = nullptr;
		rented_cars_count--;
	}
}
void IndividualCustomer::print_bill() {
	double a;
	float b;
	a = rented_car->get_rent_price();
	b = 0.16 * rented_car->get_rent_price();
	cout << "Car Rent: " << a << endl;
	cout << "Tax: " << b<<endl;
	cout << "Total: " << a + b<<endl;
}
void IndividualCustomer::display_info() {
	cout << "Name: " << name << endl;
	cout << "Customer Status: " << "Individual" << endl;
}