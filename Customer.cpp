#include "Customer.h"
#include "Vehicle.h"
Customer::Customer(string _n) :name(_n), rented_cars_count(0) {}
string Customer::get_name() {
	return name;
}
int Customer::get_rented_cars_count() {
	return rented_cars_count;
}
void Customer::display_info() {
	cout << "Customer Details\n";
	cout << "Name: " << name << endl;
	cout << "Number of rented cars: " << rented_cars_count << endl;
	cout << "Customer Status: " << "VIP" << endl;
}