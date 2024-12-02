#include "Rental_Manager.h"
RentalManager::RentalManager() :cars_count(0), customer_count(0), cars_collection(nullptr), customers_list(nullptr) {}
void RentalManager::add_a_car(Vehicle* c) {
	bool a = false;
	for (int i = 0; i < cars_count; i++) {
		if (cars_collection[i] == c) {
			a = true;
			break;
		}
		else if (i == cars_count - 1) {
			a = false;
		}
	}
	if (a == false) {
		cars_count++;
		Vehicle** temp = new Vehicle * [cars_count];
		for (int i = 0; i < cars_count - 1; i++) {
			temp[i] = cars_collection[i];
		}
		temp[cars_count - 1] = c;
		delete[] cars_collection;
		cars_collection = new Vehicle * [cars_count];
		for (int i = 0; i < cars_count; i++) {
			cars_collection[i] = temp[i];
		}
		delete[] temp;
	}
}
void RentalManager::add_a_customer(Customer* c) {
	bool a = false;
	for (int i = 0; i < customer_count; i++) {
		if (customers_list[i] == c) {
			a = true;
			break;
		}
		else if (i == customer_count - 1) {
			a = false;
		}
	}
	if (a == false) {
		customer_count++;
		Customer** temp = new Customer * [customer_count];
		for (int i = 0; i < customer_count - 1; i++) {
			temp[i] = customers_list[i];
		}
		temp[customer_count - 1] = c;
		delete[] customers_list;
		customers_list = new Customer * [customer_count];
		for (int i = 0; i < customer_count; i++) {
			customers_list[i] = temp[i];
		}
		delete[] temp;
	}
}
void RentalManager::rent_out_a_car(Vehicle* car, Customer* customer) {
	this->add_a_customer(customer);
	this->add_a_car(car);
	customer->rent_a_car(car);
	/*bool a = false;
	for (int i = 0; i < cars_count; i++) {
		if (cars_collection[i] == car) {
			a = true;
			break;
		}
		else if (i == cars_count - 1) {
			a = false;
		}
	}
	if (a == true) {
		cars_count--;
		Car** temp = new Car * [cars_count];
		for (int i = 0; i < cars_count ; i++) {
			if (cars_collection[i] != car) {
				temp[i] = cars_collection[i];
			}
		}
		delete[] cars_collection;
		cars_collection = new Car * [cars_count];
		for (int i = 0; i < cars_count; i++) {
			cars_collection[i] = temp[i];
		}
		delete[] temp;
	}*/
}
void RentalManager::get_back_a_car(Vehicle* car, Customer* customer) {
	int a;
	this->add_a_car(car);
	customer->return_a_car(car);
	a = customer->get_rented_cars_count();
	if (a == 0) {
		customer_count--;
		Customer** temp = new Customer * [customer_count];
		for (int i = 0; i < customer_count; i++) {
			if (customers_list[i] != customer) {
				temp[i] = customers_list[i];
			}
		}
		delete[] customers_list;
		customers_list = new Customer * [customer_count];
		for (int i = 0; i < customer_count; i++) {
			customers_list[i] = temp[i];
		}
		delete[] temp;
	}
}
void RentalManager::remove_a_customer_from_list(Customer* c) {
	customer_count--;
	Customer** temp = new Customer * [customer_count];
	for (int i = 0; i < customer_count; i++) {
		if (customers_list[i] != c) {
			temp[i] = customers_list[i];
		}
	}
	delete[] customers_list;
	customers_list = new Customer * [customer_count];
	for (int i = 0; i < customer_count; i++) {
		customers_list[i] = temp[i];
	}
	delete[] temp;
}
void RentalManager::display_info() {
	cout << "Manager Details\n";
	cout << "Customers: ";
	for (int i = 0; i < customer_count; i++) {
		cout << customers_list[i]->get_name() << "  ";
	}
	cout << endl << "Cars: ";
	for (int i = 0; i < cars_count; i++) {
		cout << cars_collection[i]->get_brand();
	}
	cout << endl;
}
void RentalManager::display_customer_bill(Customer* customer) {
	customer->print_bill();
}