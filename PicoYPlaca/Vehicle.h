#pragma once
#include <string>
#include <iostream>

class Vehicle
{
public:
	Vehicle(std::string plate);
	~Vehicle();
	void setPlate(std::string plate);
	std::string getPlate();
private:
	std::string plat;
};

Vehicle::Vehicle(std::string plate)
{
	plat = plate;
}

Vehicle::~Vehicle()
{
}

void Vehicle::setPlate(std::string plate) {
	plat = plate;
}

std::string Vehicle::getPlate() {
	return plat;
}

