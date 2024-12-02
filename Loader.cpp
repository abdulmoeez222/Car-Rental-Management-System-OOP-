#include "Loader.h"
Loader::Loader(string _r = "", string _b = "", int cc = 0, double _rp = 0.00) :Vehicle(_r, _b, _rp), carriage_capacity(cc) {}
int Loader::get_carriage_capacity() {
	return carriage_capacity;
}
void Loader::display_info() {
	cout << "Loader Details\n";
	cout << "Brand: " << brand << endl;
	cout << "Registration No.: " << reg_no << endl;
	cout << "Rented Status: ";
	{if (is_rented == true) {
		cout << "Rented" << endl;
	}
	else {
		cout << "Not Rented" << endl;
	}
	}
	cout << "Carriage Capacity: " << carriage_capacity;
}