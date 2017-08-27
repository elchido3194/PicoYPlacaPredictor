#pragma once
#include <string>
#include <regex>
#include <iostream>
int getDay(std::string date);
int getMonth(std::string date);
int getYear(std::string date);

//Checks if the date is correct
bool dateCorrect(std::string date){

	bool status = true;
	int day = getDay(date);
	int month = getMonth(date);
	int year = getYear(date);

	if ((month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12) && (day>31 || day<1))
	{
		status = false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day>30 || day<1))
	{
		status = false;
	}
	else if ((month == 2) && (year % 4 == 0) && (day>29 || day<1))
	{
		status = false;
	}
	else if ((month == 2) && (year % 4 != 0) && (day>28 || day<1))
	{
		status = false;
	}
	else if ((year < 999) || (year > 10000))
	{
		status = false;
	}
	if ((month < 1) || (month > 12))
	{
		status = false;
	}
	return status;
}
//Returns the day of the week for a given date
int getDayOfWeek_date(std::string date) {

	struct tm time;
	memset(&time, 0, sizeof(time));

	time.tm_mday = getDay(date);
	time.tm_mon = getMonth(date) - 1;
	time.tm_year = getYear(date) - 1900;

	mktime(&time);
	return time.tm_wday;
}
//Returns the day of the week depending on the plate's last digit
int getDayOfWeek_plate(std::string plate) {
	int dig = plate.back() - 48;//For most encodings, numbers go from 48 to 57
	if ((dig == 1) || (dig == 2)) {
		return 0;
	}
	else if ((dig == 3) || (dig == 4)) {
		return 1;
	}
	else if ((dig == 5) || (dig == 6)) {
		return 2;
	}
	else if ((dig == 7) || (dig == 8)) {
		return 3;
	}
	else if ((dig == 9) || (dig == 0)) {
		return 4;
	}
}

int getDay(std::string date) {
	std::regex aDate("(\\d{2})/(\\d{2})/(\\d{4})");

	if (std::regex_match(date, aDate)) {
		return std::stoi(std::regex_replace(date, aDate, "$01"));
	}
}

int getMonth(std::string date){
	std::regex aDate("(\\d{2})/(\\d{2})/(\\d{4})");

	if (std::regex_match(date, aDate)) {
		return std::stoi(std::regex_replace(date, aDate, "$02"));
	}
}
int getYear(std::string date) {
	std::regex aDate("(\\d{2})/(\\d{2})/(\\d{4})");

	if (std::regex_match(date, aDate)) {
		return std::stoi(std::regex_replace(date, aDate, "$03"));
	}
}