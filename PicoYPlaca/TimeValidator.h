#pragma once
#include <iostream>
#include <regex>

class TimeValidator {
public:
	TimeValidator();
	~TimeValidator();
	int getHour(std::string time);
	int getMin(std::string time);
	bool isTimeCorrect(std::string time);
	bool restrictedTime(std::string time);
};
TimeValidator::TimeValidator(){

}
TimeValidator::~TimeValidator(){

}

bool TimeValidator::isTimeCorrect(std::string time) {
	//time should be hh:mm

	bool r = false;
	int hour = getHour(time);
	int min = getMin(time);
	if (hour > 0 && hour <= 24 && min>=0 && min < 60) {
		r = true;
	}
	return r;
}

int TimeValidator::getHour(std::string time) {
	std::regex aTime("(\\d{2})\:(\\d{2})");

	if (std::regex_match(time, aTime)) {
		return std::stoi(std::regex_replace(time, aTime, "$01"));

	}
}
int TimeValidator::getMin(std::string time) {

	std::regex aTime("(\\d{2})\:(\\d{2})");
	if (std::regex_match(time, aTime)) {
		return std::stoi(std::regex_replace(time, aTime, "$02"));

	}
}

bool TimeValidator::restrictedTime(std::string time) {

	bool r = false;
	int minutes = getHour(time) * 60 + getMin(time);

	if (minutes < 570 && minutes > 420) {
		r = true;
	}
	else if (minutes < 1170 && minutes > 960) {
		r = true;
	}
	return r;
}