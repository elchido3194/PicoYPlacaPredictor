#pragma once
#include <string>
#include <regex>
//Checks if it is a valid plate
bool plateIsCorrect(std::string plate) {
	std::regex aPlate("(A|B|U|C|X|H|O|E|W|G|I|L|R|M|V|N|S|P|Q|Y|J|K|T|Z)([A-Z]{2})\\-(\\d{3})(\\d?)");

	if (std::regex_match(plate, aPlate)) {
		return true;
	}
	else {
		return false;
	}

}
