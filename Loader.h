#pragma once
#include "Vehicle.h"
class Loader :public Vehicle
{
private:
	int carriage_capacity;
public:
	Loader(string _r, string _b, int cc, double _rp);
	int get_carriage_capacity() override;
	void display_info() override;
};

