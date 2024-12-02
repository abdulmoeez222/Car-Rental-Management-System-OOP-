#include "Car.h"

Car::Car(string _r = "", string _b = "", bool _ip = false, double _rp = 0.00):Vehicle(_r,_b,_rp),is_premium(_ip){}

bool Car::is_it_premium_car(){
	return this->is_premium;
}
void Car::display_info() {
	cout << "Car Details\n";
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
	cout << "Premium: "; {
		if (is_premium == true) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}