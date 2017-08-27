#pragma once
#include "Vehicle.h"
#include "DateValidator.h"
#include "TimeValidator.h"
#include <string>

class PyPPredictor
{
public:
	PyPPredictor();
	~PyPPredictor();
	bool shouldItRide(Vehicle V, std::string date, std::string time);

private:

};

PyPPredictor::PyPPredictor(){

}

PyPPredictor::~PyPPredictor()
{
}

bool PyPPredictor::shouldItRide(Vehicle V, std::string date, std::string time) {
	bool r = true;
	
	
	//We get the day of the week
	int dayOfWeek_date = (getDayOfWeek_date(date) + 5) % 6;//mktime defines Sunday as 0
	int dayOfWeek_plate = getDayOfWeek_plate(V.getPlate());
	

	if (dayOfWeek_date < 5) { //Discards Saturdays and Sundays
		if (dayOfWeek_date == dayOfWeek_plate) {//Compares the weekday of the date with the weekday of the restriction depending on the plate
			if (restrictedTime(time)) {//Checks if it can ride at the given time
				r = false;
			}
		}
	}
	return r;

}
