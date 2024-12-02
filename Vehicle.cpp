#include "Vehicle.h"

Vehicle::Vehicle(string _r, string _b, double _rp):reg_no(_r),brand(_b),rent_price(_rp),is_rented(false),renter(nullptr){}
string Vehicle::get_reg_no() {
	return reg_no;
}
bool Vehicle::is_already_rented() {
	if (is_rented == true) {
		return true;
	}
	return false;
}
string Vehicle::get_brand() {
	return brand;
}
double Vehicle::get_rent_price() {
	return rent_price;
}
Customer* Vehicle::get_renter() {
	return renter;
}
void Vehicle::rent_this_vehicle(Customer* c) {
	this->is_rented = true;
	renter = c;
}
void Vehicle::free_this_vehicle() {
	this->is_rented = false;
	renter = nullptr;
}