#include <iostream>
#include "Vehicle.h"
#include "PyPPredictor.h"
#include "DateValidator.h"
#include "PlateValidator.h"
#include "TimeValidator.h"
#include "printInformation.h"
#define LOG(x) std::cout<< x << std::endl;

int main(void) {
	std::string plate, date, time;
	LOG(printIntro());
	do {
		do {
			LOG("Please enter a CORRECT plate number:");
			std::cin >> plate;
		} while (!plateIsCorrect(plate));

		do {
			LOG("Please enter a CORRECT date:");
			std::cin >> date;
		} while (!dateCorrect(date));

		do {
			LOG("Please enter a CORRECT time:");
			std::cin >> time;
		} while (!isTimeCorrect(time));

		PyPPredictor PyP;
		Vehicle Ve(plate);
		if (PyP.shouldItRide(Ve, date, time)) {
			LOG("The vehicle CAN ride at the given date and hour");
		}
		else {
			LOG("The vehicle CANNOT ride at the given date and hour");
		}
		LOG(printInformation(Ve, date, time));
		
	} while (true);
	return 0;
}

