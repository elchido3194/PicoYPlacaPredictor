#pragma once
#include <string>
#include <iostream>
#include "PlateValidator.h"
class Vehicle
{
public:
	Vehicle(std::string plate);
	~Vehicle();
	void setPlate(std::string plate);
	std::string getPlate();
	bool isPlateCorrect();
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
	if (plateIsCorrect(plate)) {
		plat = plate;
	}
	else {
		std::cout << "The vehicle's plate is incorrect" << std::endl;
	}
}

std::string Vehicle::getPlate() {
	return plat;
}

bool Vehicle::isPlateCorrect() {
	return plateIsCorrect(plat);
}
