#include <iostream>
#include <fstream>
#include <string>

int64_t count_characters(char characterToSearchFor, std::string const& stringToSearch) {
	return std::count(std::begin(stringToSearch), std::end(stringToSearch), characterToSearchFor);
}

bool value_in_range(int64_t value, int64_t min, int64_t max) {
	return value >= min && value <= max;
}

int main() {
	std::string lineString;
	std::ifstream fileContents("input.txt");
	int countValid = 0;
	while (std::getline(fileContents, lineString)) {
		auto positionOfHyphen = lineString.find_first_of('-');
		int minValue = std::stoi(lineString.substr(0, positionOfHyphen));
		auto positionOfFirstSpace = lineString.find_first_of(' ');
		auto positionOfSecondSpace = lineString.find_last_of(' ');
		int maxValue = std::stoi(lineString.substr(positionOfHyphen + 1, positionOfFirstSpace));
		char importantChar = lineString[positionOfFirstSpace + 1];
		auto sizeOfLineString = lineString.length();
		std::string password = lineString.substr(positionOfSecondSpace + 1, sizeOfLineString - positionOfSecondSpace);
		int64_t characterCount = count_characters(importantChar, password);
		bool passwordValid = value_in_range(characterCount, minValue, maxValue);
		if (passwordValid) {
			countValid++;
		}
		std::cout << "Line string: " << lineString << "\n";
		std::cout << "Min value: " << minValue << "\n";
		std::cout << "Max value: " << maxValue << "\n";
		std::cout << "Important char: " << importantChar << "\n";
		std::cout << "Password: " << password << "\n";
		std::cout << "Character count: " << characterCount << "\n";
		std::cout << "Password valid: " << passwordValid << "\n\n";
	}
	std::cout << "\n\n\n\nValid count: " << countValid;
}

/*
Steps:
* Find the letter we care about
* Find the min + max of that letter
* Find the password
* Find instances of letter in password
* Check it's within range, valid if true, else false.
*/