/*
The following program prompts a user to evaluate the nature
of a prompted number in the range 1-100. The user's response
is evaluated against the prompted number. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void welcome() {
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Welcome to primes quiz!" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
}

void instructions() {
	std::cout << "Prepare to evaluate the nature of the following numbers." << std::endl;
	std::cout << "If a number is composite enter c or prime enter p. If" << std::endl;
	std::cout << "you'd like to quit enter q." << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
}

int prompt() {
	int value = (rand() % 100) + 1;
	std::cout << value << std::endl;
	return value;
}

bool isPrime(const unsigned int& value) {
	if (value == 1) return false;
	int root = round(sqrt(value));
	int i = 2;
	while (i <= root) {
		if (!(value % i))
			return false;
		i++;
	}
	return true;
}

void evaluate(const std::string& response, const int& value) {
	bool prime = isPrime(value);
	if (prime && response == "p" || !prime && response == "c")
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
}

int main()
{
	welcome();
	instructions();
	srand(time(nullptr));
	std::string s = "y";
	while (s != "q" || s == "Q") {
		std::string response;
		int value = prompt();
		std::cout << "> ";
		std::cin >> response;
		if (!response.empty())
			evaluate(response, value);
	}
    return 0;
}

