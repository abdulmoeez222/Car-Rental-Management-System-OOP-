#include "VIP_Customer.h"
VIPCustomer::VIPCustomer(string _n) :Customer(_n), rented_cars(nullptr) {}
void VIPCustomer::rent_a_car(Vehicle* c) {
	if (c->is_already_rented() == false) {
		rented_cars_count++;
		Vehicle** temp = new Vehicle * [rented_cars_count];
		for (int i = 0; i < rented_cars_count-1; i++) {
			temp[i] = rented_cars[i];
		}
		temp[rented_cars_count-1] = c;
		delete[] rented_cars;
		rented_cars = new Vehicle * [rented_cars_count];
		for (int i = 0; i < rented_cars_count; i++) {
			rented_cars[i] = temp[i];
		}
		delete[] temp;
	}
	else {
		cout << "This Car is already rented!!!" << endl;
	}
}
void VIPCustomer::return_a_car(Vehicle* c) {
	bool a;
	for (int i = 0; i < rented_cars_count; i++) {
		if (rented_cars[i] == c) {
			a = true;
			break;
		}
		else if (i == rented_cars_count - 1) {
			a = false;
		}
	}
	if (c->is_already_rented() == true && a == true) {
		int k = 0;
		rented_cars_count--;
		Vehicle** temp = new Vehicle * [rented_cars_count];
		for (int i = 0; i < rented_cars_count; i++) {
			if (rented_cars[i] != c) {
				temp[k++] = rented_cars[i];
			}
		}
		delete[] rented_cars;
		rented_cars = new Vehicle * [rented_cars_count];
		for (int i = 0; i < rented_cars_count; i++) {
			rented_cars[i] = temp[i];
		}
		delete[] temp;
		c->free_this_vehicle();
	}
	else {
		if (a == false) {
			cout << "This car is not rented to this Customer";
		}
		if (c->is_already_rented() == false) {
			cout << "This car is not rented";
		}
	}
}
void VIPCustomer::print_bill() {
	double a = 0.00; float b = 0.00;
	for (int i = 0; i < rented_cars_count; i++) {
		a += rented_cars[i]->get_rent_price();
		b += 0.05 * rented_cars[i]->get_rent_price();
	}
	cout << "Accumulated Rent of all cars: " << a << endl;
	cout << "Accumulated tax of all cars: " << b << endl;
	cout << "Total Rent of all cars after tax: " << a + b << endl;
}