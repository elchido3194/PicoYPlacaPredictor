#pragma once
#include <iostream>
#define LOG(x) std::cout<< x << std::endl;
std::string printIntro();
std::string printInformation(Vehicle V, std::string date, std::string time);

std::string printIntro() {
	return "A Pico y Placa Predictor\n"
		"The plate should be inserted as AAA-1111 (using UPPERCASE)\n" 
		"The date should be inserted as DD/MM/YYYY\n" 
		"The time should be inserted as HH:MM (using 24h)\n";
}

std::string printInformation(Vehicle V, std::string date, std::string time) {
	std::string weekday;
	switch (getDayOfWeek_date(date))
	{
	case 0:
		weekday = "Sunday";
		break;
	case 1:
		weekday = "Monday";
		break;
	case 2:
		weekday = "Tuesday";
		break;
	case 3:
		weekday = "Wednesday";
		break;
	case 4:
		weekday = "Thursday";
		break;
	case 5:
		weekday = "Friday";
		break;
	case 6:
		weekday = "Saturday";
		break;
	}
	return "The vehicle's plate: " + V.getPlate() + "\n" +
		"The weekday for " + date + " is " + weekday + "\n" +
		"The time is " + time + "\n";
}