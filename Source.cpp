#include <iostream>
#include <fstream>
#include <string>

int count_characters(char characterToSearchFor, std::string stringToSearch) {
	int count = 0;

	for (int i = 0; i < stringToSearch.size(); i++)
		if (stringToSearch[i] == characterToSearchFor) count++;

	return count;
}

bool value_in_range(int value, int min, int max) {
	if (value >= min && value <= max) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::string lineString;
	std::ifstream fileContents("input.txt");
	int countValid = 0;
	while (std::getline(fileContents, lineString)) {
		int positionOfHyphen = lineString.find_first_of("-");
		int minValue = std::stoi(lineString.substr(0, positionOfHyphen));
		int positionOfFirstSpace = lineString.find_first_of(" ");
		int positionOfSecondSpace = lineString.find_last_of(" ");
		int maxValue = std::stoi(lineString.substr(positionOfHyphen + 1, positionOfFirstSpace));
		char importantChar = lineString[positionOfFirstSpace + 1];
		int sizeOfLineString = lineString.length();
		std::string password = lineString.substr(positionOfSecondSpace + 1, sizeOfLineString - positionOfSecondSpace);
		int characterCount = count_characters(importantChar, password);
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